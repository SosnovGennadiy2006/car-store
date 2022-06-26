#ifndef LAYOUTLINEEDIT_H
#define LAYOUTLINEEDIT_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QLineEdit>

class LayoutLineEdit : public QWidget
{
    Q_OBJECT

    QHBoxLayout* mainLayout;
    QSpacerItem* spacer;
    QLabel* layoutText;
    QLineEdit* lineEdit;
public:
    explicit LayoutLineEdit(QWidget *parent = nullptr);

    void setLabelText(const QString& newText);
    void setText(const QString& newText);
    void setPlaceholder(const QString& newText);
    QString getText() const;
    void setFont(const QFont& font);
    void setLineEditMinWidth(int newWidth);

signals:
    void changed();
};

#endif // LAYOUTLINEEDIT_H
