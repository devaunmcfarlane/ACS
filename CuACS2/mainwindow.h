#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QMessageBox>
#include "database.h"
#include "staffcontrol.h"
#include "animalcontrol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    StaffControl * staffCtrl;
    AnimalControl * animalCtrl;
    void checkLineEdits();

private slots:

    void on_staffLoginButton_clicked();

    void on_staffLoginButton_2_clicked();

    void on_sPortalAddAnimal_clicked();

    void on_addAnimalBackButton_clicked();

    void on_addAnimalButton_clicked();

    void on_sPortalViewAnimals_clicked();

    void on_backToStaffPortal_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
