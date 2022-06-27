#ifndef BUYPRODUCTWINDOW_H
#define BUYPRODUCTWINDOW_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <widgets/infowidget.h>
#include <logics/products/product.h>

class BuyProductWindow : public QDialog
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QScrollArea* mainArea;

    QWidget* productInfoWidget;
    QVBoxLayout* productInfoLayout;

    InfoWidget* idWidget;
    InfoWidget* vendorIdWidget;
    InfoWidget* productTypeWidget;
    InfoWidget* amountOfCarsWidget;
    InfoWidget* amountOfDetailsWidget;
    InfoWidget* amountWidget;
    InfoWidget* priceWidget;

    QWidget* buyButtonWidget;
    QHBoxLayout* buyButtonLayout;
    QPushButton* buyButton;
    QPushButton* cancelButton;

    QSpacerItem* spacer;
    QSpacerItem* areaSpacer;

    Product product;
public:
    BuyProductWindow(QWidget* parent = nullptr);

    Product getProduct() const;

    void setProduct(const Product& newProduct);

signals:
    void buyButtonClicked();
};

#endif // BUYPRODUCTWINDOW_H
