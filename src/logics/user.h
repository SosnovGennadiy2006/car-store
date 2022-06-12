#ifndef USER_H
#define USER_H

#include <QString>

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
public:
    User() = default;
    User(const UserTypes& _type);
    User(const User& other);

    qint32 getId() const;
    QString getName() const;
    QString getSurname() const;
    qint32 getAge() const;
    QString getPassword() const;
    QString getEmailAdress() const;
    QString getPhoneNumber() const;
    UserTypes getUserType() const;
    QString getRegistrationDate() const;

    void setId(const qint32& id);
    void setName(const QString& name);
    void setSurname(const QString& surname);
    void setAge(const qint32& age);
    void setPassword(const QString& password);
    void setEmailAdress(const QString& emailAdress);
    void setPhoneNumber(const QString& phoneNumber);
    void setUserType(const UserTypes& type);
    void setRegistrationDate(const QString& _date);
};

#endif // USER_H
