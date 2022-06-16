#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init_UI();

    connect(welcomeWidget, &WelcomeWidget::onSignIn, this, &MainWindow::signIn);
    connect(welcomeWidget, &WelcomeWidget::onSignUp, this, &MainWindow::signUp);
    connect(mainWidget, &MainWidget::onExitButtonClicked, this, &MainWindow::exit);
    connect(mainWidget, &MainWidget::onUserCorrected, this, &MainWindow::userCorrected);

    QDir d = QDir::current();
    d.cdUp();
    d.cd("src");
    d.cd("json");

    usersDatabasePath = d.path() + "/users.json";
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

void MainWindow::alert(QString message)
{
    QMessageBox::warning(this, "Warning!", message);
}

void MainWindow::info(QString message)
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

    for (qsizetype i = 0; i < usersArray.size(); i++)
    {
        QJsonObject user = usersArray.at(i).toObject();

        if (user["email"].toString() == userEmail)
        {
            if (user["password"].toString() == userPassword &&
                    user["name"].toString() == userName)
            {
                registeredUser = new User(user);

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
