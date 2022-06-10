#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QSpacerItem>
#include <QSizePolicy>
#include <widgets/signinform.h>
#include <widgets/signupform.h>

class WelcomeWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout* mainLayout;
    QLabel* welcomeLabel;
    QLabel* aboutLabel;
    SignInForm* signIn;
    SignUpForm* signUp;
public:
    explicit WelcomeWidget(QWidget *parent = nullptr);

    QString getSignInName() const;
    QString getSignInEmail() const;
    QString getSignInPassword() const;
    QString getSignUpName() const;
    QString getSignUpEmail() const;
    QString getSignUpPassword() const;
    QString getSignUpRepeatedPassword() const;

signals:
    void onSignIn();
    void onSignUp();

private slots:
    void redirectToSignIn();
    void redirectToSignUp();
};

#endif // WELCOMEWIDGET_H
