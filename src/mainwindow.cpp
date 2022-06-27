#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init_UI();

    connect(welcomeWidget, &WelcomeWidget::onSignIn, this, &MainWindow::signIn);
    connect(welcomeWidget, &WelcomeWidget::onSignUp, this, &MainWindow::signUp);
    connect(mainWidget, &MainWidget::onExitButtonClicked, this, &MainWindow::exit);
    connect(mainWidget, &MainWidget::onUserCorrected, this, &MainWindow::userCorrected);
    connect(mainWidget, &MainWidget::onProductSaved, this, &MainWindow::saveProduct);
    connect(mainWidget, &MainWidget::onOrderSaved, this, &MainWindow::saveOrder);

    QDir d = QDir::current();
    d.cdUp();
    d.cd("src");
    d.cd("json");

    usersDatabasePath = d.path() + "/users.json";
    ordersDatabasePath = d.path() + "/orders.json";
    productsDatabasePath = d.path() + "/products.json";
}

MainWindow::~MainWindow()
{
}

void MainWindow::init_UI()
{
    this->setWindowTitle("Car Store");

    this->setMinimumSize(1000, 600);

    welcomeWidget = new WelcomeWidget(this);
    welcomeWidget->show();
    mainWidget = new MainWidget(this);
    mainWidget->hide();

    this->setCentralWidget(welcomeWidget);
}

void MainWindow::alert(const QString& message)
{
    QMessageBox::warning(this, "Warning!", message);
}

void MainWindow::info(const QString& message)
{
    QMessageBox::information(this, "Info", message);
}

void MainWindow::redirectToMainWidget()
{
    welcomeWidget = new WelcomeWidget(this);
    welcomeWidget->hide();
    mainWidget->show();
    mainWidget->setUser(registeredUser);
    this->setCentralWidget(mainWidget);

    connect(welcomeWidget, &WelcomeWidget::onSignIn, this, &MainWindow::signIn);
    connect(welcomeWidget, &WelcomeWidget::onSignUp, this, &MainWindow::signUp);
}

void MainWindow::signIn()
{
    QString userName = welcomeWidget->getSignInName();
    QString userEmail = welcomeWidget->getSignInEmail();
    QString userPassword = welcomeWidget->getSignInPassword();
    QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailREX.setCaseSensitivity(Qt::CaseInsensitive);
    mailREX.setPatternSyntax(QRegExp::RegExp);

    QFile file(usersDatabasePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        alert("Sorry! Couldn't open store file!");
        return;
    }

    QString fileText = file.readAll();

    file.close();

    QFile orderFile(ordersDatabasePath);

    if (!orderFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        alert("Sorry! Couldn't open store file!");
        return;
    }

    QString orders_fileText = orderFile.readAll();

    orderFile.close();

    QFile productFile(productsDatabasePath);

    if (!productFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        alert("Sorry! Couldn't open store file!");
        return;
    }

    QString products_fileText = productFile.readAll();

    productFile.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileText.toUtf8());

    QJsonObject documentObj = jsonDoc.object();

    QJsonArray usersArray = documentObj["users"].toArray();

    QJsonDocument jsonDoc_orders = QJsonDocument::fromJson(orders_fileText.toUtf8());

    QJsonObject documentObj_orders = jsonDoc_orders.object();

    QJsonDocument jsonDoc_products = QJsonDocument::fromJson(products_fileText.toUtf8());

    QJsonObject documentObj_products = jsonDoc_products.object();

    QJsonArray ordersArray = documentObj_orders["orders"].toArray();

    QJsonArray productsArray = documentObj_products["products"].toArray();

    if (userName == "")
    {
        alert("User name is empty!");
        return;
    }
    if (userEmail == "")
    {
        alert("User email is empty!");
        return;
    }
    if (!mailREX.exactMatch(userEmail))
    {
        alert("User email is invalid!");
        return;
    }
    if (userPassword == "")
    {
        alert("User password is empty!");
        return;
    }

    for (qsizetype i = 0; i < usersArray.size(); i++)
    {
        QJsonObject user = usersArray.at(i).toObject();

        if (user["email"].toString() == userEmail)
        {
            if (user["password"].toString() == userPassword &&
                    user["name"].toString() == userName)
            {
                registeredUser = new User(user);

                for (qsizetype j = 0; j < ordersArray.size(); j++)
                {
                    QJsonObject order = ordersArray.at(j).toObject();
                    if (order["customerId"].toInt() == registeredUser->getId())
                    {
                        registeredUser->addOrder(Order(order));
                    }
                }

                for (qsizetype j = 0; j < productsArray.size(); j++)
                {
                    QJsonObject product = productsArray.at(j).toObject();
                    if (product["vendorId"].toInt() == registeredUser->getId())
                    {
                        registeredUser->addProduct(Product(product));
                    }
                }

                info("You have been successfully signed in!");

                redirectToMainWidget();

                return;
            }
            break;
        }
    }

    alert("The user was not found! Check the correctness of the entered data.");
}

void MainWindow::signUp()
{
    QString userName = welcomeWidget->getSignUpName();
    QString userEmail = welcomeWidget->getSignUpEmail();
    QString userPassword = welcomeWidget->getSignUpPassword();
    QString userRepeatedPassword = welcomeWidget->getSignUpRepeatedPassword();
    QString registrationDate = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");
    qint32 userId = 1;
    QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailREX.setCaseSensitivity(Qt::CaseInsensitive);
    mailREX.setPatternSyntax(QRegExp::RegExp);

    QFile file(usersDatabasePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        alert("Sorry! Couldn't open store file!");
        return;
    }

    QString fileText = file.readAll();

    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileText.toUtf8());

    QJsonObject documentObj = jsonDoc.object();

    QJsonArray usersArray = documentObj["users"].toArray();

    if (userName == "")
    {
        alert("User name is empty!");
        return;
    }
    if (userEmail == "")
    {
        alert("User email is empty!");
        return;
    }
    if (!mailREX.exactMatch(userEmail))
    {
        alert("User email is invalid!");
        return;
    }
    if (userPassword == "")
    {
        alert("User password is empty!");
        return;
    }
    if (userRepeatedPassword == "")
    {
        alert("Repeated password is empty!");
        return;
    }
    if (userRepeatedPassword != userPassword)
    {
        alert("Passwords aren't equal!");
        return;
    }

    QString _userEmail;

    for (qsizetype i = 0; i < usersArray.size(); i++)
    {
        QJsonObject user = usersArray.at(i).toObject();
        _userEmail = user["email"].toString();

        if (_userEmail == userEmail)
        {
            alert("The email has already been taken!");
            return;
        }
    }

    if (usersArray.size() != 0)
    {
        userId = usersArray.at(usersArray.size() - 1).toObject().take("id").toInt() + 1;
    }

    registeredUser = new User(UserTypes::client);

    QJsonObject userObj;
    userObj.insert("id", userId);
    userObj.insert("name", userName);
    userObj.insert("surname", "");
    userObj.insert("age", -1);
    userObj.insert("email", userEmail);
    userObj.insert("password", userPassword);
    userObj.insert("phone", "");
    userObj.insert("registrationDate", registrationDate);
    if (welcomeWidget->isVendor_signUp())
    {
        userObj.insert("type", "vendor");
        registeredUser->setUserType(UserTypes::vendor);
    }else
    {
        userObj.insert("type", "client");
    }

    usersArray.append(userObj);

    documentObj["users"] = usersArray;

    jsonDoc.setObject(documentObj);

    file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    file.write(jsonDoc.toJson());
    file.close();

    info("You have been successfully registered!");

    registeredUser->setId(userId);
    registeredUser->setName(userName);
    registeredUser->setEmailAdress(userName);
    registeredUser->setPassword(userPassword);
    registeredUser->setRegistrationDate(registrationDate);

    redirectToMainWidget();
}

void MainWindow::exit()
{
    registeredUser = new User(UserTypes::client);
    welcomeWidget->show();
    mainWidget = new MainWidget(this);
    mainWidget->hide();
    mainWidget->setUser(registeredUser);
    this->setCentralWidget(welcomeWidget);

    connect(mainWidget, &MainWidget::onExitButtonClicked, this, &MainWindow::exit);
    connect(mainWidget, &MainWidget::onUserCorrected, this, &MainWindow::userCorrected);
}

void MainWindow::userCorrected(User* correctedUser)
{
    QFile file(usersDatabasePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        alert("Sorry! Couldn't open store file!");
        return;
    }

    QString fileText = file.readAll();

    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileText.toUtf8());

    QJsonObject documentObj = jsonDoc.object();

    QJsonArray usersArray = documentObj["users"].toArray();

    for (qsizetype i = 0; i < usersArray.size(); i++)
    {
        QJsonObject user = usersArray.at(i).toObject();

        if (user["id"].toInt() == correctedUser->getId())
        {
            user["name"] = correctedUser->getName();
            user["surname"] = correctedUser->getSurname();
            user["phone"] = correctedUser->getPhoneNumber();
            user["age"] = correctedUser->getAge();
            usersArray.replace(i, user);

            documentObj["users"] = usersArray;

            jsonDoc.setObject(documentObj);

            file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
            file.write(jsonDoc.toJson());
            file.close();

            registeredUser = new User(correctedUser);
            mainWidget->setUser(registeredUser);

            info("You have successfully changed your profile!");

            return;
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (mainWidget->isProfileChanged())
    {
        QMessageBox msgBox;
        msgBox.setText("Profile changes are not saved, if you exit the program, the changes will be lost!");
        msgBox.setStandardButtons(QMessageBox::Close | QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int res = msgBox.exec();
        if (res == QMessageBox::Save)
        {
            mainWidget->saveProfileChanges();
        }
        else if (res == QMessageBox::Cancel)
        {
            event->ignore();
        }
    }
}

void MainWindow::saveProduct(Product productToSave)
{
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

    int newId;
    if (productsArray.size() != 0)
    {
        newId = productsArray[productsArray.size() - 1].toObject()["productId"].toInt() + 1;
    }else
    {
        newId = 1;
    }

    productToSave.setProductID(newId);

    productsArray.push_back(productToSave.toJson());

    documentObj_products["products"] = productsArray;

    jsonDoc_products.setObject(documentObj_products);

    productFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    productFile.write(jsonDoc_products.toJson());
    productFile.close();

    mainWidget->addProductToProducts(productToSave);
}

void MainWindow::saveOrder(Order orderToSave)
{
    qDebug() << "!!!";

    QFile orderFile(ordersDatabasePath);

    if (!orderFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        alert("Sorry! Couldn't open store file!");
        return;
    }

    QString orders_fileText = orderFile.readAll();

    orderFile.close();

    QJsonDocument jsonDoc_orders = QJsonDocument::fromJson(orders_fileText.toUtf8());

    QJsonObject documentObj_orders = jsonDoc_orders.object();

    QJsonArray ordersArray = documentObj_orders["orders"].toArray();

    int newId;
    if (ordersArray.size() != 0)
    {
        newId = ordersArray[ordersArray.size() - 1].toObject()["orderId"].toInt() + 1;
    }else
    {
        newId = 1;
    }

    orderToSave.setOrderID(newId);

    ordersArray.push_back(orderToSave.toJson());

    documentObj_orders["orders"] = ordersArray;

    jsonDoc_orders.setObject(documentObj_orders);

    orderFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    orderFile.write(jsonDoc_orders.toJson());
    orderFile.close();

    mainWidget->addOrderToOrders(orderToSave);
}
