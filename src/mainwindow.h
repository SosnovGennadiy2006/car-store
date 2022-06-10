#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <widgets/welcomewidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QWidget* centralWidget;
    WelcomeWidget* welcomeWidget;
    QVBoxLayout* mainLayout;

    QSpacerItem* firstSpacer;
    QSpacerItem* secondSpacer;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init_UI();
};
#endif // MAINWINDOW_H
