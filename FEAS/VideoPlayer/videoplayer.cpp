#include <QFileDialog>
#include "videoplayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
    , videoThread(new VideoEngine)
    , copyProcessor(new CopyProcessor)

{
    ui->setupUi(this);
    videoThread->setProcessor(copyProcessor);
    connect(videoThread, &VideoEngine::sendInputImage,
            ui->inputFrame, &VideoWidget::setImage);
    connect(videoThread, &VideoEngine::sendProcessedImage,
            ui->processedFrame, &VideoWidget::setImage);
}

VideoPlayer::~VideoPlayer()
{
    delete videoThread;
    delete ui;
    delete copyProcessor;
}

void VideoPlayer::on_actionVideodatei_ffnen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        videoThread->openFile(fileName);
     }
}

void VideoPlayer::on_actionKamera_ffnen_triggered()
{
    videoThread->openCamera();
}

void VideoPlayer::on_actionPlay_triggered()
{
    videoThread->start();
}

void VideoPlayer::on_AugenbrauenOnOff_toggled(bool checked)
{
    copyProcessor->toggleAug(checked);
}

void VideoPlayer::on_MundOnOff_toggled(bool checked)
{
    copyProcessor->toggleMund(checked);
}

void VideoPlayer::on_AugenbrauenSlider_valueChanged(int value)
{
    copyProcessor->setAugVal(value);
}

void VideoPlayer::on_MundSlider_valueChanged(int value)
{
    copyProcessor->setMundVal(value);
}

void VideoPlayer::on_horizontalSlider_valueChanged(int value)
{
    copyProcessor->setVolume(value);
}
