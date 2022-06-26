#ifndef ADDPRODUCTWINDOW_H
#define ADDPRODUCTWINDOW_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QScrollArea>
#include <QMessageBox>
#include <QGridLayout>
#include <logics/products/car.h>
#include <logics/products/detail.h>
#include <logics/products/product.h>
#include <widgets/modalWindows/adddetailwindow.h>
#include <widgets/modalWindows/addcarwindow.h>
#include <widgets/layouts/layoutspinbox.h>
#include <widgets/line.h>

class AddProductWindow : public QDialog
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QScrollArea* mainArea;

    QWidget* mainWidget;

    QVBoxLayout* areaLayout;

    QWidget* detailsWidget;
    QVBoxLayout* detailsLayout;

    QWidget* detailsInfoWidget;
    QHBoxLayout* detailsInfoLayout;
    QLabel* detailsInfoLabel;
    QLabel* detailsInfoLabel_counter;
    QPushButton* addDetailButton;

    QLabel* ifDetailsEmptyLabel;

    QWidget* detailsListWidget;
    QGridLayout* detailsListTable;

    QWidget* carsWidget;
    QVBoxLayout* carsLayout;

    QWidget* carsInfoWidget;
    QHBoxLayout* carsInfoLayout;
    QLabel* carsInfoLabel;
    QLabel* carsInfoLabel_counter;
    QPushButton* addCarButton;

    QLabel* ifCarsEmptyLabel;

    QWidget* carsListWidget;
    QGridLayout* carsListTable;

    LayoutSpinBox* amountSpinBoxLayout;

    QWidget* buttonsWidget;
    QLayout* buttonsLayout;
    QPushButton* saveButton;
    QPushButton* cancelButton;

    Line* hLine1;
    Line* hLine2;

    QSpacerItem* buttonsSpacer;
    QSpacerItem* detailsInfoSpacer;
    QSpacerItem* carsInfoSpacer;
    QSpacerItem* areaSpacer;

    AddDetailWindow* addDetailModalWindow;
    AddCarWindow* addCarModalWindow;

    Product newProduct;
public:
    AddProductWindow(QWidget* parent = nullptr);

    void alert(QString message);
    void info(QString message);

    void setupDetailsList();
    void setupCarsList();

    void addCar(const Car& carToAdd);
    void addDetail(const Detail& detailToAdd);

    Product getProduct() const;

    void setProduct(const Product& _product);

public slots:
    void onSaveButtonClicked();
    void onCancelButtonClicked();
    void onAddDetailButtonClicked();
    void onAddCarButtonClicked();

signals:
    void productSaved(Product newProduct);
};

#endif // ADDPRODUCTWINDOW_H
