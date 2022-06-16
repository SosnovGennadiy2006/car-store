#include "catalogwidget.h"

CatalogWidget::CatalogWidget(QWidget *parent)
    : QWidget{parent}
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
    welcomeLabel->setText("Catalog");
    welcomeLabel->setFont(biggerFont);

    aboutLabel = new QLabel(this);
    aboutLabel->setText("Welcome to the catalog! There is all store products:");
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

User* CatalogWidget::getUser() const
{
    return registeredUser;
}

void CatalogWidget::setUser(User* newUser)
{
    registeredUser = newUser;
}
