#ifndef CARTWIDGET_H
#define CARTWIDGET_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <logics/user.h>
#include <widgets/menuWidgets/userorderswidget.h>

class CartWidget : public QFrame
{
    Q_OBJECT

    User* registeredUser;

    QVBoxLayout* mainLayout;

    QLabel* welcomeLabel;
    QLabel* aboutLabel;

    QWidget* goToCatalogWidget;
    QHBoxLayout* goToCatalogLayout;
    QLabel* goToCatalogLabel;
    QPushButton* goToCatalogButton;

    QFrame* hLine1;
    QFrame* hLine2;

    QSpacerItem* spacer;

public:
    CartWidget(QWidget *parent = nullptr);

    User* getUser() const;

    void setUser(User* newUser);

signals:
    void onRedirectionButtonClicked();
};

#endif // CARTWIDGET_H
