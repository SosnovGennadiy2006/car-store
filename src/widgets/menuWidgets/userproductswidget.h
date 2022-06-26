#ifndef USERPRODUCTSWIDGET_H
#define USERPRODUCTSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <logics/products/product.h>
#include <widgets/line.h>

class UserProductsWidget : public QWidget
{
    Q_OBJECT

    QVector<Product> products;

    QVBoxLayout* mainLayout;
    QLabel* infoLabel;
    QWidget* gridWidget;
    QGridLayout* grid;
public:
    explicit UserProductsWidget(QWidget *parent = nullptr);

    QVector<Product> getProducts() const;
    Product getProduct(qsizetype idx) const;

    void setProducts(const QVector<Product>& newOrders);
    void setProduct(qsizetype idx, const Product& newOrder);

    void addProduct(const Product& newOrder);
signals:

};

#endif // USERPRODUCTSWIDGET_H
