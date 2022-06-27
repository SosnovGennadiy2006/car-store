#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpacerItem>


class InfoWidget : public QWidget
{
    QHBoxLayout* mainLayout;
    QLabel* name;
    QSpacerItem* spacer;
    QLabel* info;

public:
    explicit InfoWidget(QWidget* parent = nullptr) : QWidget{parent}
    {
        QFont normalFont;
        normalFont.setPixelSize(16);
        QFont boldFont;
        boldFont.setPixelSize(16);
        boldFont.setBold(true);

        mainLayout = new QHBoxLayout(this);

        name = new QLabel(this);
        name->setFont(normalFont);
        spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
        info = new QLabel(this);
        info->setFont(boldFont);

        mainLayout->addWidget(name);
        mainLayout->addItem(spacer);
        mainLayout->addWidget(info);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        this->setLayout(mainLayout);
    }

    void setName(const QString& newName)
    {
        name->setText(newName);
    }

    void setInfo(const QString& newInfo)
    {
        info->setText(newInfo);
    }
};


#endif // INFOWIDGET_H
