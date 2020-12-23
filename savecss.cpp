#include "savecss.h"
#include "ui_savecss.h"
#include "QDebug"

#include <QClipboard>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

SaveCss::SaveCss(QVector<QVector<Cell>> cells,
                 int pixelSize,
                 QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveCss)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Save css");
    this->pixelSize=pixelSize;
    this->cells=cells;
    this->ui->copiedLabel->setVisible(false);
    createCss();
}

void SaveCss::createCss(){
    css=".pixel_art{\nbox-shadow: ";
    for(int y=0;y<cells[0].size();y++){
        int currentY=pixelSize*(y+1);
        for(int x=0;x<cells.size();x++){
            css.append(QString::number((x+1)*pixelSize)).append("px ");
            css.append(QString::number(currentY)).append("px 0 0 ");
            css.append(cells[x][y].brush.color().name()).append(", ");
        }
        css.append("\n");
    }
    css.replace(css.lastIndexOf(','),2,";\n");
    css.append("height: ").append(QString::number(pixelSize)).append("px;\n");
    css.append("width: ").append(QString::number(pixelSize)).append("px;\n}");
    qDebug()<<css;
    ui->textEdit->setText(css);
}

SaveCss::~SaveCss()
{
    delete ui;
}

void SaveCss::on_copyButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    QString originalText = clipboard->text();

    clipboard->setText(ui->textEdit->toPlainText());

    ui->copiedLabel->setVisible(true);
}

void SaveCss::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save pixel art"), "pixel_art",
                                                    tr("CSS (*.css)"));
    if(fileName.isEmpty()||fileName.isNull()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    QTextStream out(&file);
    out<<css.toUtf8();
    file.close();
    out.flush();
}
