#include "addproductwindow.h"

AddProductWindow::AddProductWindow(QWidget* parent) : QDialog(parent)
{
    newProduct = Product();

    QFont normalFont;
    normalFont.setPixelSize(16);
    QFont boldFont;
    normalFont.setPixelSize(16);
    boldFont.setBold(true);

    this->setFixedSize(600, 500);
    this->setFont(normalFont);
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    this->setWindowTitle("Add product");

    mainLayout = new QVBoxLayout(this);
    mainLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);

    mainArea = new QScrollArea(this);
    mainArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainArea->setWidgetResizable(true);

    mainWidget = new QWidget(this);
    mainWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    areaLayout = new QVBoxLayout(mainWidget);

    detailsWidget = new QWidget(mainWidget);
    detailsWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    detailsLayout = new QVBoxLayout(detailsWidget);

    detailsInfoWidget = new QWidget(detailsWidget);
    detailsInfoLayout = new QHBoxLayout(detailsInfoWidget);
    detailsInfoLayout->setContentsMargins(0, 0, 0, 0);
    detailsInfoLabel = new QLabel(detailsInfoWidget);
    detailsInfoLabel->setText("Total details: ");
    detailsInfoLabel->setFont(normalFont);
    detailsInfoLabel_counter = new QLabel(detailsInfoWidget);
    detailsInfoLabel_counter->setText(QString::number(newProduct.getDetails().size()));
    detailsInfoLabel_counter->setFont(normalFont);
    detailsInfoSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    addDetailButton = new QPushButton(detailsInfoWidget);
    addDetailButton->setIcon(QIcon(":/icons/add_icon"));
    addDetailButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    addDetailButton->setStyleSheet("border: 1px solid #222; padding: 3px;");

    detailsInfoLayout->addWidget(detailsInfoLabel);
    detailsInfoLayout->addWidget(detailsInfoLabel_counter);
    detailsInfoLayout->addItem(detailsInfoSpacer);
    detailsInfoLayout->addWidget(addDetailButton);

    hLine1 = new Line(detailsWidget);
    hLine1->setFixedHeight(2);
    hLine1->setStyleSheet("background: #f0f0f0;");

    ifDetailsEmptyLabel = new QLabel(detailsWidget);
    ifDetailsEmptyLabel->setStyleSheet("color: #e53935;");
    ifDetailsEmptyLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
    ifDetailsEmptyLabel->setText("There is nothing to show, you can add details!");
    ifDetailsEmptyLabel->setFont(normalFont);

    detailsListWidget = new QWidget(detailsWidget);
    detailsListWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    detailsListTable = new QGridLayout(detailsListWidget);
    detailsListTable->setRowStretch(0, 0);

    QLabel* detailsTypeLabel = new QLabel(detailsListWidget);
    detailsTypeLabel->setText("Type");
    detailsTypeLabel->setFont(boldFont);
    detailsTypeLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* detailNameLabel = new QLabel(detailsListWidget);
    detailNameLabel->setText("Name");
    detailNameLabel->setFont(boldFont);
    detailNameLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* detailNameManufacturerMarkLabel = new QLabel(detailsListWidget);
    detailNameManufacturerMarkLabel->setText("Manufacturer");
    detailNameManufacturerMarkLabel->setFont(boldFont);
    detailNameManufacturerMarkLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* detailPriceLabel = new QLabel(detailsListWidget);
    detailPriceLabel->setText("Price");
    detailPriceLabel->setFont(boldFont);
    detailPriceLabel->setContentsMargins(3, 3, 3, 3);

    detailsListTable->addWidget(new Line(), 0, 0, 1, 9);
    detailsListTable->addWidget(new VLine(), 1, 0, 1, 1);
    detailsListTable->addWidget(detailsTypeLabel, 1, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    detailsListTable->addWidget(new VLine(), 1, 2, 1, 1);
    detailsListTable->addWidget(detailNameLabel, 1, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    detailsListTable->addWidget(new VLine(), 1, 4, 1, 1);
    detailsListTable->addWidget(detailNameManufacturerMarkLabel, 1, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    detailsListTable->addWidget(new VLine(), 1, 6, 1, 1);
    detailsListTable->addWidget(detailPriceLabel, 1, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    detailsListTable->addWidget(new VLine(), 1, 8, 1, 1);
    detailsListTable->addWidget(new Line(), 2, 0, 1, 9);
    detailsListTable->setSpacing(0);
    detailsListTable->setContentsMargins(0, 0, 0, 0);

    QVector<Detail> details = newProduct.getDetails();
    for (qsizetype i = 0; i < details.size(); i++)
    {
        addDetail(details[i]);
    }

    detailsLayout->addWidget(detailsInfoWidget);
    detailsLayout->addWidget(hLine1);
    detailsLayout->addWidget(ifDetailsEmptyLabel);
    detailsLayout->addWidget(detailsListWidget);
    detailsLayout->setContentsMargins(0, 0, 0, 0);

    detailsListWidget->hide();

    carsWidget = new QWidget(mainWidget);
    carsWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    carsLayout = new QVBoxLayout(carsWidget);

    carsInfoWidget = new QWidget(carsWidget);
    carsInfoLayout = new QHBoxLayout(carsInfoWidget);
    carsInfoLayout->setContentsMargins(0, 0, 0, 0);
    carsInfoLabel = new QLabel(carsInfoWidget);
    carsInfoLabel->setText("Total cars: ");
    carsInfoLabel->setFont(normalFont);
    carsInfoLabel_counter = new QLabel(carsInfoWidget);
    carsInfoLabel_counter->setText(QString::number(newProduct.getCars().size()));
    carsInfoLabel_counter->setFont(normalFont);
    carsInfoSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    addCarButton = new QPushButton(carsInfoWidget);
    addCarButton->setIcon(QIcon(":/icons/add_icon"));
    addCarButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    addCarButton->setStyleSheet("border: 1px solid #222; padding: 3px;");

    carsInfoLayout->addWidget(carsInfoLabel);
    carsInfoLayout->addWidget(carsInfoLabel_counter);
    carsInfoLayout->addItem(carsInfoSpacer);
    carsInfoLayout->addWidget(addCarButton);

    hLine2 = new Line(carsWidget);
    hLine2->setFixedHeight(2);
    hLine2->setStyleSheet("background: #f0f0f0;");

    ifCarsEmptyLabel = new QLabel(carsWidget);
    ifCarsEmptyLabel->setStyleSheet("color: #e53935;");
    ifCarsEmptyLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
    ifCarsEmptyLabel->setText("There is nothing to show, you can add cars!");
    ifCarsEmptyLabel->setFont(normalFont);

    carsListWidget = new QWidget(carsWidget);
    carsListWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    carsListTable = new QGridLayout(carsListWidget);
    carsListTable->setRowStretch(0, 0);

    QLabel* carNameLabel = new QLabel(carsListWidget);
    carNameLabel->setText("Name");
    carNameLabel->setFont(boldFont);
    carNameLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carMarkLabel = new QLabel(carsListWidget);
    carMarkLabel->setText("Mark");
    carMarkLabel->setFont(boldFont);
    carMarkLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carBodyTypeLabel = new QLabel(carsListWidget);
    carBodyTypeLabel->setText("Body type");
    carBodyTypeLabel->setFont(boldFont);
    carBodyTypeLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carTransmissionLabel = new QLabel(carsListWidget);
    carTransmissionLabel->setText("Transmission");
    carTransmissionLabel->setFont(boldFont);
    carTransmissionLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carDriveUnitLabel = new QLabel(carsListWidget);
    carDriveUnitLabel->setText("Drive unit");
    carDriveUnitLabel->setFont(boldFont);
    carDriveUnitLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carPriceLabel = new QLabel(carsListWidget);
    carPriceLabel->setText("Price");
    carPriceLabel->setFont(boldFont);
    carPriceLabel->setContentsMargins(3, 3, 3, 3);

    carsListTable->addWidget(new Line(), 0, 0, 1, 13);
    carsListTable->addWidget(new VLine(), 1, 0, 1, 1);
    carsListTable->addWidget(carNameLabel, 1, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), 1, 2, 1, 1);
    carsListTable->addWidget(carMarkLabel, 1, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), 1, 4, 1, 1);
    carsListTable->addWidget(carBodyTypeLabel, 1, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), 1, 6, 1, 1);
    carsListTable->addWidget(carTransmissionLabel, 1, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), 1, 8, 1, 1);
    carsListTable->addWidget(carDriveUnitLabel, 1, 9, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), 1, 10, 1, 1);
    carsListTable->addWidget(carPriceLabel, 1, 11, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), 1, 12, 1, 1);
    carsListTable->addWidget(new Line(), 2, 0, 1, 13);
    carsListTable->setSpacing(0);
    carsListTable->setContentsMargins(0, 0, 0, 0);

    QVector<Car> cars = newProduct.getCars();
    for (qsizetype i = 0; i < cars.size(); i++)
    {
        addCar(cars[i]);
    }

    carsLayout->addWidget(carsInfoWidget);
    carsLayout->addWidget(hLine2);
    carsLayout->addWidget(ifCarsEmptyLabel);
    carsLayout->addWidget(carsListWidget);
    carsLayout->setContentsMargins(0, 0, 0, 0);

    carsListWidget->hide();

    areaSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    areaLayout->addWidget(detailsWidget);
    areaLayout->addWidget(carsWidget);
    areaLayout->addItem(areaSpacer);

    mainArea->setWidget(mainWidget);
    mainArea->setStyleSheet("border: 1px solid #888;");

    amountSpinBoxLayout = new LayoutSpinBox(this);
    amountSpinBoxLayout->setMinimum(0);
    amountSpinBoxLayout->setMaximum(100);
    amountSpinBoxLayout->setValue(0);
    amountSpinBoxLayout->setLabelText("Amount:");
    amountSpinBoxLayout->setFont(normalFont);
    amountSpinBoxLayout->setLineEditMinWidth(100);

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
    mainLayout->addWidget(amountSpinBoxLayout);
    mainLayout->addWidget(buttonsWidget);

    setLayout(mainLayout);

    connect(saveButton, &QPushButton::clicked, this, &AddProductWindow::onSaveButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddProductWindow::onCancelButtonClicked);
    connect(addDetailButton, &QPushButton::clicked, this, &AddProductWindow::onAddDetailButtonClicked);
    connect(addCarButton, &QPushButton::clicked, this, &AddProductWindow::onAddCarButtonClicked);
}

void AddProductWindow::alert(QString message)
{
    QMessageBox::warning(this, "Warning!", message);
}

void AddProductWindow::info(QString message)
{
    QMessageBox::information(this, "Info", message);
}

void AddProductWindow::setupDetailsList()
{
    if (newProduct.getDetails().size() == 0)
    {
        ifDetailsEmptyLabel->show();
        detailsListWidget->hide();
        saveButton->setDisabled(true);
    }else
    {
        ifDetailsEmptyLabel->hide();
        detailsListWidget->show();
        saveButton->setDisabled(false);
    }
}

void AddProductWindow::setupCarsList()
{
    if (newProduct.getCars().size() == 0)
    {
        ifCarsEmptyLabel->show();
        carsListWidget->hide();
        saveButton->setDisabled(true);
    }else
    {
        ifCarsEmptyLabel->hide();
        carsListWidget->show();
        saveButton->setDisabled(false);
    }
}

void AddProductWindow::addCar(const Car& carToAdd)
{
    carsInfoLabel_counter->setText(QString::number(newProduct.getCars().size()));
    int i = carsListTable->rowCount();

    QFont normalFont;
    normalFont.setPixelSize(16);

    QLabel* carNameLabel = new QLabel(carsListWidget);
    carNameLabel->setText(carToAdd.get_name());
    carNameLabel->setFont(normalFont);
    carNameLabel->setStyleSheet("border: none;");
    carNameLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carMarkLabel = new QLabel(carsListWidget);
    carMarkLabel->setText(carToAdd.get_mark());
    carMarkLabel->setFont(normalFont);
    carMarkLabel->setStyleSheet("border: none;");
    carMarkLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carBodyTypeLabel = new QLabel(carsListWidget);
    carBodyTypeLabel->setText(Car::bodyTypeToString(carToAdd.get_body_type()));
    carBodyTypeLabel->setFont(normalFont);
    carBodyTypeLabel->setStyleSheet("border: none;");
    carBodyTypeLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carTransmissionLabel = new QLabel(carsListWidget);
    carTransmissionLabel->setText(Car::transmissionTypeToString(carToAdd.get_transmission()));
    carTransmissionLabel->setFont(normalFont);
    carTransmissionLabel->setStyleSheet("border: none;");
    carTransmissionLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carDriveUnitLabel = new QLabel(carsListWidget);
    carDriveUnitLabel->setText(Car::driveUnitTypeToString(carToAdd.get_drive_unit()));
    carDriveUnitLabel->setFont(normalFont);
    carDriveUnitLabel->setStyleSheet("border: none;");
    carDriveUnitLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* carPriceLabel = new QLabel(carsListWidget);
    carPriceLabel->setText(QString::number(carToAdd.get_price()));
    carPriceLabel->setFont(normalFont);
    carPriceLabel->setStyleSheet("border: none;");
    carPriceLabel->setContentsMargins(3, 3, 3, 3);

    carsListTable->addWidget(new VLine(), i, 0, 1, 1);
    carsListTable->addWidget(carNameLabel, i, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), i, 2, 1, 1);
    carsListTable->addWidget(carMarkLabel, i, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), i, 4, 1, 1);
    carsListTable->addWidget(carBodyTypeLabel, i, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), i, 6, 1, 1);
    carsListTable->addWidget(carTransmissionLabel, i, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), i, 8, 1, 1);
    carsListTable->addWidget(carDriveUnitLabel, i, 9, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), i, 10, 1, 1);
    carsListTable->addWidget(carPriceLabel, i, 11, 1, 1, Qt::AlignmentFlag::AlignCenter);
    carsListTable->addWidget(new VLine(), i, 12, 1, 1);
    carsListTable->addWidget(new Line(), i+1, 0, 1, 13);
}

void AddProductWindow::addDetail(const Detail &detailToAdd)
{
    detailsInfoLabel_counter->setText(QString::number(newProduct.getDetails().size()));
    int i = detailsListTable->rowCount();

    QFont normalFont;
    normalFont.setPixelSize(16);

    QLabel* detailsTypeLabel = new QLabel(detailsListWidget);
    detailsTypeLabel->setText(Detail::detailTypeToString(detailToAdd.getDetailType()));
    detailsTypeLabel->setFont(normalFont);
    detailsTypeLabel->setStyleSheet("border: none;");
    detailsTypeLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* detailNameLabel = new QLabel(detailsListWidget);
    detailNameLabel->setText(detailToAdd.getName());
    detailNameLabel->setFont(normalFont);
    detailNameLabel->setStyleSheet("border: none;");
    detailNameLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* detailNameManufacturerMarkLabel = new QLabel(detailsListWidget);
    detailNameManufacturerMarkLabel->setText(detailToAdd.getNameManufacturer());
    detailNameManufacturerMarkLabel->setFont(normalFont);
    detailNameManufacturerMarkLabel->setStyleSheet("border: none;");
    detailNameManufacturerMarkLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* detailPriceLabel = new QLabel(detailsListWidget);
    detailPriceLabel->setText(QString::number(detailToAdd.getPrice()));
    detailPriceLabel->setFont(normalFont);
    detailPriceLabel->setStyleSheet("border: none;");
    detailPriceLabel->setContentsMargins(3, 3, 3, 3);

    detailsListTable->addWidget(new VLine(), i, 0, 1, 1);
    detailsListTable->addWidget(detailsTypeLabel, i, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    detailsListTable->addWidget(new VLine(), i, 2, 1, 1);
    detailsListTable->addWidget(detailNameLabel, i, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    detailsListTable->addWidget(new VLine(), i, 4, 1, 1);
    detailsListTable->addWidget(detailNameManufacturerMarkLabel, i, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    detailsListTable->addWidget(new VLine(), i, 6, 1, 1);
    detailsListTable->addWidget(detailPriceLabel, i, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    detailsListTable->addWidget(new VLine(), i, 8, 1, 1);
    detailsListTable->addWidget(new Line(), i+1, 0, 1, 9);
}

Product AddProductWindow::getProduct() const
{
    return newProduct;
}

void AddProductWindow::setProduct(const Product &_product)
{
    newProduct = _product;
    detailsInfoLabel_counter->setText(QString::number(newProduct.getDetails().size()));
    carsInfoLabel_counter->setText(QString::number(newProduct.getCars().size()));

    setupDetailsList();
    setupCarsList();
}

void AddProductWindow::onSaveButtonClicked()
{
    newProduct.setAmount(amountSpinBoxLayout->getValue());

    emit productSaved(newProduct);

    hide();
}

void AddProductWindow::onCancelButtonClicked()
{
    this->hide();
}

void AddProductWindow::onAddDetailButtonClicked()
{
    addDetailModalWindow = new AddDetailWindow(this);
    addDetailModalWindow->setModal(true);
    addDetailModalWindow->setFixedSize(400, 500);
    addDetailModalWindow->show();

    connect(addDetailModalWindow, &AddDetailWindow::detailSaved, this, [this](Detail detailToSave){
        newProduct.addDetail(detailToSave);
        addDetail(detailToSave);
        setupDetailsList();
    });
}

void AddProductWindow::onAddCarButtonClicked()
{
    addCarModalWindow = new AddCarWindow(this);
    addCarModalWindow->setModal(true);
    addCarModalWindow->setFixedSize(400, 500);
    addCarModalWindow->show();

    connect(addCarModalWindow, &AddCarWindow::carSaved, this, [this](Car carToSave){
        newProduct.addCar(carToSave);
        addCar(carToSave);
        setupCarsList();
    });
}
