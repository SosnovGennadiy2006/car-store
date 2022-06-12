#include "signinform.h"

SignInForm::SignInForm(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout(this);

    emailWidget = new QWidget(this);
    emailLayout = new QHBoxLayout(emailWidget);
    emailLabel = new QLabel(emailWidget);
    emailLabel->setFixedWidth(110);
    emailLabel->setText("Email:");
    emailSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    emailLineEdit = new QLineEdit(emailWidget);
    emailLineEdit->setPlaceholderText("email");
    emailLineEdit->setMinimumWidth(170);

    emailLayout->addWidget(emailLabel);
    emailLayout->addItem(emailSpacer);
    emailLayout->addWidget(emailLineEdit);
    emailLayout->setSpacing(0);
    emailLayout->setContentsMargins(0, 0, 0, 0);

    nameWidget = new QWidget(this);
    nameLayout = new QHBoxLayout(nameWidget);
    nameLabel = new QLabel(nameWidget);
    nameLabel->setFixedWidth(110);
    nameLabel->setText("Name:");
    nameSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    nameLineEdit = new QLineEdit(nameWidget);
    nameLineEdit->setPlaceholderText("name");
    nameLineEdit->setMinimumWidth(170);

    nameLayout->addWidget(nameLabel);
    nameLayout->addItem(nameSpacer);
    nameLayout->addWidget(nameLineEdit);
    nameLayout->setSpacing(0);
    nameLayout->setContentsMargins(0, 0, 0, 0);

    passwordWidget = new QWidget(this);
    passwordLayout = new QHBoxLayout(passwordWidget);
    passwordLabel = new QLabel(passwordWidget);
    passwordLabel->setFixedWidth(110);
    passwordLabel->setText("Password:");
    passwordSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    passwordLineEdit = new QLineEdit(passwordWidget);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setMinimumWidth(170);

    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addItem(passwordSpacer);
    passwordLayout->addWidget(passwordLineEdit);
    passwordLayout->setSpacing(0);
    passwordLayout->setContentsMargins(0, 0, 0, 0);

    signInButtonWidget = new QWidget(this);
    signInButtonLayout = new QHBoxLayout(signInButtonWidget);
    signInButtonSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    signInButtonSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    signInButton = new QPushButton(signInButtonWidget);
    signInButton->setText("Sign In");
    signInButton->setMinimumWidth(90);
    signInButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    signInButtonLayout->addItem(signInButtonSpacer1);
    signInButtonLayout->addWidget(signInButton);
    signInButtonLayout->addItem(signInButtonSpacer2);
    signInButtonLayout->setSpacing(0);
    signInButtonLayout->setContentsMargins(0, 0, 0, 0);

    questionWidget = new QWidget(this);
    questionLayout = new QHBoxLayout(questionWidget);
    questionLabel = new QLabel(questionWidget);
    questionLabel->setText("Don't have an account?");
    questionSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    questionButton = new QPushButton(questionWidget);
    questionButton->setText("Sign Up");
    questionButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    questionLayout->addWidget(questionLabel);
    questionLayout->addItem(questionSpacer);
    questionLayout->addWidget(questionButton);
    questionLayout->setSpacing(0);
    questionLayout->setContentsMargins(0, 0, 0, 0);

    mainLayout->addWidget(emailWidget);
    mainLayout->addWidget(nameWidget);
    mainLayout->addWidget(passwordWidget);
    mainLayout->addWidget(signInButtonWidget);
    mainLayout->addWidget(questionWidget);
    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    connect(signInButton, &QPushButton::clicked, this, [this](){
        emit this->onSignIn();
    });
    connect(questionButton, &QPushButton::clicked, this, [this](){
        emit this->onRedirection();
    });
}

QString SignInForm::getEmail() const
{
    return this->emailLineEdit->text();
}

QString SignInForm::getName() const
{
    return this->nameLineEdit->text();
}

QString SignInForm::getPassword() const
{
    return this->passwordLineEdit->text();
}

void SignInForm::clearFields()
{
    this->nameLineEdit->setText("");
    this->emailLineEdit->setText("");
    this->passwordLineEdit->setText("");
}
