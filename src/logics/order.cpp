#include "order.h"

Order::Order()
{
    _customerID = -1;
    _orderID = -1;
    _orderPlacedDate = "";
    _deliveryDate = "";
    _orderType = OrderTypes::undefined;
    _orderProduct = Product();
}

Order::Order(QJsonObject jsonObj)
{
    _customerID = jsonObj["customerId"].toInt();
    _orderID = jsonObj["orderId"].toInt();
    _orderPlacedDate = jsonObj["placedDate"].toString();
    _deliveryDate = jsonObj["deliveryDate"].toString();
    _orderType = Order::stringToOrderType(jsonObj["orderType"].toString());
    _orderProduct = Product(jsonObj["product"].toObject());
}

qint32 Order::getOrderID() const {
    return _orderID;
}

qint32 Order::getCustomerID() const {
    return _customerID;
}

QString Order::getOrderPlacedDate() const {
    return _orderPlacedDate;
}

QString Order::getDeliveryDate() const {
    return _orderPlacedDate;
}

OrderTypes Order::getOrderType() const
{
    return _orderType;
}

Product Order::getProduct() const
{
    return _orderProduct;
}

double Order::getPrice() const
{
    return _orderProduct.getPrice();
}

void Order::setOrderID(qint32 orderID) {
    _orderID = orderID;
}

void Order::setCustomerID(qint32 customerID) {
    _customerID = customerID;
}

void Order::setOrderPlacedDate(const QString &orderPlacedDate){
    _orderPlacedDate = orderPlacedDate;
}

void Order::setDeliveryDate(const QString &deliveryDate){
    _deliveryDate = deliveryDate;
}

void Order::setOrderType(const OrderTypes& newType)
{
    _orderType = newType;
}

void Order::setProduct(const Product &newProduct)
{
    _orderProduct = newProduct;
}

void Order::addCar(const Car &car) {
    _orderProduct.addCar(car);
}

void Order::addDetail(const Detail &carDetail) {
    _orderProduct.addDetail(carDetail);
}

void Order::deleteCar(qsizetype carIndex) {
    _orderProduct.deleteCar(carIndex);
}

void Order::deleteDetail(qsizetype detailIndex) {
    _orderProduct.deleteDetail(detailIndex);
}

QJsonObject Order::toJson() const
{
    QJsonObject res;
    res.insert("customerId", _customerID);
    res.insert("orderId", _orderID);
    res.insert("placedDate", _orderPlacedDate);
    res.insert("deliveryDate", _deliveryDate);
    res.insert("orderType", Order::orderTypeToString(_orderType));
    res.insert("product", _orderProduct.toJson());

    return res;
}

QString Order::orderTypeToString(OrderTypes type)
{
    switch (type)
    {
    case OrderTypes::undefined:
    {
        return "undefined";
    }
    case OrderTypes::delivered:
    {
        return "delivered";
    }
    case OrderTypes::inProgress:
    {
        return "in progress";
    }
    case OrderTypes::created:
    {
        return "created";
    }
    }
    return "undefined";
}

OrderTypes Order::stringToOrderType(const QString &str)
{
    if (str == "undefined")
    {
        return OrderTypes::undefined;
    }else if (str == "delivered")
    {
        return OrderTypes::delivered;
    }else if (str == "in progress")
    {
        return OrderTypes::inProgress;
    }else if(str == "created")
    {
        return OrderTypes::created;
    }
    return OrderTypes::undefined;
}
