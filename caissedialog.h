#ifndef CAISSEDIALOG_H
#define CAISSEDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class CaisseDialog;
}

class CaisseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CaisseDialog(QWidget *parent = nullptr);
    ~CaisseDialog();

    // Méthode pour définir les informations du client
    void setClientInfo(const QString& nom, const QString& prenom, int id);

private:
    Ui::CaisseDialog *ui;
};

#endif // CAISSEDIALOG_H
