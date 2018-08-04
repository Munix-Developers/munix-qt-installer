#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load translations
    // TODO: It is fixed in portuguese
    // TODO: Dynamic language changing: https://stackoverflow.com/questions/15355156/is-it-possible-to-change-language-on-qt-at-runtime/48719049#48719049
    QTranslator translator;
    translator.load(":/translations/pt_br.qm");
    QCoreApplication::installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
