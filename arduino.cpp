#include "arduino.h"
#include <QMessageBox>
#include <QStringList>
#include <QDebug>

// Example RFID database
QStringList rfidDatabase = {"12345678", "ABCDEF12", "87654321"}; // Replace with your database logic


Arduino::Arduino()
{
    data = "";
    arduino_port_name = "COM10";
    arduino_is_available = false;
    serial = new QSerialPort;
}

Arduino::~Arduino()
{
    if (serial) {
        if (serial->isOpen()) {
            serial->close();
        }
        delete serial;
    }
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

int Arduino::connect_arduino()
{
    // Recherche du port sur lequel la carte Arduino est connectée
    foreach (const QSerialPortInfo& serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_product_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }

    qDebug() << "Arduino port name is:" << arduino_port_name;

    if (arduino_is_available) { // Configuration de la communication
        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600); // Débit : 9600 bits/s
            serial->setDataBits(QSerialPort::Data8);    // Longueur des données : 8 bits
            serial->setParity(QSerialPort::NoParity);   // Pas de parité
            serial->setStopBits(QSerialPort::OneStop);  // 1 bit de stop
            serial->setFlowControl(QSerialPort::NoFlowControl);
            qDebug() << "Arduino connected successfully on port:" << arduino_port_name;
            return 0;
        } else {
            qDebug() << "Failed to open port:" << arduino_port_name;
            return 1;
        }
    }

    qDebug() << "Arduino not found. Please check the connection.";
    return -1;
}

int Arduino::close_arduino()
{
    if (serial && serial->isOpen()) {
        serial->close();
        qDebug() << "Arduino connection closed.";
        return 0;
    }
    qDebug() << "Failed to close Arduino connection.";
    return 1;
}

QByteArray Arduino::read_from_arduino()
{
    if (serial && serial->isReadable()) {
        data = serial->readAll(); // Récupérer les données reçues
        qDebug() << "Data read from Arduino:" << data;
        handleRFIDData(QString::fromStdString(data.toStdString()).trimmed());
        return data;
    }
    qDebug() << "Failed to read data from Arduino. Serial not readable.";
    return QByteArray();
}

void Arduino::write_to_arduino(QByteArray d)
{
    if (serial && serial->isWritable()) {
        serial->write(d); // Envoyer des données vers Arduino
        qDebug() << "Data written to Arduino:" << d;
    } else {
        qDebug() << "Couldn't write to serial!";
    }
}

void Arduino::handleRFIDData(const QString& rfidTag)
{
    if (rfidTag.isEmpty()) {
        qDebug() << "No RFID tag received.";
        return;
    }

    qDebug() << "Received RFID Tag:" << rfidTag;

    if (rfidDatabase.contains(rfidTag)) {
        // RFID is authorized
        write_to_arduino("1"); // Send '1' to Arduino
        QMessageBox::information(nullptr, "RFID", "RFID Tag Authorized: " + rfidTag);
    } else {
        // RFID is unauthorized
        write_to_arduino("0"); // Send '0' to Arduino
        QMessageBox::critical(nullptr, "RFID", "RFID Tag Unauthorized: " + rfidTag);
    }
}


/* void Arduino::handleRFIDData(const QString& rfidData)
{
    qDebug() << "Processing RFID data:" << rfidData;

    // Database query to check if the RFID exists
    QSqlQuery query;
    query.prepare("SELECT * FROM COMMANDE WHERE ID = :tag_id");
    query.bindValue(":tag_id", rfidData);

    if (query.exec()) {
        if (query.next()) {
            // RFID tag found in the database
            qDebug() << "RFID tag found in the database.";
            write_to_arduino("1"); // Send success signal to Arduino
        } else {
            // RFID tag not found
            qDebug() << "RFID tag not found in the database.";
            write_to_arduino("0"); // Send failure signal to Arduino
        }
    } else {
        // Query execution failed
        qDebug() << "Database query failed:" << query.lastError().text();
        write_to_arduino("0"); // Send failure signal to Arduino
    }
}


*/
QSerialPort *Arduino::getserial()
{
    return serial;
}
