#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>

namespace Ui {
class Addbook;
}

class Addbook : public QDialog
{
    Q_OBJECT

public:
    explicit Addbook(QWidget *parent = 0);
    ~Addbook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Addbook *ui;
};

#endif // ADDBOOK_H
