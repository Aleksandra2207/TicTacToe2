#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setPlayersName(QString name1, QString name2);
    void increaseCounterPlayer1();
    void increaseCounterPlayer2();
    void cleanField();
    QStringList getField();


public slots:
    void onPassPlayer2Move(bool isComputer);
    void onPassPlayer1Move(bool isComputer);
    void onPushButtonCliked();
    void onSetSingPlayers(QString sign1, QString sign2);
    void onMakeComputerMove (int i, QString sign);
    void onblokField(bool isUnblok);
    void onClickedReset();

signals:
    void doCheck(QStringList field, QString player);
    void newGame();


private:
    Ui::MainWindow *ui;
    QList <QPushButton*> _pCells;
    QString _signPlayer1;
    QString _signPlayer2;
    QString _sign;
    QString _player;
    void connections();

};
#endif // MAINWINDOW_H
