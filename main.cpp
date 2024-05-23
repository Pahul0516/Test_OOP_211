#include <QtWidgets/QApplication>
#include "GUI.h"
#include "test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GUI gui;
    gui.show();

    rulare_teste();
    return a.exec();
}
