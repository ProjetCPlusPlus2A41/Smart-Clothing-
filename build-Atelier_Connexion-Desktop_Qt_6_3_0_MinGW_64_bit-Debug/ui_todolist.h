/********************************************************************************
** Form generated from reading UI file 'todolist.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODOLIST_H
#define UI_TODOLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TodoList
{
public:
    QLabel *label_32;
    QListWidget *taskList;
    QLineEdit *taskInput;
    QDateEdit *dueDateEdit;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *markDoneButton;
    QLineEdit *lineEdit_23;
    QListWidget *completedTaskList;
    QLineEdit *lineEdit_24;
    QLineEdit *lineEdit_25;

    void setupUi(QWidget *TodoList)
    {
        if (TodoList->objectName().isEmpty())
            TodoList->setObjectName(QString::fromUtf8("TodoList"));
        TodoList->resize(1286, 715);
        label_32 = new QLabel(TodoList);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(0, 0, 1311, 741));
        label_32->setPixmap(QPixmap(QString::fromUtf8("../image/WhatsApp Image 2024-11-10 \303\240 18.51.31_e66bd550.jpg")));
        label_32->setScaledContents(true);
        taskList = new QListWidget(TodoList);
        taskList->setObjectName(QString::fromUtf8("taskList"));
        taskList->setGeometry(QRect(440, 180, 301, 461));
        taskList->setStyleSheet(QString::fromUtf8("\n"
"    border: 2px solid rgb(228, 196, 255);  \n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(233, 222, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        taskInput = new QLineEdit(TodoList);
        taskInput->setObjectName(QString::fromUtf8("taskInput"));
        taskInput->setGeometry(QRect(20, 210, 361, 61));
        taskInput->setStyleSheet(QString::fromUtf8("	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"    "));
        dueDateEdit = new QDateEdit(TodoList);
        dueDateEdit->setObjectName(QString::fromUtf8("dueDateEdit"));
        dueDateEdit->setGeometry(QRect(50, 290, 281, 31));
        dueDateEdit->setStyleSheet(QString::fromUtf8("	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;"));
        addButton = new QPushButton(TodoList);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(100, 340, 191, 41));
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        deleteButton = new QPushButton(TodoList);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(430, 660, 321, 41));
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(228, 196, 255);  \n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(233, 222, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
"}"));
        markDoneButton = new QPushButton(TodoList);
        markDoneButton->setObjectName(QString::fromUtf8("markDoneButton"));
        markDoneButton->setGeometry(QRect(830, 660, 321, 41));
        markDoneButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(228, 196, 255);  \n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(233, 222, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
"}"));
        lineEdit_23 = new QLineEdit(TodoList);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));
        lineEdit_23->setGeometry(QRect(690, 70, 271, 41));
        lineEdit_23->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	color: rgb(191, 139, 255);\n"
"	background-color: transparent;\n"
"	text-decoration: underline;\n"
"	font: 700 italic 20pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_23->setFrame(false);
        completedTaskList = new QListWidget(TodoList);
        completedTaskList->setObjectName(QString::fromUtf8("completedTaskList"));
        completedTaskList->setGeometry(QRect(840, 180, 301, 461));
        completedTaskList->setStyleSheet(QString::fromUtf8("\n"
"    border: 2px solid rgb(228, 196, 255);  \n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(233, 222, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        lineEdit_24 = new QLineEdit(TodoList);
        lineEdit_24->setObjectName(QString::fromUtf8("lineEdit_24"));
        lineEdit_24->setGeometry(QRect(500, 120, 271, 41));
        lineEdit_24->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	color: rgb(191, 139, 255);\n"
"	background-color: transparent;\n"
"	text-decoration: underline;\n"
"	font: 700 italic 20pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_24->setFrame(false);
        lineEdit_25 = new QLineEdit(TodoList);
        lineEdit_25->setObjectName(QString::fromUtf8("lineEdit_25"));
        lineEdit_25->setGeometry(QRect(890, 120, 271, 41));
        lineEdit_25->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	color: rgb(191, 139, 255);\n"
"	background-color: transparent;\n"
"	text-decoration: underline;\n"
"	font: 700 italic 20pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_25->setFrame(false);

        retranslateUi(TodoList);

        QMetaObject::connectSlotsByName(TodoList);
    } // setupUi

    void retranslateUi(QWidget *TodoList)
    {
        TodoList->setWindowTitle(QCoreApplication::translate("TodoList", "Form", nullptr));
        label_32->setText(QString());
        addButton->setText(QCoreApplication::translate("TodoList", "ADD", nullptr));
        deleteButton->setText(QCoreApplication::translate("TodoList", "DELETE", nullptr));
        markDoneButton->setText(QCoreApplication::translate("TodoList", "MARK", nullptr));
        lineEdit_23->setText(QCoreApplication::translate("TodoList", "TO DO LIST", nullptr));
        lineEdit_24->setText(QCoreApplication::translate("TodoList", "TO DO ", nullptr));
        lineEdit_25->setText(QCoreApplication::translate("TodoList", "DONE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TodoList: public Ui_TodoList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODOLIST_H
