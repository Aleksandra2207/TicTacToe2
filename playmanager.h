#ifndef PLAYMANAGER_H
#define PLAYMANAGER_H

#include <QObject>
#include <QWidget>
#include "welcomewindow.h"
#include "gamemode.h"
#include "defins.h"
#include "modefactory.h"


class Playmanager: public QObject
{
    Q_OBJECT

public:
    Playmanager();
    void prepare();
    void run();
    void createMode();
    void connections();

signals:
    void doRun();

private slots:
    void onsetMode(Modes mode);
    void onSetNames (QString name1, QString name2);
    void onsetSigns(QString sign1, QString sign2);
    //void onsetLevel1(DifficultyLevel level1);
    //void onsetLevel2(DifficultyLevel level2);
    void onsetLevel(DifficultyLevel level1, DifficultyLevel level2);
    void onShowSecondWindow(QString typeWindow);
    //void onShowThirdWindowOrStartGame();


private:
    WelcomeWindow* welcomewindow;
    GameMode* _pGameMode;
    ModeFactory _modeFactory;
    Modes _mode;
    DifficultyLevel _level1;
    DifficultyLevel _level2;
    QString _name1;
    QString _sign1;
    QString _name2;
    QString _sign2;
    bool isNeedDifficultyLevel;





};
//public:
//    Playmanager();
//    void run();
//    void onStart(QString playerSign);
//    void connections();
//    bool checkForFinish(QString value, QStringList field);
//    void onPassMoveToComputer();
//    void onPassMoveToPerson();

//public slots:
//    void onFinish(QString winner);
//    void onNewGame();
//    void onCheckForFinish(QStringList cells, QString player);

//signals:
//    void computerMove();
//    void personMove();
//    void finish(QString winner);
//    void personMoveIsComplited();
//    void computerMoveIsComplited();


//private:
//   MainWindow* game;
//   HellowWindow* hellowWindow;
//   WinnerWindow* winnerWindow;
//   WelcomeWindow* welcomewindow;
//   Computer* computer;
//   int _ch=2;
//   int _countNoEmptyCell=0;
//   QString _personSign;
//   QString _computerSign;

//   void delay();
//};

#endif // PLAYMANAGER_H
