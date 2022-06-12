#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QFont>
#include <QStyle>

class MenuButton : public QWidget
{
    Q_OBJECT

    QLabel* buttonText;
    QHBoxLayout* layout;

public:
    explicit MenuButton(QWidget *parent = nullptr);

    QString text() const;

    void setText(const QString& newText);

    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;

signals:
    void clicked();
};

#endif // MENUBUTTON_H
