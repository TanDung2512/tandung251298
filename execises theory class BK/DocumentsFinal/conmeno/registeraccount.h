#ifndef REGISTERACCOUNT_H
#define REGISTERACCOUNT_H

#include <QDialog>

namespace Ui {
class RegisterAccount;
}

class RegisterAccount : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterAccount(QWidget *parent = 0);
    ~RegisterAccount();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegisterAccount *ui;
};

#endif // REGISTERACCOUNT_H
