#include "order.h"

Order::Order()
{
    _customerID = -1;
    _orderID = -1;
    _orderPlacedDate = "";
    _deliveryDate = "";
    _orderCars = QVector<Car>(0);
    _orderDetails = QVector<Detail>(0);
    _orderType = OrderTypes::undefined;
}

Order::Order(QJsonObject jsonObj)
{
    _customerID = jsonObj["customerId"].toInt();
    _orderID = jsonObj["customerId"].toInt();
    _orderPlacedDate = jsonObj["customerId"].toString();
    _deliveryDate = jsonObj["customerId"].toString();
    _orderCars = QVector<Car>(0);
    _orderDetails = QVector<Detail>(0);
    _orderType = Order::stringToOrderType(jsonObj["customerId"].toString());
    QJsonArray cars = jsonObj["orderCars"].toArray();
//    QJsonArray details = jsonObj["orderDetails"].toArray();

    for (qsizetype i = 0; i < cars.size(); i++)
    {
        _orderCars.append(Car(cars[i].toObject()));
    }
}

qint32 Order::getOrderID() const {
    return this->_orderID;
}

qint32 Order::getVendorID() const {
    return this->_customerID;
}

qint32 Order::getCustomerID() const {
    return this->_customerID;
}

QString Order::getOrderPlacedDate() const {
    return this->_orderPlacedDate;
}

QString Order::getDeliveryDate() const {
    return this->_orderPlacedDate;
}

QVector<Car> Order::getCars() const {
    return this->_orderCars;
}

QVector<Detail> Order::getDetails() const {
    return this->_orderDetails;
}

OrderTypes Order::getOrderType() const
{
    return this->_orderType;
}

void Order::setOrderID(qint32 orderID) {
    this->_orderID = orderID;
}

void Order::setVendorID(qint32 vendorID) {
    this->_vendorID = vendorID;
}

void Order::setCustomerID(qint32 customerID) {
    this->_customerID = customerID;
}

void Order::setOrderPlacedDate(const QString &orderPlacedDate){
    this->_orderPlacedDate = orderPlacedDate;
}

void Order::setDeliveryDate(const QString &deliveryDate){
    this->_deliveryDate = deliveryDate;
}

void Order::setCars(const QVector<Car> &cars){
    this->_orderCars = cars;
}

void Order::setCarParts(const QVector<Detail> &carParts){
    this->_orderDetails = carParts;
}

void Order::setOrderType(const OrderTypes& newType)
{
    _orderType = newType;
}

void Order::addCar(const Car &car) {
    this->_orderCars.push_back(car);
}

void Order::addDetail(const Detail &carDetail) {
    this->_orderDetails.push_back(carDetail);
}

void Order::deleteCar(int carIndex) {
    this->_orderCars.erase(this->_orderCars.cbegin()+carIndex);
}

void Order::deleteDetail(int carDetail) {
    this->_orderDetails.erase(this->_orderDetails.cbegin()+carDetail);
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
    assert("Unknown order type!");
    return OrderTypes::undefined;
}
