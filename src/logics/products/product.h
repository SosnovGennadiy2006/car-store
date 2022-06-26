#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <logics/products/car.h>
#include <logics/products/detail.h>

enum ProductTypes
{
    product_empty,
    product_car,
    product_detail,
    product_composite
};

class Product
{
    qint32 _vendorID;
    qint32 _productID;
    double _price;
    QVector<Car> _orderCars;
    QVector<Detail> _orderDetails;
    ProductTypes _productType;
    qint32 _amount;

public:
    Product();
    Product(const Product& other);
    Product(const QJsonObject& jsonObj);

    void setupType();

    qint32 getVendorID() const;

    qint32 getProductID() const;

    double getPrice() const;

    QVector<Car> getCars() const;

    QVector<Detail> getDetails() const;

    ProductTypes getProductType() const;

    qint32 getAmount() const;

    void setVendorID(qint32 vendorID);

    void setProductID(qint32 productID);

    void setPrice(double price);

    void setProductType(ProductTypes type);

    void setAmount(qint32 amount);

    void setCars(const QVector<Car> &cars);

    void setCarParts(const QVector<Detail> &carParts);

    void addCar(const Car &car);

    void addDetail(const Detail &carDetail);

    void deleteCar(qsizetype carIndex);

    void deleteDetail(qsizetype carDetail);

    static QString productTypeToString(ProductTypes type);

    static ProductTypes stringToProductType(const QString& str);

    QJsonObject toJson() const;
};

#endif // PRODUCT_H
