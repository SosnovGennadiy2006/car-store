#ifndef ORDER_H
#define ORDER_H

#include <QVector>
#include <QJsonObject>
#include <QJsonArray>
#include <cassert>
#include <logics/products/car.h>
#include <logics/products/detail.h>

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
    qint32 _vendorID;
    qint32 _orderID;
    QString _orderPlacedDate;
    QString _deliveryDate;
    QVector<Car> _orderCars;
    QVector<Detail> _orderDetails;
    OrderTypes _orderType;

public:
    Order();
    Order(QJsonObject jsonObj);

    qint32 getOrderID() const;

    qint32 getVendorID() const;

    qint32 getCustomerID() const;

    QString getOrderPlacedDate() const;

    QString getDeliveryDate() const;

    QVector<Car> getCars() const;

    QVector<Detail> getDetails() const;

    OrderTypes getOrderType() const;

    void setOrderID(qint32 orderID);

    void setVendorID(qint32 vendorID);

    void setCustomerID(qint32 customerID);

    void setOrderPlacedDate(const QString &orderPlacedDate);

    void setDeliveryDate(const QString &deliveryDate);

    void setCars(const QVector<Car> &cars);

    void setCarParts(const QVector<Detail> &carParts);

    void setOrderType(const OrderTypes& newType);

    void addCar(const Car &car);

    void addDetail(const Detail &carDetail);

    void deleteCar(int carIndex);

    void deleteDetail(int carDetail);

    static QString orderTypeToString(OrderTypes type);
    static OrderTypes stringToOrderType(const QString& str);

};

#endif // ORDER_H
