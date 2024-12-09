#ifndef GENERATEURQRCODE_H
#define GENERATEURQRCODE_H

#include <QImage>
#include <QString>

class GenerateurQRCode {
public:
    GenerateurQRCode(); // Constructor declaration
    QImage genererCodeQR(const QString &donnees); // Function declaration
};

#endif // GENERATEURQRCODE_H
