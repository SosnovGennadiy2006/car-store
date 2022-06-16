#include "car.h"

Car::Car()
{
    name = "";
    mark = "";
    body_type = "";
    mileage = -1;
    transmission = "";
    drive_unit = "";
}

Car::Car(const Car& other)
{
    name = other.get_name();
    mark = other.get_name();
    body_type = other.get_body_type();
    mileage = other.get_mileage();
    transmission = other.get_transmission();
    drive_unit = other.get_drive_unit();
}

Car::Car(const QJsonObject& jsonObj)
{
    name = jsonObj["name"].toString();
    mark = jsonObj["mark"].toString();
    body_type = jsonObj["bodyType"].toString();
    mileage = jsonObj["mieage"].toInt();
    transmission = jsonObj["transmission"].toString();
    drive_unit = jsonObj["driveUnit"].toString();
}

//Name

QString Car::get_name() const
{
    return this->name;
}

void Car::set_name(const QString& _name)
{
    this->name = _name;
}

//mark
QString Car::get_mark() const
{
    return this->mark;
}

void Car::set_mark(const QString& _mark)
{
    this->mark = _mark;
}

//body_type

QString Car::get_body_type() const
{
    return this->body_type;
}

void Car::set_body_type(const QString& _body_type)
{
    this->body_type = _body_type;
}


//mileage

qint32 Car::get_mileage() const
{
    return this->mileage;
}

void Car::set_mileage(const qint32& _mileage)
{
    this->mileage = _mileage;
}

//transmission

QString Car::get_transmission() const
{
    return this->transmission;
}

void Car::set_transmission(const QString& _transmission)
{
    this->transmission = _transmission;
}

//drive_unit

QString Car::get_drive_unit() const
{
    return this->drive_unit;
}

void Car::set_drive_unit(const QString& _drive_unit)
{
    this->drive_unit = _drive_unit;
}

QJsonObject Car::toJson() const
{
    QJsonObject res;
    res.insert("name", name);
    res.insert("mark", mark);
    res.insert("bodyTape", body_type);
    res.insert("mileage", mileage);
    res.insert("transmission", transmission);
    res.insert("driveUnit", drive_unit);

    return res;
}
