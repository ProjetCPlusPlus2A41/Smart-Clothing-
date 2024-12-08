#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include "gestionemployee.h"
#include "todolist.h"

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
    void on_pushButton_5_clicked();
    void on_pushButton_12_clicked();
    //void on_tableView_selectionChanged();
    void on_tableView_activated(QModelIndex &index);

    void on_pushButton_9_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_6_clicked();
    void on_button_Image_clicked();

    //void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();
    void on_buttonpdf_clicked();
    void navigateToPage(int pageIndex);

    //void rechercherParID();
    //void drawPieChart();


    void on_pushButton_3_clicked();
    void showTodoList(); // Slot pour afficher la Todolist


    void on_pushButton_7_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::MainWindow *ui;
    gestionemployee Etmp;
    //int selectedID=-1;
    void loadImage(const QString& imagePath, QLabel* label);
    bool ascending;
    bool sortBySalary;
    QSqlQueryModel *model;
    QLabel *m_statisticsLabel;
    TodoList *todoListWindow;



};


#endif // MAINWINDOW_H
