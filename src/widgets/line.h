#ifndef LINE_H
#define LINE_H

#include <QFrame>

class Line : public QFrame
{
    Q_OBJECT

public:
    Line(QWidget* parent = nullptr) : QFrame{parent}
    {    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
         setFixedHeight(1);
         setFrameShape(QFrame::HLine);
         setFrameShadow(QFrame::Sunken);
         setStyleSheet("background: #222;");
    }
};

class VLine : public QFrame
{
    Q_OBJECT

public:
    VLine(QWidget* parent = nullptr) : QFrame{parent}
    {    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
         setFixedWidth(1);
         setFrameShape(QFrame::VLine);
         setFrameShadow(QFrame::Sunken);
         setStyleSheet("background: #222;");
    }
};

#endif // LINE_H
