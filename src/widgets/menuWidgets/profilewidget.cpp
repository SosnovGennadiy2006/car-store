#include "profilewidget.h"

ProfileWidget::ProfileWidget(QWidget *parent) : QFrame{parent}
{
    registeredUser = new User(UserTypes::client);

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    mainLayout = new QVBoxLayout(this);

    welcomeLabel = new QLabel(this);
    welcomeLabel->setText("Welcome, " + registeredUser->getName());

    aboutLabel = new QLabel(this);
    aboutLabel->setText("There is all the information about you:");

    hLine1 = new QFrame(this);
    hLine1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLine1->setFixedHeight(2);
    hLine1->setFrameShape(QFrame::HLine);
    hLine1->setFrameShadow(QFrame::Sunken);

    mainLayout->addWidget(welcomeLabel);
    mainLayout->addWidget(hLine1);
    mainLayout->addWidget(aboutLabel);
}

User* ProfileWidget::getUser() const
{
    return registeredUser;
}

void ProfileWidget::setUser(User* newUser)
{
    registeredUser = newUser;
    welcomeLabel->setText("Welcome, " + registeredUser->getName());
}
