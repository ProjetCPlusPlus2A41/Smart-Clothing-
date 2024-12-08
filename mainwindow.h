#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "livraison.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void clear();
    bool controlSaisie();
    void on_tab_livraison_activated(const QModelIndex &index);

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

private:
    Ui::MainWindow *ui;
    Livraison L;
};
#endif // MAINWINDOW_H
