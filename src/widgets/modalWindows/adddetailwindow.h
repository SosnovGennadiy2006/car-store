#ifndef ADDDETAILWINDOW_H
#define ADDDETAILWINDOW_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QMessageBox>
#include <QComboBox>
#include <QSpinBox>
#include <QMap>
#include <logics/products/detail.h>
#include <widgets/layouts/layoutlineedit.h>
#include <widgets/layouts/layoutspinbox.h>
#include <widgets/layouts/layoutcombobox.h>
#include <widgets/layouts/layoutdoublespinbox.h>

class AddDetailWindow : public QDialog
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QScrollArea* mainArea;

    QWidget* mainWidget;

    QVBoxLayout* areaLayout;

    QLabel* infoLabel;

    LayoutComboBox* detailTypeWidget;

    LayoutLineEdit* nameWidget;

    LayoutLineEdit* nameManufacturerWidget;

    LayoutDoubleSpinBox* engineVolumeWidget;

    LayoutDoubleSpinBox* enginePowerWidget;

    LayoutComboBox* rubberTypeWidget;

    LayoutSpinBox* candleSizeWidget;

    LayoutComboBox* candleTypeWidget;

    LayoutComboBox* carburetorTypeWidget;

    LayoutComboBox* caliperTypeWidget;

    LayoutComboBox* brakeDiscsTypeWidget;

    LayoutComboBox* brakeDiscsTypeOfMaterialWidget;

    LayoutSpinBox* heatNumberWidget;

    LayoutDoubleSpinBox* wheelRubberRadiusWidget;

    LayoutDoubleSpinBox* wheelDiskRadiusWidget;

    LayoutSpinBox* priceWidget;

    QWidget* buttonsWidget;
    QLayout* buttonsLayout;
    QPushButton* saveButton;
    QPushButton* cancelButton;

    QSpacerItem* buttonsSpacer;
    QSpacerItem* areaSpacer;

    Detail newDetail;

    QMap<int, QVector<QWidget*>> widgetsByDetailType;
public:
    AddDetailWindow(QWidget* parent = nullptr);

    void alert(QString message);
    void info(QString message);

    Detail getDetail() const;

    void setDetail(const Detail& _product);

public slots:
    void onSaveButtonClicked();
    void onCancelButtonClicked();

    void onDetailTypeChanged();
    void onChanged();

signals:
    void detailSaved(Detail newCar);
};

#endif // ADDDETAILWINDOW_H
