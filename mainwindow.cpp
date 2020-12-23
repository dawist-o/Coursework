#include "mainwindow.h"
#include "field.h"
#include "QDebug"

#include <QDesktopServices>
#include <QColorDialog>
#include <QFileDialog>
#include <QShortcut>
#include <savecss.h>
#include <QGraphicsDropShadowEffect>
#include <ui_mainwindow.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("Pixel art");
    ui->columnsCountLabel->setText(QString::number(ui->widget->getColumnsCount()));
    ui->rowsCountLabel->setText(QString::number(ui->widget->getRowsCount()));
    ui->pixelSizeLabel->setText(QString::number(pixelSize));
    ui->widget->setFocusPolicy(Qt::StrongFocus);
    addShortcuts();
    connectColorButtons();
}

void MainWindow::addShortcuts(){
    new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Right), this, SLOT(on_incColumnsCount_clicked()));
    new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Left), this, SLOT(on_decrColumnsCount_clicked()));
    new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Down), this, SLOT(on_incRowsCountButton_clicked()));
    new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Up), this, SLOT(on_decrRowsCountButton_clicked()));

    new QShortcut(QKeySequence(Qt::Key_I), this, SLOT(on_incPixelSizeButton_clicked()));
    new QShortcut(QKeySequence(Qt::Key_D), this, SLOT(on_decrPixelSizeButton_clicked()));

    new QShortcut(QKeySequence(Qt::Key_B), this, SLOT(on_fill_clicked()));
    new QShortcut(QKeySequence(Qt::Key_E), this, SLOT(on_eraser_clicked()));
    new QShortcut(QKeySequence(Qt::Key_P), this, SLOT(on_brushButton_clicked()));
}

void MainWindow::connectColorButtons(){
    connect(ui->colorButton,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_2,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_3,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_4,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_5,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_6,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_7,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_8,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_9,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_10,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_11,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_12,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_13,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_14,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_15,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_16,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_17,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_18,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_19,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_20,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_21,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_22,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_23,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton_24,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton__25,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton__26,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton__27,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton__28,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton__29,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton__30,SIGNAL(clicked()),this,SLOT(changeColor()));
    connect(ui->colorButton,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_2,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_3,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_4,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_5,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_6,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_7,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_8,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_9,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_10,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_11,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_12,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_13,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_14,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_15,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_16,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_17,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_18,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_19,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_20,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_21,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_22,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_23,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton_24,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton__25,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton__26,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton__27,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton__28,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton__29,SIGNAL(released()),this,SLOT(changeColor()));
    connect(ui->colorButton__30,SIGNAL(released()),this,SLOT(changeColor()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::holdPressed(){
    QPushButton *button= qobject_cast<QPushButton*>(sender());
    button->setDown(true);
}

void MainWindow::on_incRowsCountButton_clicked()
{
    ui->widget->addRow();
    ui->rowsCountLabel->setText(QString::number(ui->widget->getRowsCount()));
    qDebug()<<"rowsCount increased";

}

void MainWindow::on_decrRowsCountButton_clicked()
{

    ui->widget->removeRow();
    ui->rowsCountLabel->setText(QString::number(ui->widget->getRowsCount()));
    qDebug()<<"rowsCount decreased";

}

void MainWindow::on_incColumnsCount_clicked()
{

    ui->widget->addColumn();
    ui->columnsCountLabel->setText(QString::number(ui->widget->getColumnsCount()));
    qDebug()<<"columnsCount increased";

}

void MainWindow::on_decrColumnsCount_clicked()
{

    ui->widget->removeColumn();
    ui->columnsCountLabel->setText(QString::number(ui->widget->getColumnsCount()));
    qDebug()<<"columnsCount increased";

}

void MainWindow::on_eraser_released()
{
    ui->eraser->setDown(true);
}

void MainWindow::changeColor()
{
    QPushButton *button= qobject_cast<QPushButton*>(sender());
    if (!button)
        return;
    if(lastColorButton!=nullptr){
        lastColorButton->setDown(false);
    }
    lastColorButton=button;
    button->setDown(true);
    QStringList rows=button->styleSheet().split(";");
    int rowIndex=0;
    for(int i=0;i<rows.size();++i){
        if(rows[i].contains("background-color:")){
            rowIndex=i;
            break;
        }
    }

    QString backgroundLine=rows.at(rowIndex);
    int startIndex=backgroundLine.indexOf("(")+1;
    int rgbRange=backgroundLine.indexOf(")") - startIndex;
    QString rgbString = backgroundLine.mid(startIndex,rgbRange);

    qDebug()<<"Color changed : "<<rgbString;
    QStringList rgb=rgbString.split(",");
    QColor newColor = QColor(rgb.at(0).toInt(),
                             rgb.at(1).toInt(),
                             rgb.at(2).toInt());
    ui->widget->currentColor=newColor;
    ui->widget->currentMode=Mode::drawing;
    ui->fill->setDown(false);
    ui->eraser->setDown(false);
}


void MainWindow::on_fill_released()
{
    ui->fill->setDown(true);
}

void MainWindow::on_fill_clicked()
{
    ui->widget->currentMode=Mode::bucket;
    ui->fill->setDown(true);
    ui->eraser->setDown(false);
    ui->pickerButton->setDown(false);
}

void MainWindow::on_eraser_clicked()
{
    ui->widget->currentMode=Mode::eraser;
    ui->eraser->setDown(true);
    ui->fill->setDown(false);
    ui->pickerButton->setDown(false);
    if(lastColorButton!=nullptr)
        lastColorButton->setDown(false);
}

void MainWindow::on_pickerButton_clicked()
{
    ui->widget->currentMode=Mode::colorPicking;
    ui->pickerButton->setDown(true);
    ui->fill->setDown(false);
    ui->eraser->setDown(false);
    if(lastColorButton!=nullptr)
        lastColorButton->setDown(false);
}

void MainWindow::on_brushButton_clicked()
{
    ui->widget->currentMode=Mode::drawing;
    QColorDialog dialog;
    ui->fill->setDown(false);
    ui->eraser->setDown(false);
    ui->pickerButton->setDown(false);
    dialog.setOptions(QColorDialog::NoButtons);
    dialog.setStyleSheet("QColorDialog{background-color: rgb(235, 248, 255);}"
                         "QPushButton {"
                         "min-height: 30px;"
                         "background-color: rgb(255, 172, 172);"
                         "border-radius:10px;"
                         "border: 2px outset #fff;}");
    dialog.exec();
    QColor newColor =  dialog.currentColor();;
    if(newColor != ui->widget->currentColor){
        ui->widget->currentColor=newColor;
    }
}

void MainWindow::on_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save pixel art as image"), "pixel_art",
                                                    tr("PNG (*.png);;JPEG (*.jpg)"));
    if(fileName.isEmpty()||fileName.isNull()) return;
    QPixmap pixmap(QSize(ui->widget->getCellSize()*ui->widget->getColumnsCount(),
                         ui->widget->getCellSize()*ui->widget->getRowsCount()));
    ui->widget->render(&pixmap,QPoint(-ui->widget->getOffset(),0));
    qDebug()<<fileName;
    pixmap.save(fileName);
}

void MainWindow::on_resetButton_clicked()
{
    ui->widget->reset();
}

void MainWindow::on_incPixelSizeButton_clicked()
{
    if(pixelSize<15){
        pixelSize++;
        ui->pixelSizeLabel->setText(QString::number(pixelSize));
    }
}

void MainWindow::on_decrPixelSizeButton_clicked()
{
    if(pixelSize>1){
        pixelSize--;
        ui->pixelSizeLabel->setText(QString::number(pixelSize));
    }
}

void MainWindow::on_chortcursButton_clicked()
{
    shortcuts.show();
}

void MainWindow::on_cssButton_clicked()
{
    SaveCss css(ui->widget->getCells(),pixelSize);
    css.exec();
}

void MainWindow::on_authorButton_clicked()
{
    QString link="https://github.com/dawist-o";
    QDesktopServices::openUrl(QUrl(link));

}

