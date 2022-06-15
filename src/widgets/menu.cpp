#include "menu.h"

Menu::Menu(QWidget *parent)
    : QFrame{parent}
{
    this->setStyleSheet("border-right: 1px solid #222;");
    this->setMaximumWidth(400);
    menuLayout = new QVBoxLayout(this);

    profileButton = new MenuButton();
    profileButton->setText("Profile");

    catalogButton = new MenuButton();
    catalogButton->setText("Catalog");

    cartButton = new MenuButton();
    cartButton->setText("Cart");

    exitButton = new MenuButton();
    exitButton->setText("Exit");

    spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    menuLayout->addWidget(profileButton);
    menuLayout->addWidget(catalogButton);
    menuLayout->addWidget(cartButton);
    menuLayout->addWidget(exitButton);
    menuLayout->addItem(spacer);

    menuLayout->setContentsMargins(0, 0, 0, 0);
    menuLayout->setSpacing(0);

    connect(profileButton, &MenuButton::clicked, this, [this](){
        emit this->onProfileButtonClicked();
    });
    connect(exitButton, &MenuButton::clicked, this, [this](){
        emit this->onExitButtonClicked();
    });
}
