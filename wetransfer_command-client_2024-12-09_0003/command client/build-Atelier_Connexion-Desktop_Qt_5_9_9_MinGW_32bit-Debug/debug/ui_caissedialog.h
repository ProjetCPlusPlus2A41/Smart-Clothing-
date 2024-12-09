/********************************************************************************
** Form generated from reading UI file 'caissedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAISSEDIALOG_H
#define UI_CAISSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CaisseDialog
{
public:
    QLabel *labelPrenom;
    QLabel *labelId;
    QLabel *labelNom;

    void setupUi(QDialog *CaisseDialog)
    {
        if (CaisseDialog->objectName().isEmpty())
            CaisseDialog->setObjectName(QStringLiteral("CaisseDialog"));
        CaisseDialog->resize(864, 630);
        labelPrenom = new QLabel(CaisseDialog);
        labelPrenom->setObjectName(QStringLiteral("labelPrenom"));
        labelPrenom->setGeometry(QRect(200, 240, 151, 51));
        labelId = new QLabel(CaisseDialog);
        labelId->setObjectName(QStringLiteral("labelId"));
        labelId->setGeometry(QRect(200, 310, 151, 51));
        labelNom = new QLabel(CaisseDialog);
        labelNom->setObjectName(QStringLiteral("labelNom"));
        labelNom->setGeometry(QRect(200, 170, 151, 51));

        retranslateUi(CaisseDialog);

        QMetaObject::connectSlotsByName(CaisseDialog);
    } // setupUi

    void retranslateUi(QDialog *CaisseDialog)
    {
        CaisseDialog->setWindowTitle(QApplication::translate("CaisseDialog", "Dialog", Q_NULLPTR));
        labelPrenom->setText(QApplication::translate("CaisseDialog", "TextLabel", Q_NULLPTR));
        labelId->setText(QApplication::translate("CaisseDialog", "TextLabel", Q_NULLPTR));
        labelNom->setText(QApplication::translate("CaisseDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CaisseDialog: public Ui_CaisseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAISSEDIALOG_H
