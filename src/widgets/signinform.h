#ifndef SIGNINFORM_H
#define SIGNINFORM_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>

class SignInForm : public QWidget
{
    Q_OBJECT

    QVBoxLayout* mainLayout;
    QWidget* emailWidget;
    QHBoxLayout* emailLayout;
    QLabel* emailLabel;
    QLineEdit* emailLineEdit;
    QWidget* nameWidget;
    QHBoxLayout* nameLayout;
    QLabel* nameLabel;
    QLineEdit* nameLineEdit;
    QWidget* passwordWidget;
    QHBoxLayout* passwordLayout;
    QLabel* passwordLabel;
    QLineEdit* passwordLineEdit;
    QWidget* questionWidget;
    QHBoxLayout* questionLayout;
    QLabel* questionLabel;
    QPushButton* questionButton;
    QWidget* signInButtonWidget;
    QHBoxLayout* signInButtonLayout;
    QPushButton* signInButton;

    QSpacerItem* firstSpacer;
    QSpacerItem* secondSpacer;
    QSpacerItem* emailSpacer;
    QSpacerItem* nameSpacer;
    QSpacerItem* passwordSpacer;
    QSpacerItem* questionSpacer;
    QSpacerItem* signInButtonSpacer1;
    QSpacerItem* signInButtonSpacer2;

public:
    explicit SignInForm(QWidget *parent = nullptr);

    QString getEmail() const;
    QString getName() const;
    QString getPassword() const;

    void clearFields();

signals:
    void onSignIn();
    void onRedirection();
};

#endif // SIGNINFORM_H
