#include "mainwindow.h"
#include "network.h"
#include <QApplication>
#include <QtConcurrent/QtConcurrent>

int main(int argc, char *argv[])
{
    QApplication applicaiton(argc, argv);
    MainWindow window;
    window.show();
    return applicaiton.exec();
}
