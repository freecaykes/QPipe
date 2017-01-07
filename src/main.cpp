#include "exampleqtwidgetextension.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExampleQTWidgetExtension w;
    w.show();

    return a.exec();
}
