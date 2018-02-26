#ifndef SECOND_MAIN_H
#define SECOND_MAIN_H

#include <QStackedWidget>

namespace Ui {
class Second_Main;
}

class Second_Main : public QStackedWidget
{
    Q_OBJECT

public:
    explicit Second_Main(QWidget *parent = 0);
    ~Second_Main();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Second_Main *ui;
};

#endif // SECOND_MAIN_H
