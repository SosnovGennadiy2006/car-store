#include "user.h"

User::User(const UserTypes& _type)
{
    userName = "";
    userSurname = "";
    userAge = -1;
    userEmailAdress = "";
    userPassword = "";
    phoneNumber = "";
    userType = _type;
    registrationDate = "";
    allUserOrders = QVector<Order>(0);
}

User::User(const User& other)
{
    userId = other.getId();
    userName = other.getName();
    userSurname = other.getSurname();
    userAge = other.getAge();
    userEmailAdress = other.getEmailAdress();
    userPassword = other.getPassword();
    phoneNumber = other.getPhoneNumber();
    userType = other.getUserType();
    registrationDate = other.getRegistrationDate();
    allUserOrders = other.getOrders();
}

User::User(const User* other)
{
    userId = other->getId();
    userName = other->getName();
    userSurname = other->getSurname();
    userAge = other->getAge();
    userEmailAdress = other->getEmailAdress();
    userPassword = other->getPassword();
    phoneNumber = other->getPhoneNumber();
    userType = other->getUserType();
    registrationDate = other->getRegistrationDate();
    allUserOrders = other->getOrders();
}

User::User(const QJsonObject& jsonObj)
{
    userId = jsonObj["id"].toInt();
    userName = jsonObj["name"].toString();
    userSurname = jsonObj["surname"].toString();
    userAge = jsonObj["age"].toInt();
    userPassword = jsonObj["password"].toString();
    userEmailAdress = jsonObj["email"].toString();
    registrationDate = jsonObj["registrationDate"].toString();
    phoneNumber = jsonObj["phone"].toString();
    allUserOrders = QVector<Order>(0);

    QString _userType = jsonObj["type"].toString();

    if (_userType == "client")
    {
        userType = UserTypes::client;
    }else if(_userType == "vendor")
    {
        userType = UserTypes::vendor;
    }else if(_userType == "admin")
    {
        userType = UserTypes::admin;
    }
}

qint32 User::getId() const
{
    return userId;
}

QString User::getName() const
{
    return userName;
}

QString User::getSurname() const
{
    return userSurname;
}

qint32 User::getAge() const
{
    return userAge;
}

QString User::getPassword() const
{
    return userPassword;
}

QString User::getEmailAdress() const
{
    return userEmailAdress;
}

QString User::getPhoneNumber() const
{
    return phoneNumber;
}

UserTypes User::getUserType() const
{
    return userType;
}

QString User::getRegistrationDate() const
{
    return registrationDate;
}

QVector<Order> User::getOrders() const
{
    return allUserOrders;
}

Order User::getOrder(qsizetype idx) const
{
    return allUserOrders[idx];
}

QVector<Product> User::getProducts() const
{
    return allUserProducts;
}

Product User::getProduct(qsizetype idx) const
{
    return allUserProducts[idx];
}

void User::setId(const qint32& id)
{
    userId = id;
}

void User::setName(const QString& name)
{
    userName = name;
}

void User::setSurname(const QString& surname)
{
    userSurname = surname;
}

void User::setAge(const qint32& age)
{
    userAge = age;
}

void User::setPassword(const QString& password)
{
    userPassword = password;
}

void User::setEmailAdress(const QString& emailAdress)
{
    userEmailAdress = emailAdress;
}

void User::setPhoneNumber(const QString& _phoneNumber)
{
    phoneNumber = _phoneNumber;
}

void User::setUserType(const UserTypes& name)
{
    userType = name;
}

void User::setRegistrationDate(const QString& _date)
{
    registrationDate = _date;
}

void User::addOrder(const Order &addedOrder)
{
    allUserOrders.append(addedOrder);
}

void User::popOrder()
{
    allUserOrders.pop_back();
}

void User::setOrders(const QVector<Order> &newOrders)
{
    allUserOrders = newOrders;
}

void User::setOrder(qsizetype idx, const Order &newOrder)
{
    allUserOrders[idx] = newOrder;
}

void User::addProduct(const Product &addedProduct)
{
    allUserProducts.append(addedProduct);
}

void User::popProduct()
{
    allUserProducts.pop_back();
}

void User::setProducts(const QVector<Product> &newProducts)
{
    allUserProducts = newProducts;
}

void User::setProduct(qsizetype idx, const Product &newProduct)
{
    allUserProducts[idx] = newProduct;
}
