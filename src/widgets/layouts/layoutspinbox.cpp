#include "layoutspinbox.h"

LayoutSpinBox::LayoutSpinBox(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QHBoxLayout(this);

    layoutText = new QLabel(this);
    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding,
                             QSizePolicy::Minimum);
    spinBox = new QSpinBox(this);

    mainLayout->addWidget(layoutText);
    mainLayout->addItem(spacer);
    mainLayout->addWidget(spinBox);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    connect(spinBox, &QSpinBox::valueChanged, this, [this](){ emit changed();});
}

void LayoutSpinBox::setLabelText(const QString &newText)
{
    layoutText->setText(newText);
}

void LayoutSpinBox::setValue(int newVal)
{
    spinBox->setValue(newVal);
}

int LayoutSpinBox::getValue() const
{
    return spinBox->value();
}

void LayoutSpinBox::setMinimum(int _min)
{
    spinBox->setMinimum(_min);
}

void LayoutSpinBox::setMaximum(int _max)
{
    spinBox->setMaximum(_max);
}

void LayoutSpinBox::setFont(const QFont &font)
{
    layoutText->setFont(font);
    spinBox->setFont(font);
}

void LayoutSpinBox::setLineEditMinWidth(int newWidth)
{
    spinBox->setFixedWidth(newWidth);
}

void LayoutSpinBox::setSuffix(const QString &newSuffix)
{
    spinBox->setSuffix(newSuffix);
}
