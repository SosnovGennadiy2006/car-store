#include "layoutlineedit.h"

LayoutLineEdit::LayoutLineEdit(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QHBoxLayout(this);

    layoutText = new QLabel(this);
    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding,
                             QSizePolicy::Minimum);
    lineEdit = new QLineEdit(this);

    mainLayout->addWidget(layoutText);
    mainLayout->addItem(spacer);
    mainLayout->addWidget(lineEdit);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    connect(lineEdit, &QLineEdit::textChanged, this, [this](){ emit changed();});
}

void LayoutLineEdit::setLabelText(const QString& newText)
{
    layoutText->setText(newText);
}

void LayoutLineEdit::setPlaceholder(const QString &newText)
{
    lineEdit->setPlaceholderText(newText);
}

void LayoutLineEdit::setText(const QString &newText)
{
    lineEdit->setText(newText);
}

QString LayoutLineEdit::getText() const
{
    return lineEdit->text();
}

void LayoutLineEdit::setFont(const QFont &font)
{
    layoutText->setFont(font);
    lineEdit->setFont(font);
}

void LayoutLineEdit::setLineEditMinWidth(int newWidth)
{
    lineEdit->setFixedWidth(newWidth);
}
