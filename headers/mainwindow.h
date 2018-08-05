#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, QTranslator *translator = nullptr);
    ~MainWindow();

private slots:
    void updateTitles();
    void loadLanguage(QString langCode);

private:
    Ui::MainWindow *ui;
    QTranslator *local_translator;
};

#endif // MAINWINDOW_H