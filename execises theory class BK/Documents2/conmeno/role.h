#ifndef ROLE_H
#define ROLE_H
#include <QDialog>
#include"account.h"

namespace Ui {
class Role;
}

class Role : public QDialog
{
    Q_OBJECT

public:
    explicit Role(QWidget *parent = 0);
    ~Role();

private:
    Ui::Role *ui;
};

#endif // ROLE_H
