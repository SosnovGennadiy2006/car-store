#ifndef PRODUCTINFOWIDGET_H
#define PRODUCTINFOWIDGET_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <logics/products/product.h>
#include <widgets/infowidget.h>
#include <widgets/modalWindows/buyproductwindow.h>

class ProductInfoWidget : public QFrame
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    InfoWidget* idWidget;
    InfoWidget* vendorIdWidget;
    InfoWidget* productTypeWidget;
    InfoWidget* amountOfCarsWidget;
    InfoWidget* amountOfDetailsWidget;
    InfoWidget* amountWidget;
    InfoWidget* priceWidget;

    QFrame* hLine1;

    QWidget* viewButtonWidget;
    QHBoxLayout* viewButtonLayout;
    QPushButton* viewButton;

    QSpacerItem* spacer1;
    QSpacerItem* spacer2;

    BuyProductWindow* modalWindow;

    Product product;

public:
    explicit ProductInfoWidget(QWidget *parent = nullptr);

    Product getProduct() const;
    void setProduct(const Product& newProduct);

signals:
    void onProductBuyed();

public slots:
    void viewAllInfo();

};

#endif // PRODUCTINFOWIDGET_H
