#include "profilewidget.h"

ProfileWidget::ProfileWidget(QWidget *parent) : QFrame{parent}
{
    _isChanged = false;

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
    welcomeLabel->setText("Welcome, " + registeredUser->getName());
    welcomeLabel->setFont(biggerFont);

    idLabel = new QLabel(this);
    idLabel->setText("ID: " + QString::number(registeredUser->getId()));
    idLabel->setFont(bigFont);
    idLabel->setAlignment(Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);

    aboutLabel = new QLabel(this);
    aboutLabel->setText("There is all the information about you:");
    aboutLabel->setFont(bigFont);

    hLine1 = new QFrame(this);
    hLine1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLine1->setFixedHeight(2);
    hLine1->setFrameShape(QFrame::HLine);
    hLine1->setFrameShadow(QFrame::Sunken);

    nameWidget = new QWidget(this);
    nameLayout = new QHBoxLayout(nameWidget);
    nameLabel = new QLabel(nameWidget);
    nameLabel->setText("Name:");
    nameLabel_present = new ProfileLineEdit_String(nameWidget);
    nameLabel_present->initValue(registeredUser->getName());
    nameSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    nameLayout->addWidget(nameLabel);
    nameLayout->addItem(nameSpacer);
    nameLayout->addWidget(nameLabel_present);
    nameLayout->setContentsMargins(0, 0, 0, 0);

    surnameWidget = new QWidget(this);
    surnameLayout = new QHBoxLayout(surnameWidget);
    surnameLabel = new QLabel(surnameWidget);
    surnameLabel->setText("Surname:");
    surnameLabel_present = new ProfileLineEdit_String(surnameWidget);
    surnameLabel_present->initValue(registeredUser->getSurname());
    surnameSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    surnameLayout->addWidget(surnameLabel);
    surnameLayout->addItem(surnameSpacer);
    surnameLayout->addWidget(surnameLabel_present);
    surnameLayout->setContentsMargins(0, 0, 0, 0);

    ageWidget = new QWidget(this);
    ageLayout = new QHBoxLayout(ageWidget);
    ageLabel = new QLabel(ageWidget);
    ageLabel->setText("Age:");
    ageLabel_present = new ProfileLineEdit_Int(ageWidget);
    ageLabel_present->initValue(registeredUser->getAge());
    ageLabel_present->setMinValue(0);
    ageLabel_present->setMaxValue(100);
    ageSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    ageLayout->addWidget(ageLabel);
    ageLayout->addItem(ageSpacer);
    ageLayout->addWidget(ageLabel_present);
    ageLayout->setContentsMargins(0, 0, 0, 0);

    emailAdressWidget = new QWidget(this);
    emailAdressLayout = new QHBoxLayout(emailAdressWidget);
    emailAdressLabel = new QLabel(emailAdressWidget);
    emailAdressLabel->setText("Email adress:");
    emailAdressLabel_present = new QLabel(emailAdressWidget);
    emailAdressLabel_present->setText(registeredUser->getEmailAdress());
    emailAdressSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    emailAdressLayout->addWidget(emailAdressLabel);
    emailAdressLayout->addItem(emailAdressSpacer);
    emailAdressLayout->addWidget(emailAdressLabel_present);
    emailAdressLayout->setContentsMargins(0, 0, 0, 0);

    phoneNumberWidget = new QWidget(this);
    phoneNumberLayout = new QHBoxLayout(phoneNumberWidget);
    phoneNumberLabel = new QLabel(phoneNumberWidget);
    phoneNumberLabel->setText("Phone number:");
    phoneNumberLabel_present = new ProfileLineEdit_Phone(phoneNumberWidget);
    phoneNumberLabel_present->initValue(registeredUser->getPhoneNumber());
    phoneNumberSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    phoneNumberLayout->addWidget(phoneNumberLabel);
    phoneNumberLayout->addItem(phoneNumberSpacer);
    phoneNumberLayout->addWidget(phoneNumberLabel_present);
    phoneNumberLayout->setContentsMargins(0, 0, 0, 0);

    registrationDateWidget = new QWidget(this);
    registrationDateLayout = new QHBoxLayout(registrationDateWidget);
    registrationDateLabel = new QLabel(registrationDateWidget);
    registrationDateLabel->setText("Registration date:");
    registrationDateLabel_present = new QLabel(registrationDateWidget);
    registrationDateLabel_present->setText(registeredUser->getRegistrationDate());
    registrationDateSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    registrationDateLayout->addWidget(registrationDateLabel);
    registrationDateLayout->addItem(registrationDateSpacer);
    registrationDateLayout->addWidget(registrationDateLabel_present);
    registrationDateLayout->setContentsMargins(0, 0, 0, 0);

    QFont isVendorFont;
    isVendorFont.setPixelSize(16);
    isVendorFont.setBold(true);

    isVendorLabel = new QLabel(this);
    isVendorLabel->setText("You are vendor!");
    isVendorLabel->setFont(isVendorFont);

    if (registeredUser->getUserType() == UserTypes::admin || registeredUser->getUserType() == UserTypes::vendor)
    {
        isVendorLabel->show();
    }else
    {
        isVendorLabel->hide();
    }

    hLine2 = new QFrame(this);
    hLine2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLine2->setFixedHeight(2);
    hLine2->setFrameShape(QFrame::HLine);
    hLine2->setFrameShadow(QFrame::Sunken);

    saveButtonWidget = new QWidget(this);
    saveButtonLayout = new QHBoxLayout(saveButtonWidget);
    saveButton = new QPushButton(saveButtonWidget);
    saveButton->setText("Save changes");
    saveButton->setDisabled(true);
    saveButton->setMinimumWidth(90);
    saveButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    saveButton->setStyleSheet("border: 1px solid #222; padding: 10px 20px;");
    firstSaveButtonSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    secondSaveButtonSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    saveButtonLayout->addItem(firstSaveButtonSpacer);
    saveButtonLayout->addWidget(saveButton);
    saveButtonLayout->addItem(secondSaveButtonSpacer);

    mainLayout->addWidget(welcomeLabel);
    mainLayout->addWidget(hLine1);
    mainLayout->addWidget(idLabel);
    mainLayout->addWidget(aboutLabel);
    mainLayout->addWidget(emailAdressWidget);
    mainLayout->addWidget(nameWidget);
    mainLayout->addWidget(surnameWidget);
    mainLayout->addWidget(ageWidget);
    mainLayout->addWidget(phoneNumberWidget);
    mainLayout->addWidget(registrationDateWidget);
    mainLayout->addWidget(isVendorLabel);
    mainLayout->addWidget(hLine2);
    mainLayout->addWidget(saveButtonWidget);

    connect(nameLabel_present, &ProfileLineEdit_String::edited, this, &ProfileWidget::onEdited);
    connect(surnameLabel_present, &ProfileLineEdit_String::edited, this, &ProfileWidget::onEdited);
    connect(ageLabel_present, &ProfileLineEdit_Int::edited, this, &ProfileWidget::onEdited);
    connect(phoneNumberLabel_present, &ProfileLineEdit_Phone::edited, this, &ProfileWidget::onEdited);
    connect(saveButton, &QPushButton::clicked, this, &ProfileWidget::onSaveButtonClicked);
}

User* ProfileWidget::getUser() const
{
    return registeredUser;
}

void ProfileWidget::setUser(User* newUser)
{
    registeredUser = newUser;
    welcomeLabel->setText("Welcome, " + registeredUser->getName());
    idLabel->setText("ID: " + QString::number(registeredUser->getId()));
    nameLabel_present->initValue(registeredUser->getName());
    surnameLabel_present->initValue(registeredUser->getSurname());
    ageLabel_present->initValue(registeredUser->getAge());
    emailAdressLabel_present->setText(registeredUser->getEmailAdress());
    phoneNumberLabel_present->initValue(registeredUser->getPhoneNumber());
    registrationDateLabel_present->setText(registeredUser->getRegistrationDate());
    if (registeredUser->getUserType() == UserTypes::admin || registeredUser->getUserType() == UserTypes::vendor)
    {
        isVendorLabel->show();
    }else
    {
        isVendorLabel->hide();
    }
    saveButton->setDisabled(true);
    _isChanged = false;
}

void ProfileWidget::onEdited()
{
    if (QString::compare(nameLabel_present->getValue(), registeredUser->getName()) == 0 &&
            QString::compare(surnameLabel_present->getValue(), registeredUser->getSurname()) == 0 &&
            ageLabel_present->getValue() == registeredUser->getAge() &&
            QString::compare(phoneNumberLabel_present->getValue(), registeredUser->getPhoneNumber()) == 0)
    {
        saveButton->setDisabled(true);
        _isChanged = false;
    }else
    {
        saveButton->setDisabled(false);
        _isChanged = true;
    }
}

void ProfileWidget::onSaveButtonClicked()
{
    User* correctedUser = new User(registeredUser);
    correctedUser->setName(nameLabel_present->getValue());
    correctedUser->setSurname(surnameLabel_present->getValue());
    correctedUser->setAge(ageLabel_present->getValue());
    correctedUser->setPhoneNumber(phoneNumberLabel_present->getValue());
    _isChanged = false;

    emit userCorrected(correctedUser);
}

bool ProfileWidget::isChanged()
{
    return _isChanged;
}

void ProfileWidget::saveUser()
{
    emit saveButton->clicked();
}
