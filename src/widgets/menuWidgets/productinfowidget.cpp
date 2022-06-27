#include "productinfowidget.h"

ProductInfoWidget::ProductInfoWidget(QWidget *parent)
    : QFrame{parent}
{
    QFont normalFont;
    normalFont.setPixelSize(16);

    this->setFrameShape(QFrame::Box);
    this->setFrameShadow(QFrame::Plain);
    this->setLineWidth(1);

    mainLayout = new QVBoxLayout(this);

    idWidget = new InfoWidget(this);
    idWidget->setName("Product ID:");
    idWidget->setInfo("");

    vendorIdWidget = new InfoWidget(this);
    vendorIdWidget->setName("Vendor ID:");
    vendorIdWidget->setInfo("");

    productTypeWidget = new InfoWidget(this);
    productTypeWidget->setName("Product type:");
    productTypeWidget->setInfo("");

    amountOfCarsWidget = new InfoWidget(this);
    amountOfCarsWidget->setName("Amount of cars:");
    amountOfCarsWidget->setInfo("");

    amountOfDetailsWidget = new InfoWidget(this);
    amountOfDetailsWidget->setName("Amount of details:");
    amountOfDetailsWidget->setInfo("");

    amountWidget = new InfoWidget(this);
    amountWidget->setName("Amount:");
    amountWidget->setInfo("");

    priceWidget = new InfoWidget(this);
    priceWidget->setName("Price:");
    priceWidget->setInfo("");

    hLine1 = new QFrame(this);
    hLine1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLine1->setFixedHeight(2);
    hLine1->setFrameShape(QFrame::HLine);
    hLine1->setFrameShadow(QFrame::Sunken);

    viewButtonWidget = new QWidget(this);
    viewButtonLayout = new QHBoxLayout(viewButtonWidget);
    viewButton = new QPushButton(viewButtonWidget);
    viewButton->setCursor(Qt::CursorShape::PointingHandCursor);
    viewButton->setStyleSheet("border: 1px solid #222; padding: 5px 10px;");
    viewButton->setText("View");
    viewButton->setIcon(QIcon(":/icons/view_icon"));
    viewButton->setFont(normalFont);

    spacer1 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    spacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    viewButtonLayout->addItem(spacer1);
    viewButtonLayout->addWidget(viewButton);
    viewButtonLayout->addItem(spacer2);
    viewButtonLayout->setSpacing(0);
    viewButtonLayout->setContentsMargins(0, 0, 0, 0);

    mainLayout->addWidget(idWidget);
    mainLayout->addWidget(vendorIdWidget);
    mainLayout->addWidget(productTypeWidget);
    mainLayout->addWidget(amountOfCarsWidget);
    mainLayout->addWidget(amountOfDetailsWidget);
    mainLayout->addWidget(amountWidget);
    mainLayout->addWidget(priceWidget);
    mainLayout->addWidget(hLine1);
    mainLayout->addWidget(viewButtonWidget);

    this->setLayout(mainLayout);

    connect(viewButton, &QPushButton::clicked, this, &ProductInfoWidget::viewAllInfo);
}

Product ProductInfoWidget::getProduct() const
{
    return product;
}

void ProductInfoWidget::setProduct(const Product& newProduct)
{
    product = newProduct;
    idWidget->setInfo(QString::number(product.getProductID()));
    vendorIdWidget->setInfo(QString::number(product.getVendorID()));
    productTypeWidget->setInfo(Product::productTypeToString(product.getProductType()));
    amountOfCarsWidget->setInfo(QString::number(product.getCars().size()));
    amountOfDetailsWidget->setInfo(QString::number(product.getDetails().size()));
    amountWidget->setInfo(QString::number(product.getAmount()));
    priceWidget->setInfo(QString::number(product.getPrice()));
}

void ProductInfoWidget::viewAllInfo()
{
    modalWindow = new BuyProductWindow(this);
    modalWindow->setProduct(product);
    modalWindow->setModal(true);
    modalWindow->show();

    connect(modalWindow, &BuyProductWindow::buyButtonClicked, this, [this](){
        emit onProductBuyed();
    });
}
