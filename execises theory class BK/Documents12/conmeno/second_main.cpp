#include "second_main.h"
#include "ui_second_main.h"

Second_Main::Second_Main(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::Second_Main)
{
    ui->setupUi(this);
}

Second_Main::~Second_Main()
{
    delete ui;
}
