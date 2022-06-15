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

    shoppingCart = new CartWidget();
    shoppingCart->setUser(registeredUser);

    cartScroll = new QScrollArea(this);
    cartScroll->setStyleSheet("QScrollArea {"
                                 "  border: none;"
                                 "}");
    cartScroll->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    cartScroll->setWidget(shoppingCart);
    cartScroll->setWidgetResizable(true);

    mainLayout->addWidget(widgetMenu);
    mainLayout->addWidget(profileScroll);
    mainLayout->addWidget(cartScroll);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    cartScroll->hide();

    connect(widgetMenu, &Menu::onExitButtonClicked, this, [this](){
        emit this->onExitButtonClicked();
    });
    connect(widgetMenu, &Menu::onProfileButtonClicked, this, &MainWidget::redirectToProfile);
    connect(widgetMenu, &Menu::onCartButtonClicked, this, &MainWidget::redirectToCart);
    connect(profile, &ProfileWidget::userCorrected, this, [this](User* correctedUser){
        emit onUserCorrected(correctedUser);
    });
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

bool MainWidget::isProfileChanged()
{
    return profile->isChanged();
}

void MainWidget::redirectToProfile()
{
    profileScroll->show();
    cartScroll->hide();
}

void MainWidget::redirectToCart()
{
    profileScroll->hide();
    cartScroll->show();
}

void MainWidget::saveProfileChanges()
{
    profile->saveUser();
}
