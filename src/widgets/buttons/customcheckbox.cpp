#include "customcheckbox.h"

CustomCheckBox::CustomCheckBox(QWidget* parent) : QCheckBox{parent}
{
    this->setText("No");
    this->setCursor(Qt::CursorShape::PointingHandCursor);

    connect(this, &CustomCheckBox::stateChanged, this, &CustomCheckBox::onCheckStateChanged);
}

void CustomCheckBox::onCheckStateChanged()
{
    if (this->checkState() == Qt::CheckState::Checked)
    {
        this->setText("Yes");
    }else
    {
        this->setText("No");
    }
}
