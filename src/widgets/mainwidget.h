#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QScrollArea>
#include <logics/user.h>
#include <widgets/menu.h>
#include <widgets/menuWidgets/profilewidget.h>
#include <widgets/menuWidgets/cartwidget.h>
#include <widgets/menuWidgets/catalogwidget.h>

class MainWidget : public QWidget
{
    Q_OBJECT

    User* registeredUser = new User(UserTypes::client);

    QHBoxLayout* mainLayout;

    Menu* widgetMenu;

    ProfileWidget* profile;

    CartWidget* shoppingCart;

    CatalogWidget* catalog;

    QScrollArea* profileScroll;
    QScrollArea* cartScroll;
    QScrollArea* catalogScroll;

public:
    explicit MainWidget(QWidget *parent = nullptr);

    User* getUser() const;

    void setUser(User* newUser);

    bool isProfileChanged();

    void saveProfileChanges();

    void addProductToProducts(Product newProduct);
    void addOrderToOrders(Order newOrder);

    void setupCatalog();

signals:
    void onExitButtonClicked();
    void onUserCorrected(User* correctedUser);
    void onProductSaved(Product productToSave);
    void onOrderSaved(Order orderToSave);

public slots:
    void redirectToProfile();
    void redirectToCart();
    void redirectToCatalog();
    void onNewOrder(Product orderProduct);
};

#endif // MAINWIDGET_H
