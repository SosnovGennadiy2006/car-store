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

    hLine2 = new QFrame(this);
    hLine2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLine2->setFixedHeight(2);
    hLine2->setFrameShape(QFrame::HLine);
    hLine2->setFrameShadow(QFrame::Sunken);

    goToCatalogWidget = new QWidget(this);
    goToCatalogLayout = new QHBoxLayout(goToCatalogWidget);
    goToCatalogLabel = new QLabel(goToCatalogWidget);
    goToCatalogLabel->setText("You can add order in catalog:");
    goToCatalogButton = new QPushButton(goToCatalogWidget);
    goToCatalogButton->setText("Go to Catalog");
    goToCatalogButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    goToCatalogButton->setStyleSheet("border: 1px solid #222; padding: 5px 10px;");
    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    goToCatalogLayout->addWidget(goToCatalogLabel);
    goToCatalogLayout->addWidget(goToCatalogButton);
    goToCatalogLayout->addItem(spacer);
    goToCatalogLayout->setContentsMargins(0, 0, 0, 0);

    mainLayout->addWidget(welcomeLabel);
    mainLayout->addWidget(hLine1);
    mainLayout->addWidget(aboutLabel);
    mainLayout->addWidget(hLine2);
    mainLayout->addWidget(goToCatalogWidget);

    connect(goToCatalogButton, &QPushButton::clicked, this, [this](){
        emit onRedirectionButtonClicked();
    });
}

User* CartWidget::getUser() const
{
    return registeredUser;
}

void CartWidget::setUser(User* newUser)
{
    registeredUser = newUser;
}
