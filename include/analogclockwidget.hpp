#ifndef ANALOGCLOCKWIDGET_HPP
#define ANALOGCLOCKWIDGET_HPP

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QTime>


class AnalogClockWidget : public QWidget
{
    Q_OBJECT
private:
    QTimer* timer;
protected:
    void paintEvent(QPaintEvent*) override;
public:
    explicit AnalogClockWidget(QWidget *parent = nullptr);
};

#endif // ANALOGCLOCKWIDGET_HPP
