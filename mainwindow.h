#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clients.h"
#include "messagerie.h" // Include the Messagerie header
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_13_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_modifier_clicked();

    void on_modifier_2_clicked();
    void on_buttonsearch_clicked();
    void on_buttonpdff_clicked();
    void on_historiqueButton_clicked();
    void navigateToPage(int pageIndex);


private:
    Ui::MainWindow *ui;
    Messagerie *messagerieWidget; // Add this member variable
    clients ctmp;
    bool fid;
    bool sortByFidelity;
    QSqlQueryModel *model;

};

#endif // MAINWINDOW_H
