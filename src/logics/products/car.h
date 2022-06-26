#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QJsonObject>

enum BodyTypes
{
    sedan,
    coupe,
    hatchback,
    liftback,
    station_wagon,
    minivan,
    SUV,
    pickup,
    van,
    undefined_bodyType
};

enum TransmissionTypes
{
    mechanical,
    automatic,
    robotic,
    stepless,
    undefined_transmissionType
};

enum DriveUnitTypes
{
    rear,
    front,
    all,
    undefined_driveUnit
};

class Car{
private:
    QString name;
    QString mark;
    BodyTypes body_type;
    TransmissionTypes transmission;
    DriveUnitTypes drive_unit;
    double price;

public:
    Car();
    Car(const Car& other);
    Car(const QJsonObject& jsonObj);

    // Геттеры

    QString get_name() const;
    QString get_mark() const;
    BodyTypes get_body_type() const;
    TransmissionTypes get_transmission() const;
    DriveUnitTypes get_drive_unit() const;
    double get_price() const;

    // Сеттеры

    void set_name(const QString& _name);
    void set_mark(const QString& _mark);
    void set_body_type(BodyTypes _body_type);
    void set_transmission(TransmissionTypes _transmission);
    void set_drive_unit(DriveUnitTypes _drive_unit);
    void set_price(const double& _price);

    QJsonObject toJson() const;

    static QString bodyTypeToString(BodyTypes type);
    static BodyTypes stringToBodyType(const QString& str);
    static QString transmissionTypeToString(TransmissionTypes type);
    static TransmissionTypes stringToTransmissionType(const QString& str);
    static QString driveUnitTypeToString(DriveUnitTypes type);
    static DriveUnitTypes stringToDriveUnitTypes(const QString& str);
};

#endif // CAR_H
