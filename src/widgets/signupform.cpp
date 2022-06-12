#include "signupform.h"

SignUpForm::SignUpForm(QWidget *parent)
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

    repeatedPasswordWidget = new QWidget(this);
    repeatedPasswordLayout = new QHBoxLayout(repeatedPasswordWidget);
    repeatedPasswordLabel = new QLabel(repeatedPasswordWidget);
    repeatedPasswordLabel->setFixedWidth(110);
    repeatedPasswordLabel->setText("Repeated password:");
    repeatedPasswordSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    repeatedPasswordLineEdit = new QLineEdit(passwordWidget);
    repeatedPasswordLineEdit->setEchoMode(QLineEdit::Password);
    repeatedPasswordLineEdit->setMinimumWidth(170);

    repeatedPasswordLayout->addWidget(repeatedPasswordLabel);
    repeatedPasswordLayout->addItem(repeatedPasswordSpacer);
    repeatedPasswordLayout->addWidget(repeatedPasswordLineEdit);
    repeatedPasswordLayout->setSpacing(0);
    repeatedPasswordLayout->setContentsMargins(0, 0, 0, 0);

    vendorWidget = new QWidget(this);
    vendorLayout = new QHBoxLayout(vendorWidget);
    vendorLabel = new QLabel(vendorWidget);
    vendorLabel->setText("Is vendor? ");
    vendorCheckBox = new CustomCheckBox(vendorWidget);
    vendorSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    vendorLayout->addItem(vendorSpacer);
    vendorLayout->addWidget(vendorLabel);
    vendorLayout->addWidget(vendorCheckBox);
    vendorLayout->setSpacing(0);
    vendorLayout->setContentsMargins(0, 0, 0, 0);

    signUpButtonWidget = new QWidget(this);
    signUpButtonLayout = new QHBoxLayout(signUpButtonWidget);
    signInButtonSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    signInButtonSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    signUpButton = new QPushButton(signUpButtonWidget);
    signUpButton->setText("Sign Up");
    signUpButton->setMinimumWidth(90);
    signUpButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    signUpButtonLayout->addItem(signInButtonSpacer1);
    signUpButtonLayout->addWidget(signUpButton);
    signUpButtonLayout->addItem(signInButtonSpacer2);
    signUpButtonLayout->setSpacing(0);
    signUpButtonLayout->setContentsMargins(0, 0, 0, 0);

    questionWidget = new QWidget(this);
    questionLayout = new QHBoxLayout(questionWidget);
    questionLabel = new QLabel(questionWidget);
    questionLabel->setText("Already have account?");
    questionSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    questionButton = new QPushButton(questionWidget);
    questionButton->setText("Sign In");
    questionButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    questionLayout->addWidget(questionLabel);
    questionLayout->addItem(questionSpacer);
    questionLayout->addWidget(questionButton);
    questionLayout->setSpacing(0);
    questionLayout->setContentsMargins(0, 0, 0, 0);

    mainLayout->addWidget(emailWidget);
    mainLayout->addWidget(nameWidget);
    mainLayout->addWidget(passwordWidget);
    mainLayout->addWidget(repeatedPasswordWidget);
    mainLayout->addWidget(vendorWidget);
    mainLayout->addWidget(signUpButtonWidget);
    mainLayout->addWidget(questionWidget);
    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    connect(signUpButton, &QPushButton::clicked, this, [this](){
        emit this->onSignUp();
    });
    connect(questionButton, &QPushButton::clicked, this, [this](){
        emit this->onRedirection();
    });
}

QString SignUpForm::getEmail() const
{
    return emailLineEdit->text();
}

QString SignUpForm::getName() const
{
    return nameLineEdit->text();
}

QString SignUpForm::getPassword() const
{
    return passwordLineEdit->text();
}

QString SignUpForm::getRepeatedPassword() const
{
    return repeatedPasswordLineEdit->text();
}

void SignUpForm::clearFields()
{
    this->nameLineEdit->setText("");
    this->emailLineEdit->setText("");
    this->passwordLineEdit->setText("");
    this->repeatedPasswordLineEdit->setText("");
}

bool SignUpForm::isVendor() const
{
    if (vendorCheckBox->checkState() == Qt::CheckState::Checked)
    {
        return true;
    }
    return false;
}
