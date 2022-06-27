#include "userorderswidget.h"

UserOrdersWidget::UserOrdersWidget(QWidget *parent)
    : QWidget{parent}
{
    QFont normalFont;
    normalFont.setPixelSize(16);

    QFont boldFont;
    boldFont.setPixelSize(16);
    boldFont.setBold(true);

    this->setFont(normalFont);

    orders = QVector<Order>(0);

    mainLayout = new QVBoxLayout(this);

    infoLabel = new QLabel(this);
    infoLabel->setText("You don't have any orders!");
    infoLabel->setStyleSheet("color: #e53935;");
    infoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
    infoLabel->setFont(normalFont);

    gridWidget = new QWidget(this);
    gridWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    grid = new QGridLayout();
    gridWidget->setLayout(grid);
    grid->setRowStretch(0, 0);

    QLabel* orderCustomerIdLabel = new QLabel();
    orderCustomerIdLabel->setText("Customer ID");
    orderCustomerIdLabel->setFont(boldFont);
    orderCustomerIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderIdLabel = new QLabel();
    orderIdLabel->setText("Order ID");
    orderIdLabel->setFont(boldFont);
    orderIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderPlacedDateLabel = new QLabel();
    orderPlacedDateLabel->setText("Placed date");
    orderPlacedDateLabel->setFont(boldFont);
    orderPlacedDateLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderDeliveryDateLabel = new QLabel();
    orderDeliveryDateLabel->setText("Delivery date");
    orderDeliveryDateLabel->setFont(boldFont);
    orderDeliveryDateLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderStateLabel = new QLabel();
    orderStateLabel->setText("Order state");
    orderStateLabel->setFont(boldFont);
    orderStateLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderPriceLabel = new QLabel();
    orderPriceLabel->setText("Price");
    orderPriceLabel->setFont(boldFont);
    orderPriceLabel->setContentsMargins(3, 3, 3, 3);

    grid->addWidget(new Line(), 0, 0, 1, 13);
    grid->addWidget(new VLine(), 1, 0, 1, 1);
    grid->addWidget(orderCustomerIdLabel, 1, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 2, 1, 1);
    grid->addWidget(orderIdLabel, 1, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 4, 1, 1);
    grid->addWidget(orderPlacedDateLabel, 1, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 6, 1, 1);
    grid->addWidget(orderDeliveryDateLabel, 1, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 8, 1, 1);
    grid->addWidget(orderStateLabel, 1, 9, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 10, 1, 1);
    grid->addWidget(orderPriceLabel, 1, 11, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 12, 1, 1);
    grid->addWidget(new Line(), 2, 0, 1, 13);
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    mainLayout->addWidget(infoLabel);
    mainLayout->addWidget(gridWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    infoLabel->hide();
}

QVector<Order> UserOrdersWidget::getOrders() const
{
    return orders;
}

Order UserOrdersWidget::getOrder(qsizetype idx) const
{
    return orders[idx];
}

void UserOrdersWidget::setOrders(const QVector<Order>& newOrders)
{
    QFont boldFont;
    boldFont.setPixelSize(16);
    boldFont.setBold(true);

    delete grid;
    grid = new QGridLayout();
    gridWidget->setLayout(grid);
    grid->setRowStretch(0, 0);

    QLabel* orderCustomerIdLabel = new QLabel();
    orderCustomerIdLabel->setText("Customer ID");
    orderCustomerIdLabel->setFont(boldFont);
    orderCustomerIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderIdLabel = new QLabel();
    orderIdLabel->setText("Order ID");
    orderIdLabel->setFont(boldFont);
    orderIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderPlacedDateLabel = new QLabel();
    orderPlacedDateLabel->setText("Placed date");
    orderPlacedDateLabel->setFont(boldFont);
    orderPlacedDateLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderDeliveryDateLabel = new QLabel();
    orderDeliveryDateLabel->setText("Delivery date");
    orderDeliveryDateLabel->setFont(boldFont);
    orderDeliveryDateLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderStateLabel = new QLabel();
    orderStateLabel->setText("Order state");
    orderStateLabel->setFont(boldFont);
    orderStateLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderPriceLabel = new QLabel();
    orderPriceLabel->setText("Price");
    orderPriceLabel->setFont(boldFont);
    orderPriceLabel->setContentsMargins(3, 3, 3, 3);

    grid->addWidget(new Line(), 0, 0, 1, 13);
    grid->addWidget(new VLine(), 1, 0, 1, 1);
    grid->addWidget(orderCustomerIdLabel, 1, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 2, 1, 1);
    grid->addWidget(orderIdLabel, 1, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 4, 1, 1);
    grid->addWidget(orderPlacedDateLabel, 1, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 6, 1, 1);
    grid->addWidget(orderDeliveryDateLabel, 1, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 8, 1, 1);
    grid->addWidget(orderStateLabel, 1, 9, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 10, 1, 1);
    grid->addWidget(orderPriceLabel, 1, 11, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), 1, 12, 1, 1);
    grid->addWidget(new Line(), 2, 0, 1, 13);
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    for (qsizetype i = 0 ; i < newOrders.size(); i++)
    {
        addOrder(newOrders[i]);
    }

    if (orders.size() == 0)
    {
        infoLabel->show();
        gridWidget->hide();
    }else
    {
        infoLabel->hide();
        gridWidget->show();
    }
}

void UserOrdersWidget::setOrder(qsizetype idx, const Order& newOrder)
{
    orders[idx] = newOrder;
}

void UserOrdersWidget::addOrder(const Order &newOrder)
{
    orders.push_back(newOrder);

    QFont normalFont;
    normalFont.setPixelSize(16);

    int i = grid->rowCount();

    QLabel* orderCustomerIdLabel = new QLabel();
    orderCustomerIdLabel->setText(QString::number(newOrder.getCustomerID()));
    orderCustomerIdLabel->setFont(normalFont);
    orderCustomerIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderIdLabel = new QLabel();
    orderIdLabel->setText(QString::number(newOrder.getOrderID()));
    orderIdLabel->setFont(normalFont);
    orderIdLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderPlacedDateLabel = new QLabel();
    orderPlacedDateLabel->setText(newOrder.getOrderPlacedDate());
    orderPlacedDateLabel->setFont(normalFont);
    orderPlacedDateLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderDeliveryDateLabel = new QLabel();
    orderDeliveryDateLabel->setText(newOrder.getDeliveryDate());
    orderDeliveryDateLabel->setFont(normalFont);
    orderDeliveryDateLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderStateLabel = new QLabel();
    orderStateLabel->setText(Order::orderTypeToString(newOrder.getOrderType()));
    orderStateLabel->setFont(normalFont);
    orderStateLabel->setContentsMargins(3, 3, 3, 3);
    QLabel* orderPriceLabel = new QLabel();
    orderPriceLabel->setText(QString::number(newOrder.getPrice()));
    orderPriceLabel->setFont(normalFont);
    orderPriceLabel->setContentsMargins(3, 3, 3, 3);

    grid->addWidget(new VLine(), i, 0, 1, 1);
    grid->addWidget(orderCustomerIdLabel, i, 1, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 2, 1, 1);
    grid->addWidget(orderIdLabel, i, 3, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 4, 1, 1);
    grid->addWidget(orderPlacedDateLabel, i, 5, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 6, 1, 1);
    grid->addWidget(orderDeliveryDateLabel, i, 7, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 8, 1, 1);
    grid->addWidget(orderStateLabel, i, 9, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 10, 1, 1);
    grid->addWidget(orderPriceLabel, i, 11, 1, 1, Qt::AlignmentFlag::AlignCenter);
    grid->addWidget(new VLine(), i, 12, 1, 1);
    grid->addWidget(new Line(), i+1, 0, 1, 13);

    if (orders.size() == 0)
    {
        infoLabel->show();
        gridWidget->hide();
    }else
    {
        infoLabel->hide();
        gridWidget->show();
    }
}
