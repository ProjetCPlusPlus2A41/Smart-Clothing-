#ifndef HISTORIQUEDIALOG_H
#define HISTORIQUEDIALOG_H

#include "qlabel.h"
#include <QWidget>
#include <QDialog>
#include <QListWidget>
#include <QStandardItemModel>

namespace Ui {
class HistoriqueDialog;
}

class HistoriqueDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoriqueDialog(QWidget *parent = nullptr);
    ~HistoriqueDialog();
    void chargerHistorique();


private:
    Ui::HistoriqueDialog *ui;
    QListWidget *historiqueList;
    QStringList historiqueEntries;
    void loadImage(const QString& imagePath, QLabel* label);
};

#endif // HISTORIQUEDIALOG_H
