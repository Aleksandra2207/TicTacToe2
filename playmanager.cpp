#include "playmanager.h"
#include "secondwindowtwoperson.h"
#include "secondwindowpersoncomputer.h"
#include <QTime>
#include <QCoreApplication>

const QString kPersonWin = "Поздравляем! Вы победили";
const QString kComputerWin = "Увы, вы проиграли";
const QString kDraw = "Ничья";
const QString kX = "X";
const QString k0 = "0";
const QString kPlayer1 = "person";
const QString kComputer = "computer";

const QString k2P="k2P";
const QString kPC="kPC";
const QString k2C="k2C";

Playmanager::Playmanager()
{
    welcomewindow = new WelcomeWindow();
    _pGameMode = nullptr;
    _level1=DifficultyLevel::easyLevel;
    _level2=DifficultyLevel::easyLevel;
    _name1="name1";
    _name2="name2";
    connections();
}

void Playmanager::prepare()
{
    welcomewindow->show();
}

void Playmanager::run()
{
    createMode();
    _pGameMode->onStart();
}

void Playmanager::createMode()
{
    _pGameMode = _modeFactory.createMode(_mode, _sign1, _sign2, _name1, _name2, _level1, _level2);
}

void Playmanager::connections()
{
    connect(welcomewindow, &WelcomeWindow::sendMode, this, &Playmanager::onsetMode);
    connect (welcomewindow, &WelcomeWindow::nextWindow, this, &Playmanager::onShowSecondWindow);
    connect(this, &Playmanager::doRun, this, &Playmanager::run);
}

void Playmanager::onsetMode(Modes mode)
{
    _mode = mode;
}

void Playmanager::onSetNames(QString name1, QString name2)
{
    _name1=name1;
    _name2=name2;
}

void Playmanager::onsetSigns(QString sign1, QString sign2)
{
    _sign1=sign1;
    _sign2=sign2;
}

void Playmanager::onsetLevel(DifficultyLevel level1, DifficultyLevel level2)
{
    _level1 = level1;
    _level2=level2;
}

void Playmanager::onShowSecondWindow(QString typeWindow)
{
    if(typeWindow == k2P)
    {
        SecondWindowTwoPerson* secondWindow = new SecondWindowTwoPerson();
        connect (secondWindow, &SecondWindowTwoPerson::sendPlayersName, this, &Playmanager::onSetNames);
        connect (secondWindow, &SecondWindowTwoPerson::sendSigns, this, &Playmanager::onsetSigns);
        connect(secondWindow, &SecondWindowTwoPerson::nextWindow, this, &Playmanager::run);
        secondWindow->show();
    }
    if(typeWindow == kPC)
    {
       SecondWindowPersonComputer* secondWindowPersonComputer = new SecondWindowPersonComputer();
        connect (secondWindowPersonComputer, &SecondWindowPersonComputer::sendLevels, this, &Playmanager::onsetLevel);
       connect (secondWindowPersonComputer, &SecondWindowPersonComputer::sendPlayersName, this, &Playmanager::onSetNames);
       connect (secondWindowPersonComputer, &SecondWindowPersonComputer::sendSigns, this, &Playmanager::onsetSigns);
       connect(secondWindowPersonComputer, &SecondWindowPersonComputer::nextWindow, this, &Playmanager::run);
       secondWindowPersonComputer->show();

    }
    if(typeWindow == k2C)
    {
        _level1=DifficultyLevel::easyLevel;
        _level2=DifficultyLevel::easyLevel;
        _name1 = "Компьютер 1";
        _sign1="X";
        _name2="Компьютер 2";
        _sign2="0";
        run();
    }
}

//void Playmanager::onsetLevel1(DifficultyLevel level1)
//{
//    _level1=level1;
//}

//void Playmanager::onsetLevel2(DifficultyLevel level2)
//{
//    _level2=level2;
//}
//void Playmanager::onShowThirdWindowOrStartGame()
//{
//   chooseHard->show();
//}

//void Playmanager::onStart(QString playerSign)
//{
//    _personSign = playerSign; //получили символ, за который будет играть человек
//    game->setPlayerName(hellowWindow->getPlayerName());
//    game->show();
//    _countNoEmptyCell = 0;
//    _ch=2;
//    //если человек выбрал X, то он ходит первым
//    if(playerSign=="X")
//    {
//        game->onSetSingPlayer1(playerSign);
//        _computerSign = k0;
//        computer->setSign(k0);
//        game->onPassPersonMove();
//    }
//    if(playerSign=="0")
//    {
//        game->onSetSingPlayer1(playerSign);
//        _computerSign = kX;
//        computer->setSign(kX);
//        game->onPassComputerMove();
//        computer->makeMove(game->getField());

//    }
//}

//void Playmanager::connections()
//{
//    connect(hellowWindow, &HellowWindow::startGame, this, &Playmanager::onStart);
//    connect(game, &MainWindow::doCheck, this, &Playmanager::onCheckForFinish);

//    connect(this, &Playmanager::personMoveIsComplited, this, &Playmanager::onPassMoveToComputer);
//    connect (this, &Playmanager::computerMoveIsComplited, this, &Playmanager::onPassMoveToPerson);
//    connect (computer, &Computer::finishMove, game, &MainWindow::onMakeComputerMove);
//    connect (this, &Playmanager::finish, this, &Playmanager::onFinish);
//    connect(winnerWindow, &WinnerWindow::newNewGame, this, &Playmanager::onNewGame);
//    connect(game, &MainWindow::newGame, this, &Playmanager::onNewGame);
//}

//void Playmanager::onPassMoveToComputer()
//{
//    game->onPassComputerMove();
//    delay();
//    computer->makeMove(game->getField());
//}

//void Playmanager::onPassMoveToPerson()
//{
//    game->onPassPersonMove();
//}

//void Playmanager::onFinish(QString winner)
//{
//    if(winner == _computerSign)
//    {
//        winnerWindow->setLabelwinner(kComputerWin);
//        game->increaseCounterComputer();
//    }
//    if(winner == _personSign)
//    {
//        winnerWindow->setLabelwinner(kPersonWin);
//         game->increaseCounterPerson();
//    }
//    if(winner == "draw")
//        winnerWindow->setLabelwinner(kDraw);
//    winnerWindow->show();
//}

//void Playmanager::onNewGame()
//{
//    game->cleanField();
//    onStart(_personSign);
//}

//void Playmanager::onCheckForFinish(QStringList cells,QString player)
//{
//    _countNoEmptyCell++;
//   if (checkForFinish("0", cells) || checkForFinish("X", cells))
//        return;
//   if(player==kPlayer1)
//       emit personMoveIsComplited();
//   if(player==kComputer)
//       emit computerMoveIsComplited();
//}

//bool Playmanager::checkForFinish(QString value, QStringList field)
//{
//    int ch=0;
//    for (int i=0; i<=6;)
//    {
//        int j=i+1, k=i+2;
//        if(field.at(i) == value && field.at(j)== value && field.at(k) == value)
//        {
//            ch++;
//            emit finish(value);
//            return true;
//        }
//        i+=3;
//    }
//    for (int i=0; i<=2; i++)
//    {
//        int j=i+3, k=i+6;
//        if(field.at(i) == value && field.at(j)== value && field.at(k) == value)
//        {
//            ch++;
//            emit finish(value);
//            return true;
//        }
//    }
//    if(field.at(0) == value && field.at(4)== value && field.at(8) == value)
//    {
//        ch++;
//        emit finish(value);
//        return true;
//    }
//    if(field.at(2) == value && field.at(4)== value && field.at(6) == value)
//    {
//        ch++;
//        emit finish(value);
//        return true;
//    }
//    if(ch==0 && _countNoEmptyCell == countCell)
//    {
//        _ch--;
//    }
//    if(_ch==0 && _countNoEmptyCell == countCell)
//    {
//        emit finish ("draw");
//        return true;
//    }
//        return false;
//}

//void Playmanager::delay()
//{
//    QTime dieTime= QTime::currentTime().addSecs(1);
//    while (QTime::currentTime() < dieTime)
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 2000);
//}
