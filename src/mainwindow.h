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

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QWidget* centralWidget;
    WelcomeWidget* welcomeWidget;
    QVBoxLayout* mainLayout;

    QSpacerItem* firstSpacer;
    QSpacerItem* secondSpacer;

    QString usersDatabasePath;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init_UI();
    void alert(QString message);
    void info(QString message);

public slots:
    void signIn();
    void signUp();
};
#endif // MAINWINDOW_H
