#include "profilelineedit_int.h"

ProfileLineEdit_Int::ProfileLineEdit_Int(QWidget *parent)
    : QWidget{parent}
{
    init_UI();

    connect(mainButton, &QPushButton::clicked, this, &ProfileLineEdit_Int::onButtonClicked);
}

void ProfileLineEdit_Int::init_UI()
{

    QFont font;
    font.setPixelSize(16);

    this->setFont(font);

    state = false;

    mainLayout = new QHBoxLayout(this);

    lineEditContent = new QLabel(this);
    lineEditContent->setFont(font);
    lineEditContent->setText("not specified");
    lineEditContent->setStyleSheet("color: #e53935;");

    lineEdit = new QSpinBox(this);
    lineEdit->setValue(0);
    lineEdit->hide();

    mainButton = new QPushButton(this);
    mainButton->setIcon(QIcon(":/icons/write_icon"));
    mainButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    mainButton->setStyleSheet("border: 1px solid #222; padding: 4px;");

    mainLayout->addWidget(lineEditContent);
    mainLayout->addWidget(lineEdit);
    mainLayout->addWidget(mainButton);
    mainLayout->setContentsMargins(0, 0, 0, 0);
}

void ProfileLineEdit_Int::initValue(const qint32& newVal)
{
    if (newVal != -1)
    {
        lineEditContent->setText(QString::number(newVal));
        lineEditContent->setStyleSheet("color: #000;");
    }
    else
    {
        lineEditContent->setText("not specified");
        lineEditContent->setStyleSheet("color: #e53935;");
    }
    lineEdit->setValue(newVal);
}

void ProfileLineEdit_Int::setValue(const qint32& newVal)
{
    if (newVal != lineEditContent->text().toInt())
        emit edited();
    if (newVal != -1 && newVal != 0)
    {
        lineEditContent->setText(QString::number(newVal));
        lineEditContent->setStyleSheet("color: #000;");
    }
    else
    {
        lineEditContent->setText("not specified");
        lineEditContent->setStyleSheet("color: #e53935;");
    }
    lineEdit->setValue(newVal);
}

qint32 ProfileLineEdit_Int::getValue()
{
    qint32 val = lineEdit->value();
    if (val == 0)
    {
        return -1;
    }
    return val;
}

void ProfileLineEdit_Int::onButtonClicked()
{
    if (state)
    {
        lineEditContent->show();
        lineEdit->hide();
        mainButton->setIcon(QIcon(":/icons/write_icon"));
        setValue(lineEdit->value());
    }else
    {
        lineEditContent->hide();
        lineEdit->show();
        mainButton->setIcon(QIcon(":/icons/ok_icon"));
    }
    state = 1 - state;
}

void ProfileLineEdit_Int::setMinValue(const qint32& _min)
{
    lineEdit->setMinimum(_min);
}

void ProfileLineEdit_Int::setMaxValue(const qint32& _max)
{
    lineEdit->setMaximum(_max);
}
