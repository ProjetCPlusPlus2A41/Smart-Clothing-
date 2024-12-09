/********************************************************************************
** Form generated from reading UI file 'historiquedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIQUEDIALOG_H
#define UI_HISTORIQUEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_HistoriqueDialog
{
public:
    QLabel *label_2;
    QLabel *label;
    QListView *historiqueList;

    void setupUi(QDialog *HistoriqueDialog)
    {
        if (HistoriqueDialog->objectName().isEmpty())
            HistoriqueDialog->setObjectName(QStringLiteral("HistoriqueDialog"));
        HistoriqueDialog->resize(649, 462);
        label_2 = new QLabel(HistoriqueDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 330, 261, 41));
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"	font: 700 italic 15pt \"Segoe UI\";"));
        label = new QLabel(HistoriqueDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 250, 611, 581));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/aesthetic template 02.jpeg")));
        label->setScaledContents(true);
        historiqueList = new QListView(HistoriqueDialog);
        historiqueList->setObjectName(QStringLiteral("historiqueList"));
        historiqueList->setGeometry(QRect(300, 430, 451, 321));
        historiqueList->setStyleSheet(QLatin1String(" background-color: transparent;\n"
"    width: 10px;\n"
"    border: 2px solid transparent;\n"
"    border-radius: 25px;\n"
"   font:16px;\n"
""));

        retranslateUi(HistoriqueDialog);

        QMetaObject::connectSlotsByName(HistoriqueDialog);
    } // setupUi

    void retranslateUi(QDialog *HistoriqueDialog)
    {
        HistoriqueDialog->setWindowTitle(QApplication::translate("HistoriqueDialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("HistoriqueDialog", "HISTORIQUE", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HistoriqueDialog: public Ui_HistoriqueDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIQUEDIALOG_H
