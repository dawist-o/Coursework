#ifndef MYFIELD_H
#define MYFIELD_H

#include "cell.h"

#include <QWidget>
#include <QPaintEvent>
#include <QBrush>
#include <QVector>
#include <mode.h>

class Field : public QWidget
{
    Q_OBJECT

public:
    Mode currentMode=Mode::drawing;

    void addColumn();
    void removeColumn();

    void addRow();
    void removeRow();

    void reset();

    void moveFieldRight();
    void moveFieldLeft();
    void moveFieldUp();
    void moveFieldDown();

    QColor currentColor=QColor(255,255,255);

    Field(QWidget *parent= nullptr);

    int getRowsCount();
    int getColumnsCount();
    int getCellSize();
    QVector<QVector<Cell>> getCells();
    double getOffset();

private:
    const int maxRowsCount = 50;
    const int minRowsCount = 5;

    const int maxColumnsCount = 50;
    const int minColumnsCount = 5;
    int rowsCount=15;
    int columnsCount=15;
    double offset=0;

    double cellSize=50;
    QVector<QVector<Cell>> cells;
    void resizeCell();


    QColor defaultColor=QColor(255,255,255);

    void floodFill(int x, int y, QColor newC);
    void floodFillUtil(int x, int y, QColor prevC, QColor newC);

    void draw(QMouseEvent *event);

protected:
    void init();
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYFIELD_H
