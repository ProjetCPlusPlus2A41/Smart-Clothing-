#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino
{
public:
    Arduino();  // Constructor
    ~Arduino(); // Destructor

    int connect_arduino(); // Connect to Arduino
    int close_arduino();   // Close the connection
    void write_to_arduino(QByteArray data); // Send data to Arduino
    QByteArray read_from_arduino();         // Receive data from Arduino
    QString getarduino_port_name();
    QSerialPort* getserial();
    void handleRFIDData(const QString& rfidData); // Traiter les données RFID


private:
    QSerialPort* serial;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;

};

#endif // ARDUINO_H
