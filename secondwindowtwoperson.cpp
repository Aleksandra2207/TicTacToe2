#include "secondwindowtwoperson.h"
#include "ui_secondwindowtwoperson.h"
#include <QMessageBox>

const QString kHellowWindowTitle = "Крестики-Нолики";

SecondWindowTwoPerson::SecondWindowTwoPerson(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindowTwoPerson)
{
    ui->setupUi(this);
    setWindowTitle(kHellowWindowTitle);
    connect(ui->pushButton, &QPushButton::clicked, this, &SecondWindowTwoPerson::onPushButtonStartClicked);
}

SecondWindowTwoPerson::~SecondWindowTwoPerson()
{
    delete ui;
}

QString SecondWindowTwoPerson::getPlayer1Name()
{
    return ui->lineEditName1->text();
}

QString SecondWindowTwoPerson::getPlayer2Name()
{
    return ui->lineEditName_2->text();
}

void SecondWindowTwoPerson::onPushButtonStartClicked()
{
    if(ui->radioButton0_1->isChecked()==false && ui->radioButtonX_2->isChecked()==false && ui->radioButtonX_1->isChecked()==false && ui->radioButton0_2->isChecked()==false)
    {
        QMessageBox errorMessage;
        errorMessage.setText("Пожалуйста, сделайте выбор символа");
        errorMessage.exec();
    }

    if((ui->radioButton0_1->isChecked()==true && ui->radioButton0_2->isChecked()==true) ||  (ui->radioButtonX_1->isChecked()==true && ui->radioButtonX_2->isChecked()==true))
    {
        QMessageBox errorMessage;
        errorMessage.setText("Пожалуйста, сделайте корректный выбор");
        errorMessage.exec();
    }
    if(ui->lineEditName1->text().isEmpty() || ui->lineEditName_2->text().isEmpty())
    {
        QMessageBox errorMessage;
        errorMessage.setText("Пожалуйста, введите имя игроков");
        errorMessage.exec();
    }
    if(ui->radioButton0_1->isChecked()==true && ui->radioButtonX_2->isChecked()==true && !ui->lineEditName1->text().isEmpty() && !ui->lineEditName_2->text().isEmpty())
    {
        emit sendSigns(ui->radioButton0_1->text(), ui->radioButtonX_2->text());
        emit sendPlayersName(ui->lineEditName1->text(), ui->lineEditName_2->text());
        emit nextWindow();
        close();
    }
    if(ui->radioButtonX_1->isChecked()==true && ui->radioButton0_2->isChecked()==true && !ui->lineEditName1->text().isEmpty() && !ui->lineEditName_2->text().isEmpty())
    {
        emit sendSigns(ui->radioButtonX_1->text(), ui->radioButton0_2->text());
        emit sendPlayersName(ui->lineEditName1->text(), ui->lineEditName_2->text());
        emit nextWindow();
        close();
    }
}
