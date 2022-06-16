//
// Created by skine on 6/6/2022.
//

#ifndef CARSTORE_DETAIL_H
#define CARSTORE_DETAIL_H
#include <string>

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
    candle_multielectrode,
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
enum CaliperType{
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

class detail {
    std::string nameManufacturer;
    double engineVolume;
    int enginePower;
    RubberTypes wheelRubber;
    DetailTypes detailType;
    int candleSize;
    CandleTypes candleType;
    CarburetorTypes carburetorType;
    CaliperType caliperType;
    BrakeDiscsTypes brakeDiscsType;
    BrakeDiscsTypesOfMaterial brakeDiscsTypeOfMaterial;
    int heatNumber;
    int wheelRubberRadius;
    int wheelDiskRadius;

public:
    detail();

    std::string getNameManufacturer() const;
    void setNameManufacturer(std::string new_val);

    double getEngineVolume() const;
    void setEngineVolume(double new_val);

    int getEnginePower() const;
    void setEnginePower(int new_val);

    RubberTypes getWheelRubber() const;
    void setWheelRubber(RubberTypes new_val);

    DetailTypes getDetailType() const;
    void setDetailType(DetailTypes new_val);

    int getCandleSize() const;
    void setCandleSize(int new_val);

    CandleTypes getCandleType() const;
    void setCandleType(CandleTypes new_val);

    CarburetorTypes getCarburetorType() const;
    void setCarburetorType(CarburetorTypes new_val);

    CaliperType getCaliperType() const;
    void setCaliperType(CaliperType new_val);

    BrakeDiscsTypes getBrakeDiscsType() const;
    void setBrakeDiscsType(BrakeDiscsTypes new_val);

    BrakeDiscsTypesOfMaterial getBrakeDiscsTypeOfMaterial() const;
    void setBrakeDiscsTypeOfMaterial(BrakeDiscsTypesOfMaterial new_val);

    int getHeatNumber() const;
    void setHeatNumber(int new_val);

    int getWheelRubberRadius() const;
    void setWheelRubberRadius(int new_val);

    int getWheelDiskRadius() const;
    void setWheelDiskRadius(int new_val);
};


#endif //CARSTORE_DETAIL_H
