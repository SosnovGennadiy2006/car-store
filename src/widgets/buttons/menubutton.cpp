#include "menubutton.h"

MenuButton::MenuButton(QWidget *parent)
    : QWidget{parent}
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("QWidget {"
                        "   background: #fff;"
                        "   border-bottom: 1px solid #222;"
                        "   color: #222;"
                        "}"
                        "QWidget:hover {"
                        "   background: #5DADE2;"
                        "   color: #fff;"
                        "}");
    this->setFixedHeight(70);
    this->setCursor(Qt::CursorShape::PointingHandCursor);

    layout = new QHBoxLayout(this);

    QFont font;
    font.setPixelSize(24);

    buttonText = new QLabel(this);
    buttonText->setFont(font);
    buttonText->setAlignment(Qt::AlignmentFlag::AlignCenter);

    layout->addWidget(buttonText);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
}

QString MenuButton::text() const
{
    return buttonText->text();
}

void MenuButton::setText(const QString &newText)
{
    buttonText->setText(newText);
}

void MenuButton::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    this->setStyleSheet("QWidget {"
                        "   background: #fff;"
                        "   border-bottom: 1px solid #222;"
                        "   color: #222;"
                        "}"
                        "QWidget:hover {"
                        "   background: #3498DB;"
                        "   color: #fff;"
                        "}");
    emit clicked();
}

void MenuButton::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    this->setStyleSheet("QWidget {"
                        "   background: #fff;"
                        "   border-bottom: 1px solid #222;"
                        "   color: #222;"
                        "}"
                        "QWidget:hover {"
                        "   background: #5DADE2;"
                        "   color: #fff;"
                        "}");
}
