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

signals:
    void langChanged();

private slots:
    void updateTitles();
    void loadLanguage(QString langCode);

    void nextStep();
    void previousStep();

private:
    Ui::MainWindow *ui;
    QTranslator *local_translator;

    int curInstallIdx = 0;

    void retranslate();
};

#endif // MAINWINDOW_H
