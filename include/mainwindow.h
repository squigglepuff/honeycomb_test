#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>

#include "include/honeycomb.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

protected:
    void paintEvent(QPaintEvent *apEvent);

private:
    CHoneyComb *mpComb;
};

#endif // MAINWINDOW_H
