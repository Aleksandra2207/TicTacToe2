#include "mainwindow.h"
#include "playmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Playmanager playManager;
    playManager.prepare();
    return a.exec();
}
