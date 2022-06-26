//
// Created by skine on 6/6/2022.
//

#ifndef CARSTORE_DETAIL_H
#define CARSTORE_DETAIL_H

#include <QString>
#include <QJsonObject>

//Типы деталей
enum DetailTypes{
    detail_engine,
    detail_wheelRubber,
    detail_wheelDisk,
    detail_candle,
    detail_carburetor,
    detail_caliper,
    detail_brakeDiscs,
    undefined_detailType
};

//Типы резины
enum RubberTypes{
    winter_tires,
    summer_tires,
    undefined_rubberType
};

//Типы свечей
enum CandleTypes{
    candle_singleElectrode,
    candle_multieElectrode,
    candle_special,
    candle_torch,
    candle_plasmaPrechamber,
    undefined_candleType
};

//Типы карбюратора
enum CarburetorTypes{
    carburetor_bubbling, //Барботажный
    carburetor_wick, //Фитильный
    carburetor_membraneNeedle, //Мембранно-игольчатый
    carburetor_float, //Поплавковый
    undefined_carburetorType
};

//Виды суппортов
enum CaliperTypes{
    caliper_floating, //плавающий
    caliper_fixed, //фиксированный
    undefined_caliperType
};

//Виды тормозных дисков
enum BrakeDiscsTypes{
    brakeDiscs_solid, //Сплошные
    brakeDiscs_ventilated, //Вентилируемые
    brakeDiscs_composite, //Составные
    undefined_brakeDiscsType
};

//Виды тормозных дисков о материалу
enum BrakeDiscsTypesOfMaterial{
    brakeDiscsMat_metal, //Металлические
    brakeDiscsMat_ceramic, //Керамические
    undefined_brakeDiscsTypeOfMaterial
};

class Detail {
    DetailTypes detailType;
    QString name;
    QString nameManufacturer;
    double engineVolume;
    qint32 enginePower;
    RubberTypes wheelRubber;
    qint32 candleSize;
    CandleTypes candleType;
    CarburetorTypes carburetorType;
    CaliperTypes caliperType;
    BrakeDiscsTypes brakeDiscsType;
    BrakeDiscsTypesOfMaterial brakeDiscsTypeOfMaterial;
    qint32 heatNumber;
    qint32 wheelRubberRadius;
    qint32 wheelDiskRadius;
    double price;

public:
    Detail();
    Detail(const Detail& other);
    Detail(const QJsonObject& jsonObj);

    QString getName() const;
    void setName(const QString& new_val);

    QString getNameManufacturer() const;
    void setNameManufacturer(const QString& new_val);

    double getEngineVolume() const;
    void setEngineVolume(double new_val);

    qint32 getEnginePower() const;
    void setEnginePower(qint32 new_val);

    RubberTypes getWheelRubber() const;
    void setWheelRubber(RubberTypes new_val);

    DetailTypes getDetailType() const;
    void setDetailType(DetailTypes new_val);

    qint32 getCandleSize() const;
    void setCandleSize(qint32 new_val);

    CandleTypes getCandleType() const;
    void setCandleType(CandleTypes new_val);

    CarburetorTypes getCarburetorType() const;
    void setCarburetorType(CarburetorTypes new_val);

    CaliperTypes getCaliperType() const;
    void setCaliperType(CaliperTypes new_val);

    BrakeDiscsTypes getBrakeDiscsType() const;
    void setBrakeDiscsType(BrakeDiscsTypes new_val);

    BrakeDiscsTypesOfMaterial getBrakeDiscsTypeOfMaterial() const;
    void setBrakeDiscsTypeOfMaterial(BrakeDiscsTypesOfMaterial new_val);

    qint32 getHeatNumber() const;
    void setHeatNumber(qint32 new_val);

    qint32 getWheelRubberRadius() const;
    void setWheelRubberRadius(qint32 new_val);

    qint32 getWheelDiskRadius() const;
    void setWheelDiskRadius(qint32 new_val);

    double getPrice() const;
    void setPrice(double new_val);

    static QString detailTypeToString(DetailTypes type);
    static DetailTypes stringToDetailType(const QString& str);

    static QString rubberTypeToString(RubberTypes type);
    static RubberTypes stringToRubberType(const QString& str);

    static QString candleTypeToString(CandleTypes type);
    static CandleTypes stringToCandleType(const QString& str);

    static QString carburetorTypeToString(CarburetorTypes type);
    static CarburetorTypes stringToCarburetorType(const QString& str);

    static QString caliperTypeToString(CaliperTypes type);
    static CaliperTypes stringToCaliperType(const QString& str);

    static QString brakeDiscsTypeToString(BrakeDiscsTypes type);
    static BrakeDiscsTypes stringToBrakeDiscsType(const QString& str);

    static QString brakeDiscsTypesOfMaterialToString(BrakeDiscsTypesOfMaterial type);
    static BrakeDiscsTypesOfMaterial stringToBrakeDiscsTypesOfMaterial(const QString& str);

    QJsonObject toJson() const;
};


#endif //CARSTORE_DETAIL_H
