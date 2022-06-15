#include "cartwidget.h"

CartWidget::CartWidget(QWidget *parent) : QFrame{parent}
{
    QFont biggerFont;
    biggerFont.setPixelSize(32);

    QFont bigFont;
    bigFont.setPixelSize(24);

    QFont normalFont;
    normalFont.setPixelSize(16);

    this->setFont(normalFont);

    registeredUser = new User(UserTypes::client);

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    mainLayout = new QVBoxLayout(this);

    welcomeLabel = new QLabel(this);
    welcomeLabel->setText("Shopping Cart");
    welcomeLabel->setFont(biggerFont);

    aboutLabel = new QLabel(this);
    aboutLabel->setText("There is all your orders:");
    aboutLabel->setFont(bigFont);

    hLine1 = new QFrame(this);
    hLine1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLine1->setFixedHeight(2);
    hLine1->setFrameShape(QFrame::HLine);
    hLine1->setFrameShadow(QFrame::Sunken);

    mainLayout->addWidget(welcomeLabel);
    mainLayout->addWidget(hLine1);
    mainLayout->addWidget(aboutLabel);
}

User* CartWidget::getUser() const
{
    return registeredUser;
}

void CartWidget::setUser(User* newUser)
{
    registeredUser = newUser;
}
