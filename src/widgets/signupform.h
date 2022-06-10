#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <widgets/buttons/customcheckbox.h>

class SignUpForm : public QWidget
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
    QWidget* repeatedPasswordWidget;
    QHBoxLayout* repeatedPasswordLayout;
    QLabel* repeatedPasswordLabel;
    QLineEdit* repeatedPasswordLineEdit;
    QWidget* vendorWidget;
    QHBoxLayout* vendorLayout;
    QLabel* vendorLabel;
    CustomCheckBox* vendorCheckBox;

    QWidget* questionWidget;
    QHBoxLayout* questionLayout;
    QLabel* questionLabel;
    QPushButton* questionButton;
    QWidget* signUpButtonWidget;
    QHBoxLayout* signUpButtonLayout;
    QPushButton* signUpButton;


    QSpacerItem* emailSpacer;
    QSpacerItem* nameSpacer;
    QSpacerItem* passwordSpacer;
    QSpacerItem* repeatedPasswordSpacer;
    QSpacerItem* vendorSpacer;
    QSpacerItem* questionSpacer;
    QSpacerItem* signInButtonSpacer1;
    QSpacerItem* signInButtonSpacer2;

public:
    explicit SignUpForm(QWidget *parent = nullptr);

    QString getEmail() const;
    QString getName() const;
    QString getPassword() const;
    QString getRepeatedPassword() const;
    bool isVendor() const;

    void clearFields();

signals:
    void onSignUp();
    void onRedirection();

};

#endif // SIGNUPFORM_H
