#include <QApplication>
#include <QTranslator>

#include "headers/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a translator object
    // TODO: receive the language from command line
    QTranslator *translator = new QTranslator;

    MainWindow w(nullptr, translator);
    w.show();

    return a.exec();
}