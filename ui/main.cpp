#include <QApplication>
#include <QStyle>
#include <QTranslator>
#include <QScreen>

#include "ui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a translator object
    // TODO: receive the language from command line
    QTranslator *translator = new QTranslator;

    MainWindow w(nullptr, translator);
    w.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            w.size(),
            QGuiApplication::screens().first()->availableGeometry()
            )
        );
    w.show();

    return a.exec();
}
