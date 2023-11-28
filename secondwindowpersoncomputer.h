#ifndef SECONDWINDOWPERSONCOMPUTER_H
#define SECONDWINDOWPERSONCOMPUTER_H

#include <QDialog>
#include "defins.h"

namespace Ui {
class SecondWindowPersonComputer;
}

class SecondWindowPersonComputer : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindowPersonComputer(QDialog *parent = nullptr);
    ~SecondWindowPersonComputer();
    QString getPlayer1Name();

public slots:
    void onSetPlayer2Sign(QString signPlayer1);
    void onPushButtonStartClicked();
    void onRadioButton0();
    void onRadioButtonX();
    void onRadioButtonLevel();

signals:
    void sendLevels(DifficultyLevel level1, DifficultyLevel level2);
    void sendSigns(QString sign1, QString sign2);
    void sendPlayersName(QString name1, QString name2);
    void nextWindow();

private:
    Ui::SecondWindowPersonComputer *ui;
    QString _signPlayer2;
    QString _namePlayer2;
    DifficultyLevel _level1;
    DifficultyLevel _level2;
};

#endif // SECONDWINDOWPERSONCOMPUTER_H
