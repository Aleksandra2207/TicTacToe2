QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    computer.cpp \
    factorylevel.cpp \
    gamemode.cpp \
    ieasystrategycomputer.cpp \
    istrategycomputer.cpp \
    main.cpp \
    mainwindow.cpp \
    modefactory.cpp \
    modeplayerwithcomputer.cpp \
    modetwocomputers.cpp \
    modetwoplayers.cpp \
    person.cpp \
    players.cpp \
    playersfactory.cpp \
    playmanager.cpp \
    secondwindowpersoncomputer.cpp \
    secondwindowtwoperson.cpp \
    welcomewindow.cpp \
    winnerwindow.cpp

HEADERS += \
    computer.h \
    defins.h \
    factorylevel.h \
    gamemode.h \
    ieasystrategycomputer.h \
    istrategycomputer.h \
    mainwindow.h \
    modefactory.h \
    modeplayerwithcomputer.h \
    modetwocomputers.h \
    modetwoplayers.h \
    person.h \
    players.h \
    playersfactory.h \
    playmanager.h \
    secondwindowpersoncomputer.h \
    secondwindowtwoperson.h \
    welcomewindow.h \
    winnerwindow.h

FORMS += \
    mainwindow.ui \
    secondwindowpersoncomputer.ui \
    secondwindowtwoperson.ui \
    welcomewindow.ui \
    winnerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
