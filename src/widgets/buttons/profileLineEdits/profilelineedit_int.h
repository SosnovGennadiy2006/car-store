#ifndef PROFILELINEEDIT_INT_H
#define PROFILELINEEDIT_INT_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>

class ProfileLineEdit_Int : public QWidget
{
    Q_OBJECT

    bool state;

    QHBoxLayout* mainLayout;
    QLabel* lineEditContent;
    QSpinBox* lineEdit;
    QPushButton* mainButton;
public:
    explicit ProfileLineEdit_Int(QWidget *parent = nullptr);

    void init_UI();

    void initValue(const qint32& newVal);
    void setValue(const qint32& newVal);
    void setMinValue(const qint32& _min);
    void setMaxValue(const qint32& _max);

    qint32 getValue();

signals:
    void edited();

private slots:
    virtual void onButtonClicked();

};

#endif // PROFILELINEEDIT_INT_H
