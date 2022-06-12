#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background: #f0f0f0;");

    mainLayout = new QHBoxLayout(this);

    widgetMenu = new Menu(this);
    widgetMenu->setMinimumWidth(400);
    widgetMenu->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    profile = new ProfileWidget();
    profile->setUser(registeredUser);

    profileScroll = new QScrollArea(this);
    profileScroll->setStyleSheet("QScrollArea {"
                                 "  border: none;"
                                 "}");
    profileScroll->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    profileScroll->setWidget(profile);
    profileScroll->setWidgetResizable(true);

    mainLayout->addWidget(widgetMenu);
    mainLayout->addWidget(profileScroll);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    connect(widgetMenu, &Menu::onExitButtonClicked, this, [this](){
        emit this->onExitButtonClicked();
    });
    connect(widgetMenu, &Menu::onProfileButtonClicked, this, &MainWidget::redirectToProfile);
}

User* MainWidget::getUser() const
{
    return registeredUser;
}

void MainWidget::setUser(User* newUser)
{
    registeredUser = newUser;
    profile->setUser(registeredUser);
}

void MainWidget::redirectToProfile()
{
    qDebug() << "!!!\n";
}
