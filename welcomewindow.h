#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>
#include "QDialog"
#include "defins.h"

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QDialog *parent = nullptr);
    ~WelcomeWindow();

public slots:
    void onPushButtonContinueClicked ();

signals:
    void nextWindow(QString gameMode);
    void sendMode(Modes id);

private:
    Ui::WelcomeWindow *ui;
};

#endif // WELCOMEWINDOW_H
