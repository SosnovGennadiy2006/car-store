#ifndef CARTWIDGET_H
#define CARTWIDGET_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <logics/user.h>
#include <widgets/menuWidgets/userorderswidget.h>
#include <widgets/menuWidgets/userproductswidget.h>
#include <widgets/modalWindows/addproductwindow.h>

class CartWidget : public QFrame
{
    Q_OBJECT

    User* registeredUser;

    QVBoxLayout* mainLayout;

    QLabel* welcomeLabel;
    QLabel* aboutLabel;
    UserOrdersWidget* orders;

    QWidget* goToCatalogWidget;
    QHBoxLayout* goToCatalogLayout;
    QLabel* goToCatalogLabel;
    QPushButton* goToCatalogButton;

    QLabel* vendorLabel;
    UserProductsWidget* products;

    QWidget* createProductWidget;
    QHBoxLayout* createProductLayout;
    QLabel* createProductLabel;
    QPushButton* newProductButton;

    QFrame* hLine1;
    QFrame* hLine2;

    QSpacerItem* spacer;
    QSpacerItem* spacer2;

    AddProductWindow* modalWindow;

public:
    CartWidget(QWidget *parent = nullptr);

    User* getUser() const;

    void setUser(User* newUser);

    void addProductToProducts(Product newProduct);
    void addOrderToOrders(Order newOrder);

signals:
    void onRedirectionButtonClicked();
    void onProductSaved(Product productToSave);

public slots:
    void addProduct();
};

#endif // CARTWIDGET_H
