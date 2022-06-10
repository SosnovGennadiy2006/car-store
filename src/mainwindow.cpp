#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init_UI();

    connect(welcomeWidget, &WelcomeWidget::onSignIn, this, &MainWindow::signIn);
    connect(welcomeWidget, &WelcomeWidget::onSignUp, this, &MainWindow::signUp);

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
    this->setMinimumSize(500, 400);
    centralWidget = new QWidget(this);

    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setAlignment(Qt::AlignmentFlag::AlignCenter);

    welcomeWidget = new WelcomeWidget(centralWidget);
    welcomeWidget->setMaximumWidth(400);
    welcomeWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));

    firstSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    secondSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    mainLayout->addItem(firstSpacer);
    mainLayout->addWidget(welcomeWidget, Qt::AlignmentFlag::AlignCenter);
    mainLayout->addItem(secondSpacer);

    this->setCentralWidget(centralWidget);
}

void MainWindow::alert(QString message)
{
    QMessageBox::warning(this, "Warning!", message);
}

void MainWindow::info(QString message)
{
    QMessageBox::information(this, "Info", message);
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

        if (user.take("email").toString() == userEmail)
        {
            if (user.take("password").toString() == userPassword &&
                    user.take("name").toString() == userName)
            {
                info("You have been successfully signed in!");
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
        _userEmail = user.take("email").toString();

        if (_userEmail == userEmail)
        {
            alert("The email has already been taken!");
            return;
        }
    }

    QJsonObject userObj;
    userObj.insert("name", userName);
    userObj.insert("email", userEmail);
    userObj.insert("password", userPassword);
    userObj.insert("date", QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss"));

    usersArray.append(userObj);

    documentObj["users"] = usersArray;

    jsonDoc.setObject(documentObj);

    file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    file.write(jsonDoc.toJson());
    file.close();

    info("You have been successfully registered!");
}
