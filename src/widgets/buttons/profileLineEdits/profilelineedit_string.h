#ifndef PROFILELINEEDIT_STRING_H
#define PROFILELINEEDIT_STRING_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class ProfileLineEdit_String : public QWidget
{
    Q_OBJECT

    bool state;
    QString value;

    QHBoxLayout* mainLayout;
    QLabel* lineEditContent;
    QLineEdit* lineEdit;
    QPushButton* mainButton;

public:
    explicit ProfileLineEdit_String(QWidget *parent = nullptr);

    void init_UI();

    void initValue(const QString& newVal);
    void setValue(const QString& newVal);

    QString getValue();

signals:
    void edited();

private slots:
    virtual void onButtonClicked();
};

#endif // PROFILELINEEDIT_STRING_H
