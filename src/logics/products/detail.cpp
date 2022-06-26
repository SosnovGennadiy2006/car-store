//
// Created by skine on 6/6/2022.
//

#include "detail.h"

Detail::Detail() {
    detailType = undefined_detailType;
    name = "";
    nameManufacturer = "";
    engineVolume = 0;
    enginePower = 0;
    wheelRubber = undefined_rubberType;
    candleType = undefined_candleType;
    carburetorType = undefined_carburetorType;
    caliperType = undefined_caliperType;
    brakeDiscsType = undefined_brakeDiscsType;
    brakeDiscsTypeOfMaterial = undefined_brakeDiscsTypeOfMaterial;
    heatNumber = 0;
    wheelRubberRadius = 0;
    wheelDiskRadius = 0;
    price = 0;
}

Detail::Detail(const Detail& other)
{
    detailType = other.getDetailType();
    name = other.getName();
    nameManufacturer = other.getNameManufacturer();
    engineVolume = other.getEngineVolume();
    enginePower = other.getEnginePower();
    wheelRubber = other.getWheelRubber();
    candleSize = other.getCandleSize();
    candleType = other.getCandleType();
    carburetorType = other.getCarburetorType();
    caliperType = other.getCaliperType();
    brakeDiscsType = other.getBrakeDiscsType();
    brakeDiscsTypeOfMaterial = other.getBrakeDiscsTypeOfMaterial();
    heatNumber = other.getHeatNumber();
    wheelRubberRadius = other.getWheelRubberRadius();
    wheelDiskRadius = other.getWheelDiskRadius();
    price = other.getPrice();
}

Detail::Detail(const QJsonObject& jsonObj)
{
    detailType = stringToDetailType(jsonObj["detailType"].toString());
    name = jsonObj["name"].toString();
    nameManufacturer = jsonObj["nameManufacturer"].toString();
    engineVolume = jsonObj["engineVolume"].toDouble();
    enginePower = jsonObj["enginePower"].toInt();
    wheelRubber = stringToRubberType(jsonObj["wheelRubber"].toString());
    candleType = stringToCandleType(jsonObj["candleType"].toString());
    candleSize = jsonObj["candleSize"].toInt();
    carburetorType = stringToCarburetorType(jsonObj["carburetorType"].toString());
    caliperType = stringToCaliperType(jsonObj["caliperType"].toString());
    brakeDiscsType = stringToBrakeDiscsType(jsonObj["brakeDiscsType"].toString());
    brakeDiscsTypeOfMaterial = stringToBrakeDiscsTypesOfMaterial(jsonObj["brakeDiscsTypeOfMaterial"].toString());
    heatNumber = jsonObj["heatNumber"].toInt();
    wheelRubberRadius = jsonObj["wheelRubberRadius"].toInt();
    wheelDiskRadius = jsonObj["wheelDiskRadius"].toInt();
    price = jsonObj["price"].toDouble();
}

QString Detail::getName() const
{
    return name;
}

void Detail::setName(const QString &new_val)
{
    name = new_val;
}

QString Detail::getNameManufacturer() const{
    return nameManufacturer;
}

void Detail::setNameManufacturer(const QString& new_val){
    nameManufacturer = new_val;
}

double Detail::getEngineVolume() const{
    return engineVolume;
}

void Detail::setEngineVolume(double new_val) {
    engineVolume = new_val;
}

qint32 Detail::getEnginePower() const {
    return enginePower;
}

void Detail::setEnginePower(qint32 new_val) {
    enginePower = new_val;
}

RubberTypes Detail::getWheelRubber() const{
    return wheelRubber;
}

void Detail::setWheelRubber(RubberTypes new_val) {
    wheelRubber = new_val;
}

DetailTypes Detail::getDetailType() const {
    return detailType;
}

void Detail::setDetailType(DetailTypes new_val){
    detailType = new_val;
}

qint32 Detail::getCandleSize() const{
    return candleSize;
}

void Detail::setCandleSize(qint32 new_val){
    candleSize = new_val;
}

CandleTypes Detail::getCandleType() const{
    return candleType;
}

void Detail::setCandleType(CandleTypes new_val){
    candleType = new_val;
}

CarburetorTypes Detail::getCarburetorType() const{
    return carburetorType;
}

void Detail::setCarburetorType(CarburetorTypes new_val){
    carburetorType = new_val;
}

CaliperTypes Detail::getCaliperType() const{
    return caliperType;
}

void Detail::setCaliperType(CaliperTypes new_val){
    caliperType = new_val;
}

BrakeDiscsTypes Detail::getBrakeDiscsType() const{
    return brakeDiscsType;
}

void Detail::setBrakeDiscsType(BrakeDiscsTypes new_val){
    brakeDiscsType = new_val;
}

BrakeDiscsTypesOfMaterial Detail::getBrakeDiscsTypeOfMaterial() const{
    return brakeDiscsTypeOfMaterial;
}

void Detail::setBrakeDiscsTypeOfMaterial(BrakeDiscsTypesOfMaterial new_val){
    brakeDiscsTypeOfMaterial = new_val;
}

qint32 Detail::getHeatNumber() const{
    return heatNumber;
}

void Detail::setHeatNumber(qint32 new_val){
    heatNumber = new_val;
}

qint32 Detail::getWheelRubberRadius() const{
    return wheelRubberRadius;
}

void Detail::setWheelRubberRadius(qint32 new_val){
    wheelRubberRadius = new_val;
}

qint32 Detail::getWheelDiskRadius() const{
    return wheelDiskRadius;
}

void Detail::setWheelDiskRadius(qint32 new_val){
    wheelDiskRadius = new_val;
}

double Detail::getPrice() const
{
    return price;
}

void Detail::setPrice(double new_val)
{
    price = new_val;
}

QJsonObject Detail::toJson() const
{
    QJsonObject res;
    res.insert("detailType", detailTypeToString(detailType));
    res.insert("nameManufacturer", nameManufacturer);
    res.insert("engineVolume", engineVolume);
    res.insert("enginePower", enginePower);
    res.insert("wheelRubber", rubberTypeToString(wheelRubber));
    res.insert("candleSize", candleSize);
    res.insert("candleType", candleTypeToString(candleType));
    res.insert("carburetorType", carburetorTypeToString(carburetorType));
    res.insert("caliperType", caliperTypeToString(caliperType));
    res.insert("brakeDiscsType", brakeDiscsTypeToString(brakeDiscsType));
    res.insert("brakeDiscsTypeOfMaterial", brakeDiscsTypesOfMaterialToString(brakeDiscsTypeOfMaterial));
    res.insert("heatNumber", heatNumber);
    res.insert("wheelRubberRadius", wheelRubberRadius);
    res.insert("wheelDiskRadius", wheelDiskRadius);
    res.insert("price", price);

    return res;
}

QString Detail::detailTypeToString(DetailTypes type)
{
    switch (type)
    {
    case (undefined_detailType):
        return "undefined";
    case (detail_engine):
        return "engine";
    case (detail_wheelRubber):
        return "tire";
    case (detail_wheelDisk):
        return "wheel disk";
    case (detail_candle):
        return "candle";
    case (detail_carburetor):
        return "carburetor";
    case (detail_caliper):
        return "caliper";
    case (detail_brakeDiscs):
        return "brake discs";
    }
    return "undefined";
}

DetailTypes Detail::stringToDetailType(const QString &str)
{
    if (str == "engine")
        return DetailTypes::detail_engine;
    if (str == "tire")
        return DetailTypes::detail_wheelRubber;
    if (str == "wheel disk")
        return DetailTypes::detail_wheelDisk;
    if (str == "candle")
        return DetailTypes::detail_candle;
    if (str == "carburetor")
        return DetailTypes::detail_carburetor;
    if (str == "caliper")
        return DetailTypes::detail_caliper;
    if (str == "brake discs")
        return DetailTypes::detail_brakeDiscs;
    return DetailTypes::undefined_detailType;
}

QString Detail::rubberTypeToString(RubberTypes type)
{
    switch (type)
    {
    case (RubberTypes::winter_tires):
        return "winter";
    case (RubberTypes::summer_tires):
        return "summer";
    case (RubberTypes::undefined_rubberType):
        return "undefined";
    }
    return "undefined";
}

RubberTypes Detail::stringToRubberType(const QString &str)
{
    if (str == "winter")
        return RubberTypes::winter_tires;
    if (str == "summer")
        return RubberTypes::summer_tires;
    return RubberTypes::undefined_rubberType;
}

QString Detail::candleTypeToString(CandleTypes type)
{
    switch(type)
    {
    case (CandleTypes::candle_singleElectrode):
        return "single electrode";
    case (CandleTypes::candle_multieElectrode):
        return "multie electrode";
    case (CandleTypes::candle_special):
        return "special";
    case (CandleTypes::candle_torch):
        return "torch";
    case (CandleTypes::candle_plasmaPrechamber):
        return "plasma prechamber";
    case (CandleTypes::undefined_candleType):
        return "undefined";
    }
    return "undefined";
}

CandleTypes Detail::stringToCandleType(const QString& str)
{
    if (str == "single electrode")
        return CandleTypes::candle_singleElectrode;
    if (str == "multie electrode")
        return CandleTypes::candle_multieElectrode;
    if (str == "special")
        return CandleTypes::candle_special;
    if (str == "torch")
        return CandleTypes::candle_torch;
    if (str == "plasma prechamber")
        return CandleTypes::candle_plasmaPrechamber;
    return CandleTypes::undefined_candleType;
}

QString Detail::carburetorTypeToString(CarburetorTypes type)
{
    switch(type)
    {
    case (CarburetorTypes::carburetor_bubbling):
        return "bubbling";
    case (CarburetorTypes::carburetor_wick):
        return "wick";
    case (CarburetorTypes::carburetor_membraneNeedle):
        return "membrane needle";
    case (CarburetorTypes::carburetor_float):
        return "float";
    case (CarburetorTypes::undefined_carburetorType):
        return "undefined";
    }
    return "undefined";
}

CarburetorTypes Detail::stringToCarburetorType(const QString &str)
{
    if (str == "bubbling")
        return CarburetorTypes::carburetor_bubbling;
    if (str == "wick")
        return CarburetorTypes::carburetor_wick;
    if (str == "membrane needle")
        return CarburetorTypes::carburetor_membraneNeedle;
    if (str == "float")
        return CarburetorTypes::carburetor_float;
    return CarburetorTypes::undefined_carburetorType;
}

QString Detail::caliperTypeToString(CaliperTypes type)
{
    switch(type)
    {
    case (CaliperTypes::caliper_floating):
        return "floating";
    case (CaliperTypes::caliper_fixed):
        return "fixed";
    case (CaliperTypes::undefined_caliperType):
        return "undefined";
    }
    return "undefined";
}

CaliperTypes Detail::stringToCaliperType(const QString &str)
{
    if (str == "floating")
        return CaliperTypes::caliper_floating;
    if (str == "fixed")
        return CaliperTypes::caliper_fixed;
    return CaliperTypes::undefined_caliperType;
}

QString Detail::brakeDiscsTypeToString(BrakeDiscsTypes type)
{
    switch(type)
    {
    case (BrakeDiscsTypes::brakeDiscs_solid):
        return "solid";
    case (BrakeDiscsTypes::brakeDiscs_ventilated):
        return "ventilated";
    case (BrakeDiscsTypes::brakeDiscs_composite):
        return "composite";
    case (BrakeDiscsTypes::undefined_brakeDiscsType):
        return "undefined";
    }
    return "undefined";
}

BrakeDiscsTypes Detail::stringToBrakeDiscsType(const QString &str)
{
    if (str == "solid")
        return BrakeDiscsTypes::brakeDiscs_solid;
    if (str == "ventilated")
        return BrakeDiscsTypes::brakeDiscs_ventilated;
    if (str == "composite")
        return BrakeDiscsTypes::brakeDiscs_composite;
    return BrakeDiscsTypes::undefined_brakeDiscsType;
}

QString Detail::brakeDiscsTypesOfMaterialToString(BrakeDiscsTypesOfMaterial type)
{
    switch(type)
    {
    case (BrakeDiscsTypesOfMaterial::brakeDiscsMat_metal):
        return "metal";
    case (BrakeDiscsTypesOfMaterial::brakeDiscsMat_ceramic):
        return "ceramic";
    case (BrakeDiscsTypesOfMaterial::undefined_brakeDiscsTypeOfMaterial):
        return "undefined";
    }
    return "undefined";
}

BrakeDiscsTypesOfMaterial Detail::stringToBrakeDiscsTypesOfMaterial(const QString &str)
{
    if (str == "metal")
        return BrakeDiscsTypesOfMaterial::brakeDiscsMat_metal;
    if (str == "ceramic")
        return BrakeDiscsTypesOfMaterial::brakeDiscsMat_ceramic;
    return BrakeDiscsTypesOfMaterial::undefined_brakeDiscsTypeOfMaterial;
}
