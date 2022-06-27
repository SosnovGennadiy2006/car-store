#include "buyproductwindow.h"

BuyProductWindow::BuyProductWindow(QWidget* parent) : QDialog{parent}
{
    this->setMinimumSize(700, 400);
    this->setWindowTitle("View product");

    product = Product();

    QFont normalFont;
    normalFont.setPixelSize(16);

    mainLayout = new QVBoxLayout();
    this->setLayout(mainLayout);

    mainArea = new QScrollArea(this);
    mainArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainArea->setWidgetResizable(true);
    mainArea->setStyleSheet("QScrollArea {border: 1px solid #222;}");

    productInfoWidget = new QWidget(this);
    productInfoLayout = new QVBoxLayout(productInfoWidget);

    idWidget = new InfoWidget(productInfoWidget);
    idWidget->setName("Product ID:");
    idWidget->setInfo("");

    vendorIdWidget = new InfoWidget(productInfoWidget);
    vendorIdWidget->setName("Vendor ID:");
    vendorIdWidget->setInfo("");

    productTypeWidget = new InfoWidget(productInfoWidget);
    productTypeWidget->setName("Product type:");
    productTypeWidget->setInfo("");

    amountOfCarsWidget = new InfoWidget(productInfoWidget);
    amountOfCarsWidget->setName("Amount of cars:");
    amountOfCarsWidget->setInfo("");

    amountOfDetailsWidget = new InfoWidget(productInfoWidget);
    amountOfDetailsWidget->setName("Amount of details:");
    amountOfDetailsWidget->setInfo("");

    amountWidget = new InfoWidget(productInfoWidget);
    amountWidget->setName("Amount:");
    amountWidget->setInfo("");

    priceWidget = new InfoWidget(productInfoWidget);
    priceWidget->setName("Price:");
    priceWidget->setInfo("");

    areaSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    productInfoLayout->addWidget(idWidget);
    productInfoLayout->addWidget(vendorIdWidget);
    productInfoLayout->addWidget(productTypeWidget);
    productInfoLayout->addWidget(amountOfCarsWidget);
    productInfoLayout->addWidget(amountOfDetailsWidget);
    productInfoLayout->addWidget(amountWidget);
    productInfoLayout->addWidget(priceWidget);
    productInfoLayout->addItem(areaSpacer);

    mainArea->setWidget(productInfoWidget);

    buyButtonWidget = new QWidget(this);
    buyButtonLayout = new QHBoxLayout(buyButtonWidget);
    buyButton = new QPushButton(buyButtonWidget);
    buyButton->setText("Buy");
    buyButton->setStyleSheet("border: 1px solid #222; padding: 10px 20px;");
    buyButton->setFont(normalFont);
    buyButton->setCursor(Qt::CursorShape::PointingHandCursor);
    buyButton->setDisabled(true);
    cancelButton = new QPushButton(buyButtonWidget);
    cancelButton->setText("Cancel");
    cancelButton->setStyleSheet("border: 1px solid #222; padding: 10px 20px;");
    cancelButton->setFont(normalFont);
    cancelButton->setCursor(Qt::CursorShape::PointingHandCursor);
    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buyButtonLayout->addItem(spacer);
    buyButtonLayout->addWidget(buyButton);
    buyButtonLayout->addWidget(cancelButton);

    mainLayout->addWidget(mainArea, 100);
    mainLayout->addWidget(buyButtonWidget);

    connect(buyButton, &QPushButton::clicked, this, [this](){ emit buyButtonClicked(); });
    connect(cancelButton, &QPushButton::clicked, this, [this](){ hide(); });
}

Product BuyProductWindow::getProduct() const
{
    return product;
}

void BuyProductWindow::setProduct(const Product& newProduct)
{
    product = newProduct;
    idWidget->setInfo(QString::number(product.getProductID()));
    vendorIdWidget->setInfo(QString::number(product.getVendorID()));
    productTypeWidget->setInfo(Product::productTypeToString(product.getProductType()));
    amountOfCarsWidget->setInfo(QString::number(product.getCars().size()));
    amountOfDetailsWidget->setInfo(QString::number(product.getDetails().size()));
    amountWidget->setInfo(QString::number(product.getAmount()));
    priceWidget->setInfo(QString::number(product.getPrice()));

    if (product.getAmount() == 0)
    {
        buyButton->setDisabled(true);
    }else
    {
        buyButton->setDisabled(false);
    }
}
