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

    catalog = new CatalogWidget();
    catalog->setUser(registeredUser);

    catalogScroll = new QScrollArea(this);
    catalogScroll->setStyleSheet("QScrollArea {"
                                 "  border: none;"
                                 "}");
    catalogScroll->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    catalogScroll->setWidget(catalog);
    catalogScroll->setWidgetResizable(true);

    mainLayout->addWidget(widgetMenu);
    mainLayout->addWidget(profileScroll);
    mainLayout->addWidget(catalogScroll);
    mainLayout->addWidget(cartScroll);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    cartScroll->hide();
    catalogScroll->hide();

    connect(widgetMenu, &Menu::onExitButtonClicked, this, [this](){
        emit this->onExitButtonClicked();
    });
    connect(widgetMenu, &Menu::onProfileButtonClicked, this, &MainWidget::redirectToProfile);
    connect(widgetMenu, &Menu::onCartButtonClicked, this, &MainWidget::redirectToCart);
    connect(widgetMenu, &Menu::onCatalogButtonClicked, this, &MainWidget::redirectToCatalog);
    connect(shoppingCart, &CartWidget::onRedirectionButtonClicked, this, &MainWidget::redirectToCatalog);
    connect(profile, &ProfileWidget::userCorrected, this, [this](User* correctedUser){
        emit onUserCorrected(correctedUser);
    });
    connect(shoppingCart, &CartWidget::onProductSaved, this, [this](Product p){
        emit onProductSaved(p);
    });
    connect(catalog, &CatalogWidget::productBuyed, this, &MainWidget::onNewOrder);

}

User* MainWidget::getUser() const
{
    return registeredUser;
}

void MainWidget::setUser(User* newUser)
{
    registeredUser = newUser;
    profile->setUser(registeredUser);
    shoppingCart->setUser(registeredUser);
}

bool MainWidget::isProfileChanged()
{
    return profile->isChanged();
}

void MainWidget::redirectToProfile()
{
    profileScroll->show();
    cartScroll->hide();
    catalogScroll->hide();
}

void MainWidget::redirectToCart()
{
    profileScroll->hide();
    cartScroll->show();
    catalogScroll->hide();
}

void MainWidget::redirectToCatalog()
{
    profileScroll->hide();
    cartScroll->hide();
    catalogScroll->show();
}

void MainWidget::saveProfileChanges()
{
    profile->saveUser();
}

void MainWidget::onNewOrder(Product orderProduct)
{
    Order newOrder;
    newOrder.setProduct(orderProduct);
    newOrder.setCustomerID(registeredUser->getId());
    newOrder.setOrderPlacedDate(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss"));

    emit onOrderSaved(newOrder);
}

void MainWidget::addOrderToOrders(Order newOrder)
{
    shoppingCart->addOrderToOrders(newOrder);
}

void MainWidget::addProductToProducts(Product newProduct)
{
    shoppingCart->addProductToProducts(newProduct);
}
