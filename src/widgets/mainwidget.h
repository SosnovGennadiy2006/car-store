#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QScrollArea>
#include <logics/user.h>
#include <widgets/menu.h>
#include <widgets/menuWidgets/profilewidget.h>

class MainWidget : public QWidget
{
    Q_OBJECT

    User* registeredUser = new User(UserTypes::client);

    QHBoxLayout* mainLayout;

    Menu* widgetMenu;

    ProfileWidget* profile;

    QScrollArea* profileScroll;

public:
    explicit MainWidget(QWidget *parent = nullptr);

    User* getUser() const;

    void setUser(User* newUser);

    bool isProfileChanged();

    void saveProfileChanges();

signals:
    void onExitButtonClicked();
    void onUserCorrected(User* correctedUser);

public slots:
    void redirectToProfile();
};

#endif // MAINWIDGET_H
