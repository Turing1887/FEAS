#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionVideodatei_ffnen_triggered();
    void on_actionKamera_ffnen_triggered();
    void on_actionPlay_triggered();

private:
    Ui::MainWindow *ui;
    VideoEngine *videoThread;
};

#endif // MAINWINDOW_H
