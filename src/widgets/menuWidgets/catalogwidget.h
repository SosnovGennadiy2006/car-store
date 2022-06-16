#ifndef CATALOGWIDGET_H
#define CATALOGWIDGET_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <logics/user.h>

class CatalogWidget : public QWidget
{
    Q_OBJECT

    User* registeredUser;

    QVBoxLayout* mainLayout;
    QLabel* welcomeLabel;
    QFrame* hLine1;
    QLabel* aboutLabel;
public:
    explicit CatalogWidget(QWidget *parent = nullptr);

    User* getUser() const;

    void setUser(User* newUser);
};

#endif // CATALOGWIDGET_H
