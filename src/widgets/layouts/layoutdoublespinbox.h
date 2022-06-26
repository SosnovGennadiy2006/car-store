#ifndef LAYOUTDOUBLESPINBOX_H
#define LAYOUTDOUBLESPINBOX_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QDoubleSpinBox>

class LayoutDoubleSpinBox : public QWidget
{
    Q_OBJECT

    QHBoxLayout* mainLayout;
    QSpacerItem* spacer;
    QLabel* layoutText;
    QDoubleSpinBox* spinBox;
public:
    explicit LayoutDoubleSpinBox(QWidget *parent = nullptr);

    void setLabelText(const QString& newText);
    void setValue(double newVal);
    double getValue() const;
    void setMinimum(int _min);
    void setMaximum(int _max);
    void setFont(const QFont& font);
    void setLineEditMinWidth(int newWidth);
    void setSuffix(const QString& newSuffix);

signals:
    void changed();

};

#endif // LAYOUTDOUBLESPINBOX_H
