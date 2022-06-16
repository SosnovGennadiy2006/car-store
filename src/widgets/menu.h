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
    MenuButton* catalogButton;
    MenuButton* cartButton;
    MenuButton* exitButton;

    QSpacerItem* spacer;

public:
    explicit Menu(QWidget *parent = nullptr);

signals:
    void onProfileButtonClicked();
    void onCartButtonClicked();
    void onCatalogButtonClicked();
    void onExitButtonClicked();
};

#endif // MENU_H
