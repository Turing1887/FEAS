#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "copyprocessor.h"
#include "facerecognizer.h"

namespace Ui {
class VideoPlayer;
}

class VideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

private slots:
    void on_actionVideodatei_ffnen_triggered();
    void on_actionKamera_ffnen_triggered();
    void on_actionPlay_triggered();
    void on_AugenbrauenOnOff_toggled(bool checked);

    void on_MundOnOff_toggled(bool checked);

    void on_AugenbrauenSlider_valueChanged(int value);

    void on_MundSlider_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::VideoPlayer *ui;
    VideoEngine *videoThread;
    CopyProcessor *copyProcessor;
};

#endif // VIDEOPLAYER_H
