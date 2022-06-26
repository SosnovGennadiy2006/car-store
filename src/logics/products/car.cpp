#include "car.h"

Car::Car()
{
    name = "";
    mark = "";
    body_type = BodyTypes::undefined_bodyType;
    transmission = TransmissionTypes::undefined_transmissionType;
    drive_unit = DriveUnitTypes::undefined_driveUnit;
    price = 0;
}

Car::Car(const Car& other)
{
    name = other.get_name();
    mark = other.get_mark();
    body_type = other.get_body_type();
    transmission = other.get_transmission();
    drive_unit = other.get_drive_unit();
    price = other.get_price();
}

Car::Car(const QJsonObject& jsonObj)
{
    name = jsonObj["name"].toString();
    mark = jsonObj["mark"].toString();
    body_type = Car::stringToBodyType(jsonObj["bodyType"].toString());
    transmission = Car::stringToTransmissionType(jsonObj["transmission"].toString());
    drive_unit = Car::stringToDriveUnitTypes(jsonObj["driveUnit"].toString());
    price = jsonObj["price"].toDouble();
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

BodyTypes Car::get_body_type() const
{
    return this->body_type;
}

void Car::set_body_type(BodyTypes _body_type)
{
    this->body_type = _body_type;
}

//transmission

TransmissionTypes Car::get_transmission() const
{
    return this->transmission;
}

void Car::set_transmission(TransmissionTypes _transmission)
{
    this->transmission = _transmission;
}

//drive_unit

DriveUnitTypes Car::get_drive_unit() const
{
    return this->drive_unit;
}

void Car::set_drive_unit(DriveUnitTypes _drive_unit)
{
    this->drive_unit = _drive_unit;
}

//price

double Car::get_price() const
{
    return price;
}

void Car::set_price(const double& _price)
{
    price = _price;
}

QJsonObject Car::toJson() const
{
    QJsonObject res;
    res.insert("name", name);
    res.insert("mark", mark);
    res.insert("bodyTape", Car::bodyTypeToString(body_type));
    res.insert("transmission", Car::transmissionTypeToString(transmission));
    res.insert("driveUnit", Car::driveUnitTypeToString(drive_unit));
    res.insert("price", price);

    return res;
}

QString Car::bodyTypeToString(BodyTypes type)
{
    switch (type)
    {
    case (BodyTypes::sedan):
        return "sedan";
    case (BodyTypes::coupe):
        return "coupe";
    case (BodyTypes::hatchback):
        return "hatchback";
    case (BodyTypes::liftback):
        return "liftback";
    case (BodyTypes::station_wagon):
        return "station wagon";
    case (BodyTypes::minivan):
        return "minivan";
    case (BodyTypes::SUV):
        return "SUV";
    case (BodyTypes::pickup):
        return "pickup";
    case (BodyTypes::van):
        return "van";
    case (BodyTypes::undefined_bodyType):
        return "undefined";
    }
    return "undefined";
}

BodyTypes Car::stringToBodyType(const QString &str)
{
    if (str == "sedan")
        return BodyTypes::sedan;
    if (str == "coupe")
        return BodyTypes::coupe;
    if (str == "hatchback")
        return BodyTypes::hatchback;
    if (str == "liftback")
        return BodyTypes::liftback;
    if (str == "station wagon")
        return BodyTypes::station_wagon;
    if (str == "minivan")
        return BodyTypes::minivan;
    if (str == "SUV")
        return BodyTypes::SUV;
    if (str == "pickup")
        return BodyTypes::pickup;
    if (str == "van")
        return BodyTypes::van;
    return BodyTypes::undefined_bodyType;
}

QString Car::transmissionTypeToString(TransmissionTypes type)
{
    switch (type)
    {
    case (TransmissionTypes::mechanical):
        return "mechanical";
    case (TransmissionTypes::automatic):
        return "automatic";
    case (TransmissionTypes::robotic):
        return "robotic";
    case (TransmissionTypes::stepless):
        return "stepless";
    case (TransmissionTypes::undefined_transmissionType):
        return "undefined";
    }
    return "undefined";
}

TransmissionTypes Car::stringToTransmissionType(const QString &str)
{
    if (str == "mechanical")
        return TransmissionTypes::mechanical;
    if (str == "automatic")
        return TransmissionTypes::automatic;
    if (str == "robotic")
        return TransmissionTypes::robotic;
    if (str == "stepless")
        return TransmissionTypes::stepless;
    return TransmissionTypes::undefined_transmissionType;
}

QString Car::driveUnitTypeToString(DriveUnitTypes type)
{
    switch(type)
    {
    case (DriveUnitTypes::rear):
        return "rear";
    case (DriveUnitTypes::front):
        return "front";
    case (DriveUnitTypes::all):
        return "all";
    case (DriveUnitTypes::undefined_driveUnit):
        return "undefined";
    }
    return "undefined";
}

DriveUnitTypes Car::stringToDriveUnitTypes(const QString &str)
{
    if (str == "rear")
        return DriveUnitTypes::rear;
    if (str == "front")
        return DriveUnitTypes::front;
    if (str == "all")
        return DriveUnitTypes::all;
    return DriveUnitTypes::undefined_driveUnit;
}
