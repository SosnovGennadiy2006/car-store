#include "product.h"

Product::Product()
{
    _vendorID = -1;
    _productID = -1;
    _price = 0;
    _orderCars = QVector<Car>(0);
    _orderDetails = QVector<Detail>(0);
    _productType = ProductTypes::product_empty;
    _amount = 0;
}

Product::Product(const Product& other)
{
    _vendorID = other.getVendorID();
    _productID = other.getProductID();
    _price = other.getPrice();
    _orderCars = other.getCars();
    _orderDetails = other.getDetails();
    _productType = other.getProductType();
    _amount = other.getAmount();
}

Product::Product(const QJsonObject& jsonObj)
{
    _vendorID = jsonObj["vendorId"].toInt();
    _productID = jsonObj["productId"].toInt();
    _price = jsonObj["price"].toDouble();
    _productType = Product::stringToProductType(jsonObj["productType"].toString());
    _amount = jsonObj["amount"].toInt();
    _orderCars = QVector<Car>(0);
    _orderDetails = QVector<Detail>(0);

    QJsonArray cars = jsonObj["cars"].toArray();
    QJsonArray details = jsonObj["details"].toArray();

    for (qsizetype i = 0; i < cars.size(); i++)
    {
        _orderCars.push_back(Car(cars[i].toObject()));
    }

    for (qsizetype i = 0; i < details.size(); i++)
    {
        _orderDetails.push_back(Detail(details[i].toObject()));
    }
}

void Product::setupType()
{
    if (_orderCars.size() == 0)
    {
        if (_orderDetails.size() == 0)
        {
            _productType = ProductTypes::product_empty;
        }else if (_orderDetails.size() == 1)
        {
            _productType = ProductTypes::product_detail;
        }else
        {
            _productType = ProductTypes::product_composite;
        }
    }else if (_orderCars.size() == 1)
    {
        if (_orderDetails.size() == 0)
        {
            _productType = ProductTypes::product_car;
        }else
        {
            _productType = ProductTypes::product_composite;
        }
    }else
    {
        _productType = ProductTypes::product_composite;
    }
}

qint32 Product::getVendorID() const {
    return _vendorID;
}

qint32 Product::getProductID() const
{
    return _productID;
}

double Product::getPrice() const
{
    return _price;
}

QVector<Car> Product::getCars() const {
    return _orderCars;
}

QVector<Detail> Product::getDetails() const {
    return _orderDetails;
}

ProductTypes Product::getProductType() const
{
    return _productType;
}

qint32 Product::getAmount() const
{
    return _amount;
}

void Product::setVendorID(qint32 vendorID) {
    _vendorID = vendorID;
}

void Product::setProductID(qint32 productID)
{
    _productID = productID;
}

void Product::setPrice(double price)
{
    _price = price;
}

void Product::setProductType(ProductTypes type)
{
    _productType = type;
}

void Product::setAmount(qint32 amount)
{
    _amount = amount;
}

void Product::setCars(const QVector<Car> &cars){
    _orderCars = cars;
    setupType();
}

void Product::setCarParts(const QVector<Detail> &carParts){
    _orderDetails = carParts;
    setupType();
}

void Product::addCar(const Car &car) {
    _orderCars.append(car);
    _price += car.get_price();
    setupType();
}

void Product::addDetail(const Detail &carDetail) {
    _orderDetails.append(carDetail);
    _price += carDetail.getPrice();
    setupType();
}

void Product::deleteCar(qsizetype carIndex) {
    _price -= _orderCars[carIndex].get_price();
    _orderCars.erase(this->_orderCars.cbegin()+carIndex);
    setupType();
}

void Product::deleteDetail(qsizetype detailIndex) {
    _price -= _orderDetails[detailIndex].getPrice();
    _orderDetails.erase(this->_orderDetails.cbegin()+detailIndex);
    setupType();
}

QString Product::productTypeToString(ProductTypes type)
{
    switch(type)
    {
    case (ProductTypes::product_car):
        return "car";
    case (ProductTypes::product_detail):
        return "detail";
    case (ProductTypes::product_composite):
        return "package";
    case (ProductTypes::product_empty):
        return "empty";
    }
    return "empty";
}

ProductTypes Product::stringToProductType(const QString &str)
{
    if (str == "car")
        return ProductTypes::product_car;
    if (str == "detail")
        return ProductTypes::product_detail;
    if (str == "package")
        return ProductTypes::product_composite;
    return ProductTypes::product_empty;
}

QJsonObject Product::toJson() const
{
    QJsonObject res;
    res.insert("vendorId", _vendorID);
    res.insert("productId", _productID);
    res.insert("price", _price);
    res.insert("productType", Product::productTypeToString(_productType));
    res.insert("amount", _amount);

    QJsonArray cars, details;
    for (qsizetype i = 0; i < _orderCars.size(); i++)
    {
        cars.append(_orderCars[i].toJson());
    }
    for (qsizetype i = 0; i < _orderDetails.size(); i++)
    {
        details.append(_orderDetails[i].toJson());
    }
    res.insert("cars", cars);
    res.insert("details", details);

    return res;
}
