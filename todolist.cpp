#include "todolist.h"
#include "ui_todolist.h"
#include <QMainWindow>
#include <QDateEdit>
#include <QDate>

TodoList::TodoList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TodoList)
{
    ui->setupUi(this);
    connect(ui->addButton, &QPushButton::clicked, this, &TodoList::addTask);
    connect(ui->deleteButton, &QPushButton::clicked, this, &TodoList::deleteTask);
    connect(ui->markDoneButton, &QPushButton::clicked, this, &TodoList::markTaskDone);
}

TodoList::~TodoList()
{
    delete ui;
}

// Ajoute une tâche avec la date d’échéance
void TodoList::addTask()
{
    QString taskText = ui->taskInput->text().trimmed();
    QDate dueDate = ui->dueDateEdit->date();
    if (!taskText.isEmpty()) {
        QString taskWithDate = QString("%1 (Échéance : %2)")
                                   .arg(taskText)
                                   .arg(dueDate.toString("dd/MM/yyyy"));
        ui->taskList->addItem(taskWithDate);
        ui->taskInput->clear();
        ui->dueDateEdit->setDate(QDate::currentDate()); // Réinitialise la date
    }
}

// Supprime la tâche sélectionnée de la liste active
void TodoList::deleteTask()
{
    QListWidgetItem *selectedItem = nullptr;

    // Essaie de supprimer dans taskList
    selectedItem = ui->taskList->currentItem();
    if (selectedItem) {
        delete ui->taskList->takeItem(ui->taskList->row(selectedItem));
        qDebug() << "Tâche supprimée de taskList";
        return;
    }

    // Sinon, essaie de supprimer dans completedTaskList
    selectedItem = ui->completedTaskList->currentItem();
    if (selectedItem) {
        delete ui->completedTaskList->takeItem(ui->completedTaskList->row(selectedItem));
        qDebug() << "Tâche supprimée de completedTaskList";
    } else {
        qDebug() << "Aucune tâche sélectionnée pour suppression";
    }
}

// Marque la tâche sélectionnée comme terminée et la déplace vers completedTaskList
void TodoList::markTaskDone()
{
    QListWidgetItem *selectedItem = ui->taskList->currentItem();
    if (selectedItem) {
        QString completedTask = selectedItem->text();
        ui->completedTaskList->addItem(completedTask);
        delete ui->taskList->takeItem(ui->taskList->row(selectedItem));
    }
}
