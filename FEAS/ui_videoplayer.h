/********************************************************************************
** Form generated from reading UI file 'videoplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_VideoPlayer
{
public:
    QAction *actionVideodatei_ffnen;
    QAction *actionKamera_ffnen;
    QAction *actionPlay;
    QWidget *centralWidget;
    VideoWidget *inputFrame;
    VideoWidget *processedFrame;
    QSlider *AugenbrauenSlider;
    QSlider *MundSlider;
    QLabel *Kalibrierung;
    QLabel *Augenbrauen;
    QLabel *Mund;
    QCheckBox *AugenbrauenOnOff;
    QCheckBox *MundOnOff;
    QLabel *Options;
    QLabel *Volume;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QMenu *menuVideo;
    QMenu *menuPlay;

    void setupUi(QMainWindow *VideoPlayer)
    {
        if (VideoPlayer->objectName().isEmpty())
            VideoPlayer->setObjectName(QStringLiteral("VideoPlayer"));
        VideoPlayer->resize(1323, 800);
        VideoPlayer->setMinimumSize(QSize(1323, 800));
        actionVideodatei_ffnen = new QAction(VideoPlayer);
        actionVideodatei_ffnen->setObjectName(QStringLiteral("actionVideodatei_ffnen"));
        actionKamera_ffnen = new QAction(VideoPlayer);
        actionKamera_ffnen->setObjectName(QStringLiteral("actionKamera_ffnen"));
        actionPlay = new QAction(VideoPlayer);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        centralWidget = new QWidget(VideoPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputFrame = new VideoWidget(centralWidget);
        inputFrame->setObjectName(QStringLiteral("inputFrame"));
        inputFrame->setGeometry(QRect(20, 20, 641, 481));
        inputFrame->setMinimumSize(QSize(641, 481));
        inputFrame->setMaximumSize(QSize(641, 16777215));
        inputFrame->setFrameShape(QFrame::Box);
        inputFrame->setScaledContents(false);
        inputFrame->setAlignment(Qt::AlignCenter);
        processedFrame = new VideoWidget(centralWidget);
        processedFrame->setObjectName(QStringLiteral("processedFrame"));
        processedFrame->setGeometry(QRect(670, 20, 641, 481));
        processedFrame->setMinimumSize(QSize(641, 481));
        processedFrame->setFrameShape(QFrame::Box);
        processedFrame->setScaledContents(false);
        processedFrame->setAlignment(Qt::AlignCenter);
        AugenbrauenSlider = new QSlider(centralWidget);
        AugenbrauenSlider->setObjectName(QStringLiteral("AugenbrauenSlider"));
        AugenbrauenSlider->setGeometry(QRect(30, 600, 441, 22));
        AugenbrauenSlider->setMaximum(127);
        AugenbrauenSlider->setSliderPosition(35);
        AugenbrauenSlider->setOrientation(Qt::Horizontal);
        MundSlider = new QSlider(centralWidget);
        MundSlider->setObjectName(QStringLiteral("MundSlider"));
        MundSlider->setGeometry(QRect(30, 670, 441, 22));
        MundSlider->setMaximum(127);
        MundSlider->setSliderPosition(10);
        MundSlider->setOrientation(Qt::Horizontal);
        Kalibrierung = new QLabel(centralWidget);
        Kalibrierung->setObjectName(QStringLiteral("Kalibrierung"));
        Kalibrierung->setGeometry(QRect(20, 510, 191, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Kalibrierung->setFont(font);
        Kalibrierung->setTextFormat(Qt::AutoText);
        Kalibrierung->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Augenbrauen = new QLabel(centralWidget);
        Augenbrauen->setObjectName(QStringLiteral("Augenbrauen"));
        Augenbrauen->setGeometry(QRect(30, 550, 91, 21));
        QFont font1;
        font1.setPointSize(10);
        Augenbrauen->setFont(font1);
        Mund = new QLabel(centralWidget);
        Mund->setObjectName(QStringLiteral("Mund"));
        Mund->setGeometry(QRect(30, 630, 81, 21));
        Mund->setFont(font1);
        AugenbrauenOnOff = new QCheckBox(centralWidget);
        AugenbrauenOnOff->setObjectName(QStringLiteral("AugenbrauenOnOff"));
        AugenbrauenOnOff->setGeometry(QRect(490, 600, 121, 17));
        AugenbrauenOnOff->setChecked(true);
        MundOnOff = new QCheckBox(centralWidget);
        MundOnOff->setObjectName(QStringLiteral("MundOnOff"));
        MundOnOff->setGeometry(QRect(490, 670, 131, 17));
        MundOnOff->setChecked(true);
        Options = new QLabel(centralWidget);
        Options->setObjectName(QStringLiteral("Options"));
        Options->setGeometry(QRect(670, 510, 141, 31));
        Options->setFont(font);
        Volume = new QLabel(centralWidget);
        Volume->setObjectName(QStringLiteral("Volume"));
        Volume->setGeometry(QRect(680, 560, 141, 16));
        Volume->setFont(font1);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(680, 600, 421, 22));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSliderPosition(80);
        horizontalSlider->setOrientation(Qt::Horizontal);
        VideoPlayer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VideoPlayer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1323, 21));
        menuVideo = new QMenu(menuBar);
        menuVideo->setObjectName(QStringLiteral("menuVideo"));
        menuPlay = new QMenu(menuBar);
        menuPlay->setObjectName(QStringLiteral("menuPlay"));
        VideoPlayer->setMenuBar(menuBar);

        menuBar->addAction(menuVideo->menuAction());
        menuBar->addAction(menuPlay->menuAction());
        menuVideo->addAction(actionVideodatei_ffnen);
        menuVideo->addAction(actionKamera_ffnen);
        menuPlay->addAction(actionPlay);

        retranslateUi(VideoPlayer);

        QMetaObject::connectSlotsByName(VideoPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *VideoPlayer)
    {
        VideoPlayer->setWindowTitle(QApplication::translate("VideoPlayer", "VideoPlayer", 0));
        actionVideodatei_ffnen->setText(QApplication::translate("VideoPlayer", "Videodatei \303\226ffnen ...", 0));
        actionKamera_ffnen->setText(QApplication::translate("VideoPlayer", "Kamera \303\226ffnen", 0));
        actionPlay->setText(QApplication::translate("VideoPlayer", "Play", 0));
        inputFrame->setText(QString());
        processedFrame->setText(QString());
        Kalibrierung->setText(QApplication::translate("VideoPlayer", "Kalibrierung", 0));
        Augenbrauen->setText(QApplication::translate("VideoPlayer", "Augenbrauen:", 0));
        Mund->setText(QApplication::translate("VideoPlayer", "Mund:", 0));
        AugenbrauenOnOff->setText(QApplication::translate("VideoPlayer", "Toggle State On/Off", 0));
        MundOnOff->setText(QApplication::translate("VideoPlayer", "Toggle State On/Off", 0));
        Options->setText(QApplication::translate("VideoPlayer", "Options", 0));
        Volume->setText(QApplication::translate("VideoPlayer", "Volume", 0));
        menuVideo->setTitle(QApplication::translate("VideoPlayer", "Video", 0));
        menuPlay->setTitle(QApplication::translate("VideoPlayer", "Play", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayer: public Ui_VideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
