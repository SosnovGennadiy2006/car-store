#include "profilelineedit_phone.h"

ProfileLineEdit_Phone::ProfileLineEdit_Phone(QWidget *parent)
    : QWidget{parent}
{
    init_UI();

    connect(mainButton, &QPushButton::clicked, this, &ProfileLineEdit_Phone::onButtonClicked);
}

void ProfileLineEdit_Phone::init_UI()
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

    lineEdit = new PhoneNumberLineEdit(this);
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

void ProfileLineEdit_Phone::initValue(const QString& newVal)
{
    if (newVal != "")
    {
        lineEditContent->setText(newVal);
        lineEditContent->setStyleSheet("color: #000;");
    }
    else
    {
        lineEditContent->setText("not specified");
        lineEditContent->setStyleSheet("color: #e53935;");
    }
    lineEdit->setValue(newVal);
}

void ProfileLineEdit_Phone::setValue(const QString& newVal)
{
    if (newVal != "000-000-0000")
    {
        if (newVal != lineEditContent->text())
            emit edited();
        lineEditContent->setText(newVal);
        lineEditContent->setStyleSheet("color: #000;");
    }
    else
    {
        if (lineEditContent->text() != "000-000-0000")
            emit edited();
        lineEditContent->setText("not specified");
        lineEditContent->setStyleSheet("color: #e53935;");
    }
    lineEdit->setValue(newVal);
}

QString ProfileLineEdit_Phone::getValue()
{
    if (lineEdit->value() == "000-000-0000")
        return "";
    return lineEdit->value();
}

void ProfileLineEdit_Phone::onButtonClicked()
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
