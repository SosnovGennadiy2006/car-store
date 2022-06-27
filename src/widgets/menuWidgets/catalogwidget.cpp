#include "catalogwidget.h"

CatalogWidget::CatalogWidget(QWidget *parent)
    : QWidget{parent}
{
    QDir d = QDir::current();
    d.cdUp();
    d.cd("src");
    d.cd("json");

    productsDatabasePath = d.path() + "/products.json";

    QFont biggerFont;
    biggerFont.setPixelSize(32);

    QFont bigFont;
    bigFont.setPixelSize(24);

    QFont normalFont;
    normalFont.setPixelSize(16);

    this->setFont(normalFont);

    registeredUser = new User(UserTypes::client);

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    mainLayout = new QVBoxLayout(this);

    welcomeLabel = new QLabel(this);
    welcomeLabel->setText("Catalog");
    welcomeLabel->setFont(biggerFont);

    aboutLabel = new QLabel(this);
    aboutLabel->setText("Welcome to the catalog! There is all store products:");
    aboutLabel->setFont(bigFont);

    hLine1 = new QFrame(this);
    hLine1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLine1->setFixedHeight(2);
    hLine1->setFrameShape(QFrame::HLine);
    hLine1->setFrameShadow(QFrame::Sunken);

    catalogArea = new QScrollArea(this);
    catalogArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    catalogArea->setWidgetResizable(true);
    catalogArea->setStyleSheet("QScrollArea {border: 1px solid #222;}");
    catalogArea->setMinimumHeight(400);

    catalogWidget = new QWidget(this);
    catalogLayout = new QVBoxLayout(catalogWidget);
    catalogLayout->setSpacing(30);

    setup();

    catalogArea->setWidget(catalogWidget);

    mainLayout->addWidget(welcomeLabel);
    mainLayout->addWidget(hLine1);
    mainLayout->addWidget(aboutLabel);
    mainLayout->addWidget(catalogArea);
}

User* CatalogWidget::getUser() const
{
    return registeredUser;
}

void CatalogWidget::setUser(User* newUser)
{
    registeredUser = newUser;
}

void CatalogWidget::alert(const QString& message)
{
    QMessageBox::warning(this, "Warning!", message);
}

void CatalogWidget::info(const QString& message)
{
    QMessageBox::information(this, "Info", message);
}

void CatalogWidget::setup()
{
    QFont normalFont;
    normalFont.setPixelSize(16);

    delete catalogLayout;
    delete catalogWidget;
    catalogWidget = new QWidget(this);
    catalogLayout = new QVBoxLayout(catalogWidget);
    catalogLayout->setSpacing(30);
    catalogArea->setWidget(catalogWidget);

    QFile productFile(productsDatabasePath);

    if (!productFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        alert("Sorry! Couldn't open store file!");
        return;
    }

    QString products_fileText = productFile.readAll();

    productFile.close();

    QJsonDocument jsonDoc_products = QJsonDocument::fromJson(products_fileText.toUtf8());

    QJsonObject documentObj_products = jsonDoc_products.object();

    QJsonArray productsArray = documentObj_products["products"].toArray();

    if (productsArray.size() == 0)
    {
        QLabel* label = new QLabel(catalogWidget);
        label->setText("There aren't any products!");
        label->setFont(normalFont);
        label->setStyleSheet("color: #e53935;");

        catalogLayout->addWidget(label);
    }else
    {
        for (qsizetype i = 0; i < productsArray.size(); i++)
        {
            Product p = Product(productsArray[i].toObject());
            ProductInfoWidget* info = new ProductInfoWidget(catalogWidget);
            info->setProduct(p);
            catalogLayout->addWidget(info);

            connect(info, &ProductInfoWidget::onProductBuyed, [this, p](){
                emit productBuyed(Product(p));
            });
        }
    }
}
