/********************************************************************************
** Form generated from reading UI file 'historiquedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIQUEDIALOG_H
#define UI_HISTORIQUEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_HistoriqueDialog
{
public:
    QLabel *label_2;
    QListView *historiqueList;
    QLabel *label;

    void setupUi(QDialog *HistoriqueDialog)
    {
        if (HistoriqueDialog->objectName().isEmpty())
            HistoriqueDialog->setObjectName(QString::fromUtf8("HistoriqueDialog"));
        HistoriqueDialog->resize(1162, 673);
        label_2 = new QLabel(HistoriqueDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 270, 261, 41));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"\n"
"	font: 700 italic 15pt \"Segoe UI\";"));
        historiqueList = new QListView(HistoriqueDialog);
        historiqueList->setObjectName(QString::fromUtf8("historiqueList"));
        historiqueList->setGeometry(QRect(220, 370, 451, 321));
        historiqueList->setStyleSheet(QString::fromUtf8(" background-color: transparent;\n"
"    width: 10px;\n"
"    border: 2px solid transparent;\n"
"    border-radius: 25px;\n"
"   font:16px;\n"
""));
        label = new QLabel(HistoriqueDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 190, 611, 581));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/aesthetic template 02.jpeg")));
        label->setScaledContents(true);

        retranslateUi(HistoriqueDialog);

        QMetaObject::connectSlotsByName(HistoriqueDialog);
    } // setupUi

    void retranslateUi(QDialog *HistoriqueDialog)
    {
        HistoriqueDialog->setWindowTitle(QCoreApplication::translate("HistoriqueDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("HistoriqueDialog", "HISTORIQUE", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HistoriqueDialog: public Ui_HistoriqueDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIQUEDIALOG_H
