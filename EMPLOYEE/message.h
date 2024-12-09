#ifndef MESSAGE_H
#define MESSAGE_H
#include "mainwindow.h"

#include "qdatetime.h"
#include <QWidget>

namespace Ui {
class Message;
}

class Message : public QWidget
{
    Q_OBJECT

public:
    explicit Message(QWidget *parent = nullptr);
    ~Message();
    void sendMessage();  // Declare the sendMessage function
    void updateNotificationsForReceiver(int receiverId);
    QList<Message> loadUnreadMessagesForReceiver(int receiverId);
    void onNotificationClick(int notificationIndex);
    void markMessageAsRead(const Message& msg);
    QJsonDocument loadJsonFile(const QString &filePath);
    void processJsonData(const QJsonDocument &doc);
    void openJsonFile();
    void saveJsonFile(const QString &filePath, const QJsonDocument &doc);
    void addMessageToJson(QJsonDocument &doc, const QString &messageContent);
    int id;
    int senderId;
    int receiverId;
    QString content;
    QDateTime timestamp;
    bool isRead;

    Message(int sender, int receiver, const QString& msg, const QDateTime& time)
        : senderId(sender), receiverId(receiver), content(msg), timestamp(time), isRead(false) {}

private:
    Ui::Message *ui;
    MainWindow *m_mainWindow;
};

#endif // MESSAGE_H
