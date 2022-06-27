#include "userproductswidget.h"

UserProductsWidget::UserProductsWidget(QWidget *parent)
    : QWidget{parent}
{
    QFont normalFont;
    normalFont.setPixelSize(16);

    QFont boldFont;
    boldFont.setPixelSize(16);
    boldFont.setBold(true);

    this->setFont(normalFont);

    products = QVector<Product>(0);

    mainLayout = new QVBoxLayout(this);

    infoLabel = new QLabel(this);
    infoLabel->setText("You don't have any products!");
    infoLabel->setStyleSheet("color: #e53935;");
    infoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
    infoLabel->setFont(normalFont);

    gridWidget = new QWidget(this);
    gridWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    grid = new QGridLayout();
    gridWidget->setLayout(grid);
    grid->setRowStretch(0, 0);

    QLabel* productVendorIdLabel = new QLabel();
    productVendorIdLabel->setText("Vendor ID");
    productVendorIdLabel->setFont(boldFont);
    productVendorIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* productIdLabel = new QLabel();
    productIdLabel->setText("Product ID");
    productIdLabel->setFont(boldFont);
    productIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* productNumberOfDetails = new QLabel();
    productNumberOfDetails->setText("Amount of details");
    productNumberOfDetails->setFont(boldFont);
    productNumberOfDetails->setContentsMargins(3, 3, 3, 3);
    QLabel* productNumberOfCars = new QLabel();
    productNumberOfCars->setText("Amount of cars");
    productNumberOfCars->setFont(boldFont);
    productNumberOfCars->setContentsMargins(3, 3, 3, 3);
    QLabel* productTypeLabel = new QLabel();
    productTypeLabel->setText("State");
    productTypeLabel->setFont(boldFont);
    productTypeLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* productPriceLabel = new QLabel();
    productPriceLabel->setText("Price");
    productPriceLabel->setFont(boldFont);
    productPriceLabel->setContentsMargins(3, 3, 3, 3);

    grid->addWidget(new Line(), 0, 0, 1, 13);
    grid->addWidget(new VLine(), 1, 0, 1, 1);
    grid->addWidget(productVendorIdLabel, 1, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 2, 1, 1);
    grid->addWidget(productIdLabel, 1, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 4, 1, 1);
    grid->addWidget(productNumberOfDetails, 1, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 6, 1, 1);
    grid->addWidget(productNumberOfCars, 1, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 8, 1, 1);
    grid->addWidget(productTypeLabel, 1, 9, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 10, 1, 1);
    grid->addWidget(productPriceLabel, 1, 11, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 12, 1, 1);
    grid->addWidget(new Line(), 2, 0, 1, 13);
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    mainLayout->addWidget(infoLabel);
    mainLayout->addWidget(gridWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    infoLabel->hide();
}

QVector<Product> UserProductsWidget::getProducts() const
{
    return products;
}

Product UserProductsWidget::getProduct(qsizetype idx) const
{
    return products[idx];
}

void UserProductsWidget::setProducts(const QVector<Product>& newProducts)
{
    QFont boldFont;
    boldFont.setPixelSize(16);
    boldFont.setBold(true);

    delete grid;
    grid = new QGridLayout();
    gridWidget->setLayout(grid);
    grid->setRowStretch(0, 0);

    QLabel* productVendorIdLabel = new QLabel();
    productVendorIdLabel->setText("Vendor ID");
    productVendorIdLabel->setFont(boldFont);
    productVendorIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* productIdLabel = new QLabel();
    productIdLabel->setText("Product ID");
    productIdLabel->setFont(boldFont);
    productIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* productNumberOfDetails = new QLabel();
    productNumberOfDetails->setText("Amount of details");
    productNumberOfDetails->setFont(boldFont);
    productNumberOfDetails->setContentsMargins(3, 3, 3, 3);
    QLabel* productNumberOfCars = new QLabel();
    productNumberOfCars->setText("Amount of cars");
    productNumberOfCars->setFont(boldFont);
    productNumberOfCars->setContentsMargins(3, 3, 3, 3);
    QLabel* productTypeLabel = new QLabel();
    productTypeLabel->setText("State");
    productTypeLabel->setFont(boldFont);
    productTypeLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* productPriceLabel = new QLabel();
    productPriceLabel->setText("Price");
    productPriceLabel->setFont(boldFont);
    productPriceLabel->setContentsMargins(3, 3, 3, 3);

    grid->addWidget(new Line(), 0, 0, 1, 13);
    grid->addWidget(new VLine(), 1, 0, 1, 1);
    grid->addWidget(productVendorIdLabel, 1, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 2, 1, 1);
    grid->addWidget(productIdLabel, 1, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 4, 1, 1);
    grid->addWidget(productNumberOfDetails, 1, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 6, 1, 1);
    grid->addWidget(productNumberOfCars, 1, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 8, 1, 1);
    grid->addWidget(productTypeLabel, 1, 9, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 10, 1, 1);
    grid->addWidget(productPriceLabel, 1, 11, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 12, 1, 1);
    grid->addWidget(new Line(), 2, 0, 1, 13);
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    for (qsizetype i = 0 ; i < newProducts.size(); i++)
    {
        addProduct(newProducts[i]);
    }

    if (products.size() == 0)
    {
        infoLabel->show();
        gridWidget->hide();
    }else
    {
        infoLabel->hide();
        gridWidget->show();
    }
}

void UserProductsWidget::setProduct(qsizetype idx, const Product& newOrder)
{
    products[idx] = newOrder;
}

void UserProductsWidget::addProduct(const Product &newProduct)
{
    products.push_back(newProduct);

    QFont normalFont;
    normalFont.setPixelSize(16);

    int i = grid->rowCount();

    QLabel* productVendorIdLabel = new QLabel();
    productVendorIdLabel->setText(QString::number(newProduct.getVendorID()));
    productVendorIdLabel->setFont(normalFont);
    productVendorIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* productIdLabel = new QLabel();
    productIdLabel->setText(QString::number(newProduct.getProductID()));
    productIdLabel->setFont(normalFont);
    productIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* productNumberOfDetails = new QLabel();
    productNumberOfDetails->setText(QString::number(newProduct.getDetails().size()));
    productNumberOfDetails->setFont(normalFont);
    productNumberOfDetails->setContentsMargins(3, 3, 3, 3);
    QLabel* productNumberOfCars = new QLabel();
    productNumberOfCars->setText(QString::number(newProduct.getCars().size()));
    productNumberOfCars->setFont(normalFont);
    productNumberOfCars->setContentsMargins(3, 3, 3, 3);
    QLabel* productTypeLabel = new QLabel();
    productTypeLabel->setText(Product::productTypeToString(newProduct.getProductType()));
    productTypeLabel->setFont(normalFont);
    productTypeLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* productPriceLabel = new QLabel();
    productPriceLabel->setText(QString::number(newProduct.getPrice()));
    productPriceLabel->setFont(normalFont);

    grid->addWidget(new VLine(), i, 0, 1, 1);
    grid->addWidget(productVendorIdLabel, i, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 2, 1, 1);
    grid->addWidget(productIdLabel, i, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 4, 1, 1);
    grid->addWidget(productNumberOfDetails, i, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 6, 1, 1);
    grid->addWidget(productNumberOfCars, i, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 8, 1, 1);
    grid->addWidget(productTypeLabel, i, 9, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 10, 1, 1);
    grid->addWidget(productPriceLabel, i, 11, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 12, 1, 1);
    grid->addWidget(new Line(), i+1, 0, 1, 13);


    if (products.size() == 0)
    {
        infoLabel->show();
        gridWidget->hide();
    }else
    {
        infoLabel->hide();
        gridWidget->show();
    }
}
