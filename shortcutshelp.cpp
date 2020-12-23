#include "shortcutshelp.h"
#include "ui_shortcutshelp.h"

ShortcutsHelp::ShortcutsHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortcutsHelp)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Shortcuts");
}

ShortcutsHelp::~ShortcutsHelp()
{
    delete ui;
}
