TEMPLATE = app
TARGET = Contagion

QT = core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    mainwindow.cpp \
    #city.cpp \
    #contPlanner.cpp \
    #Dispatcher.cpp \
    #hero.cpp \
    #icard.cpp \
    #Medic.cpp \
    #OpExpert.cpp \
    #pcard.cpp \
    #QSpecialist.cpp \
    #Researcher.cpp \
    #Scientist.cpp \
    #test.cpp \
    #world.cpp


HEADERS += \
    window.h \
    mainwindow.h \
    transpbutton.h \
    #city.h \
    #contPlanner.h \
    #Dispatcher.h \
    #hero.h \
    #icard.h \
    #Medic.h \
    #OpExpert.h \
    #pcard.h \
    #QSpecialist.h \
    #Researcher.h \
    #Scientist.h \
    #world.h
