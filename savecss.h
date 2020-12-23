#ifndef SAVECSS_H
#define SAVECSS_H

#include "cell.h"
#include <QDialog>
#include <QVector>

namespace Ui {
class SaveCss;
}

class SaveCss : public QDialog
{
    Q_OBJECT


public:
    explicit SaveCss(QVector<QVector<Cell>> cells,
                     int pixelSize,
                     QWidget *parent = nullptr);
    ~SaveCss();

private slots:
    void on_copyButton_clicked();
    void on_saveButton_clicked();

private:
    void createCss();
    QVector<QVector<Cell>> cells;
    int pixelSize;
    QString css;
    Ui::SaveCss *ui;
};

#endif // SAVECSS_H
