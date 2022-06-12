#include "welcomewidget.h"

WelcomeWidget::WelcomeWidget(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignmentFlag::AlignCenter);

    QFont bigFont = QFont();
    bigFont.setPixelSize(32);
    QFont normalFont = QFont();
    normalFont.setPixelSize(20);

    welcomeLabel = new QLabel(this);
    welcomeLabel->setText("Welcome to car store!");
    welcomeLabel->setFont(bigFont);
    welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

    aboutLabel = new QLabel(this);
    aboutLabel->setText("For further work, you need to log in:");
    aboutLabel->setFont(normalFont);
    aboutLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

    signIn = new SignInForm(this);
    signUp = new SignUpForm(this);
    signUp->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    signUp->hide();

    formsWidget = new QWidget(this);
    formsWidget->setMaximumWidth(500);
    formsWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    formsLayout = new QHBoxLayout(formsWidget);

    formsLayout->addWidget(signIn);
    formsLayout->addWidget(signUp);

    firstSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    secondSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    mainLayout->addItem(firstSpacer);
    mainLayout->addWidget(welcomeLabel);
    mainLayout->addWidget(aboutLabel);
    mainLayout->addWidget(formsWidget, Qt::AlignmentFlag::AlignHCenter);
    mainLayout->addItem(secondSpacer);
    mainLayout->setSpacing(0);

    connect(signIn, &SignInForm::onRedirection, this, &WelcomeWidget::redirectToSignUp);
    connect(signUp, &SignUpForm::onRedirection, this, &WelcomeWidget::redirectToSignIn);

    connect(signIn, &SignInForm::onSignIn, this, [this](){
        emit this->onSignIn();
    });
    connect(signUp, &SignUpForm::onSignUp, this, [this](){
        emit this->onSignUp();
    });
}

QString WelcomeWidget::getSignInName() const
{
    return signIn->getName();
}

QString WelcomeWidget::getSignInEmail() const
{
    return signIn->getEmail();
}

QString WelcomeWidget::getSignInPassword() const
{
    return signIn->getPassword();
}

QString WelcomeWidget::getSignUpName() const
{
    return signUp->getName();
}

QString WelcomeWidget::getSignUpEmail() const
{
    return signUp->getEmail();
}

QString WelcomeWidget::getSignUpPassword() const
{
    return signUp->getPassword();
}

QString WelcomeWidget::getSignUpRepeatedPassword() const
{
    return signUp->getRepeatedPassword();
}

bool WelcomeWidget::isVendor_signUp() const
{
    return signUp->isVendor();
}

void WelcomeWidget::redirectToSignIn()
{
    signUp->hide();
    signIn->show();
    signUp->clearFields();
}

void WelcomeWidget::redirectToSignUp()
{
    signIn->hide();
    signUp->show();
    signIn->clearFields();
}
