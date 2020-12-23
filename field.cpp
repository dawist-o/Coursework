#include "field.h"
#include <QDebug>
#include <QPainter>

Field::Field(QWidget *parent) : QWidget(parent)
{
    init();
    this->setCursor(Qt::CrossCursor);
}

void Field::init()
{
    qDebug()<<"Field: init called";
    for (int i=0; i<columnsCount; ++i ) {
        QVector<Cell> tempVector;
        for (int j=0; j< rowsCount; ++j) {
            tempVector.append(Cell{QRectF(i*cellSize,j*cellSize,cellSize,cellSize),QBrush(defaultColor)});
        }
        cells.append(tempVector);
    }
}

void Field::floodFill(int x, int y, QColor newC)
{
    QColor prevC = cells[x][y].brush.color();
    floodFillUtil(x, y, prevC, newC);
}

void Field::reset()
{
    for (int i=0; i<cells.size(); ++i ) {
        for (int j=0; j<cells.at(i).size();++j) {
            cells[i][j].brush.setColor(defaultColor);
        }
    }
    this->update();
}

void Field::floodFillUtil(int x, int y, QColor prevC, QColor newC)
{
    if (x < 0 || x >= columnsCount || y < 0 || y >= rowsCount)
        return;

    if (cells[x][y].brush.color() != prevC)
        return;

    if (cells[x][y].brush.color() == newC)
        return;

    // Replace the color at (x, y)
    cells[x][y].brush.setColor(newC);

    // Recur for north, east, south and west
    floodFillUtil(x+1, y, prevC, newC);
    floodFillUtil(x-1, y, prevC, newC);
    floodFillUtil(x, y+1, prevC, newC);
    floodFillUtil(x, y-1, prevC, newC);
}

void Field::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"Press event";
    switch(event->key()){
    case Qt::Key_Right:
        moveFieldRight();
        this->update();
        break;
    case Qt::Key_Left:
        moveFieldLeft();
        this->update();
        break;
    case Qt::Key_Up:
        moveFieldUp();
        this->update();
        break;
    case Qt::Key_Down:
        moveFieldDown();
        this->update();
        break;
    }
}
void Field::moveFieldRight()
{
    if(cells.size()<1) return;

    QVector<Cell> lastColumn = cells[cells.size()-1];
    for(int x=cells.size()-1;x>0;x--){
        cells[x]=cells[x-1];
    }
    cells[0]=lastColumn;
}

void Field::moveFieldLeft(){
    if(cells.size()<1) return;

    QVector<Cell> firstColumn = cells[0];
    for(int x=1;x<cells.size();x++){
        cells[x-1]=cells[x];
    }
    cells[cells.size()-1]=firstColumn;
}

void Field::moveFieldUp()
{
    if(cells.size()<1) return;
    if(cells[0].size()<1) return;

    QVector<Cell> firstRow;
    for(int x=0; x<cells.size();x++){
        firstRow.append(cells[x][0]);
    }
    for(int y=0;y<cells[0].size()-1;y++){
        for(int x=0;x<cells.size();x++){
            cells[x][y].brush.setColor(cells[x][y+1].brush.color());
        }
    }
    for(int x=0; x<cells.size();x++){
        cells[x][cells[0].size()-1].brush.setColor(firstRow[x].brush.color());
    }
}

void Field::moveFieldDown()
{
    if(cells.size()<1) return;
    if(cells[0].size()<1) return;

    QVector<Cell> lastRow;
    for(int x=0; x<cells.size();x++){
        lastRow.append(cells[x][cells[0].size()-1]);
    }
    for(int y=cells[0].size()-1;y>0;y--){
        for(int x=0;x<cells.size();x++){
            cells[x][y].brush.setColor(cells[x][y-1].brush.color());
        }
    }
    for(int x=0; x<cells.size();x++){
        cells[x][0].brush.setColor(lastRow[x].brush.color());
    }
}

void Field::resizeCell()
{
    double cellWidth=(double) (this->width()-1)/columnsCount;
    double cellHeight=(double) (this->height()-1)/rowsCount;

    if(cellWidth<cellHeight){
        cellSize=cellWidth;
        offset=0;
    }else{
        cellSize=cellHeight;
        offset=(this->width() - cellSize*columnsCount)/2;
    }
    qDebug()<<"Cell size: "<<cellSize;
    qDebug()<<"Field size: width= "<<this->width()<<" height= "<<this->height();
    for (int i=0; i<cells.size(); ++i ) {
        for (int j=0; j<cells.at(i).size();++j) {
            cells[i][j].rect.setCoords(offset+i*cellSize,j*cellSize,
                                       offset+(i+1)*cellSize,(j+1)*cellSize);
        }
    }
}

void Field::addColumn()
{
    if(columnsCount >= maxColumnsCount) return;

    columnsCount++;
    QVector<Cell> tempVector;
    for (int j=0; j< rowsCount; ++j) {
        tempVector.append(Cell{QRectF((columnsCount-1)*cellSize,j*cellSize,cellSize,cellSize),QBrush(defaultColor)});
    }
    cells.append(tempVector);
    this->update();
}

void Field::removeColumn()
{
    if(columnsCount <= minColumnsCount) return;

    columnsCount--;
    cells.removeLast();
    this->update();
}

void Field::addRow()
{
    if(rowsCount >= maxRowsCount) return;

    for (int i=0; i<cells.size() ;++i ) {
        cells[i].append(Cell{QRectF(i*cellSize,rowsCount*cellSize,cellSize,cellSize),QBrush(defaultColor)});
    }
    rowsCount++;
    this->update();

}

void Field::removeRow()
{
    if(rowsCount <= minRowsCount) return;

    for (int i=0; i<cells.size() ;++i ) {
        cells[i].removeLast();
    }
    rowsCount--;
    this->update();
}

void Field::mousePressEvent(QMouseEvent *event)
{
    draw(event);
}


void Field::mouseMoveEvent(QMouseEvent *event)
{
    draw(event);
}

void Field::draw(QMouseEvent *event){
    int xPos=event->pos().x();
    int yPos=event->pos().y();

    if(xPos<=offset) return;

    int xVectorPos=(xPos-offset)/cellSize;
    int yVectorPos=yPos/cellSize;

    qDebug()<<"x pos = "<<xVectorPos<<" y pos = "<<yVectorPos;

    if(xVectorPos >= columnsCount || yVectorPos >= rowsCount ||
            xVectorPos < 0 || yVectorPos < 0) return;

    switch (currentMode) {
    case Mode::bucket:
        floodFill(xVectorPos,yVectorPos,currentColor);
        break;

    case Mode::colorPicking:
        currentColor=cells[xVectorPos][yVectorPos].brush.color();
        currentMode=Mode::drawing;
        break;

    case Mode::drawing:
        cells[xVectorPos][yVectorPos].brush.setColor(currentColor);
        break;

    case Mode::eraser:
        currentColor=defaultColor;
        cells[xVectorPos][yVectorPos].brush.setColor(currentColor);
        break;
    }

    this->update();
}

void Field::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen({QColor("#bbbbbb"),1});
    qDebug()<<"Field: paint event called";
    resizeCell();
    for (int i=0; i<cells.size(); ++i ) {
        for (int j=0; j<cells.at(i).size();++j) {
            painter.setBrush(cells.at(i).at(j).brush);
            painter.drawRect(cells.at(i).at(j).rect);
        }
    }
}

int Field::getRowsCount(){
    return this->rowsCount;
}

int Field::getColumnsCount(){
    return this->columnsCount;
}

QVector<QVector<Cell>> Field::getCells(){
    return this->cells;
}

int Field::getCellSize(){
    return this->cellSize;
}

double Field::getOffset(){
    return this->offset;
}


