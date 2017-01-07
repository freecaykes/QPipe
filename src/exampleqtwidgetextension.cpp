#include "exampleqtwidgetextension.h"
#include "ui_exampleqtwidgetextension.h"
#include "QTExtensionThread.h"

using namespace Common;
//customizable callback
void outcallback( const char* ptr, std::streamsize count, void* pTextBox )
{
     (void) count;
    //cast writeto object as Qwidget to writeto
//    qRegisterMetaType<QTextEdit>("QTextEdit");
    QTextEdit* outBox = static_cast< QTextEdit* >( pTextBox );
    if(print_allowed){
        outBox->append(ptr);
    }
    print_allowed  = false;

}

ExampleQTWidgetExtension::ExampleQTWidgetExtension(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExampleQTWidgetExtension)
{
    ui->setupUi(this);

    stdDir = new StdDirector<>(std::cout, outcallback, ui->textEdit);
    app_t = new QTExtensionThread();
    app_t->setApplicationArguments("uname -r");
    app_t->start();
    app_t->run();

   ui->textEdit->setReadOnly(true);
}

ExampleQTWidgetExtension::~ExampleQTWidgetExtension()
{
    delete ui;
    delete stdDir;
}
