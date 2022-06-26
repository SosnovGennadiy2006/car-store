#include "layoutcombobox.h"

LayoutComboBox::LayoutComboBox(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QHBoxLayout(this);

    layoutText = new QLabel(this);
    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding,
                             QSizePolicy::Minimum);
    comboBox = new QComboBox(this);

    mainLayout->addWidget(layoutText);
    mainLayout->addItem(spacer);
    mainLayout->addWidget(comboBox);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    connect(comboBox, &QComboBox::currentIndexChanged, this, [this](){ emit changed();});
}

void LayoutComboBox::setLabelText(const QString& newText)
{
    layoutText->setText(newText);
}

void LayoutComboBox::setIndex(int newIndex)
{
    comboBox->setCurrentIndex(newIndex);
}

void LayoutComboBox::addItem(const QString& newItemText)
{
    comboBox->addItem(newItemText);
}

QString LayoutComboBox::getText() const
{
    return comboBox->currentText();
}

int LayoutComboBox::getIndex() const
{
    return comboBox->currentIndex();
}

void LayoutComboBox::setFont(const QFont &font)
{
    layoutText->setFont(font);
    comboBox->setFont(font);
}

void LayoutComboBox::setLineEditMinWidth(int newWidth)
{
    comboBox->setFixedWidth(newWidth);
}
