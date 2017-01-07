#ifndef EXAMPLEQTWIDGETEXTENSION_H
#define EXAMPLEQTWIDGETEXTENSION_H

#include <QWidget>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Common.h"
#include "StdDirector.hpp"
#include "QTExtensionThread.h"

namespace Ui {
class ExampleQTWidgetExtension;
}

class ExampleQTWidgetExtension : public QWidget
{
    Q_OBJECT

public:
    explicit ExampleQTWidgetExtension(QWidget *parent = 0);
    ~ExampleQTWidgetExtension();
    StdDirector<>* stdDir;
    QTExtensionThread* app_t;

private:
    Ui::ExampleQTWidgetExtension *ui;
};

#endif // EXAMPLEQTWIDGETEXTENSION_H
