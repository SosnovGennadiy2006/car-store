#ifndef LAYOUTCOMBOBOX_H
#define LAYOUTCOMBOBOX_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QComboBox>

class LayoutComboBox : public QWidget
{
    Q_OBJECT

    QHBoxLayout* mainLayout;
    QSpacerItem* spacer;
    QLabel* layoutText;
    QComboBox* comboBox;
public:
    explicit LayoutComboBox(QWidget *parent = nullptr);

    void setLabelText(const QString& newText);
    void setIndex(int newIndex);
    void addItem(const QString& newItemText);
    QString getText() const;
    int getIndex() const;
    void setFont(const QFont& font);
    void setLineEditMinWidth(int newWidth);

signals:
    void changed();
};

#endif // LAYOUTCOMBOBOX_H
