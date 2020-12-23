#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "shortcutshelp.h"

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QRect>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_incRowsCountButton_clicked();
    void on_decrRowsCountButton_clicked();
    void on_incColumnsCount_clicked();
    void on_decrColumnsCount_clicked();

    void changeColor();
    void holdPressed();

    void on_fill_clicked();
    void on_eraser_clicked();
    void on_pickerButton_clicked();
    void on_brushButton_clicked();

    void on_fill_released();
    void on_eraser_released();

    void on_incPixelSizeButton_clicked();
    void on_decrPixelSizeButton_clicked();

    void on_chortcursButton_clicked();
    void on_cssButton_clicked();
    void on_save_clicked();
    void on_authorButton_clicked();

    void on_resetButton_clicked();

private:
    int pixelSize=5;
    QPushButton *lastColorButton=nullptr;
    void connectColorButtons();
    void addShortcuts();

    ShortcutsHelp shortcuts;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
