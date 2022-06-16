#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QJsonObject>

class Car{
private:
    QString name;
    QString mark;
    QString body_type;
    qint32 mileage;
    QString transmission;
    QString drive_unit;

public:
    Car();
    Car(const Car& other);
    Car(const QJsonObject& jsonObj);

    // Геттеры

    QString get_name() const;
    QString get_mark() const;
    QString get_body_type() const;
    qint32 get_mileage() const;
    QString get_transmission() const;
    QString get_drive_unit() const;

    // Сеттеры

    void set_name(const QString& _name);
    void set_mark(const QString& _mark);
    void set_body_type(const QString& _body_type);
    void set_mileage(const qint32& _mileage);
    void set_transmission(const QString& _transmission);
    void set_drive_unit(const QString& _drive_unit);

    QJsonObject toJson() const;
};

#endif // CAR_H
