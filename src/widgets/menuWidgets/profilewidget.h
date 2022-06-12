#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <logics/user.h>

class ProfileWidget : public QFrame
{
    Q_OBJECT

    User* registeredUser;

    QVBoxLayout* mainLayout;

    QLabel* welcomeLabel;
    QLabel* aboutLabel;

    QFrame* hLine1;

    QWidget* nameWidget;
    QHBoxLayout* nameLayout;
    QLabel* nameLabel;
    QLabel* nameLabel_present;

    QWidget* surnameWidget;
    QHBoxLayout* surnameLayout;
    QLabel* surnameLabel;
    QLabel* surnameLabel_present;

    QWidget* ageWidget;
    QHBoxLayout* ageLayout;
    QLabel* ageLabel;
    QLabel* ageLabel_present;

    QWidget* emailAdressWidget;
    QHBoxLayout* emailAdressLayout;
    QLabel* emailAdressLabel;
    QLabel* emailAdressLabel_present;

    QWidget* phoneNumberWidget;
    QHBoxLayout* phoneNumberLayout;
    QLabel* phoneNumberLabel;
    QLabel* phoneNumberLabel_present;

    QWidget* registrationWidget;
    QHBoxLayout* registrationLayout;
    QLabel* registrationLabel;
    QLabel* registrationLabel_present;

    QSpacerItem* nameSpacer;
    QSpacerItem* surnameSpacer;
    QSpacerItem* ageSpacer;
    QSpacerItem* emailAdressSpacer;
    QSpacerItem* phoneNumberSpacer;
    QSpacerItem* registrationDateSpacer;

public:
    ProfileWidget(QWidget *parent = nullptr);

    User* getUser() const;

    void setUser(User* newUser);
};

#endif // PROFILEWIDGET_H
