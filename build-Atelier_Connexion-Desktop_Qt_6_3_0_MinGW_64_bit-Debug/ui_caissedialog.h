/********************************************************************************
** Form generated from reading UI file 'caissedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAISSEDIALOG_H
#define UI_CAISSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CaisseDialog
{
public:
    QLabel *labelId;
    QLabel *labelNom;
    QLabel *labelPrenom;

    void setupUi(QDialog *CaisseDialog)
    {
        if (CaisseDialog->objectName().isEmpty())
            CaisseDialog->setObjectName(QString::fromUtf8("CaisseDialog"));
        CaisseDialog->resize(794, 481);
        labelId = new QLabel(CaisseDialog);
        labelId->setObjectName(QString::fromUtf8("labelId"));
        labelId->setGeometry(QRect(240, 390, 151, 51));
        labelNom = new QLabel(CaisseDialog);
        labelNom->setObjectName(QString::fromUtf8("labelNom"));
        labelNom->setGeometry(QRect(240, 250, 151, 51));
        labelPrenom = new QLabel(CaisseDialog);
        labelPrenom->setObjectName(QString::fromUtf8("labelPrenom"));
        labelPrenom->setGeometry(QRect(240, 320, 151, 51));

        retranslateUi(CaisseDialog);

        QMetaObject::connectSlotsByName(CaisseDialog);
    } // setupUi

    void retranslateUi(QDialog *CaisseDialog)
    {
        CaisseDialog->setWindowTitle(QCoreApplication::translate("CaisseDialog", "Dialog", nullptr));
        labelId->setText(QCoreApplication::translate("CaisseDialog", "TextLabel", nullptr));
        labelNom->setText(QCoreApplication::translate("CaisseDialog", "TextLabel", nullptr));
        labelPrenom->setText(QCoreApplication::translate("CaisseDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CaisseDialog: public Ui_CaisseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAISSEDIALOG_H
