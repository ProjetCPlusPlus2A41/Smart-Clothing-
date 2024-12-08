/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *qrcode;
    QWidget *tab;
    QLabel *label_15;
    QFrame *frame_3;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *histo;
    QFrame *frame_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QPushButton *pushButton_11;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QLabel *label_8;
    QLabel *label_19;
    QWidget *tab_3;
    QTableView *tableView;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QWidget *tab_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *stats;
    QWidget *tab_2;
    QFrame *frame_4;
    QLabel *qrcode_label;
    QLineEdit *qr_code_bar;
    QPushButton *pushButton_10;
    QWidget *tab_5;
    QLabel *label;
    QLabel *lab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1193, 758);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        qrcode = new QTabWidget(centralWidget);
        qrcode->setObjectName("qrcode");
        qrcode->setGeometry(QRect(100, 10, 1061, 661));
        qrcode->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"   \n"
"    border: 2px solid #EF8EBA; /* Pink border around the tab widget */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    padding: 5px; /* Space between tabs and content */\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: rgb(255, 176, 192); /* Slightly darker pink for tabs */\n"
"    border: 1px solid #EF8EBA; /* Pink border for tabs */\n"
"    border-radius: 10px; /* Rounded corners for tabs */\n"
"    padding: 5px 10px; /* Padding inside the tabs */\n"
"    color: #3F3F3F; /* Dark text color for contrast */\n"
"    font-weight: bold; /* Bold text for tabs */\n"
"    min-width: 80px; /* Minimum width for consistent sizing */\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #EF8EBA; /* Highlighted pink for selected tab */\n"
"    color: white; /* White text for better contrast on selected tab */\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background-color: rgb(255, 150, 170); /* Slightly brighter pink on hover */\n"
"    color: white; /* White text"
                        " on hover for visibility */\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* Push non-selected tabs down slightly for a layered look */\n"
"}\n"
"\n"
"QTabWidget QScrollBar {\n"
"    background: rgb(255, 202, 213); /* Match scrollbar background */\n"
"    border: none;\n"
"}\n"
"\n"
"QTabWidget QScrollBar::handle {\n"
"    background: #EF8EBA; /* Pink scrollbar handle */\n"
"    border-radius: 5px; /* Rounded scrollbar handle */\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        label_15 = new QLabel(tab);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(440, 20, 61, 51));
        label_15->setStyleSheet(QString::fromUtf8("QLabel{\n"
"\n"
"border-color:  transparent;\n"
"border-radius:20px;\n"
"}\n"
"QLabel {\n"
"    background-color: transparent;\n"
"}\n"
""));
        label_15->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/add-removebg-preview.png")));
        label_15->setScaledContents(true);
        frame_3 = new QFrame(tab);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(690, 10, 321, 511));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 25px;\n"
"}"));
        frame_3->setFrameShape(QFrame::NoFrame);
        label_17 = new QLabel(frame_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 140, 61, 61));
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        label_17->setPixmap(QPixmap(QString::fromUtf8("../../../Bureau/icon employee/liist or task.png")));
        label_17->setScaledContents(true);
        label_18 = new QLabel(frame_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 210, 61, 61));
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../../../Bureau/icon employee/Capture d\342\200\231\303\251cran 2024-10-20 152058.png")));
        label_18->setScaledContents(true);
        histo = new QPushButton(frame_3);
        histo->setObjectName("histo");
        histo->setGeometry(QRect(100, 230, 131, 51));
        histo->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        frame_2 = new QFrame(tab);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(240, 40, 431, 511));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 25px;\n"
"}"));
        frame_2->setFrameShape(QFrame::NoFrame);
        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(40, 70, 61, 20));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color: #EF8EBA;\n"
"	font: 700 italic 10pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_2->setFrame(false);
        lineEdit_3 = new QLineEdit(frame_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(20, 150, 81, 20));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color:#EF8EBA;\n"
"	font: 700 italic 10pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_3->setFrame(false);
        lineEdit_4 = new QLineEdit(frame_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(10, 190, 131, 20));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color:#EF8EBA;\n"
"	font: 700 italic 10pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_4->setFrame(false);
        lineEdit_5 = new QLineEdit(frame_2);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(20, 240, 121, 20));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color:#EF8EBA;\n"
"	font: 700 italic 10pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_5->setFrame(false);
        lineEdit_6 = new QLineEdit(frame_2);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(20, 270, 121, 20));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color: #EF8EBA;\n"
"	font: 700 italic 10pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_6->setFrame(false);
        lineEdit_7 = new QLineEdit(frame_2);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(20, 310, 131, 20));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color: #EF8EBA;\n"
"	font: 700 italic 10pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_7->setFrame(false);
        lineEdit_8 = new QLineEdit(frame_2);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(140, 70, 151, 26));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        lineEdit_9 = new QLineEdit(frame_2);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(140, 150, 151, 26));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        lineEdit_10 = new QLineEdit(frame_2);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(140, 190, 151, 26));
        lineEdit_10->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        lineEdit_13 = new QLineEdit(frame_2);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(140, 310, 151, 26));
        lineEdit_13->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        lineEdit_14 = new QLineEdit(frame_2);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(130, 10, 191, 31));
        lineEdit_14->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color: #EF8EBA;\n"
"	font: 700 italic 15pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_14->setFrame(false);
        lineEdit_16 = new QLineEdit(frame_2);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setGeometry(QRect(140, 350, 151, 26));
        lineEdit_16->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        lineEdit_18 = new QLineEdit(frame_2);
        lineEdit_18->setObjectName("lineEdit_18");
        lineEdit_18->setGeometry(QRect(20, 350, 101, 20));
        lineEdit_18->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color: #EF8EBA;\n"
"	font: 700 italic 10pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_18->setFrame(false);
        lineEdit_19 = new QLineEdit(frame_2);
        lineEdit_19->setObjectName("lineEdit_19");
        lineEdit_19->setGeometry(QRect(30, 390, 101, 20));
        lineEdit_19->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color: #EF8EBA;\n"
"	font: 700 italic 10pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_19->setFrame(false);
        lineEdit_20 = new QLineEdit(frame_2);
        lineEdit_20->setObjectName("lineEdit_20");
        lineEdit_20->setGeometry(QRect(140, 390, 151, 26));
        lineEdit_20->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 440, 111, 51));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(140, 100, 71, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        pushButton_8 = new QPushButton(frame_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(220, 100, 81, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(140, 230, 151, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;"));
        dateEdit_2 = new QDateEdit(frame_2);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(140, 270, 151, 31));
        dateEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;"));
        pushButton_11 = new QPushButton(frame_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(150, 440, 111, 51));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        frame = new QFrame(tab);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 20, 191, 541));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 25px;\n"
"}"));
        frame->setFrameShape(QFrame::NoFrame);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 120, 121, 31));
        label_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 50, 121, 31));
        label_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 200, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 270, 121, 31));
        label_5->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 340, 121, 31));
        label_6->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 420, 141, 31));
        label_7->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 490, 161, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(170, 170, 255);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:10px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 410, 51, 41));
        label_8->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_19 = new QLabel(tab);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(660, 20, 61, 51));
        label_19->setStyleSheet(QString::fromUtf8("QLabel{\n"
"\n"
"border-color:  transparent;\n"
"border-radius:20px;\n"
"}\n"
"QLabel {\n"
"    background-color: transparent;\n"
"}\n"
""));
        label_19->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/Capture_d_\303\251cran_2024-10-20_141614-removebg-preview.png")));
        label_19->setScaledContents(true);
        qrcode->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tableView = new QTableView(tab_3);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 90, 991, 511));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: rgb(255, 202, 213); /* Same pink background */\n"
"    border: 2px solid #EF8EBA; /* Pink border */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    padding: 2px;\n"
"    gridline-color: #EF8EBA; /* Gridlines with the same pink color */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    background-color: rgb(255, 255, 255); /* White background for items */\n"
"    border: 1px solid #EF8EBA; /* Light pink border for cells */\n"
"    padding: 5px; /* Padding inside cells */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: rgb(255, 176, 192); /* Slightly darker pink for headers */\n"
"    border: 1px solid #EF8EBA; /* Pink border for headers */\n"
"    color: #3F3F3F; /* Dark text color for contrast */\n"
"    font-weight: bold;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #EF8EBA; /* Highlighted item color */\n"
"    color: white; /* White text for selected items */\n"
"}\n"
"\n"
"QTableView QScrollBar {\n"
"    "
                        "background: rgb(255, 202, 213); /* Match scrollbar background */\n"
"    border: none;\n"
"}\n"
"\n"
"QTableView QScrollBar::handle {\n"
"    background: #EF8EBA; /* Pink scrollbar handle */\n"
"    border-radius: 5px; /* Rounded scrollbar handle */\n"
"}\n"
""));
        lineEdit_11 = new QLineEdit(tab_3);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(140, 30, 181, 41));
        lineEdit_11->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        lineEdit_12 = new QLineEdit(tab_3);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(30, 40, 101, 31));
        lineEdit_12->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	text-decoration: underline;\n"
"	color: #EF8EBA;\n"
"	font: 700 italic 10pt \"Segoe UI\";\n"
"	;\n"
"}"));
        lineEdit_12->setFrame(false);
        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(870, 20, 131, 51));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        pushButton_9 = new QPushButton(tab_3);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(730, 20, 131, 51));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        qrcode->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        verticalLayoutWidget = new QWidget(tab_4);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 30, 971, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stats = new QPushButton(tab_4);
        stats->setObjectName("stats");
        stats->setGeometry(QRect(400, 530, 241, 51));
        stats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        qrcode->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        frame_4 = new QFrame(tab_2);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(180, 40, 701, 501));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 25px;\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        qrcode_label = new QLabel(frame_4);
        qrcode_label->setObjectName("qrcode_label");
        qrcode_label->setGeometry(QRect(180, 70, 341, 301));
        qrcode_label->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    \n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"    padding: 20px; /* Add some inner spacing to frame content */\n"
"}\n"
"\n"
"QLabel {\n"
"    color: rgb(255, 255, 255);\n"
"    qproperty-alignment: 'AlignCenter'; /* Centers QLabel content */\n"
"}\n"
""));
        qr_code_bar = new QLineEdit(frame_4);
        qr_code_bar->setObjectName("qr_code_bar");
        qr_code_bar->setGeometry(QRect(320, 390, 341, 61));
        qr_code_bar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 202, 213);\n"
"    border: 2px solid #EF8EBA; /* Bordure rose */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 2px;\n"
"}"));
        pushButton_10 = new QPushButton(frame_4);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(40, 380, 261, 71));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        qrcode->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        label = new QLabel(tab_5);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 50, 661, 211));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(255, 176, 192); /* Light pink background */\n"
"    border: 2px solid #EF8EBA; /* Pink border around the label */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    padding: 10px; /* Padding inside the label */\n"
"    color: #3F3F3F; /* Dark text color for contrast */\n"
"    font-weight: bold; /* Bold text */\n"
"    font-size:24px; /* Adjust the font size as needed */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(255, 150, 170); /* Slightly brighter pink on hover */\n"
"    color: white; /* White text on hover for better contrast */\n"
"}\n"
""));
        lab = new QLabel(tab_5);
        lab->setObjectName("lab");
        lab->setGeometry(QRect(190, 290, 661, 211));
        lab->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(255, 176, 192); /* Light pink background */\n"
"    border: 2px solid #EF8EBA; /* Pink border around the label */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    padding: 10px; /* Padding inside the label */\n"
"    color: #3F3F3F; /* Dark text color for contrast */\n"
"    font-weight: bold; /* Bold text */\n"
"    font-size:24px; /* Adjust the font size as needed */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(255, 150, 170); /* Slightly brighter pink on hover */\n"
"    color: white; /* White text on hover for better contrast */\n"
"}\n"
""));
        qrcode->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1193, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        qrcode->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        label_15->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        histo->setText(QCoreApplication::translate("MainWindow", "Histo", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "ID_P", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "Nom-P", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "Pourcentage-P", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "DateDebut-P", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "DateFin-P", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "CodePromo-P", nullptr));
        lineEdit_14->setText(QCoreApplication::translate("MainWindow", "PROMOTION", nullptr));
        lineEdit_18->setText(QCoreApplication::translate("MainWindow", "Categorie-P", nullptr));
        lineEdit_19->setText(QCoreApplication::translate("MainWindow", "Statut-P", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "      Employee", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "          Client", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "        Product", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "         Orders", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "        Delivery", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "         Promotion", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Deconnection", nullptr));
        label_8->setText(QString());
        label_19->setText(QString());
        qrcode->setTabText(qrcode->indexOf(tab), QCoreApplication::translate("MainWindow", "Promotion", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindow", "recherch ", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Order", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "affichage", nullptr));
        qrcode->setTabText(qrcode->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        stats->setText(QCoreApplication::translate("MainWindow", "Stats", nullptr));
        qrcode->setTabText(qrcode->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Stats", nullptr));
        qrcode_label->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "QrCode", nullptr));
        qrcode->setTabText(qrcode->indexOf(tab_2), QCoreApplication::translate("MainWindow", "QrCode", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "waiting ...", nullptr));
        lab->setText(QString());
        qrcode->setTabText(qrcode->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Arduino", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
