#ifndef BLIRARIANCOFIRM_H
#define BLIRARIANCOFIRM_H

#include <QDialog>

namespace Ui {
class blirariancofirm;
}

class blirariancofirm : public QDialog
{
    Q_OBJECT

public:
    explicit blirariancofirm(QWidget *parent = 0);
    ~blirariancofirm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::blirariancofirm *ui;
};

#endif // BLIRARIANCOFIRM_H
