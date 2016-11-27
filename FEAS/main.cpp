#include <dlib/image_processing/frontal_face_detector.h>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */

    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
}
