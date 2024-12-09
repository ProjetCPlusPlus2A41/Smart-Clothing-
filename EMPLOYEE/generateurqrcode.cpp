#include "generateurqrcode.h"  // Include the header to match the declaration
#include <QPainter>
#include "QrCodeGenerator.h"  // Include the QR code generator header

GenerateurQRCode::GenerateurQRCode() {
    // Constructor implementation (if any)
}

QImage GenerateurQRCode::genererCodeQR(const QString &donnees) {
    using namespace qrcodegen;

    QrCodeGenerator generator;
    QImage qrCodeImage = generator.generateQr(donnees, 200);  // QR code generation
    return qrCodeImage;  // Return the generated QR code as QImage
}
