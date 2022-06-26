#ifndef LAYOUTSPINBOX_H
#define LAYOUTSPINBOX_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QSpinBox>

class LayoutSpinBox : public QWidget
{
    Q_OBJECT

    QHBoxLayout* mainLayout;
    QSpacerItem* spacer;
    QLabel* layoutText;
    QSpinBox* spinBox;
public:
    explicit LayoutSpinBox(QWidget *parent = nullptr);

    void setLabelText(const QString& newText);
    void setValue(int newVal);
    int getValue() const;
    void setMinimum(int _min);
    void setMaximum(int _max);
    void setFont(const QFont& font);
    void setLineEditMinWidth(int newWidth);
    void setSuffix(const QString& newSuffix);

signals:
    void changed();
};

#endif // LAYOUTSPINBOX_H
