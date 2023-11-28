#ifndef SECONDWINDOWTWOPERSON_H
#define SECONDWINDOWTWOPERSON_H

#include <QDialog>

namespace Ui {
class SecondWindowTwoPerson;
}

class SecondWindowTwoPerson : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindowTwoPerson(QDialog *parent = nullptr);
    ~SecondWindowTwoPerson();
    QString getPlayer1Name();
    QString getPlayer2Name();

public slots:
    void onPushButtonStartClicked();

signals:
    void sendSigns(QString sign1, QString sign2);
    void sendPlayersName(QString name1, QString name2);
    void nextWindow();


private:
    Ui::SecondWindowTwoPerson *ui;
};

#endif // SECONDWINDOWTWOPERSON_H
