#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <QThread>
#include <qDebug>
#include <facerecognizer.h>
#include "midiinput.h"
#include "copyprocessor.h"

using namespace cv;
using namespace dlib;
using namespace std;
using namespace drumstick::rt;

CopyProcessor::CopyProcessor()
    :tmp(0)
    , frameCount(1)
    , volume(80)
{

}

void CopyProcessor::setAugVal(int AugVal) {
    this->AugVal = AugVal;
}
void CopyProcessor::setMundVal(int MundVal) {
    this->MundVal = MundVal;
}
void CopyProcessor::toggleAug(bool AugTog) {
    this->AugTog = AugTog;
}
void CopyProcessor::toggleMund(bool MundTog) {
    this->MundTog = MundTog;
}
int CopyProcessor::getAugVal() {
    qDebug() << "AugVal: " << AugVal;
    return AugVal;
}
int CopyProcessor::getMundVal() {
    qDebug() << "MundVal: " << MundVal;
    return MundVal;
}
bool CopyProcessor::getToggleAug() {
    qDebug() << "AugTog: " << AugTog;
    return AugTog;
}
bool CopyProcessor::getToggleMund() {
    qDebug() << "MundTog: " << MundTog;
    return MundTog;
}
void CopyProcessor::setVolume(int volume) {
    this->volume = volume;
}

// wird vor dem ersten Videoframe aufgerufen
void CopyProcessor::startProcessing(const VideoFormat& format){
    try
    {
            midiOutput.open("Microsoft GS Wavetable Synth");

            // Load face detection and pose estimation models.
            detector = get_frontal_face_detector();

            deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;
    }
    catch(serialization_error& e)
    {
        cout << "You need dlib's default face landmarking model file to run this example." << endl;
        cout << "You can get it from the following URL: " << endl;
        cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
        cout << endl << e.what() << endl;
    }
    catch(exception& e)
    {
        cout << e.what() << endl;
    }

}

// wird für jedes Videoframe aufgerufen
    cv::Mat CopyProcessor::process(const cv::Mat&source){
    Mat copyOfSource;
    source.copyTo(copyOfSource);

    frameCount++;
    cv_image<bgr_pixel> cimg(copyOfSource);


     // Detect faces
     std::vector<dlib::rectangle> faces = detector(cimg);


     // Find the pose of each face.
     std::vector<full_object_detection> shapes;
     for (unsigned long i = 0; i < faces.size(); ++i) {
          shapes.push_back(pose_model(cimg, faces[i]));
     }



     // Display it all on the screen
     //cimg.clear_overlay();
     //cimg.set_image(cimg);


     // calculate overlay
     FaceRecognizer recog = FaceRecognizer();
     //std::vector<image_window::overlay_line> lines = recog.calculateOverlay(copyOfSource, shapes);
     recog.calculateOverlay(copyOfSource, shapes);

     if (frameCount >= 5) {
         int note = recog.getNote();
         midiOutput.sendNoteOn(2, note, volume);
         tmp = note;
         frameCount = 0;
      }
      // add overlay
      //cimg.add_overlay(lines);

    return copyOfSource;


}
