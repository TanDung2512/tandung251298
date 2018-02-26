#include "mainwindow.h"
#include <QApplication>
#include "search.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Search q;
    w.setWindowFlags(Qt::WindowTitleHint);
    q.show();
    w.show();

    return a.exec();
}
