QT += core gui
QT += core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logics/user.cpp \
    main.cpp \
    mainwindow.cpp \
    widgets/buttons/customcheckbox.cpp \
    widgets/buttons/menubutton.cpp \
    widgets/mainwidget.cpp \
    widgets/menu.cpp \
    widgets/menuWidgets/profilewidget.cpp \
    widgets/signinform.cpp \
    widgets/signupform.cpp \
    widgets/welcomewidget.cpp

HEADERS += \
    logics/user.h \
    mainwindow.h \
    widgets/buttons/customcheckbox.h \
    widgets/buttons/menubutton.h \
    widgets/mainwidget.h \
    widgets/menu.h \
    widgets/menuWidgets/profilewidget.h \
    widgets/signinform.h \
    widgets/signupform.h \
    widgets/welcomewidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    json/users.json
