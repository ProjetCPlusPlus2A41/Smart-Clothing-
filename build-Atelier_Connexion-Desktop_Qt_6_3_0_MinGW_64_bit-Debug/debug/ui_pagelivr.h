/********************************************************************************
** Form generated from reading UI file 'pagelivr.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGELIVR_H
#define UI_PAGELIVR_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pagelivr
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QPushButton *PDF;
    QPushButton *STAT;
    QTabWidget *tabWidget;
    QWidget *AjouterLivraison;
    QLineEdit *le_refL;
    QLineEdit *le_refCMDL;
    QLineEdit *le_prixL;
    QLineEdit *le_addresseL;
    QLineEdit *le_CINcL;
    QDateEdit *le_dateL;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pb_ajouter;
    QPushButton *pb_modifier;
    QComboBox *le_statusL;
    QComboBox *le_modeL;
    QWidget *tab;
    QTableView *tab_livraison;
    QLabel *label_12;
    QLineEdit *le_REFL_supp;
    QPushButton *pb_supprimer;
    QPushButton *sortAscButton;
    QPushButton *sortDescButton;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QLabel *label_13;
    QLabel *lab_chart;
    QPushButton *pushButton;
    QLineEdit *saveaddr;
    QWidget *tab_3;
    QPushButton *send;
    QLabel *label_53;
    QTimeEdit *timeEdit;
    QPlainTextEdit *msg;
    QLineEdit *rcpt;
    QLabel *label_56;
    QFrame *frame;
    QLabel *label;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_2;
    QPushButton *client1;
    QPushButton *emp;
    QPushButton *ordr;
    QPushButton *prom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *pagelivr)
    {
        if (pagelivr->objectName().isEmpty())
            pagelivr->setObjectName(QString::fromUtf8("pagelivr"));
        pagelivr->resize(1426, 896);
        centralwidget = new QWidget(pagelivr);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(180, 10, 1191, 761));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        PDF = new QPushButton(tab_2);
        PDF->setObjectName(QString::fromUtf8("PDF"));
        PDF->setGeometry(QRect(30, 240, 75, 23));
        PDF->setStyleSheet(QString::fromUtf8("color: #FF8C00;"));
        STAT = new QPushButton(tab_2);
        STAT->setObjectName(QString::fromUtf8("STAT"));
        STAT->setGeometry(QRect(40, 130, 101, 41));
        STAT->setStyleSheet(QString::fromUtf8("color: #FF8C00;"));
        tabWidget = new QTabWidget(tab_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(280, 70, 831, 631));
        tabWidget->setStyleSheet(QString::fromUtf8("QWidget{background:transparent; } \n"
"\n"
"QTabWidget::pane{border: 0px;background-color: transparent;font:Bold;\n"
"color: #528299;} \n"
"\n"
"QTabBar::tab {background-color: transparent;width:280px;height:40px;font-size:18px;font:regular;color:#115272;font:Bold;} \n"
"\n"
"QTabBar::tab:hover{\n"
"font:Bold;\n"
"color: #528299;\n"
"padding:4px;\n"
"font-size: 23px;}\n"
"QDateEdit {\n"
"    border-color: #528299;\n"
"    color: #000000;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-style: outset;\n"
"}\n"
"\n"
"\n"
"QPushButton{\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"color:#115272;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QPushButton::default{\n"
"	border-style: groove;\n"
"	border-width: 1px;\n"
"	border-radius:10px;\n"
"	padding: 2px;\n"
"color:#115272;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-style: groove;\n"
"	border-width: 1px;\n"
"	border-radius: 20px;\n"
"    color:#528299;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	bord"
                        "er-style: groove;\n"
"	border-width: 1px;\n"
"	border-radius: 20px;\n"
"	color: #528299;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-style: groove;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color:#115272;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"\n"
"QLineEdit {\n"
"border-color:#528299;color:#000000;\n"
"	border-width: 2px; border-radius: 10px;\n"
"	border-style: outset;\n"
"}\n"
"\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"	background-color: rgb(155, 186, 139);\n"
"	border: 1px solid #9BBA8B;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"/*QPlainTextEdit\n"
"{\n"
"	background-color: #F1615C;\n"
"	color : #eee;\n"
"	border: 1px solid #343434;\n"
"	border-radius: 2px;\n"
"	padding: 3px;\n"
"	padding-left: 5px;\n"
"}\n"
"*/\n"
"QHeaderView::section\n"
"{\n"
"background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(155, 186, 139, 255),stop:1 rgba(155, 186, 139, 255));\n"
"	border: 1px solid #89A46D;\n"
"    color: #fff;\n"
"    text-align: left;\n"
"	padding: 4px;\n"
""
                        "	\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:disabled\n"
"{\n"
"    background-color: #89A46D;\n"
"    color: #89A46D;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:checked\n"
"{\n"
"    background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(155, 186, 139, 255),stop:1 rgba(155, 186, 139, 255));\n"
"    color: #D3E2D3;\n"
"\n"
"}\n"
"\n"
"QHeaderView::section::vertical::first,\n"
"QHeaderView::section::vertical::only-one\n"
"{\n"
"    border-top: 1px solid #9BBA8B;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::vertical\n"
"{\n"
"    border-top: 1px solid #9BBA8B;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::horizontal::first,\n"
"QHeaderView::section::horizontal::only-one\n"
"{\n"
"    border-left: 1px solid #9BBA8B;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::horizontal\n"
"{\n"
"    border-left: 1px solid #9BBA8B;\n"
"\n"
"}\n"
"\n"
"\n"
"QTableCornerButton::section\n"
"{\n"
"    background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(155, 186, 13"
                        "9, 255),stop:1 rgba(155, 186, 139, 255));\n"
"	border: 1px solid #89A46D;\n"
"    color: #9BBA8B;\n"
"\n"
"}\n"
"\n"
"QListView \n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"    border : #89a46d;\n"
"    color: white;\n"
"    show-decoration-selected: 1; \n"
"    outline: 0;\n"
"	border: 1px solid #89a46d;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::disabled \n"
"{\n"
"	background-color: #89a46d;\n"
"	color: #3c768e;\n"
"    border: 1px solid #89a46d;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item \n"
"{\n"
"	background-color: #89a46d;\n"
"    padding: 1px;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:alternate \n"
"{\n"
"    background-color: #89a46d;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:selected \n"
"{\n"
"	background-color: #89a46d;\n"
"	border: 1px solid #89a46d;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:selected:!active \n"
"{\n"
"	background-color: #89a46d;\n"
"	border: 1px solid #89a46d;\n"
"	"
                        "color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:selected:active \n"
"{\n"
"	background-color: #89a46d;\n"
"	border: 1px solid #89a46d;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:hover {\n"
"    background-color: #89a46d;\n"
"    border: #89a46d;\n"
"    color: white;\n"
"\n"
"}\n"
"\n"
"\n"
"QRadioButton \n"
"{\n"
"	color: #fff;\n"
"	background-color: transparent;\n"
"\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator::unchecked:hover \n"
"{\n"
"	background-color: #fff;\n"
"	border: 2px solid #a3d1a3;\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator::checked \n"
"{\n"
"	border: 2px solid #a3d1a3;\n"
"	border-radius: 6px;\n"
"	/*background-color: rgba(155,186,139,20);*/  \n"
"	width: 9px; \n"
"	height: 9px; \n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QScrollBar:horizontal\n"
"{\n"
"    border: 1px solid #89a46d;\n"
"    background-color: #98a8b2;\n"
"    height: 15px;\n"
"    margin: 0px 16px 0 16px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"	background-color: qline"
                        "argradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    min-height: 20px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-line:horizontal\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    width: 15px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::sub-line:horizontal\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    width: 15px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::right-arrow:horizontal\n"
"{\n"
"    image: url(://arrow-right.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::left-a"
                        "rrow:horizontal\n"
"{\n"
"    image: url(://arrow-left.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"    background: none;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"    background-color: #98a8b2;\n"
"    width: 16px;\n"
"	border: 1px solid #89a46d;\n"
"    margin: 16px 0px 16px 0px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    min-height: 20px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    height: 15px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar"
                        "::sub-line:vertical\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    height: 15px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::up-arrow:vertical\n"
"{\n"
"    image: url(://arrow-up.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::down-arrow:vertical\n"
"{\n"
"    image: url(://arrow-down.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"    background: none;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QTableView::item:selected {\n"
"border: 2px solid #89a46d;\n"
"background-color:#b9c4ad;\n"
"};\n"
"\n"
""));
        AjouterLivraison = new QWidget();
        AjouterLivraison->setObjectName(QString::fromUtf8("AjouterLivraison"));
        le_refL = new QLineEdit(AjouterLivraison);
        le_refL->setObjectName(QString::fromUtf8("le_refL"));
        le_refL->setGeometry(QRect(230, 100, 261, 41));
        le_refCMDL = new QLineEdit(AjouterLivraison);
        le_refCMDL->setObjectName(QString::fromUtf8("le_refCMDL"));
        le_refCMDL->setGeometry(QRect(240, 210, 181, 41));
        le_prixL = new QLineEdit(AjouterLivraison);
        le_prixL->setObjectName(QString::fromUtf8("le_prixL"));
        le_prixL->setGeometry(QRect(120, 270, 171, 31));
        le_addresseL = new QLineEdit(AjouterLivraison);
        le_addresseL->setObjectName(QString::fromUtf8("le_addresseL"));
        le_addresseL->setGeometry(QRect(230, 440, 161, 31));
        le_CINcL = new QLineEdit(AjouterLivraison);
        le_CINcL->setObjectName(QString::fromUtf8("le_CINcL"));
        le_CINcL->setGeometry(QRect(230, 490, 161, 31));
        le_dateL = new QDateEdit(AjouterLivraison);
        le_dateL->setObjectName(QString::fromUtf8("le_dateL"));
        le_dateL->setGeometry(QRect(110, 160, 171, 41));
        le_dateL->setStyleSheet(QString::fromUtf8("QDate::currentDate()"));
        le_dateL->setMaximumDate(QDate(9999, 10, 30));
        le_dateL->setDisplayFormat(QString::fromUtf8("MM/dd/yy"));
        le_dateL->setCurrentSectionIndex(0);
        le_dateL->setTimeSpec(Qt::TimeZone);
        le_dateL->setDate(QDate(2000, 2, 10));
        label_3 = new QLabel(AjouterLivraison);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 30, 591, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(26);
        font.setBold(false);
        font.setItalic(false);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: #FFA500;\n"
"font: 50;"));
        label_4 = new QLabel(AjouterLivraison);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 110, 161, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font1.setPointSize(16);
        font1.setBold(false);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: #115272;\n"
""));
        label_5 = new QLabel(AjouterLivraison);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 170, 71, 21));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: #115272;\n"
""));
        label_6 = new QLabel(AjouterLivraison);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 220, 221, 21));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: #115272;\n"
""));
        label_7 = new QLabel(AjouterLivraison);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(370, 320, 101, 21));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: #115272;\n"
""));
        label_8 = new QLabel(AjouterLivraison);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 280, 71, 21));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: #115272;\n"
""));
        label_9 = new QLabel(AjouterLivraison);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 320, 91, 21));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: #115272;\n"
""));
        label_10 = new QLabel(AjouterLivraison);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(70, 440, 141, 21));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: #115272;\n"
""));
        label_11 = new QLabel(AjouterLivraison);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(70, 490, 151, 21));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: #115272;\n"
""));
        pb_ajouter = new QPushButton(AjouterLivraison);
        pb_ajouter->setObjectName(QString::fromUtf8("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(510, 430, 121, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font2.setPointSize(14);
        font2.setBold(false);
        pb_ajouter->setFont(font2);
        pb_ajouter->setStyleSheet(QString::fromUtf8("color: #FF8C00;"));
        pb_modifier = new QPushButton(AjouterLivraison);
        pb_modifier->setObjectName(QString::fromUtf8("pb_modifier"));
        pb_modifier->setGeometry(QRect(510, 480, 121, 31));
        pb_modifier->setFont(font2);
        pb_modifier->setStyleSheet(QString::fromUtf8("color: #FF8C00;"));
        le_statusL = new QComboBox(AjouterLivraison);
        le_statusL->addItem(QString());
        le_statusL->addItem(QString());
        le_statusL->addItem(QString());
        le_statusL->setObjectName(QString::fromUtf8("le_statusL"));
        le_statusL->setGeometry(QRect(120, 320, 171, 31));
        le_statusL->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border-color: #528299;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: transparent;\n"
"    padding: 2px;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: 1px solid #528299;\n"
"    border-radius: 5px;\n"
"    background-color: #FFFFFF;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(://down-arrow.png); /* Optional: replace with your own image */\n"
"}\n"
"\n"
"QComboBox::item {\n"
"    background-color: transparent;\n"
"    padding: 5px;\n"
"    color: #115272;\n"
"}\n"
"\n"
"QComboBox::item:selected {\n"
"    background-color: #89a46d;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QComboBox::editable {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QComboBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border-color: #528299;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border-color: #528299;\n"
"}\n"
""));
        le_statusL->setEditable(true);
        le_modeL = new QComboBox(AjouterLivraison);
        le_modeL->addItem(QString());
        le_modeL->addItem(QString());
        le_modeL->setObjectName(QString::fromUtf8("le_modeL"));
        le_modeL->setGeometry(QRect(470, 320, 171, 31));
        le_modeL->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border-color: #528299;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: transparent;\n"
"    padding: 2px;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: 1px solid #528299;\n"
"    border-radius: 5px;\n"
"    background-color: #FFFFFF;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(://down-arrow.png); /* Optional: replace with your own image */\n"
"}\n"
"\n"
"QComboBox::item {\n"
"    background-color: transparent;\n"
"    padding: 5px;\n"
"    color: #115272;\n"
"}\n"
"\n"
"QComboBox::item:selected {\n"
"    background-color: #89a46d;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QComboBox::editable {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QComboBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border-color: #528299;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border-color: #528299;\n"
"}\n"
""));
        le_modeL->setEditable(true);
        tabWidget->addTab(AjouterLivraison, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab_livraison = new QTableView(tab);
        tab_livraison->setObjectName(QString::fromUtf8("tab_livraison"));
        tab_livraison->setGeometry(QRect(50, 150, 661, 301));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        tab_livraison->setFont(font3);
        tab_livraison->setStyleSheet(QString::fromUtf8("\n"
"color:#3c768e;\n"
"QWidget{background:transparent} QTabWidget::pane{border: 1px/*;border-color:red*/;background-color: transparent;} \n"
"QTabBar::tab {background-color: transparent/*;color: #ccc*/;width: 200px;height:48px;font-size:12px} \n"
""));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(90, 460, 181, 41));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color:#115272;"));
        le_REFL_supp = new QLineEdit(tab);
        le_REFL_supp->setObjectName(QString::fromUtf8("le_REFL_supp"));
        le_REFL_supp->setGeometry(QRect(170, 510, 231, 41));
        QPalette palette;
        QBrush brush(QColor(60, 118, 142, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        le_REFL_supp->setPalette(palette);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font4.setPointSize(11);
        le_REFL_supp->setFont(font4);
        le_REFL_supp->setStyleSheet(QString::fromUtf8("color:#3c768e;\n"
""));
        le_REFL_supp->setAlignment(Qt::AlignCenter);
        pb_supprimer = new QPushButton(tab);
        pb_supprimer->setObjectName(QString::fromUtf8("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(430, 510, 131, 31));
        pb_supprimer->setFont(font2);
        pb_supprimer->setStyleSheet(QString::fromUtf8("color: #FF8C00;"));
        sortAscButton = new QPushButton(tab);
        sortAscButton->setObjectName(QString::fromUtf8("sortAscButton"));
        sortAscButton->setGeometry(QRect(50, 130, 301, 23));
        sortDescButton = new QPushButton(tab);
        sortDescButton->setObjectName(QString::fromUtf8("sortDescButton"));
        sortDescButton->setGeometry(QRect(344, 130, 371, 23));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(230, 90, 83, 18));
        radioButton->setStyleSheet(QString::fromUtf8("color: #FF8C00;"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(350, 80, 351, 31));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(110, 80, 91, 31));
        lab_chart = new QLabel(tab);
        lab_chart->setObjectName(QString::fromUtf8("lab_chart"));
        lab_chart->setGeometry(QRect(80, 60, 631, 441));
        tabWidget->addTab(tab, QString());
        lab_chart->raise();
        tab_livraison->raise();
        label_12->raise();
        le_REFL_supp->raise();
        pb_supprimer->raise();
        sortAscButton->raise();
        sortDescButton->raise();
        radioButton->raise();
        lineEdit->raise();
        label_13->raise();
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 360, 93, 28));
        pushButton->setStyleSheet(QString::fromUtf8("QWidget{background:transparent; } \n"
"\n"
"QTabWidget::pane{border: 0px;background-color: transparent;font:Bold;\n"
"color: #528299;} \n"
"\n"
"QTabBar::tab {background-color: transparent;width:280px;height:40px;font-size:18px;font:regular;color:#115272;font:Bold;} \n"
"\n"
"QTabBar::tab:hover{\n"
"font:Bold;\n"
"color: #528299;\n"
"padding:4px;\n"
"font-size: 23px;}\n"
"QDateEdit {\n"
"    border-color: #528299;\n"
"    color: #000000;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-style: outset;\n"
"}\n"
"\n"
"\n"
"QPushButton{\n"
"	border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"color:#115272;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QPushButton::default{\n"
"	border-style: groove;\n"
"	border-width: 1px;\n"
"	border-radius:10px;\n"
"	padding: 2px;\n"
"color:#115272;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-style: groove;\n"
"	border-width: 1px;\n"
"	border-radius: 20px;\n"
"    color:#528299;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	bord"
                        "er-style: groove;\n"
"	border-width: 1px;\n"
"	border-radius: 20px;\n"
"	color: #528299;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	border-style: groove;\n"
"	border-width: 1px;\n"
"	border-radius: 10px;\n"
"	color:#115272;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"\n"
"QLineEdit {\n"
"border-color:#528299;color:#000000;\n"
"	border-width: 2px; border-radius: 10px;\n"
"	border-style: outset;\n"
"}\n"
"\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"	background-color: rgb(155, 186, 139);\n"
"	border: 1px solid #9BBA8B;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"/*QPlainTextEdit\n"
"{\n"
"	background-color: #F1615C;\n"
"	color : #eee;\n"
"	border: 1px solid #343434;\n"
"	border-radius: 2px;\n"
"	padding: 3px;\n"
"	padding-left: 5px;\n"
"}\n"
"*/\n"
"QHeaderView::section\n"
"{\n"
"background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(155, 186, 139, 255),stop:1 rgba(155, 186, 139, 255));\n"
"	border: 1px solid #89A46D;\n"
"    color: #fff;\n"
"    text-align: left;\n"
"	padding: 4px;\n"
""
                        "	\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:disabled\n"
"{\n"
"    background-color: #89A46D;\n"
"    color: #89A46D;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:checked\n"
"{\n"
"    background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(155, 186, 139, 255),stop:1 rgba(155, 186, 139, 255));\n"
"    color: #D3E2D3;\n"
"\n"
"}\n"
"\n"
"QHeaderView::section::vertical::first,\n"
"QHeaderView::section::vertical::only-one\n"
"{\n"
"    border-top: 1px solid #9BBA8B;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::vertical\n"
"{\n"
"    border-top: 1px solid #9BBA8B;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::horizontal::first,\n"
"QHeaderView::section::horizontal::only-one\n"
"{\n"
"    border-left: 1px solid #9BBA8B;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::horizontal\n"
"{\n"
"    border-left: 1px solid #9BBA8B;\n"
"\n"
"}\n"
"\n"
"\n"
"QTableCornerButton::section\n"
"{\n"
"    background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(155, 186, 13"
                        "9, 255),stop:1 rgba(155, 186, 139, 255));\n"
"	border: 1px solid #89A46D;\n"
"    color: #9BBA8B;\n"
"\n"
"}\n"
"\n"
"QListView \n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"    border : #89a46d;\n"
"    color: white;\n"
"    show-decoration-selected: 1; \n"
"    outline: 0;\n"
"	border: 1px solid #89a46d;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::disabled \n"
"{\n"
"	background-color: #89a46d;\n"
"	color: #3c768e;\n"
"    border: 1px solid #89a46d;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item \n"
"{\n"
"	background-color: #89a46d;\n"
"    padding: 1px;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:alternate \n"
"{\n"
"    background-color: #89a46d;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:selected \n"
"{\n"
"	background-color: #89a46d;\n"
"	border: 1px solid #89a46d;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:selected:!active \n"
"{\n"
"	background-color: #89a46d;\n"
"	border: 1px solid #89a46d;\n"
"	"
                        "color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:selected:active \n"
"{\n"
"	background-color: #89a46d;\n"
"	border: 1px solid #89a46d;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:hover {\n"
"    background-color: #89a46d;\n"
"    border: #89a46d;\n"
"    color: white;\n"
"\n"
"}\n"
"\n"
"\n"
"QRadioButton \n"
"{\n"
"	color: #fff;\n"
"	background-color: transparent;\n"
"\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator::unchecked:hover \n"
"{\n"
"	background-color: #fff;\n"
"	border: 2px solid #a3d1a3;\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator::checked \n"
"{\n"
"	border: 2px solid #a3d1a3;\n"
"	border-radius: 6px;\n"
"	/*background-color: rgba(155,186,139,20);*/  \n"
"	width: 9px; \n"
"	height: 9px; \n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QScrollBar:horizontal\n"
"{\n"
"    border: 1px solid #89a46d;\n"
"    background-color: #98a8b2;\n"
"    height: 15px;\n"
"    margin: 0px 16px 0 16px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"	background-color: qline"
                        "argradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    min-height: 20px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-line:horizontal\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    width: 15px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::sub-line:horizontal\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    width: 15px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::right-arrow:horizontal\n"
"{\n"
"    image: url(://arrow-right.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::left-a"
                        "rrow:horizontal\n"
"{\n"
"    image: url(://arrow-left.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"    background: none;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"    background-color: #98a8b2;\n"
"    width: 16px;\n"
"	border: 1px solid #89a46d;\n"
"    margin: 16px 0px 16px 0px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    min-height: 20px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    height: 15px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar"
                        "::sub-line:vertical\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(196, 200, 207, 255),stop:1 rgba(196, 200, 207, 255));\n"
"	border: 1px solid #89a46d;\n"
"    height: 15px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::up-arrow:vertical\n"
"{\n"
"    image: url(://arrow-up.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::down-arrow:vertical\n"
"{\n"
"    image: url(://arrow-down.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"    background: none;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QTableView::item:selected {\n"
"border: 2px solid #89a46d;\n"
"background-color:#b9c4ad;\n"
"};\n"
"\n"
""));
        saveaddr = new QLineEdit(tab_2);
        saveaddr->setObjectName(QString::fromUtf8("saveaddr"));
        saveaddr->setGeometry(QRect(50, 140, 81, 20));
        tabWidget_2->addTab(tab_2, QString());
        saveaddr->raise();
        PDF->raise();
        STAT->raise();
        tabWidget->raise();
        pushButton->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        send = new QPushButton(tab_3);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(510, 487, 141, 31));
        label_53 = new QLabel(tab_3);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(170, 180, 191, 31));
        timeEdit = new QTimeEdit(tab_3);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(530, 490, 118, 22));
        msg = new QPlainTextEdit(tab_3);
        msg->setObjectName(QString::fromUtf8("msg"));
        msg->setGeometry(QRect(400, 310, 511, 150));
        rcpt = new QLineEdit(tab_3);
        rcpt->setObjectName(QString::fromUtf8("rcpt"));
        rcpt->setGeometry(QRect(410, 180, 501, 30));
        rcpt->setStyleSheet(QString::fromUtf8(""));
        label_56 = new QLabel(tab_3);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(160, 340, 171, 31));
        tabWidget_2->addTab(tab_3, QString());
        timeEdit->raise();
        send->raise();
        label_53->raise();
        msg->raise();
        rcpt->raise();
        label_56->raise();
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 181, 721));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 25px;\n"
"}"));
        frame->setFrameShape(QFrame::NoFrame);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 340, 51, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-color:  rgb(239, 142, 186);\n"
"border-radius:20px;\n"
"background-color: rgb(239, 142, 186);\n"
"}\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/WhatsApp_Image_2024-11-10_\303\240_18.51.31_1cb58230-removebg-preview.png")));
        label->setScaledContents(true);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 230, 121, 31));
        label_14->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(30, 290, 121, 31));
        label_15->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_16 = new QLabel(frame);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(30, 350, 121, 31));
        label_16->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(30, 420, 121, 31));
        label_17->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #EF8EBA;\n"
"    width: 10px;\n"
"    border: 2px solid #EF8EBA;\n"
"    border-radius: 15px;\n"
"}\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 500, 161, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(170, 170, 255);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:10px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        client1 = new QPushButton(frame);
        client1->setObjectName(QString::fromUtf8("client1"));
        client1->setGeometry(QRect(30, 90, 121, 51));
        client1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        emp = new QPushButton(frame);
        emp->setObjectName(QString::fromUtf8("emp"));
        emp->setGeometry(QRect(30, 160, 121, 51));
        emp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        ordr = new QPushButton(frame);
        ordr->setObjectName(QString::fromUtf8("ordr"));
        ordr->setGeometry(QRect(30, 280, 121, 51));
        ordr->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        prom = new QPushButton(frame);
        prom->setObjectName(QString::fromUtf8("prom"));
        prom->setGeometry(QRect(20, 410, 131, 51));
        prom->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 202, 213);\n"
"    color: white; /* Texte blanc */\n"
"    border-radius:20px  ; /* Coins arrondis */\n"
"	border-color: rgb(239, 142, 186);\n"
"    padding: 8px;\n"
"}"));
        pagelivr->setCentralWidget(centralwidget);
        menubar = new QMenuBar(pagelivr);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1426, 26));
        pagelivr->setMenuBar(menubar);
        statusbar = new QStatusBar(pagelivr);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        pagelivr->setStatusBar(statusbar);

        retranslateUi(pagelivr);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(pagelivr);
    } // setupUi

    void retranslateUi(QMainWindow *pagelivr)
    {
        pagelivr->setWindowTitle(QCoreApplication::translate("pagelivr", "MainWindow", nullptr));
        PDF->setText(QCoreApplication::translate("pagelivr", "PDF", nullptr));
        STAT->setText(QCoreApplication::translate("pagelivr", "stat", nullptr));
        label_3->setText(QCoreApplication::translate("pagelivr", "Les donn\303\251es de la livraison : ", nullptr));
        label_4->setText(QCoreApplication::translate("pagelivr", "R\303\251f\303\251rence :", nullptr));
        label_5->setText(QCoreApplication::translate("pagelivr", "Date:", nullptr));
        label_6->setText(QCoreApplication::translate("pagelivr", "R\303\251f Commande:", nullptr));
        label_7->setText(QCoreApplication::translate("pagelivr", "Mode :", nullptr));
        label_8->setText(QCoreApplication::translate("pagelivr", "Prix :", nullptr));
        label_9->setText(QCoreApplication::translate("pagelivr", "Status:", nullptr));
        label_10->setText(QCoreApplication::translate("pagelivr", "Addresse :", nullptr));
        label_11->setText(QCoreApplication::translate("pagelivr", "CIN Client:", nullptr));
        pb_ajouter->setText(QCoreApplication::translate("pagelivr", "Ajouter", nullptr));
        pb_modifier->setText(QCoreApplication::translate("pagelivr", "Modifier", nullptr));
        le_statusL->setItemText(0, QCoreApplication::translate("pagelivr", "En Cours", nullptr));
        le_statusL->setItemText(1, QCoreApplication::translate("pagelivr", "Livre", nullptr));
        le_statusL->setItemText(2, QCoreApplication::translate("pagelivr", "Retarde", nullptr));

        le_statusL->setCurrentText(QCoreApplication::translate("pagelivr", "En Cours", nullptr));
        le_modeL->setItemText(0, QCoreApplication::translate("pagelivr", "Standard", nullptr));
        le_modeL->setItemText(1, QCoreApplication::translate("pagelivr", "Express", nullptr));

        le_modeL->setCurrentText(QCoreApplication::translate("pagelivr", "Standard", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AjouterLivraison), QCoreApplication::translate("pagelivr", "Ajouter Livraison", nullptr));
        label_12->setText(QCoreApplication::translate("pagelivr", "Suppression :", nullptr));
        pb_supprimer->setText(QCoreApplication::translate("pagelivr", "supprimer", nullptr));
        sortAscButton->setText(QCoreApplication::translate("pagelivr", "asc", nullptr));
        sortDescButton->setText(QCoreApplication::translate("pagelivr", "desc", nullptr));
        radioButton->setText(QCoreApplication::translate("pagelivr", "Reference", nullptr));
        label_13->setText(QCoreApplication::translate("pagelivr", "Recherche", nullptr));
        lab_chart->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("pagelivr", "Afficher Livraison", nullptr));
        pushButton->setText(QCoreApplication::translate("pagelivr", "Show map", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("pagelivr", "Page 1", nullptr));
        send->setText(QCoreApplication::translate("pagelivr", "Send mail", nullptr));
        label_53->setText(QCoreApplication::translate("pagelivr", "Email", nullptr));
        label_56->setText(QCoreApplication::translate("pagelivr", "Message:", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("pagelivr", "Mailing", nullptr));
        label->setText(QString());
        label_14->setText(QCoreApplication::translate("pagelivr", "            Product", nullptr));
        label_15->setText(QCoreApplication::translate("pagelivr", "            Orders", nullptr));
        label_16->setText(QCoreApplication::translate("pagelivr", "            Delivery", nullptr));
        label_17->setText(QCoreApplication::translate("pagelivr", "            Promotion", nullptr));
        pushButton_2->setText(QCoreApplication::translate("pagelivr", "Deconnection", nullptr));
        client1->setText(QCoreApplication::translate("pagelivr", "Clients", nullptr));
        emp->setText(QCoreApplication::translate("pagelivr", "Employe", nullptr));
        ordr->setText(QCoreApplication::translate("pagelivr", "Orders", nullptr));
        prom->setText(QCoreApplication::translate("pagelivr", "promotion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pagelivr: public Ui_pagelivr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGELIVR_H
