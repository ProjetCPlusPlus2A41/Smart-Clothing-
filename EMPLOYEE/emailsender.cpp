#include "emailsender.h"
#include <QDebug>
#include <QSslSocket>
#include <QString>
#include <QTextStream>
EmailSender::EmailSender(const QString &from, const QString &to, const QString &subject, const QString &body, const QString &smtpServer, int port)
    : from(from), to(to), subject(subject), body(body), smtpServer(smtpServer), port(port) {

    appPassword = "qprn xxfu itjj nuse"; // Replace with a Google app password
    socket = new QSslSocket(this);
    connect(socket, &QSslSocket::encrypted, this, &EmailSender::onConnected);
    connect(socket, &QSslSocket::readyRead, this, &EmailSender::onReadyRead);

}

void EmailSender::sendMail() {
    socket->connectToHostEncrypted(smtpServer, port);
}

void EmailSender::onConnected() {
    stream.setDevice(socket);
    sendCommand("EHLO " + smtpServer);
}
void EmailSender::onReadyRead() {
    QString response = socket->readAll();
    qDebug() << "Server response:" << response;

    if (response.startsWith("220")) {
        sendCommand("EHLO " + smtpServer);
    } else if (response.startsWith("250") && !authenticated) {
        sendCommand("AUTH LOGIN");
    } else if (response.startsWith("334")) {
        // Username and password handling in base64 encoding
        if (!authenticated) {
            qDebug() << "Sending encoded username";
            sendCommand(from.toUtf8().toBase64());
        } else {
            qDebug() << "Sending encoded password";
            sendCommand(appPassword.toUtf8().toBase64());
        }
        authenticated = true;
    } else if (response.startsWith("354")) {
        QString message = "From: " + from + "\n" +
                          "To: " + to + "\n" +
                          "Subject: " + subject + "\n" +
                          body + "\n";
        sendCommand(message);
    } else if (response.startsWith("250 OK")) {
        qDebug() << "Email sent successfully.";
        socket->disconnectFromHost();
    } else {
        qDebug() << "Unexpected server response or error:" << response;
    }
}

void EmailSender::sendCommand(const QString &cmd) {
    qDebug() << "Sending command:" << cmd;
    stream << cmd << "\r\n";
    stream.flush();
    socket->waitForBytesWritten(500); // Wait for command to process
}

void EmailSender::onError(QAbstractSocket::SocketError socketError) {
    qDebug() << "Error:" << socketError << socket->errorString();
}
