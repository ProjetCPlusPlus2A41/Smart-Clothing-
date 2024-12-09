#include "message.h"
#include "ui_message.h"
#include "mainwindow.h"  // Inclure le header de MainWindow
#include <QListWidget>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextStream>
#include <QDebug>

Message::Message(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Message)
{
    ui->setupUi(this);

    // Créer un widget de notification pour afficher les messages
    QListWidget *notificationWidget = new QListWidget(this);
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->addWidget(notificationWidget);
    // Exemple d'ajout de notification
    QListWidgetItem *item = new QListWidgetItem("Nouveau message de Gestionnaire " + QString::number(1));  // Exemple avec un senderId fictif
    item->setBackground(Qt::yellow);  // Couleur de la notification
    notificationWidget->addItem(item);
}

Message::~Message()
{
    delete ui;
}

void MainWindow::sendMessage() {
    int senderId = currentUserId;  // L'ID de l'utilisateur actuel
    int receiverId = selectedReceiverId;  // L'ID du gestionnaire destinataire
    QString content = messageInput->toPlainText();  // Contenu du message
    QDateTime timestamp = QDateTime::currentDateTime();  // Date/heure du message

    // Créer un nouveau message
    Message newMessage(senderId, receiverId, content, timestamp);

    // Sauvegarder ce message dans la base de données
    saveMessageToDatabase(newMessage);

    // Mettre à jour l'interface du gestionnaire destinataire
    updateNotificationsForReceiver(receiverId);
}

void MainWindow::updateNotificationsForReceiver(int receiverId) {
    // Récupérer tous les messages non lus pour ce gestionnaire
    QList<Message> unreadMessages = loadUnreadMessagesForReceiver(receiverId);

    // Si des messages non lus existent, afficher la notification
    for (const Message& msg : unreadMessages) {
        // Ajouter une notification dans l'interface utilisateur
        QListWidgetItem *item = new QListWidgetItem("Nouveau message de Gestionnaire " + QString::number(msg.senderId));
        item->setBackground(Qt::yellow);  // Couleur de la notification
        notificationWidget->addItem(item);
    }
}

QList<Message> MainWindow::loadUnreadMessagesForReceiver(int receiverId) {
    // Charger les messages non lus pour le gestionnaire actuel
    QList<Message> unreadMessages;

    // Exécution de la requête pour récupérer les messages non lus du gestionnaire
    for (const Message& msg : allMessages) {
        if (msg.receiverId == receiverId && !msg.isRead) {
            unreadMessages.append(msg);
        }
    }

    return unreadMessages;
}

void MainWindow::onNotificationClick(int notificationIndex) {
    // Récupérer le message complet à partir de l'index
    Message selectedMessage = loadMessageByIndex(notificationIndex);

    // Afficher le contenu du message
    messageContentDisplay->setText(selectedMessage.content);

    // Marquer le message comme lu
    markMessageAsRead(selectedMessage);
}

void MainWindow::markMessageAsRead(const Message& msg) {
    // Mettre à jour le statut du message dans la base de données (isRead = true)
    updateMessageStatus(msg.id, true);
}

QJsonDocument MainWindow::loadJsonFile(const QString &filePath) {
    QFile file(filePath);

    // Ouvrir le fichier en mode lecture
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Le fichier n'a pas pu être ouvert:" << filePath;
        return QJsonDocument();  // Retourner un document vide en cas d'échec
    }

    // Lire le contenu du fichier
    QByteArray data = file.readAll();

    // Fermer le fichier après lecture
    file.close();

    // Convertir le contenu en un QJsonDocument
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) {
        qWarning() << "Erreur lors de la lecture du fichier JSON";
    }

    return doc;
}

void MainWindow::processJsonData(const QJsonDocument &doc) {
    if (!doc.isNull()) {
        // Si le JSON est un objet
        if (doc.isObject()) {
            QJsonObject jsonObject = doc.object();
            if (jsonObject.contains("messages")) {
                QJsonArray messagesArray = jsonObject["messages"].toArray();

                // Parcourir tous les messages
                for (const QJsonValue &value : messagesArray) {
                    QJsonObject message = value.toObject();
                    int id = message["id"].toInt();
                    QString content = message["content"].toString();
                    qDebug() << "ID:" << id << "Content:" << content;
                }
            }
        }
    }
}

void MainWindow::openJsonFile() {
    QString filePath = "path/to/your/file.json";  // Spécifie le chemin de ton fichier JSON
    QJsonDocument doc = loadJsonFile(filePath);

    // Traiter les données JSON
    processJsonData(doc);
}

void MainWindow::saveJsonFile(const QString &filePath, const QJsonDocument &doc) {
    QFile file(filePath);

    // Ouvrir le fichier en mode écriture
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Le fichier n'a pas pu être ouvert pour l'écriture:" << filePath;
        return;
    }

    // Écrire le document JSON dans le fichier
    file.write(doc.toJson());

    // Fermer le fichier après écriture
    file.close();
}

void MainWindow::addMessageToJson(QJsonDocument &doc, const QString &messageContent) {
    if (doc.isObject()) {
        QJsonObject jsonObject = doc.object();

        // Charger les messages existants
        QJsonArray messagesArray = jsonObject["messages"].toArray();

        // Créer un nouveau message
        QJsonObject newMessage;
        newMessage["id"] = messagesArray.size() + 1;  // ID unique
        newMessage["content"] = messageContent;
        newMessage["isRead"] = false;

        // Ajouter le message au tableau
        messagesArray.append(newMessage);

        // Mettre à jour l'objet JSON
        jsonObject["messages"] = messagesArray;
        doc.setObject(jsonObject);

        // Sauvegarder les modifications dans le fichier
        saveJsonFile("path/to/your/file.json", doc);
    }
}
