#include "welcomewidget.h"

WelcomeWidget::WelcomeWidget(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout(this);

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
    signUp->hide();

    mainLayout->addWidget(welcomeLabel);
    mainLayout->addWidget(aboutLabel);
    mainLayout->addWidget(signIn);
    mainLayout->addWidget(signUp);
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
