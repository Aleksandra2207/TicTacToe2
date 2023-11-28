#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "QMessageBox"


const QString k2P="k2P";
const QString kPC="kPC";
const QString k2C="k2C";
const QString kHellowWindowTitle = "Крестики-Нолики";

WelcomeWindow::WelcomeWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    setWindowTitle(kHellowWindowTitle);
    connect(ui->pushButtonContinue, &QPushButton::clicked, this, &WelcomeWindow::onPushButtonContinueClicked);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::onPushButtonContinueClicked()
{
    if(ui->radioButtonTwoPerson->isChecked()==false && ui->radioButtonPerson_Computer->isChecked()==false && ui->radioButton_TwoComputer->isChecked()==false)
    {
        QMessageBox errorMessage;
        errorMessage.setText("Пожалуйста, сделайте выбор режима");
        errorMessage.exec();

    }
    if(ui->radioButtonTwoPerson->isChecked()==true)
    {
        emit sendMode(modeTwoPerson);
        emit nextWindow(k2P);
        close();
    }
    if(ui->radioButtonPerson_Computer->isChecked()==true)
    {
        emit sendMode(modePerson_Computer);
        emit nextWindow(kPC);
        close();
    }
    if(ui->radioButton_TwoComputer->isChecked()==true)
    {
        emit sendMode(modeTwoComputer);
        emit nextWindow(k2C);
        close();
    }
}
