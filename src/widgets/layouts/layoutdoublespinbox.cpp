#include "layoutdoublespinbox.h"

LayoutDoubleSpinBox::LayoutDoubleSpinBox(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QHBoxLayout(this);

    layoutText = new QLabel(this);
    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding,
                             QSizePolicy::Minimum);
    spinBox = new QDoubleSpinBox(this);

    mainLayout->addWidget(layoutText);
    mainLayout->addItem(spacer);
    mainLayout->addWidget(spinBox);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    connect(spinBox, &QDoubleSpinBox::valueChanged, this, [this](){ emit changed();});
}

void LayoutDoubleSpinBox::setLabelText(const QString &newText)
{
    layoutText->setText(newText);
}

void LayoutDoubleSpinBox::setValue(double newVal)
{
    spinBox->setValue(newVal);
}

double LayoutDoubleSpinBox::getValue() const
{
    return spinBox->value();
}

void LayoutDoubleSpinBox::setMinimum(int _min)
{
    spinBox->setMinimum(_min);
}

void LayoutDoubleSpinBox::setMaximum(int _max)
{
    spinBox->setMaximum(_max);
}

void LayoutDoubleSpinBox::setFont(const QFont &font)
{
    layoutText->setFont(font);
    spinBox->setFont(font);
}

void LayoutDoubleSpinBox::setLineEditMinWidth(int newWidth)
{
    spinBox->setFixedWidth(newWidth);
}

void LayoutDoubleSpinBox::setSuffix(const QString &newSuffix)
{
    spinBox->setSuffix(newSuffix);
}
