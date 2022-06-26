#ifndef ORDER_H
#define ORDER_H

#include <QVector>
#include <QJsonObject>
#include <QJsonArray>
#include <logics/products/car.h>
#include <logics/products/detail.h>
#include <logics/products/product.h>

enum OrderTypes
{
    undefined,
    created,
    inProgress,
    delivered
};

class Order {
private:
    qint32 _customerID;
    qint32 _orderID;
    QString _orderPlacedDate;
    QString _deliveryDate;
    OrderTypes _orderType;
    Product _orderProduct;

public:
    Order();
    Order(QJsonObject jsonObj);

    qint32 getOrderID() const;

    qint32 getCustomerID() const;

    QString getOrderPlacedDate() const;

    QString getDeliveryDate() const;

    OrderTypes getOrderType() const;

    Product getProduct() const;

    double getPrice() const;

    void setOrderID(qint32 orderID);

    void setCustomerID(qint32 customerID);

    void setOrderPlacedDate(const QString &orderPlacedDate);

    void setDeliveryDate(const QString &deliveryDate);

    void setOrderType(const OrderTypes& newType);

    void setProduct(const Product& newProduct);

    void addCar(const Car &car);

    void addDetail(const Detail &carDetail);

    void deleteCar(qsizetype carIndex);

    void deleteDetail(qsizetype detailIndex);

    QJsonObject toJson() const;

    static QString orderTypeToString(OrderTypes type);
    static OrderTypes stringToOrderType(const QString& str);

};

#endif // ORDER_H
