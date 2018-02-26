#ifndef MAIN_READER_H
#define MAIN_READER_H

#include <QWidget>

namespace Ui {
class Main_Reader;
}

class Main_Reader : public QWidget
{
    Q_OBJECT

public:
    explicit Main_Reader(QWidget *parent = 0);
    ~Main_Reader();

private:
    Ui::Main_Reader *ui;
};

#endif // MAIN_READER_H
