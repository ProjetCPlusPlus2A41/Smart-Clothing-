#ifndef MESSAGERIE_H
#define MESSAGERIE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QComboBox>

class Messagerie : public QWidget {
    Q_OBJECT

public:
    explicit Messagerie(QWidget *parent = nullptr);

private slots:
    void sendMessageUser1();
    void sendMessageUser2();
    void sendMessageUser3(); // New method for User 3

private:
    QLineEdit *lineEditMessage1;
    QPushButton *pushButtonSend1;
    QListWidget *listWidgetMessages1;
    QComboBox *comboBoxUser1; // ComboBox for User 1

    QLineEdit *lineEditMessage2;
    QPushButton *pushButtonSend2;
    QListWidget *listWidgetMessages2;
    QComboBox *comboBoxUser2; // ComboBox for User 2

    QLineEdit *lineEditMessage3; // New for User 3
    QPushButton *pushButtonSend3; // New for User 3
    QListWidget *listWidgetMessages3; // New for User 3
    QComboBox *comboBoxUser3; // ComboBox for User 3
};

#endif // MESSAGERIE_H
