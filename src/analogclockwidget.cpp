#include "../include/analogclockwidget.hpp"

AnalogClockWidget::AnalogClockWidget(QWidget *parent) : QWidget{parent} {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&AnalogClockWidget::update));
    timer->setInterval(16);
    timer->start();
}

void AnalogClockWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    double s = qMin(width(), height()) / 200.0;
    painter.translate(width() / 2, height() / 2);
    painter.scale(s, s);

    painter.setPen(Qt::NoPen);
    painter.setBrush("#000000");
    painter.drawEllipse(QPoint(0, 0), 97, 97);
    painter.setPen("#FFFFFF");
    painter.drawEllipse(QPoint(0, 0), 97, 97);

    QFont font = painter.font();
    font.setBold(true);
    font.setPointSize(14);
    painter.setFont(font);

    for (int i = 1; i <= 12; ++i) {
        painter.save();

        painter.rotate(i * 30.0);
        painter.translate(0, -80);
        painter.rotate(-i * 30.0);

        QRect textRect(-15, -15, 30, 30);
        painter.drawText(textRect, Qt::AlignCenter, QString::number(i));

        painter.restore();
    }

    const QTime time = QTime::currentTime();

    painter.save();
    painter.rotate(30.0 * (time.hour() % 12 + time.minute() / 60.0));
    painter.setPen(Qt::NoPen);
    painter.setBrush("#EDEDED");
    painter.drawRect(-4, -50, 4, 50);
    painter.restore();

    painter.setBrush("#FFFCFC");
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawRect(-2, -70, 4, 70);
    painter.restore();

    painter.save();
    painter.setPen("#F79316");
    painter.rotate(6.0 * time.second());
    painter.drawLine(0, 0, 0, -90);
    painter.restore();
}
