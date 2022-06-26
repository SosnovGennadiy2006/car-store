#ifndef ADDCARWINDOW_H
#define ADDCARWINDOW_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QMessageBox>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <logics/products/car.h>
#include <widgets/layouts/layoutlineedit.h>
#include <widgets/layouts/layoutcombobox.h>
#include <widgets/layouts/layoutspinbox.h>

class AddCarWindow : public QDialog
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QScrollArea* mainArea;

    QWidget* mainWidget;

    QVBoxLayout* areaLayout;

    QLabel* infoLabel;

    LayoutLineEdit* nameWidget;

    LayoutLineEdit* markWidget;

    LayoutComboBox* bodyTypeWidget;

    LayoutComboBox* transmissionWidget;

    LayoutComboBox* driveUnitWidget;

    LayoutSpinBox* priceWidget;

    QWidget* buttonsWidget;
    QLayout* buttonsLayout;
    QPushButton* saveButton;
    QPushButton* cancelButton;

    QSpacerItem* buttonsSpacer;
    QSpacerItem* areaSpacer;

    Car newCar;
public:
    AddCarWindow(QWidget* parent = nullptr);

    void alert(QString message);
    void info(QString message);

    Car getCar() const;

    void setCar(const Car& _car);

public slots:
    void onSaveButtonClicked();
    void onCancelButtonClicked();

    void onChanged();

signals:
    void carSaved(Car newCar);
};

#endif // ADDCARWINDOW_H
