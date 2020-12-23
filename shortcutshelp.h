#ifndef SHORTCUTSHELP_H
#define SHORTCUTSHELP_H

#include <QDialog>

namespace Ui {
class ShortcutsHelp;
}

class ShortcutsHelp : public QDialog
{
    Q_OBJECT

public:
    explicit ShortcutsHelp(QWidget *parent = nullptr);
    ~ShortcutsHelp();

private:
    Ui::ShortcutsHelp *ui;
};

#endif // SHORTCUTSHELP_H
