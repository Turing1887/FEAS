#ifndef COPYPROCESSOR_H
#define COPYPROCESSOR_H

#include "videoprocessor.h"
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <facerecognizer.h>
#include "midiinput.h"
#include "midioutput.h"

class CopyProcessor : public VideoProcessor
{
public:
    dlib::frontal_face_detector detector;
    dlib::shape_predictor pose_model;
    drumstick::rt::MIDIOutput midiOutput;
    CopyProcessor();
    void startProcessing(const VideoFormat& format);
    cv::Mat process(const cv::Mat&source);
    void setAugVal(int AugVal);
    void setMundVal(int MundVal);
    void toggleAug(bool AugTog);
    void toggleMund(bool MundTog);
    int getAugVal();
    int getMundVal();
    bool getToggleAug();
    bool getToggleMund();
    void setVolume(int volume);
private:
    int frameCount;
    int tmp;
    int count;
    int AugVal;
    int MundVal;
    bool AugTog;
    bool MundTog;
    int volume;

};

#endif // COPYPROCESSOR_H
