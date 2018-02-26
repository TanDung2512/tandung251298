#include "reader.h"
#include "ui_reader.h"

Reader::Reader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reader)
{
    ui->setupUi(this);
}

Reader::~Reader()
{
    delete ui;
}
