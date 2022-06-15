#ifndef CARTWIDGET_H
#define CARTWIDGET_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <logics/user.h>
#include <widgets/menuWidgets/userorderswidget.h>

class CartWidget : public QFrame
{
    Q_OBJECT

    User* registeredUser;

    QVBoxLayout* mainLayout;

    QLabel* welcomeLabel;
    QLabel* aboutLabel;

    QFrame* hLine1;

public:
    CartWidget(QWidget *parent = nullptr);

    User* getUser() const;

    void setUser(User* newUser);
};

#endif // CARTWIDGET_H
