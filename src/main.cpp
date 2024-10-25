#include "lin_interface.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   
    LinInterface i;
    i.setWindowTitle("Lin Interface");
    i.setMinimumWidth(800);
    i.setMinimumHeight(750);
    i.show();
   
    return a.exec();
}
