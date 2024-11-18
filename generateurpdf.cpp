#include "generateurpdf.h"
#include <QMessageBox>
void GenerateurPDF::genererPDF(QSqlQueryModel* model, const QString& nomFichierPDF) {
    QPdfWriter writer(nomFichierPDF);//creer un fichier pdf
    QPainter painter(&writer); //dessiner dans le fichier pdf(essiner des éléments graphiques (comme du texte et des formes)


    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);


    int rowCount = model->rowCount(); //rowCount et columnCount : Nombre de lignes et colonnes dans le modèle SQL
    int columnCount = model->columnCount();
    int cellWidth = 1996;//cellWidth et cellHeight : Dimensions (en pixels) des cellules dans le tableau PDF
    int cellHeight = 400;
    int margin = 10; // Marge entre les éléments du tableau.


    for (int i = 0; i < columnCount; ++i) {

        painter.drawRect(margin + i * cellWidth, margin, cellWidth, cellHeight);

        painter.drawText(margin + i * cellWidth, margin, cellWidth, cellHeight, Qt::AlignCenter, model->headerData(i, Qt::Horizontal).toString().toUtf8());
    }


    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {

            painter.drawRect(margin + col * cellWidth, margin + (row + 1) * cellHeight, cellWidth, cellHeight);

            painter.drawText(margin + col * cellWidth, margin + (row + 1) * cellHeight, cellWidth, cellHeight, Qt::AlignCenter, model->data(model->index(row, col)).toString().toUtf8());
        }
    }


    painter.drawRect(margin, margin + (rowCount + 1) * cellHeight, columnCount * cellWidth, cellHeight);
    painter.drawText(margin, margin + (rowCount + 1) * cellHeight, columnCount * cellWidth, cellHeight, Qt::AlignCenter, "Fin du document");

    QMessageBox::information(nullptr, "PDF créé", "Le fichier PDF a été créé avec succès !");
}
