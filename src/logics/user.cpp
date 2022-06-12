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
}

User::User(const User& other)
{
    userName = other.getName();
    userSurname = other.getSurname();
    userAge = other.getAge();
    userEmailAdress = other.getEmailAdress();
    userPassword = other.getPassword();
    phoneNumber = other.getPhoneNumber();
    userType = other.getUserType();
    registrationDate = other.getRegistrationDate();
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
