/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton_login;
    QLabel *label;
    QLineEdit *lineEdit_email;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_7;
    QPushButton *forgot_password;
    QWidget *page_2;
    QLabel *label_12;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_confirm;
    QLineEdit *lineEdit_answer;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_10;
    QComboBox *comboBox_question;
    QLabel *label_19;
    QLineEdit *lineEdit_email_forgot;
    QWidget *page_3;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *lineEdit_repeat_password;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *pushButton_change_password;
    QLineEdit *lineEdit_new_password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1268, 780);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-10, 0, 1261, 731));
        page = new QWidget();
        page->setObjectName("page");
        pushButton_login = new QPushButton(page);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(490, 430, 221, 31));
        pushButton_login->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 0, 153);\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px;\n"
"}"));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(-30, 0, 1301, 721));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/back.jpg")));
        label->setScaledContents(true);
        lineEdit_email = new QLineEdit(page);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(490, 310, 221, 26));
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid rgb(255, 0, 153); /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(380, 140, 491, 461));
        label_5->setStyleSheet(QString::fromUtf8("QString imagePath1 = \"file:///C:/Users/the cast/Downloads/cnx.png\";"));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/cnx.png")));
        label_5->setScaledContents(true);
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 10, 301, 281));
        label_2->setStyleSheet(QString::fromUtf8("QString imagePath2 = \"file:///C:/Users/the cast/Downloads/logo.png\";"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/logo.png")));
        label_2->setScaledContents(true);
        lineEdit_password = new QLineEdit(page);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(490, 380, 221, 26));
        lineEdit_password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid rgb(255, 0, 153); /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(450, 220, 201, 51));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(230, 23, 147);\n"
"font: 15pt \"Titillium Web\";\n"
"border-radius: 10px; /* Coins arrondis */"));
        label_11 = new QLabel(page);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(490, 350, 191, 20));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 9pt \"Yu Gothic\";\n"
""));
        label_7 = new QLabel(page);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(490, 280, 191, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 9pt \"Yu Gothic\";\n"
""));
        forgot_password = new QPushButton(page);
        forgot_password->setObjectName("forgot_password");
        forgot_password->setGeometry(QRect(630, 220, 141, 31));
        forgot_password->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 0, 153);\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px;\n"
"}"));
        stackedWidget->addWidget(page);
        label->raise();
        label_5->raise();
        label_2->raise();
        lineEdit_password->raise();
        label_8->raise();
        label_11->raise();
        label_7->raise();
        lineEdit_email->raise();
        pushButton_login->raise();
        forgot_password->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_12 = new QLabel(page_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(500, 430, 191, 20));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 9pt \"Yu Gothic\";\n"
""));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(450, 10, 301, 281));
        label_3->setStyleSheet(QString::fromUtf8("QString imagePath2 = \"file:///C:/Users/the cast/Downloads/logo.png\";"));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/logo.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(-30, 0, 1301, 721));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/back.jpg")));
        label_4->setScaledContents(true);
        pushButton_confirm = new QPushButton(page_2);
        pushButton_confirm->setObjectName("pushButton_confirm");
        pushButton_confirm->setGeometry(QRect(500, 510, 221, 31));
        pushButton_confirm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 0, 153);\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px;\n"
"}"));
        lineEdit_answer = new QLineEdit(page_2);
        lineEdit_answer->setObjectName("lineEdit_answer");
        lineEdit_answer->setGeometry(QRect(500, 460, 221, 26));
        lineEdit_answer->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid rgb(255, 0, 153); /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(500, 350, 191, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 9pt \"Yu Gothic\";\n"
""));
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(380, 140, 491, 541));
        label_6->setStyleSheet(QString::fromUtf8("QString imagePath1 = \"file:///C:/Users/the cast/Downloads/cnx.png\";"));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/cnx.png")));
        label_6->setScaledContents(true);
        label_10 = new QLabel(page_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(510, 220, 201, 51));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(230, 23, 147);\n"
"font: 15pt \"Titillium Web\";\n"
"border-radius: 10px; /* Coins arrondis */"));
        comboBox_question = new QComboBox(page_2);
        comboBox_question->addItem(QString());
        comboBox_question->addItem(QString());
        comboBox_question->addItem(QString());
        comboBox_question->addItem(QString());
        comboBox_question->addItem(QString());
        comboBox_question->setObjectName("comboBox_question");
        comboBox_question->setGeometry(QRect(480, 380, 291, 31));
        comboBox_question->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;"));
        label_19 = new QLabel(page_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(500, 280, 191, 20));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 9pt \"Yu Gothic\";\n"
""));
        lineEdit_email_forgot = new QLineEdit(page_2);
        lineEdit_email_forgot->setObjectName("lineEdit_email_forgot");
        lineEdit_email_forgot->setGeometry(QRect(500, 310, 221, 26));
        lineEdit_email_forgot->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid rgb(255, 0, 153); /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        stackedWidget->addWidget(page_2);
        label_4->raise();
        label_6->raise();
        label_12->raise();
        label_3->raise();
        pushButton_confirm->raise();
        lineEdit_answer->raise();
        label_9->raise();
        label_10->raise();
        comboBox_question->raise();
        label_19->raise();
        lineEdit_email_forgot->raise();
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_13 = new QLabel(page_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(-30, 0, 1301, 721));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/back.jpg")));
        label_13->setScaledContents(true);
        label_14 = new QLabel(page_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(450, 10, 301, 281));
        label_14->setStyleSheet(QString::fromUtf8("QString imagePath2 = \"file:///C:/Users/the cast/Downloads/logo.png\";"));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/logo.png")));
        label_14->setScaledContents(true);
        label_15 = new QLabel(page_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(380, 140, 491, 461));
        label_15->setStyleSheet(QString::fromUtf8("QString imagePath1 = \"file:///C:/Users/the cast/Downloads/cnx.png\";"));
        label_15->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/cnx.png")));
        label_15->setScaledContents(true);
        label_16 = new QLabel(page_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(510, 220, 201, 51));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(230, 23, 147);\n"
"font: 15pt \"Titillium Web\";\n"
"border-radius: 10px; /* Coins arrondis */"));
        lineEdit_repeat_password = new QLineEdit(page_3);
        lineEdit_repeat_password->setObjectName("lineEdit_repeat_password");
        lineEdit_repeat_password->setGeometry(QRect(490, 380, 221, 26));
        lineEdit_repeat_password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid rgb(255, 0, 153); /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        label_17 = new QLabel(page_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(490, 350, 191, 20));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 9pt \"Yu Gothic\";\n"
""));
        label_18 = new QLabel(page_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(490, 280, 191, 20));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 9pt \"Yu Gothic\";\n"
""));
        pushButton_change_password = new QPushButton(page_3);
        pushButton_change_password->setObjectName("pushButton_change_password");
        pushButton_change_password->setGeometry(QRect(490, 430, 221, 31));
        pushButton_change_password->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 0, 153);\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px;\n"
"}"));
        lineEdit_new_password = new QLineEdit(page_3);
        lineEdit_new_password->setObjectName("lineEdit_new_password");
        lineEdit_new_password->setGeometry(QRect(490, 310, 221, 26));
        lineEdit_new_password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid rgb(255, 0, 153); /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        stackedWidget->addWidget(page_3);
        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1268, 26));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName("statusbar");
        login->setStatusBar(statusbar);

        retranslateUi(login);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "MainWindow", nullptr));
        pushButton_login->setText(QCoreApplication::translate("login", "LOGIN", nullptr));
        label->setText(QString());
        label_5->setText(QString());
        label_2->setText(QString());
        label_8->setText(QCoreApplication::translate("login", "       Welcome", nullptr));
        label_11->setText(QCoreApplication::translate("login", "Password:", nullptr));
        label_7->setText(QCoreApplication::translate("login", "Email:", nullptr));
        forgot_password->setText(QCoreApplication::translate("login", "forgot password ? ", nullptr));
        label_12->setText(QCoreApplication::translate("login", "Answer", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        pushButton_confirm->setText(QCoreApplication::translate("login", "CONFIRM", nullptr));
        label_9->setText(QCoreApplication::translate("login", "Question:", nullptr));
        label_6->setText(QString());
        label_10->setText(QCoreApplication::translate("login", "Forgot Password", nullptr));
        comboBox_question->setItemText(0, QCoreApplication::translate("login", "Quelle est votre date de naissance ?", nullptr));
        comboBox_question->setItemText(1, QCoreApplication::translate("login", "Quel est le titre de votre certification professionnelle la plus r\303\251cente ?", nullptr));
        comboBox_question->setItemText(2, QCoreApplication::translate("login", "Quel est le nom de votre superviseur professionnel dans notre entreprise ?", nullptr));
        comboBox_question->setItemText(3, QCoreApplication::translate("login", "Quelle est la date \303\240 laquelle vous avez rejoint notre entreprise ?", nullptr));
        comboBox_question->setItemText(4, QCoreApplication::translate("login", "Quelle est la sp\303\251cialisation de votre premier dipl\303\264me ?", nullptr));

        label_19->setText(QCoreApplication::translate("login", "Email:", nullptr));
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QCoreApplication::translate("login", "Forgot Password", nullptr));
        label_17->setText(QCoreApplication::translate("login", "Repeat password", nullptr));
        label_18->setText(QCoreApplication::translate("login", "Enter New Password", nullptr));
        pushButton_change_password->setText(QCoreApplication::translate("login", "Change Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
