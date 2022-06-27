#ifndef CATALOGWIDGET_H
#define CATALOGWIDGET_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDir>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <logics/user.h>
#include <widgets/menuWidgets/productinfowidget.h>

class CatalogWidget : public QWidget
{
    Q_OBJECT

    User* registeredUser;

    QVBoxLayout* mainLayout;
    QLabel* welcomeLabel;
    QFrame* hLine1;
    QLabel* aboutLabel;

    QScrollArea* catalogArea;

    QWidget* catalogWidget;
    QVBoxLayout* catalogLayout;

    QString productsDatabasePath;
public:
    explicit CatalogWidget(QWidget *parent = nullptr);

    void alert(const QString& message);
    void info(const QString& message);

    User* getUser() const;

    void setUser(User* newUser);

    void setup();

signals:
    void productBuyed(Product product);
};

#endif // CATALOGWIDGET_H
