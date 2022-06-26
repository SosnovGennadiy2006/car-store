#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>
#include <QJsonObject>
#include <logics/order.h>
#include <logics/products/product.h>

enum UserTypes
{
    admin,
    client,
    vendor
};

class User
{
private:
    qint32 userId;
    QString userName;
    QString userSurname;
    qint32 userAge;
    QString userEmailAdress;
    QString userPassword;
    QString phoneNumber;
    UserTypes userType;
    QString registrationDate;
    QVector<Order> allUserOrders;
    QVector<Product> allUserProducts;
public:
    User() = default;
    User(const User& other);
    explicit User(const UserTypes& _type);
    explicit User(const User* other);
    explicit User(const QJsonObject& jsonObj);

    qint32 getId() const;
    QString getName() const;
    QString getSurname() const;
    qint32 getAge() const;
    QString getPassword() const;
    QString getEmailAdress() const;
    QString getPhoneNumber() const;
    UserTypes getUserType() const;
    QString getRegistrationDate() const;
    QVector<Order> getOrders() const;
    Order getOrder(qsizetype idx) const;
    QVector<Product> getProducts() const;
    Product getProduct(qsizetype idx) const;

    void setId(const qint32& id);
    void setName(const QString& name);
    void setSurname(const QString& surname);
    void setAge(const qint32& age);
    void setPassword(const QString& password);
    void setEmailAdress(const QString& emailAdress);
    void setPhoneNumber(const QString& phoneNumber);
    void setUserType(const UserTypes& type);
    void setRegistrationDate(const QString& _date);

    void addOrder(const Order& addedOrder);
    void popOrder();
    void setOrders(const QVector<Order>& newOrders);
    void setOrder(qsizetype idx, const Order& newOrder);

    void addProduct(const Product& addedProduct);
    void popProduct();
    void setProducts(const QVector<Product>& newProducts);
    void setProduct(qsizetype idx, const Product& newProduct);
};

#endif // USER_H
