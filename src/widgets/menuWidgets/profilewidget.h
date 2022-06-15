#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QFont>
#include <logics/user.h>
#include <widgets/buttons/profileLineEdits/profilelineedit_int.h>
#include <widgets/buttons/profileLineEdits/profilelineedit_string.h>
#include <widgets/buttons/profileLineEdits/profilelineedit_phone.h>

class ProfileWidget : public QFrame
{
    Q_OBJECT

    bool _isChanged;

    User* registeredUser;

    QVBoxLayout* mainLayout;

    QLabel* welcomeLabel;
    QLabel* idLabel;
    QLabel* aboutLabel;

    QFrame* hLine1;
    QFrame* hLine2;

    QWidget* nameWidget;
    QHBoxLayout* nameLayout;
    QLabel* nameLabel;
    ProfileLineEdit_String* nameLabel_present;

    QWidget* surnameWidget;
    QHBoxLayout* surnameLayout;
    QLabel* surnameLabel;
    ProfileLineEdit_String* surnameLabel_present;

    QWidget* ageWidget;
    QHBoxLayout* ageLayout;
    QLabel* ageLabel;
    ProfileLineEdit_Int* ageLabel_present;

    QWidget* emailAdressWidget;
    QHBoxLayout* emailAdressLayout;
    QLabel* emailAdressLabel;
    QLabel* emailAdressLabel_present;

    QWidget* phoneNumberWidget;
    QHBoxLayout* phoneNumberLayout;
    QLabel* phoneNumberLabel;
    ProfileLineEdit_Phone* phoneNumberLabel_present;

    QWidget* registrationDateWidget;
    QHBoxLayout* registrationDateLayout;
    QLabel* registrationDateLabel;
    QLabel* registrationDateLabel_present;

    QLabel* isVendorLabel;

    QWidget* saveButtonWidget;
    QHBoxLayout* saveButtonLayout;
    QPushButton* saveButton;

    QSpacerItem* firstSaveButtonSpacer;
    QSpacerItem* secondSaveButtonSpacer;
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

    bool isChanged();

    void saveUser();

signals:
    void userCorrected(User* savedUser);

private slots:
    void onEdited();
    void onSaveButtonClicked();
};

#endif // PROFILEWIDGET_H
