#include "gamemode.h"

const QString kPlayer1Win = "Игрок 1 победил";
const QString kPlayer2Win = "Игрок 2 победил";
const QString kDraw = "Ничья";
const QString kPlayer1 = "player1";
const QString kPlayer2 = "player2";
const int countCell = 9;

GameMode::GameMode()
{
}
void GameMode::onPassMoveToPlayer2()
{
    game->onPassPlayer2Move(_isPlayer2IsComputer);
}

void GameMode::onPassMoveToPlayer1()
{
    game->onPassPlayer1Move(_isPlayer1IsComputer);
}

void GameMode::connections()
{
    connect(game, &MainWindow::doCheck, this, &GameMode::onCheckForFinish);
    connect(this, &GameMode::player1MoveIsComplited, this, &GameMode::onPassMoveToPlayer2);
    connect (this, &GameMode::player2MoveIsComplited, this, &GameMode::onPassMoveToPlayer1);
    connect (this, &GameMode::finish, this, &GameMode::onFinish);
    connect(winnerWindow, &WinnerWindow::newNewGame, this, &GameMode::onNewGame);
    connect(game, &MainWindow::newGame, this, &GameMode::onNewGame);
}

void GameMode::onFinish(QString winner)
{
    if(winner == _player1Sign)
    {
        winnerWindow->setLabelwinner(kPlayer1Win);
        game->increaseCounterPlayer1();
    }
    if(winner == _player2Sign)
    {
        winnerWindow->setLabelwinner(kPlayer2Win);
         game->increaseCounterPlayer2();
    }
    if(winner == "draw")
        winnerWindow->setLabelwinner(kDraw);
    winnerWindow->show();
}

void GameMode::onNewGame()
{
    winnerWindow->close();
    game->cleanField();
    onStart();
}

void GameMode::onCheckForFinish(QStringList cells,QString player)
{
    _countNoEmptyCell++;
   if (checkForFinish("0", cells) || checkForFinish("X", cells))
        return;
   if(player==kPlayer1)
       emit player1MoveIsComplited();
   if(player==kPlayer2)
       emit player2MoveIsComplited();
}

bool GameMode::checkForFinish(QString value, QStringList field)
{
    int ch=0;
    for (int i=0; i<=6;)
    {
        int j=i+1, k=i+2;
        if(field.at(i) == value && field.at(j)== value && field.at(k) == value)
        {
            ch++;
            emit finish(value);
            return true;
        }
        i+=3;
    }
    for (int i=0; i<=2; i++)
    {
        int j=i+3, k=i+6;
        if(field.at(i) == value && field.at(j)== value && field.at(k) == value)
        {
            ch++;
            emit finish(value);
            return true;
        }
    }
    if(field.at(0) == value && field.at(4)== value && field.at(8) == value)
    {
        ch++;
        emit finish(value);
        return true;
    }
    if(field.at(2) == value && field.at(4)== value && field.at(6) == value)
    {
        ch++;
        emit finish(value);
        return true;
    }
    if(ch==0 && _countNoEmptyCell == countCell)
    {
        _ch--;
    }
    if(_ch==0 && _countNoEmptyCell == countCell)
    {
        emit finish ("draw");
        return true;
    }
        return false;
}
