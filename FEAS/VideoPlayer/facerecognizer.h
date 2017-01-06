#ifndef FACERECOGNIZER_H
#define FACERECOGNIZER_H


class FaceRecognizer
{
public:
    int note;
    FaceRecognizer();
    std::vector<dlib::image_window::overlay_line> calculateOverlay(std::vector<dlib::full_object_detection> shapes);
    int getNote();
};

#endif // FACERECOGNIZER_H
