#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    connect(ui->forgot_password, &QPushButton::clicked, this, [this]() { navigateToPage(1); });

}

login::~login()
{
    delete ui;
}
void login::on_pushButton_login_clicked()
{
    QString email = ui->lineEdit_email->text(); // Assuming you have a lineEdit for email
    QString password = ui->lineEdit_password->text(); // Assuming you have a lineEdit for password

    // Prepare SQL query to check credentials
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEE WHERE MAIL_E = :email AND MDP = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (query.exec()) {
        if (query.next()) { // If a record was found
            // Login successful, open MainWindow
            MainWindow *mainWindow = new MainWindow(); // Create an instance of MainWindow
            mainWindow->show(); // Show the main window
            this->close(); // Close the login window
        } else {
            // Show error message for invalid credentials
            QMessageBox::warning(this, "Invalid Credentials", "Invalid email or password.");
        }
    } else {
        // Show error message for database error
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }

}



void login::on_pushButton_confirm_clicked()
{
    QString email = ui->lineEdit_email_forgot->text(); // Get email from the forgot password page
    QString question = ui->comboBox_question->currentText(); // Get selected question
    QString answer = ui->lineEdit_answer->text(); // Get answer from QLineEdit

    // Validate the security question and answer
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEE WHERE MAIL_E = :email AND QUESTION = :question AND REPONSE = :answer");
    query.bindValue(":email", email);
    query.bindValue(":question", question);
    query.bindValue(":answer", answer);

    if (query.exec()) {
        if (query.next()) {
            currentEmail = email; // Store current email for password update
            ui->stackedWidget->setCurrentIndex(2); // Navigate to the change password page
        } else {
            QMessageBox::warning(this, "Invalid Information", "The provided Email, Answer or question is incorrect.");
        }
    } else {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void login::on_pushButton_change_password_clicked()
{
    QString newPassword = ui->lineEdit_new_password->text();
    QString confirmPassword = ui->lineEdit_repeat_password->text();

    // Check if both passwords match
    if (newPassword == confirmPassword) {
        // Update the password in the database
        QSqlQuery query;
        query.prepare("UPDATE EMPLOYEE SET MDP = :newPassword WHERE MAIL_E = :email");
        query.bindValue(":newPassword", newPassword);
        query.bindValue(":email", currentEmail);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Password changed successfully.");
            ui->stackedWidget->setCurrentIndex(0); // Navigate back to the login page after success
        } else {
            QMessageBox::critical(this, "Database Error", query.lastError().text());
        }
    } else {
        QMessageBox::warning(this, "Password Mismatch", "The new password and confirmation do not match.");
    }
}
void login::navigateToPage(int pageIndex)
{
    ui->stackedWidget->setCurrentIndex(pageIndex);
}
