#include "addcarwindow.h"

AddCarWindow::AddCarWindow(QWidget* parent) : QDialog(parent)
{
    newCar = Car();

    QFont bigFont;
    bigFont.setPixelSize(24);
    QFont normalFont;
    normalFont.setPixelSize(16);

    this->setFixedSize(400, 500);
    this->setFont(normalFont);
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    this->setWindowTitle("Add car");

    mainLayout = new QVBoxLayout(this);
    mainLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);

    mainArea = new QScrollArea(this);
    mainArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainArea->setWidgetResizable(true);

    mainWidget = new QWidget(this);
    mainWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    areaLayout = new QVBoxLayout(mainWidget);

    infoLabel = new QLabel(mainWidget);
    infoLabel->setText("New car info:");
    infoLabel->setFont(bigFont);
    infoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

    nameWidget = new LayoutLineEdit(mainWidget);
    nameWidget->setPlaceholder("name");
    nameWidget->setLabelText("Name:");
    nameWidget->setFont(normalFont);
    nameWidget->setLineEditMinWidth(150);

    markWidget = new LayoutLineEdit(mainWidget);
    markWidget->setPlaceholder("mark");
    markWidget->setLabelText("Mark:");
    markWidget->setFont(normalFont);
    markWidget->setLineEditMinWidth(150);

    bodyTypeWidget = new LayoutComboBox(mainWidget);
    bodyTypeWidget->setLabelText("Body type:");
    bodyTypeWidget->addItem("Not selected");
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::sedan));
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::coupe));
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::sedan));
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::hatchback));
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::liftback));
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::station_wagon));
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::minivan));
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::SUV));
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::pickup));
    bodyTypeWidget->addItem(Car::bodyTypeToString(BodyTypes::van));
    bodyTypeWidget->setIndex(0);
    bodyTypeWidget->setFont(normalFont);
    bodyTypeWidget->setLineEditMinWidth(150);

    transmissionWidget = new LayoutComboBox(mainWidget);
    transmissionWidget->setLabelText("Transmission:");
    transmissionWidget->addItem("Not selected");
    transmissionWidget->addItem(Car::transmissionTypeToString(TransmissionTypes::automatic));
    transmissionWidget->addItem(Car::transmissionTypeToString(TransmissionTypes::mechanical));
    transmissionWidget->addItem(Car::transmissionTypeToString(TransmissionTypes::robotic));
    transmissionWidget->addItem(Car::transmissionTypeToString(TransmissionTypes::stepless));
    transmissionWidget->setIndex(0);
    transmissionWidget->setFont(normalFont);
    transmissionWidget->setLineEditMinWidth(150);

    driveUnitWidget = new LayoutComboBox(mainWidget);
    driveUnitWidget->setLabelText("Drive unit:");
    driveUnitWidget->addItem("Not selected");
    driveUnitWidget->addItem(Car::driveUnitTypeToString(DriveUnitTypes::rear));
    driveUnitWidget->addItem(Car::driveUnitTypeToString(DriveUnitTypes::front));
    driveUnitWidget->addItem(Car::driveUnitTypeToString(DriveUnitTypes::all));
    driveUnitWidget->setIndex(0);
    driveUnitWidget->setFont(normalFont);
    driveUnitWidget->setLineEditMinWidth(150);

    priceWidget = new LayoutSpinBox(mainWidget);
    priceWidget->setLabelText("Price:");
    priceWidget->setSuffix("$");
    priceWidget->setValue(0);
    priceWidget->setMinimum(0);
    priceWidget->setMaximum(10000000);
    priceWidget->setFont(normalFont);
    priceWidget->setLineEditMinWidth(150);

    areaSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    areaLayout->addWidget(infoLabel);
    areaLayout->addWidget(nameWidget);
    areaLayout->addWidget(markWidget);
    areaLayout->addWidget(bodyTypeWidget);
    areaLayout->addWidget(transmissionWidget);
    areaLayout->addWidget(driveUnitWidget);
    areaLayout->addWidget(priceWidget);
    areaLayout->addItem(areaSpacer);

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

    connect(saveButton, &QPushButton::clicked, this, &AddCarWindow::onSaveButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddCarWindow::onCancelButtonClicked);

    // on changed
    connect(nameWidget, &LayoutLineEdit::changed, this, &AddCarWindow::onChanged);
    connect(markWidget, &LayoutLineEdit::changed, this, &AddCarWindow::onChanged);
    connect(bodyTypeWidget, &LayoutComboBox::changed, this, &AddCarWindow::onChanged);
    connect(transmissionWidget, &LayoutComboBox::changed, this, &AddCarWindow::onChanged);
    connect(driveUnitWidget, &LayoutComboBox::changed, this, &AddCarWindow::onChanged);
    connect(priceWidget, &LayoutSpinBox::changed, this, &AddCarWindow::onChanged);
}

void AddCarWindow::alert(QString message)
{
    QMessageBox::warning(this, "Warning!", message);
}

void AddCarWindow::info(QString message)
{
    QMessageBox::information(this, "Info", message);
}

Car AddCarWindow::getCar() const
{
    return newCar;
}

void AddCarWindow::setCar(const Car &_car)
{
    newCar = _car;
}

void AddCarWindow::onSaveButtonClicked()
{
    Car result;
    result.set_name(nameWidget->getText());
    result.set_mark(markWidget->getText());
    result.set_body_type(Car::stringToBodyType(bodyTypeWidget->getText()));
    result.set_transmission(Car::stringToTransmissionType(transmissionWidget->getText()));
    result.set_drive_unit(Car::stringToDriveUnitTypes(driveUnitWidget->getText()));
    result.set_price(priceWidget->getValue());

    emit carSaved(result);

    this->hide();
}

void AddCarWindow::onCancelButtonClicked()
{
    this->hide();
}

void AddCarWindow::onChanged()
{
    bool flag = true;

    if (bodyTypeWidget->getIndex() == 0)
    {
        flag = false;
    }

    if (transmissionWidget->getIndex() == 0)
    {
        flag = false;
    }

    if (driveUnitWidget->getIndex() == 0)
    {
        flag = false;
    }

    if (nameWidget->getText() == "" || markWidget->getText() == "")
        flag = false;

    if (Car::stringToBodyType(bodyTypeWidget->getText()) == newCar.get_body_type() &&
            Car::stringToTransmissionType(transmissionWidget->getText()) == newCar.get_transmission() &&
            Car::stringToDriveUnitTypes(driveUnitWidget->getText()) == newCar.get_drive_unit() &&
            nameWidget->getText() == newCar.get_name() && markWidget->getText() == newCar.get_mark() &&
            priceWidget->getValue() == newCar.get_price())
        flag = false;

    saveButton->setDisabled(!flag);
}

