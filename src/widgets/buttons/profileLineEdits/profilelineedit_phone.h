#ifndef PROFILELINEEDIT_PHONE_H
#define PROFILELINEEDIT_PHONE_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <libs/RangeLineEdit/PhoneNumberLineEdit.h>

class ProfileLineEdit_Phone : public QWidget
{
    Q_OBJECT

    bool state;

    QHBoxLayout* mainLayout;
    QLabel* lineEditContent;
    PhoneNumberLineEdit* lineEdit;
    QPushButton* mainButton;
public:
    explicit ProfileLineEdit_Phone(QWidget *parent = nullptr);

    void init_UI();

    void initValue(const QString& newVal);
    void setValue(const QString& newVal);

    QString getValue();

signals:
    void edited();

private slots:
    virtual void onButtonClicked();
};

#endif // PROFILELINEEDIT_PHONE_H
