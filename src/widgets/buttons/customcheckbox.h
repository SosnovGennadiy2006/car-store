#ifndef CUSTOMCHECKBOX_H
#define CUSTOMCHECKBOX_H

#include <QCheckBox>
#include <QObject>
#include <QWidget>

class CustomCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    CustomCheckBox(QWidget* parent);

public slots:
    void onCheckStateChanged();
};

#endif // CUSTOMCHECKBOX_H
