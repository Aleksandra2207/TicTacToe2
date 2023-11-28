#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRandomGenerator>

const QString kPlayer1 = "player1";
const QString kPlayer2 = "player2";
const QString kMainWindowTitle = "Крестики-Нолики";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(kMainWindowTitle);
    _pCells.append(ui->pushButton_1);
    _pCells.append(ui->pushButton_2);
    _pCells.append(ui->pushButton_3);
    _pCells.append(ui->pushButton_4);
    _pCells.append(ui->pushButton_5);
    _pCells.append(ui->pushButton_6);
    _pCells.append(ui->pushButton_7);
    _pCells.append(ui->pushButton_8);
    _pCells.append(ui->pushButton_9);
    connections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connections()
{
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButtonResetPlay, &QPushButton::clicked, this, &MainWindow::onClickedReset);

}

void MainWindow::onPassPlayer2Move(bool isComputer)
{
    if(isComputer==true)
        onblokField(false);
    else
        onblokField(true);
    QPalette palette;
    palette.setColor(QPalette::Background,Qt::gray);
    ui->labelPlayer1->setPalette(palette);
    palette.setColor(QPalette::Background,Qt::yellow);
    ui->labelPlayer2->setPalette(palette);
    _sign = _signPlayer2;
    _player = kPlayer2;
}

void MainWindow::onPassPlayer1Move(bool isComputer)
{
    if(isComputer==true)
        onblokField(false);
    else
        onblokField(true);
    QPalette palette;
    palette.setColor(QPalette::Background,Qt::yellow);
    ui->labelPlayer1->setPalette(palette);
    palette.setColor(QPalette::Background,Qt::gray);
    ui->labelPlayer2->setPalette(palette);
    _sign = _signPlayer1;
    _player = kPlayer1;
}

void MainWindow::onPushButtonCliked()
{
    QObject* button = QObject::sender();
    bool isOk = false;
    qDebug()<< "We are from MainWindow::onPushButtonCliked";
     if(button == ui->pushButton_1 && ui->pushButton_1->text().isEmpty())
     {
         ui->pushButton_1->setText(_sign);
         isOk = true;
     }
     if(button == ui->pushButton_2 && ui->pushButton_2->text().isEmpty())
     {
         ui->pushButton_2->setText(_sign);
          isOk = true;
     }
     if(button == ui->pushButton_3 && ui->pushButton_3->text().isEmpty())
     {
         ui->pushButton_3->setText(_sign);
          isOk = true;
     }
     if(button == ui->pushButton_4 && ui->pushButton_4->text().isEmpty())
     {
          ui->pushButton_4->setText(_sign);
         isOk = true;
     }
     if(button == ui->pushButton_5 && ui->pushButton_5->text().isEmpty())
     {
         ui->pushButton_5->setText(_sign);
         isOk = true;
     }
     if(button == ui->pushButton_6 && ui->pushButton_6->text().isEmpty())
     {
         ui->pushButton_6->setText(_sign);
         isOk = true;
     }
     if(button == ui->pushButton_7 && ui->pushButton_7->text().isEmpty())
     {
         ui->pushButton_7->setText(_sign);
         isOk = true;
     }
     if(button == ui->pushButton_8 && ui->pushButton_8->text().isEmpty())
     {
         ui->pushButton_8->setText(_sign);
         isOk = true;
     }
     if(button == ui->pushButton_9 && ui->pushButton_9->text().isEmpty())
     {
         ui->pushButton_9->setText(_sign);
         isOk = true;
     }
     if(isOk==true)
         emit doCheck(getField(), _player);
}

void MainWindow::onSetSingPlayers(QString sign1, QString sign2)
{
    _signPlayer1 = sign1;
    _signPlayer2 = sign2;
}

void MainWindow::onMakeComputerMove(int i, QString sign)
{
    _pCells.at(i)->setText(sign);
    emit doCheck(getField(), _player);
}

void MainWindow::setPlayersName(QString name1, QString name2)
{
    ui->labelPlayerName1->setText(name1);
    ui->labelPlayer2->setText(name2);
}

void MainWindow::increaseCounterPlayer1()
{
    int ch = ui->spinBoxPlayer1->value()+1;
    ui->spinBoxPlayer1->setValue(ch);
}

void MainWindow::increaseCounterPlayer2()
{
    int ch = ui->spinBoxPlayer2->value()+1;
    ui->spinBoxPlayer2->setValue(ch);
}

void MainWindow::cleanField()
{
    foreach(QPushButton* cell, _pCells)
    {
        cell->setText("");
    }
}

QStringList MainWindow::getField()
{
    QStringList field;
    foreach(QPushButton* cell, _pCells)
    {
        field.append(cell->text());
    }
    return field;
}

void MainWindow::onblokField(bool isUnblok)
{
    foreach (QPushButton* cell, _pCells)
    {
        cell->setEnabled(isUnblok);
    }
}


void MainWindow::onClickedReset()
{
    emit newGame();
}
