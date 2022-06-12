#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <widgets/buttons/menubutton.h>

class Menu : public QFrame
{
    Q_OBJECT

    QVBoxLayout* menuLayout;

    MenuButton* profileButton;
    MenuButton* exitButton;

    QSpacerItem* spacer;

public:
    explicit Menu(QWidget *parent = nullptr);

signals:
    void onProfileButtonClicked();
    void onExitButtonClicked();
};

#endif // MENU_H
