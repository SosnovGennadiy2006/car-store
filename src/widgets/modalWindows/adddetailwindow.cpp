#include "adddetailwindow.h"

AddDetailWindow::AddDetailWindow(QWidget* parent) : QDialog(parent)
{
    newDetail = Detail();

    QFont bigFont;
    bigFont.setPixelSize(24);
    QFont normalFont;
    normalFont.setPixelSize(16);

    this->setFixedSize(400, 500);
    this->setFont(normalFont);
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    this->setWindowTitle("Add detail");

    mainLayout = new QVBoxLayout(this);
    mainLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);

    mainArea = new QScrollArea(this);
    mainArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainArea->setWidgetResizable(true);

    mainWidget = new QWidget(this);
    mainWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    areaLayout = new QVBoxLayout(mainWidget);

    infoLabel = new QLabel(mainWidget);
    infoLabel->setText("New detail info:");
    infoLabel->setFont(bigFont);
    infoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

    detailTypeWidget = new LayoutComboBox(mainWidget);
    detailTypeWidget->setLabelText("Detail type:");
    detailTypeWidget->setFont(normalFont);
    detailTypeWidget->addItem(Detail::detailTypeToString(DetailTypes::detail_engine));
    detailTypeWidget->addItem(Detail::detailTypeToString(DetailTypes::detail_wheelRubber));
    detailTypeWidget->addItem(Detail::detailTypeToString(DetailTypes::detail_wheelDisk));
    detailTypeWidget->addItem(Detail::detailTypeToString(DetailTypes::detail_candle));
    detailTypeWidget->addItem(Detail::detailTypeToString(DetailTypes::detail_carburetor));
    detailTypeWidget->addItem(Detail::detailTypeToString(DetailTypes::detail_caliper));
    detailTypeWidget->addItem(Detail::detailTypeToString(DetailTypes::detail_brakeDiscs));
    detailTypeWidget->setIndex(0);
    detailTypeWidget->setLineEditMinWidth(150);

    nameWidget = new LayoutLineEdit(mainWidget);
    nameWidget->setLabelText("Name:");
    nameWidget->setFont(normalFont);
    nameWidget->setPlaceholder("name");
    nameWidget->setLineEditMinWidth(150);

    nameManufacturerWidget = new LayoutLineEdit(mainWidget);
    nameManufacturerWidget->setLabelText("Manufacturer:");
    nameManufacturerWidget->setFont(normalFont);
    nameManufacturerWidget->setPlaceholder("manufacturer");
    nameManufacturerWidget->setLineEditMinWidth(150);

    engineVolumeWidget = new LayoutDoubleSpinBox(mainWidget);
    engineVolumeWidget->setLabelText("Engine volume:");
    engineVolumeWidget->setSuffix("cm^3");
    engineVolumeWidget->setFont(normalFont);
    engineVolumeWidget->setValue(200);
    engineVolumeWidget->setMinimum(200);
    engineVolumeWidget->setMaximum(1000);
    engineVolumeWidget->setLineEditMinWidth(150);

    enginePowerWidget = new LayoutDoubleSpinBox(mainWidget);
    enginePowerWidget->setLabelText("Engine power:");
    enginePowerWidget->setSuffix("kW");
    enginePowerWidget->setFont(normalFont);
    enginePowerWidget->setValue(10);
    enginePowerWidget->setMinimum(10);
    enginePowerWidget->setMaximum(1000);
    enginePowerWidget->setLineEditMinWidth(150);

    rubberTypeWidget = new LayoutComboBox(mainWidget);
    rubberTypeWidget->setLabelText("Tire type:");
    rubberTypeWidget->setFont(normalFont);
    rubberTypeWidget->addItem("Not selected");
    rubberTypeWidget->addItem(Detail::rubberTypeToString(RubberTypes::winter_tires));
    rubberTypeWidget->addItem(Detail::rubberTypeToString(RubberTypes::summer_tires));
    rubberTypeWidget->setIndex(0);
    rubberTypeWidget->setLineEditMinWidth(150);

    wheelRubberRadiusWidget = new LayoutDoubleSpinBox(mainWidget);
    wheelRubberRadiusWidget->setLabelText("Tier radius:");
    wheelRubberRadiusWidget->setSuffix("cm");
    wheelRubberRadiusWidget->setFont(normalFont);
    wheelRubberRadiusWidget->setValue(15);
    wheelRubberRadiusWidget->setMinimum(15);
    wheelRubberRadiusWidget->setMaximum(60);
    wheelRubberRadiusWidget->setLineEditMinWidth(150);

    wheelDiskRadiusWidget = new LayoutDoubleSpinBox(mainWidget);
    wheelDiskRadiusWidget->setLabelText("Wheel disk radius:");
    wheelDiskRadiusWidget->setSuffix("cm");
    wheelDiskRadiusWidget->setFont(normalFont);
    wheelDiskRadiusWidget->setValue(15);
    wheelDiskRadiusWidget->setMinimum(15);
    wheelDiskRadiusWidget->setMaximum(60);
    wheelDiskRadiusWidget->setLineEditMinWidth(150);

    candleTypeWidget = new LayoutComboBox(mainWidget);
    candleTypeWidget->setLabelText("Candle type:");
    candleTypeWidget->setFont(normalFont);
    candleTypeWidget->addItem("Not selected");
    candleTypeWidget->addItem(Detail::candleTypeToString(CandleTypes::candle_singleElectrode));
    candleTypeWidget->addItem(Detail::candleTypeToString(CandleTypes::candle_multieElectrode));
    candleTypeWidget->addItem(Detail::candleTypeToString(CandleTypes::candle_special));
    candleTypeWidget->addItem(Detail::candleTypeToString(CandleTypes::candle_torch));
    candleTypeWidget->addItem(Detail::candleTypeToString(CandleTypes::candle_plasmaPrechamber));
    candleTypeWidget->setIndex(0);
    candleTypeWidget->setLineEditMinWidth(150);

    candleSizeWidget = new LayoutSpinBox(mainWidget);
    candleSizeWidget->setLabelText("Candle size:");
    candleSizeWidget->setSuffix("mm");
    candleSizeWidget->setFont(normalFont);
    candleSizeWidget->setValue(10);
    candleSizeWidget->setMinimum(10);
    candleSizeWidget->setMaximum(30);
    candleSizeWidget->setLineEditMinWidth(150);

    heatNumberWidget = new LayoutSpinBox(mainWidget);
    heatNumberWidget->setLabelText("Heat number:");
    heatNumberWidget->setFont(normalFont);
    heatNumberWidget->setValue(10);
    heatNumberWidget->setMinimum(10);
    heatNumberWidget->setMaximum(40);
    heatNumberWidget->setLineEditMinWidth(150);

    carburetorTypeWidget = new LayoutComboBox(mainWidget);
    carburetorTypeWidget->setLabelText("Carburetor type:");
    carburetorTypeWidget->setFont(normalFont);
    carburetorTypeWidget->addItem("Not selected");
    carburetorTypeWidget->addItem(Detail::carburetorTypeToString(CarburetorTypes::carburetor_bubbling));
    carburetorTypeWidget->addItem(Detail::carburetorTypeToString(CarburetorTypes::carburetor_wick));
    carburetorTypeWidget->addItem(Detail::carburetorTypeToString(CarburetorTypes::carburetor_membraneNeedle));
    carburetorTypeWidget->addItem(Detail::carburetorTypeToString(CarburetorTypes::carburetor_float));
    carburetorTypeWidget->setIndex(0);
    carburetorTypeWidget->setLineEditMinWidth(150);

    brakeDiscsTypeWidget = new LayoutComboBox(mainWidget);
    brakeDiscsTypeWidget->setLabelText("Brake discs type:");
    brakeDiscsTypeWidget->setFont(normalFont);
    brakeDiscsTypeWidget->addItem("Not selected");
    brakeDiscsTypeWidget->addItem(Detail::brakeDiscsTypeToString(BrakeDiscsTypes::brakeDiscs_solid));
    brakeDiscsTypeWidget->addItem(Detail::brakeDiscsTypeToString(BrakeDiscsTypes::brakeDiscs_ventilated));
    brakeDiscsTypeWidget->addItem(Detail::brakeDiscsTypeToString(BrakeDiscsTypes::brakeDiscs_composite));
    brakeDiscsTypeWidget->setIndex(0);
    brakeDiscsTypeWidget->setLineEditMinWidth(150);

    brakeDiscsTypeOfMaterialWidget = new LayoutComboBox(mainWidget);
    brakeDiscsTypeOfMaterialWidget->setLabelText("Brake discs material:");
    brakeDiscsTypeOfMaterialWidget->setFont(normalFont);
    brakeDiscsTypeOfMaterialWidget->addItem("Not selected");
    brakeDiscsTypeOfMaterialWidget->addItem(Detail::brakeDiscsTypesOfMaterialToString(BrakeDiscsTypesOfMaterial::brakeDiscsMat_metal));
    brakeDiscsTypeOfMaterialWidget->addItem(Detail::brakeDiscsTypesOfMaterialToString(BrakeDiscsTypesOfMaterial::brakeDiscsMat_ceramic));
    brakeDiscsTypeOfMaterialWidget->setIndex(0);
    brakeDiscsTypeOfMaterialWidget->setLineEditMinWidth(150);

    caliperTypeWidget = new LayoutComboBox(mainWidget);
    caliperTypeWidget->setLabelText("Caliper type:");
    caliperTypeWidget->setFont(normalFont);
    caliperTypeWidget->addItem("Not selected");
    caliperTypeWidget->addItem(Detail::caliperTypeToString(CaliperTypes::caliper_floating));
    caliperTypeWidget->addItem(Detail::caliperTypeToString(CaliperTypes::caliper_fixed));
    caliperTypeWidget->setIndex(0);
    caliperTypeWidget->setLineEditMinWidth(150);

    priceWidget = new LayoutSpinBox(mainWidget);
    priceWidget->setLabelText("Price:");
    priceWidget->setSuffix("$");
    priceWidget->setFont(normalFont);
    priceWidget->setValue(0);
    priceWidget->setMinimum(0);
    priceWidget->setMaximum(10000);
    priceWidget->setLineEditMinWidth(150);

    areaSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    areaLayout->addWidget(infoLabel);
    areaLayout->addWidget(detailTypeWidget);
    areaLayout->addWidget(nameWidget);
    areaLayout->addWidget(nameManufacturerWidget);
    areaLayout->addWidget(engineVolumeWidget);
    areaLayout->addWidget(enginePowerWidget);
    areaLayout->addWidget(rubberTypeWidget);
    areaLayout->addWidget(wheelRubberRadiusWidget);
    areaLayout->addWidget(wheelDiskRadiusWidget);
    areaLayout->addWidget(candleTypeWidget);
    areaLayout->addWidget(candleSizeWidget);
    areaLayout->addWidget(heatNumberWidget);
    areaLayout->addWidget(carburetorTypeWidget);
    areaLayout->addWidget(brakeDiscsTypeWidget);
    areaLayout->addWidget(brakeDiscsTypeOfMaterialWidget);
    areaLayout->addWidget(caliperTypeWidget);
    areaLayout->addWidget(priceWidget);
    areaLayout->addItem(areaSpacer);

    rubberTypeWidget->hide();
    wheelRubberRadiusWidget->hide();
    wheelDiskRadiusWidget->hide();
    candleTypeWidget->hide();
    candleSizeWidget->hide();
    heatNumberWidget->hide();
    carburetorTypeWidget->hide();
    brakeDiscsTypeWidget->hide();
    brakeDiscsTypeOfMaterialWidget->hide();
    caliperTypeWidget->hide();

    mainArea->setWidget(mainWidget);
    mainArea->setStyleSheet("border: 1px solid #888;");

    buttonsWidget = new QWidget(this);
    buttonsWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    buttonsLayout = new QHBoxLayout(buttonsWidget);
    saveButton = new QPushButton(buttonsWidget);
    saveButton->setText("Save");
    saveButton->setStyleSheet("border: 1px solid #222; padding: 5px 10px;");
    saveButton->setCursor(Qt::CursorShape::PointingHandCursor);
    saveButton->setDisabled(true);
    cancelButton = new QPushButton(buttonsWidget);
    cancelButton->setText("Cancel");
    cancelButton->setStyleSheet("border: 1px solid #222; padding: 5px 10px;");
    cancelButton->setCursor(Qt::CursorShape::PointingHandCursor);
    buttonsSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buttonsLayout->addItem(buttonsSpacer);
    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->setContentsMargins(0, 5, 0, 0);

    mainLayout->addWidget(mainArea, 100);
    mainLayout->addWidget(buttonsWidget);

    setLayout(mainLayout);

    widgetsByDetailType = QMap<int, QVector<QWidget*>>();
    widgetsByDetailType[0] = QVector<QWidget*>{engineVolumeWidget, enginePowerWidget};
    widgetsByDetailType[1] = QVector<QWidget*>{rubberTypeWidget, wheelRubberRadiusWidget};
    widgetsByDetailType[2] = QVector<QWidget*>{wheelDiskRadiusWidget};
    widgetsByDetailType[3] = QVector<QWidget*>{candleTypeWidget, candleSizeWidget, heatNumberWidget};
    widgetsByDetailType[4] = QVector<QWidget*>{carburetorTypeWidget};
    widgetsByDetailType[5] = QVector<QWidget*>{caliperTypeWidget};
    widgetsByDetailType[6] = QVector<QWidget*>{brakeDiscsTypeWidget, brakeDiscsTypeOfMaterialWidget};

    connect(saveButton, &QPushButton::clicked, this, &AddDetailWindow::onSaveButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddDetailWindow::onCancelButtonClicked);
    connect(detailTypeWidget, &LayoutComboBox::changed, this, &AddDetailWindow::onDetailTypeChanged);

    connect(nameWidget, &LayoutLineEdit::changed, this, &AddDetailWindow::onChanged);
    connect(nameManufacturerWidget, &LayoutLineEdit::changed, this, &AddDetailWindow::onChanged);
    connect(engineVolumeWidget, &LayoutDoubleSpinBox::changed, this, &AddDetailWindow::onChanged);
    connect(enginePowerWidget, &LayoutDoubleSpinBox::changed, this, &AddDetailWindow::onChanged);
    connect(rubberTypeWidget, &LayoutComboBox::changed, this, &AddDetailWindow::onChanged);
    connect(wheelRubberRadiusWidget, &LayoutDoubleSpinBox::changed, this, &AddDetailWindow::onChanged);
    connect(wheelDiskRadiusWidget, &LayoutDoubleSpinBox::changed, this, &AddDetailWindow::onChanged);
    connect(candleTypeWidget, &LayoutComboBox::changed, this, &AddDetailWindow::onChanged);
    connect(candleSizeWidget, &LayoutSpinBox::changed, this, &AddDetailWindow::onChanged);
    connect(heatNumberWidget, &LayoutSpinBox::changed, this, &AddDetailWindow::onChanged);
    connect(carburetorTypeWidget, &LayoutComboBox::changed, this, &AddDetailWindow::onChanged);
    connect(brakeDiscsTypeWidget, &LayoutComboBox::changed, this, &AddDetailWindow::onChanged);
    connect(brakeDiscsTypeOfMaterialWidget, &LayoutComboBox::changed, this, &AddDetailWindow::onChanged);
    connect(caliperTypeWidget, &LayoutComboBox::changed, this, &AddDetailWindow::onChanged);
    connect(priceWidget, &LayoutSpinBox::changed, this, &AddDetailWindow::onChanged);
}

void AddDetailWindow::alert(QString message)
{
    QMessageBox::warning(this, "Warning!", message);
}

void AddDetailWindow::info(QString message)
{
    QMessageBox::information(this, "Info", message);
}

Detail AddDetailWindow::getDetail() const
{
    return newDetail;
}

void AddDetailWindow::setDetail(const Detail &_detail)
{
    newDetail = _detail;
}

void AddDetailWindow::onSaveButtonClicked()
{
    Detail detailToSave;

    detailToSave.setDetailType(Detail::stringToDetailType(detailTypeWidget->getText()));
    detailToSave.setName(nameWidget->getText());
    detailToSave.setNameManufacturer(nameManufacturerWidget->getText());
    detailToSave.setEngineVolume(engineVolumeWidget->getValue());
    detailToSave.setEnginePower(enginePowerWidget->getValue());
    detailToSave.setWheelRubber(Detail::stringToRubberType(rubberTypeWidget->getText()));
    detailToSave.setWheelRubberRadius(wheelRubberRadiusWidget->getValue());
    detailToSave.setWheelDiskRadius(wheelDiskRadiusWidget->getValue());
    detailToSave.setCandleType(Detail::stringToCandleType(candleTypeWidget->getText()));
    detailToSave.setCandleSize(candleSizeWidget->getValue());
    detailToSave.setHeatNumber(heatNumberWidget->getValue());
    detailToSave.setCarburetorType(Detail::stringToCarburetorType(carburetorTypeWidget->getText()));
    detailToSave.setBrakeDiscsType(Detail::stringToBrakeDiscsType(brakeDiscsTypeWidget->getText()));
    detailToSave.setBrakeDiscsTypeOfMaterial(Detail::stringToBrakeDiscsTypesOfMaterial(brakeDiscsTypeOfMaterialWidget->getText()));
    detailToSave.setCaliperType(Detail::stringToCaliperType(caliperTypeWidget->getText()));
    detailToSave.setPrice(priceWidget->getValue());

    emit detailSaved(detailToSave);

    this->hide();
}

void AddDetailWindow::onCancelButtonClicked()
{
    this->hide();
}

void AddDetailWindow::onDetailTypeChanged()
{
    engineVolumeWidget->setValue(200);
    enginePowerWidget->setValue(10);
    rubberTypeWidget->setIndex(0);
    wheelRubberRadiusWidget->setValue(15);
    wheelDiskRadiusWidget->setValue(15);
    candleTypeWidget->setIndex(0);
    candleSizeWidget->setValue(0);
    heatNumberWidget->setValue(10);
    carburetorTypeWidget->setIndex(0);
    brakeDiscsTypeWidget->setIndex(0);
    brakeDiscsTypeOfMaterialWidget->setIndex(0);
    caliperTypeWidget->setIndex(0);

    engineVolumeWidget->hide();
    enginePowerWidget->hide();
    rubberTypeWidget->hide();
    wheelRubberRadiusWidget->hide();
    wheelDiskRadiusWidget->hide();
    candleTypeWidget->hide();
    candleSizeWidget->hide();
    heatNumberWidget->hide();
    carburetorTypeWidget->hide();
    brakeDiscsTypeWidget->hide();
    brakeDiscsTypeOfMaterialWidget->hide();
    caliperTypeWidget->hide();

    QVector<QWidget*> widgets = widgetsByDetailType[detailTypeWidget->getIndex()];
    for (qsizetype i = 0; i < widgets.size(); i++)
    {
        widgets[i]->show();
    }
    saveButton->setDisabled(true);
}

void AddDetailWindow::onChanged()
{
    bool flag = true, flag2 = true;

    if (nameWidget->getText() == "")
        flag = false;
    if (nameManufacturerWidget->getText() == "")
        flag = false;
    if (priceWidget->getValue() != newDetail.getPrice())
        flag2 = false;
    if (!engineVolumeWidget->isHidden())
    {
        if (engineVolumeWidget->getValue() != newDetail.getEngineVolume())
            flag2 = false;
    }
    if (!enginePowerWidget->isHidden())
    {
        if (enginePowerWidget->getValue() != newDetail.getEnginePower())
            flag2 = false;
    }
    if (!candleSizeWidget->isHidden())
    {
        if (candleSizeWidget->getValue() != newDetail.getCandleSize())
            flag2 = false;
    }
    if (!heatNumberWidget->isHidden())
    {
        if (heatNumberWidget->getValue() != newDetail.getHeatNumber())
            flag2 = false;
    }
    if (!rubberTypeWidget->isHidden())
    {
        if (rubberTypeWidget->getIndex() == 0)
            flag = false;
        if (Detail::stringToRubberType(rubberTypeWidget->getText()) != newDetail.getWheelRubber())
            flag2 = false;
    }
    if (!candleTypeWidget->isHidden())
    {
        if (candleTypeWidget->getIndex() == 0)
            flag = false;
        if (Detail::stringToCandleType(candleTypeWidget->getText()) != newDetail.getCandleType())
            flag2 = false;
    }
    if (!carburetorTypeWidget->isHidden())
    {
        if (carburetorTypeWidget->getIndex() == 0)
            flag = false;
        if (Detail::stringToCarburetorType(carburetorTypeWidget->getText()) != newDetail.getCarburetorType())
            flag2 = false;
    }
    if (!caliperTypeWidget->isHidden())
    {
        if (caliperTypeWidget->getIndex() == 0)
            flag = false;
        if (Detail::stringToCaliperType(caliperTypeWidget->getText()) != newDetail.getCaliperType())
            flag2 = false;
    }
    if (!brakeDiscsTypeWidget->isHidden())
    {
        if (brakeDiscsTypeWidget->getIndex() == 0)
            flag = false;
        if (Detail::stringToBrakeDiscsType(brakeDiscsTypeWidget->getText()) != newDetail.getBrakeDiscsType())
            flag2 = false;
    }
    if (!brakeDiscsTypeOfMaterialWidget->isHidden())
    {
        if (brakeDiscsTypeOfMaterialWidget->getIndex() == 0)
            flag = false;
        if (Detail::stringToBrakeDiscsTypesOfMaterial(brakeDiscsTypeOfMaterialWidget->getText()) != newDetail.getBrakeDiscsTypeOfMaterial())
            flag2 = false;
    }

    if (flag2)
        flag = false;

    saveButton->setDisabled(!flag);
}
