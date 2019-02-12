#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    QSqlDatabase start = QSqlDatabase::addDatabase("QSQLITE");
    start.setHostName( "test" );
    start.setDatabaseName("wowab");

    database* db = new database(start);

    staffCtrl = new StaffControl(db);
    animalCtrl = new AnimalControl(db);

    /*connect(ui->addAnimalType, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->addAnimalBreed, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->addAnimalAge, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->addAnimalSize, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->addAnimalColour, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->addAnimalWeight, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    */
}

MainWindow::~MainWindow()
{
    staffCtrl->returnAllDataToDb();
    animalCtrl->returnAllDataToDb();
    delete ui;
}

void MainWindow::on_staffLoginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->badLoginLabel->setVisible(false);
}

void MainWindow::on_staffLoginButton_2_clicked()
{
    int idInputed = ui->staffIdInput->text().toInt();
    QString passwordInputed = ui->staffPasswordInput->text();
    if(staffCtrl->checkPassword(idInputed, passwordInputed)) {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else {
        ui->badLoginLabel->setVisible(true);
    }
}

void MainWindow::on_sPortalAddAnimal_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->typeNotInputed->setVisible(false);
    ui->breedNotInputed->setVisible(false);
    ui->ageNotInputed->setVisible(false);
    ui->sizeNotInputed->setVisible(false);
    ui->colourNotInputed->setVisible(false);
    ui->weightNotInputed->setVisible(false);

}

void MainWindow::on_addAnimalBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->addAnimalType->setText("");
    ui->addAnimalBreed->setText("");
    ui->addAnimalAge->setText("");
    ui->addAnimalSize->setText("");
    ui->addAnimalColour->setText("");
    ui->addAnimalWeight->setText("");
}

void MainWindow::checkLineEdits() {
    bool ok = !ui->addAnimalType->text().isEmpty()
        && !ui->addAnimalBreed->text().isEmpty()
        && !ui->addAnimalAge->text().isEmpty()
        && !ui->addAnimalSize->text().isEmpty()
        && !ui->addAnimalColour->text().isEmpty()
        && !ui->addAnimalWeight->text().isEmpty();
    ui->addAnimalButton->setEnabled(ok);
}

void MainWindow::on_addAnimalButton_clicked()
{
    QString type = ui->addAnimalType->text();
    QString breed = ui->addAnimalBreed->text();
    QString age = ui->addAnimalAge->text();
    QString size = ui->addAnimalSize->text();
    QString colour = ui->addAnimalColour->text();
    QString weight = ui->addAnimalWeight->text();
    if(type != "" && breed != "" && age != "" && size != "" && colour != "" && weight != "") {
        bool result = animalCtrl->addAnimal(type, breed, age, size, colour, weight);
        if (result) {
            QMessageBox::information(
                this,
                tr("CuACS"),
                tr("Animal Added.") );
            ui->addAnimalType->setText("");
            ui->addAnimalBreed->setText("");
            ui->addAnimalAge->setText("");
            ui->addAnimalSize->setText("");
            ui->addAnimalColour->setText("");
            ui->addAnimalWeight->setText("");
        }
        else {
            QMessageBox::warning(
                this,
                tr("CuACS"),
                tr("Animal Not Added.") );
            ui->addAnimalType->setText("");
            ui->addAnimalBreed->setText("");
            ui->addAnimalAge->setText("");
            ui->addAnimalSize->setText("");
            ui->addAnimalColour->setText("");
            ui->addAnimalWeight->setText("");
        }
    }
    else {
        if(type == "") {
            ui->typeNotInputed->setVisible(true);
        }
        if(breed == "") {
            ui->breedNotInputed->setVisible(true);
        }
        if(age == "") {
            ui->ageNotInputed->setVisible(true);
        }
        if(size == "") {
            ui->sizeNotInputed->setVisible(true);
        }if(colour == "") {
            ui->colourNotInputed->setVisible(true);
        }
        if(weight == "") {
            ui->weightNotInputed->setVisible(true);
        }
    }
}

void MainWindow::on_sPortalViewAnimals_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    AnimalArray* aArray = new AnimalArray();
    aArray = animalCtrl->getAllAnimals();

    QTableWidgetItem* item = new QTableWidgetItem();

    for(int i = 0; i < aArray->getSize(); i++){
            ui->SummaryTable->insertRow(ui->SummaryTable->rowCount());
            for(int j = 0; j < 7; j++){
                switch(j){
                case 0:
                    item = new QTableWidgetItem();
                    item->setData(Qt::DisplayRole, aArray->getAnimal(i)->getID());
                    ui->SummaryTable->setItem(i,j,item);
                    break;
                case 1:
                    item = new QTableWidgetItem();
                    item->setData(Qt::DisplayRole, aArray->getAnimal(i)->getType());
                    ui->SummaryTable->setItem(i,j,item);
                    break;
                case 2:
                    item = new QTableWidgetItem();
                    item->setData(Qt::DisplayRole, aArray->getAnimal(i)->getBreed());
                    ui->SummaryTable->setItem(i,j,item);
                    break;
                case 3:
                    item = new QTableWidgetItem();
                    item->setData(Qt::DisplayRole, aArray->getAnimal(i)->getAge());
                    ui->SummaryTable->setItem(i,j,item);
                    break;
                case 4:
                    item = new QTableWidgetItem();
                    item->setData(Qt::DisplayRole, aArray->getAnimal(i)->getSize());
                    ui->SummaryTable->setItem(i,j,item);
                    break;
                case 5:
                    item = new QTableWidgetItem();
                    item->setData(Qt::DisplayRole, aArray->getAnimal(i)->getColour());
                    ui->SummaryTable->setItem(i,j,item);
                    break;
                case 6:
                    item = new QTableWidgetItem();
                    item->setData(Qt::DisplayRole, aArray->getAnimal(i)->getWeight());
                    ui->SummaryTable->setItem(i,j,item);
                    break;
                }
            }
    }
}

void MainWindow::on_backToStaffPortal_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

