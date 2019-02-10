#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase start = QSqlDatabase::addDatabase("QSQLITE");
    start.setHostName( "test" );
    start.setDatabaseName("wowab");

    database* db = new database(start);

    staffCtrl = new StaffControl(db);
}

MainWindow::~MainWindow()
{

    //delete staffCtrl;
    delete ui;

}
