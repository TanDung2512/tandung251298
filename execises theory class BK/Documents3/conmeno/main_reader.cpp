#include "main_reader.h"
#include "ui_main_reader.h"

Main_Reader::Main_Reader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Main_Reader)
{
    ui->setupUi(this);
}

Main_Reader::~Main_Reader()
{
    delete ui;
}
