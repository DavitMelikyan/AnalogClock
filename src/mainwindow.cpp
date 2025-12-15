#include "mainwindow.hpp"
#include "analogclockwidget.hpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto* clock = new AnalogClockWidget(this);
    setCentralWidget(clock);
    setStyleSheet("background-color: #303030;");
    setMinimumSize(450, 450);
    setWindowTitle("Analog Clock");
}

MainWindow::~MainWindow() {}
