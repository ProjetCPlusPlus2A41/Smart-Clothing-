#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_login_clicked(); // Slot for the login button click
    void on_pushButton_confirm_clicked(); // Slot for confirm button in forgot password
    void on_pushButton_change_password_clicked(); // Slot for change password button
    void navigateToPage(int pageIndex);

private:
    Ui::login *ui;
    QString currentEmail; // To store the current user's email for password update

};

#endif // LOGIN_H
