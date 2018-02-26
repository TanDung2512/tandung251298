#ifndef ADMINC_H
#define ADMINC_H

#include <QDialog>

namespace Ui {
class Adminc;
}

class Adminc : public QDialog
{
    Q_OBJECT

public:
    explicit Adminc(QWidget *parent = 0);
    ~Adminc();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Adminc *ui;
};

#endif // ADMINC_H
