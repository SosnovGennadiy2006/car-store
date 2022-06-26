#ifndef USERORDERSWIDGET_H
#define USERORDERSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <logics/order.h>
#include <widgets/line.h>

class UserOrdersWidget : public QWidget
{
    Q_OBJECT

    QVector<Order> orders;

    QVBoxLayout* mainLayout;
    QLabel* infoLabel;
    QWidget* gridWidget;
    QGridLayout* grid;

public:
    explicit UserOrdersWidget(QWidget *parent = nullptr);

    QVector<Order> getOrders() const;
    Order getOrder(qsizetype idx) const;

    void setOrders(const QVector<Order>& newOrders);
    void setOrder(qsizetype idx, const Order& newOrder);

    void addOrder(const Order& newOrder);

signals:

};

#endif // USERORDERSWIDGET_H
