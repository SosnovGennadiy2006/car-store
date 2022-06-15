#include "profilelineedit_string.h"

ProfileLineEdit_String::ProfileLineEdit_String(QWidget *parent)
    : QWidget{parent}
{
    init_UI();

    connect(mainButton, &QPushButton::clicked, this, &ProfileLineEdit_String::onButtonClicked);
    connect(lineEdit, &QLineEdit::returnPressed, mainButton, &QPushButton::click);
}

void ProfileLineEdit_String::init_UI()
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
    value = "";

    lineEdit = new QLineEdit(this);
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

void ProfileLineEdit_String::initValue(const QString& newVal)
{
    value = newVal;
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
    lineEdit->setText(newVal);
}

void ProfileLineEdit_String::setValue(const QString& newVal)
{
    value = newVal;
    if (newVal != "")
    {
        if (newVal != lineEditContent->text())
            emit edited();
        lineEditContent->setText(newVal);
        lineEditContent->setStyleSheet("color: #000;");
    }
    else
    {
        if (lineEditContent->text() != "")
            emit edited();
        lineEditContent->setText("not specified");
        lineEditContent->setStyleSheet("color: #e53935;");
    }
    lineEdit->setText(newVal);
}

QString ProfileLineEdit_String::getValue()
{
    return value;
}

void ProfileLineEdit_String::onButtonClicked()
{
    if (state)
    {
        lineEditContent->show();
        lineEdit->hide();
        mainButton->setIcon(QIcon(":/icons/write_icon"));
        setValue(lineEdit->text());
    }else
    {
        lineEditContent->hide();
        lineEdit->show();
        mainButton->setIcon(QIcon(":/icons/ok_icon"));
    }
    state = 1 - state;
}
