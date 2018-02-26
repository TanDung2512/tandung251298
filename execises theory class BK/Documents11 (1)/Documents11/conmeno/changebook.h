#ifndef CHANGEBOOK_H
#define CHANGEBOOK_H

#include <QDialog>

namespace Ui {
class changeBook;
}

class changeBook : public QDialog
{
    Q_OBJECT

public:
    explicit changeBook(QWidget *parent = 0);
    ~changeBook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::changeBook *ui;
};

#endif // CHANGEBOOK_H
