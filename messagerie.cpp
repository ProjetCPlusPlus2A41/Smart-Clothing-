#include "messagerie.h"
#include <QVBoxLayout>
#include <QString>
#include <QStackedWidget>

Messagerie::Messagerie(QWidget *parent)
    : QWidget(parent) {
    QStackedWidget *stackedWidget = parent->findChild<QStackedWidget*>("stackedWidget");

    // User 1
    QWidget *page3 = stackedWidget->widget(2);
    lineEditMessage1 = page3->findChild<QLineEdit*>("lineEditMessage1");
    pushButtonSend1 = page3->findChild<QPushButton*>("pushButtonSend1");
    listWidgetMessages1 = page3->findChild<QListWidget*>("listWidgetMessages1");
    comboBoxUser1 = page3->findChild<QComboBox*>("comboBoxUser1"); // ComboBox for User 1

    // User 2
    QWidget *page4 = stackedWidget->widget(3);
    lineEditMessage2 = page4->findChild<QLineEdit*>("lineEditMessage2");
    pushButtonSend2 = page4->findChild<QPushButton*>("pushButtonSend2");
    listWidgetMessages2 = page4->findChild<QListWidget*>("listWidgetMessages2");
    comboBoxUser2 = page4->findChild<QComboBox*>("comboBoxUser2"); // ComboBox for User 2

    // User 3
    QWidget *page5 = stackedWidget->widget(4); // Assuming User 3 is on the fifth page
    lineEditMessage3 = page5->findChild<QLineEdit*>("lineEditMessage3");
    pushButtonSend3 = page5->findChild<QPushButton*>("pushButtonSend3");
    listWidgetMessages3 = page5->findChild<QListWidget*>("listWidgetMessages3");
    comboBoxUser3 = page5->findChild<QComboBox*>("comboBoxUser3"); // ComboBox for User 3

    // Connect button signals
    connect(pushButtonSend1, &QPushButton::clicked, this, &Messagerie::sendMessageUser1);
    connect(pushButtonSend2, &QPushButton::clicked, this, &Messagerie::sendMessageUser2);
    connect(pushButtonSend3, &QPushButton::clicked, this, &Messagerie::sendMessageUser3);
}

void Messagerie::sendMessageUser1() {
    QString message = lineEditMessage1->text();
    if (!message.isEmpty()) {
        QString recipient = comboBoxUser1->currentText();
        listWidgetMessages1->addItem("Sent to " + recipient + ": " + message);
        lineEditMessage1->clear();

        // Simulate receiving the message in the appropriate list
        if (recipient == "Gestion Employee") {
            listWidgetMessages2->addItem("Received from Gestion Client: " + message);
        } else if (recipient == "Gestion Product") {
            listWidgetMessages3->addItem("Received from Gestion Client: " + message);
        }
    }
}

void Messagerie::sendMessageUser2() {
    QString message = lineEditMessage2->text();
    if (!message.isEmpty()) {
        QString recipient = comboBoxUser2->currentText();
        listWidgetMessages2->addItem("Sent to " + recipient + ": " + message);
        lineEditMessage2->clear();

        // Simulate receiving the message in the appropriate list
        if (recipient == "Gestion Client") {
            listWidgetMessages1->addItem("Received from Gestion Employee: " + message);
        } else if (recipient == "Gestion Product") {
            listWidgetMessages3->addItem("Received from Gestion Employee: " + message);
        }
    }
}

void Messagerie::sendMessageUser3() {
    QString message = lineEditMessage3->text();
    if (!message.isEmpty()) {
        QString recipient = comboBoxUser3->currentText();
        listWidgetMessages3->addItem("Sent to " + recipient + ": " + message);
        lineEditMessage3->clear();

        // Simulate receiving the message in the appropriate list
        if (recipient == "Gestion Client") {
            listWidgetMessages1->addItem("Received from Gestion Product: " + message);
        } else if (recipient == "Gestion Employee") {
            listWidgetMessages2->addItem("Received from Gestion Product: " + message);
        }
    }
}
