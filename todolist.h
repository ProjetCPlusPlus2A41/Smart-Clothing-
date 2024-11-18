#ifndef TODOLIST_H
#define TODOLIST_H

#include <QWidget>

namespace Ui {
class TodoList;
}

class TodoList : public QWidget
{
    Q_OBJECT

public:
    explicit TodoList(QWidget *parent = nullptr);
    ~TodoList();

private slots:
    void addTask();       // Fonction pour ajouter une tâche avec une date d'échéance
    void deleteTask();    // Fonction pour supprimer la tâche sélectionnée
    void markTaskDone();  // Fonction pour marquer la tâche sélectionnée comme terminée

private:
    Ui::TodoList *ui;
};

#endif // TODOLIST_H
