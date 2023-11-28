#include "secondwindowpersoncomputer.h"
#include "ui_secondwindowpersoncomputer.h"
#include <QMessageBox>

const QString kHellowWindowTitle = "Крестики-Нолики";


SecondWindowPersonComputer::SecondWindowPersonComputer(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindowPersonComputer)
{
    ui->setupUi(this);
    setWindowTitle(kHellowWindowTitle);
    _namePlayer2 = "Компьютер";
    _level1 = DifficultyLevel::easyLevel;
    connect(ui->pushButton, &QPushButton::clicked, this, &SecondWindowPersonComputer::onPushButtonStartClicked);
    connect (ui->radioButton0_1, &QRadioButton::clicked, this,  &SecondWindowPersonComputer::onRadioButton0);
    connect (ui->radioButtonX_1, &QRadioButton::clicked, this,  &SecondWindowPersonComputer::onRadioButtonX);
    connect (ui->radioButtonEasy, &QRadioButton::clicked, this,  &SecondWindowPersonComputer::onRadioButtonLevel);
}

SecondWindowPersonComputer::~SecondWindowPersonComputer()
{
    delete ui;
}

QString SecondWindowPersonComputer::getPlayer1Name()
{
    return ui->lineEditName1->text();
}

void SecondWindowPersonComputer::onSetPlayer2Sign(QString signPlayer1)
{
    if(signPlayer1=="X")
        _signPlayer2 = "0";
    else
        _signPlayer2 = "X";
}

void SecondWindowPersonComputer::onPushButtonStartClicked()
{
    if(ui->radioButton0_1->isChecked()==false && ui->radioButtonX_1->isChecked()==false)
    {
        QMessageBox errorMessage;
        errorMessage.setText("Пожалуйста, сделайте выбор символа");
        errorMessage.exec();
    }
    if(ui->lineEditName1->text().isEmpty())
    {
        QMessageBox errorMessage;
        errorMessage.setText("Пожалуйста, введите имя игроков");
        errorMessage.exec();
    }
    if(ui->radioButtonEasy->isChecked() == false)
    {
        QMessageBox errorMessage;
        errorMessage.setText("Пожалуйста, выберите сложность");
        errorMessage.exec();
    }
    if(ui->radioButton0_1->isChecked()==true && !ui->lineEditName1->text().isEmpty() && ui->radioButtonEasy->isChecked() == true)
    {
        emit sendSigns(ui->radioButton0_1->text(),_signPlayer2);
        emit sendLevels(_level1, _level2);
        emit sendPlayersName(ui->lineEditName1->text(), _namePlayer2);
        emit nextWindow();
        close();
    }
    if(ui->radioButtonX_1->isChecked()==true && !ui->lineEditName1->text().isEmpty() && ui->radioButtonEasy->isChecked() == true)
    {
        emit sendSigns(ui->radioButtonX_1->text(),_signPlayer2);
        emit sendPlayersName(ui->lineEditName1->text(), _namePlayer2);
        emit nextWindow();
        close();
    }
}

void SecondWindowPersonComputer::onRadioButton0()
{
    onSetPlayer2Sign(ui->radioButton0_1->text());
}

void SecondWindowPersonComputer::onRadioButtonX()
{
    onSetPlayer2Sign(ui->radioButtonX_1->text());
}

void SecondWindowPersonComputer::onRadioButtonLevel()
{
    _level2 = DifficultyLevel::easyLevel;
}
