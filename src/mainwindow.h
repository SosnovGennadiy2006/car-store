#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QDir>
#include <QRegExp>
#include <widgets/welcomewidget.h>
#include <widgets/mainwidget.h>
#include <logics/user.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    WelcomeWidget* welcomeWidget;
    MainWidget* mainWidget;

    QString usersDatabasePath;

    User* registeredUser = new User(UserTypes::client);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init_UI();
    void alert(QString message);
    void info(QString message);

    void redirectToMainWidget();

public slots:
    void signIn();
    void signUp();
    void exit();
};
#endif // MAINWINDOW_H
