//
// Created by skine on 6/6/2022.
//

#include "detail.h"

detail::detail() {
    nameManufacturer = "";
    engineVolume = -1;
    enginePower = -1;
    wheelRubber = undefined_rubberType;
    detailType = undefined_detailType;
    candleType = undefined_candleType;
    carburetorType = undefined_carburetorType;
    caliperType = undefined_caliperType;
    brakeDiscsType = undefined_brakeDiscsType;
    brakeDiscsTypeOfMaterial = undefined_brakeDiscsTypeOfMaterial;
    heatNumber = -1;
    wheelRubberRadius = -1;
    wheelDiskRadius = -1;
}

std::string detail::getNameManufacturer() const{
    return nameManufacturer;
}
void detail::setNameManufacturer(std::string new_val){
    nameManufacturer = new_val;
}

double detail::getEngineVolume() const{
    return engineVolume;
}
void detail::setEngineVolume(double new_val) {
    engineVolume = new_val;
}

int detail::getEnginePower() const {
    return enginePower;
}
void detail::setEnginePower(int new_val) {
    enginePower = new_val;
}

RubberTypes detail::getWheelRubber() const{
    return wheelRubber;
}
void detail::setWheelRubber(RubberTypes new_val) {
    wheelRubber = new_val;
}

DetailTypes detail::getDetailType() const {
    return detailType;
}
void detail::setDetailType(DetailTypes new_val){
    detailType = new_val;
}

int detail::getCandleSize() const{
    return candleSize;
}
void detail::setCandleSize(int new_val){
    candleSize = new_val;
}

CandleTypes detail::getCandleType() const{
    return candleType;
}
void detail::setCandleType(CandleTypes new_val){
    candleType = new_val;
}

CarburetorTypes detail::getCarburetorType() const{
    return carburetorType;
}
void detail::setCarburetorType(CarburetorTypes new_val){
    carburetorType = new_val;
}

CaliperType detail::getCaliperType() const{
    return caliperType;
}
void detail::setCaliperType(CaliperType new_val){
    caliperType = new_val;
}

BrakeDiscsTypes detail::getBrakeDiscsType() const{
    return brakeDiscsType;
}
void detail::setBrakeDiscsType(BrakeDiscsTypes new_val){
    brakeDiscsType = new_val;
}

BrakeDiscsTypesOfMaterial detail::getBrakeDiscsTypeOfMaterial() const{
    return brakeDiscsTypeOfMaterial;
}
void detail::setBrakeDiscsTypeOfMaterial(BrakeDiscsTypesOfMaterial new_val){
    brakeDiscsTypeOfMaterial = new_val;
}

int detail::getHeatNumber() const{
    return heatNumber;
}
void detail::setHeatNumber(int new_val){
    heatNumber = new_val;
}

int detail::getWheelRubberRadius() const{
    return wheelRubberRadius;
}
void detail::setWheelRubberRadius(int new_val){
    wheelRubberRadius = new_val;
}

int detail::getWheelDiskRadius() const{
    return wheelDiskRadius;
}
void detail::setWheelDiskRadius(int new_val){
    wheelDiskRadius = new_val;
}