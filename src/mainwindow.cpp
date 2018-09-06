#include <QtGui>
#include "include/mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent), mpComb{nullptr}
{
    // Set the window properties.
    setWindowTitle(tr("Hexagon Draw Test"));
    resize(768, 768);

    QPointF qCenter(width() / 2.0, height() / 2.0);

    // Setup the honeycomb.
    mpComb = new CHoneyComb();
    mpComb->SetPosition(qCenter);
    mpComb->SetCellSize(256);

    mpComb->GetCells()[0].SetColor(Cell_White);
    mpComb->GetCells()[1].SetColor(Cell_Red);
    mpComb->GetCells()[2].SetColor(Cell_Orange);
    mpComb->GetCells()[3].SetColor(Cell_Yellow);
    mpComb->GetCells()[4].SetColor(Cell_Lime);
    mpComb->GetCells()[5].SetColor(Cell_Green);
    mpComb->GetCells()[6].SetColor(Cell_Cyan);
}

CMainWindow::~CMainWindow()
{
    // Intentionally left blank.
}

void CMainWindow::paintEvent(QPaintEvent *apEvent)
{
    if (nullptr != apEvent && nullptr != mpComb)
    {
        QPainter *pPainter = new QPainter();
        pPainter->begin(this);
        mpComb->Draw(pPainter);
        pPainter->end();

        if (nullptr != pPainter) { delete pPainter; }
    }
    else
    {
        qCritical("apEvent for paintEvent is a nullptr! Aborting paint!");
    }
}
