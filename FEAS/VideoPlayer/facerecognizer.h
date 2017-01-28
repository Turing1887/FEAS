#ifndef FACERECOGNIZER_H
#define FACERECOGNIZER_H

#include "copyprocessor.h"

class FaceRecognizer
{
public:
    FaceRecognizer();
    void calculateOverlay(cv::Mat mat, std::vector<dlib::full_object_detection> shapes);
    int getNote();
private:
    int octave;
    int noteNumber;
    int note;
    //CopyProcessor *copyprocessor;
};

#endif // FACERECOGNIZER_H
