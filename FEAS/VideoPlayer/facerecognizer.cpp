// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*

    This example program shows how to find frontal human faces in an image and
    estimate their pose.  The pose takes the form of 68 landmarks.  These are
    points on the face such as the corners of the mouth, along the eyebrows, on
    the eyes, and so forth.


    This example is essentially just a version of the face_landmark_detection_ex.cpp
    example modified to use OpenCV's VideoCapture object to read from a camera instead
    of files.


    Finally, note that the face detector is fastest when compiled with at least
    SSE2 instructions enabled.  So if you are using a PC with an Intel or AMD
    chip then you should enable at least SSE2 instructions.  If you are using
    cmake to compile this program you can enable them by using one of the
    following commands when you create the build project:
        cmake path_to_dlib_root/examples -DUSE_SSE2_INSTRUCTIONS=ON
        cmake path_to_dlib_root/examples -DUSE_SSE4_INSTRUCTIONS=ON
        cmake path_to_dlib_root/examples -DUSE_AVX_INSTRUCTIONS=ON
    This will set the appropriate compiler options for GCC, clang, Visual
    Studio, or the Intel compiler.  If you are using another compiler then you
    need to consult your compiler's manual to determine how to enable these
    instructions.  Note that AVX is the fastest but requires a CPU from at least
    2011.  SSE4 is the next fastest and is supported by most current machines.
*/

#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/core/utility.hpp"
//#include "opencv2/core/private.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <QThread>
#include <qDebug>

#include <cmath>

// include class header file
#include "facerecognizer.h"
#include "midiinput.h"

using namespace dlib;
using namespace std;
using namespace cv;
using namespace drumstick::rt;

FaceRecognizer::FaceRecognizer()
    : octave(0)
    , noteNumber(0)
    , note(0)
{
}


//std::vector<image_window::overlay_line> FaceRecognizer::calculateOverlay(std::vector<full_object_detection> shapes) {
void FaceRecognizer::calculateOverlay(cv::Mat mat, std::vector<full_object_detection> shapes) {

    int firstX;
    int firstY;
    int secondX;
    int secondY;
    Point first;
    Point second;
    //bool MundTog = copyProcessor->getToggleMund();
    //bool AugTog = copyProcessor->getToggleAug();
    //int MundVal = copyProcessor->getMundVal();
    //int AugVal = copyProcessor->getAugVal();

    /*
    qDebug() << "MundTog: " << MundTog;
    qDebug() << "AugTog: " << AugTog;
    qDebug() << "MundVal: " << MundVal;
    qDebug() << "AugVal: " << AugVal;
    */
    for (unsigned long i = 0; i < shapes.size(); ++i)
    {
        DLIB_CASSERT(shapes[i].num_parts() == 68,
            "\t std::vector<image_window::overlay_line> render_face_detections()"
            << "\n\t Invalid inputs were given to this function. "
            << "\n\t shapes["<<i<<"].num_parts():  " << shapes[i].num_parts()
        );

        const full_object_detection& d = shapes[i];

        // Rechteck zeichnen
        if(note == 0) {
            line(mat, Point(200, 100), Point(200, 400), Scalar(255,0,0), 2);
            line(mat, Point(200, 400), Point(450, 400), Scalar(255,0,0), 2);
            line(mat, Point(450, 400), Point(450, 100), Scalar(255,0,0), 2);
            line(mat, Point(450, 100), Point(200, 100), Scalar(255,0,0), 2);
        }

        // Lippen
        //if (MundTog) {
            for (int i = 61; i <= 67; ++i) {
                firstX = d.part(i).x();
                firstY = d.part(i).y();
                secondX = d.part(i-1).x();
                secondY = d.part(i-1).y();
                first = Point(firstX, firstY);
                second = Point(secondX, secondY);
                line(mat, first, second, Scalar(120,120,255), 2);
            }

            firstX = d.part(60).x();
            firstY = d.part(60).y();
            secondX = d.part(67).x();
            secondY = d.part(67).y();
            first = Point(firstX, firstY);
            second = Point(secondX, secondY);
            line(mat, first, second, Scalar(255,0,0), 2);

            point upper = point(0,0);
            point lower = point(0,500);

            for(int i = 61; i < 68; i++) {
                if (d.part(i).y() < lower.y()){
                    lower = d.part(i);
                }
                if (d.part(i).y() > upper.y()){
                    upper = d.part(i);
                }
            }

            int lowerX = lower.x();
            int lowerY = lower.y();
            int upperX = upper.x();
            int upperY = upper.y();
            first = Point(lowerX, lowerY);
            second = Point(upperX, upperY);
            line(mat, first, second, Scalar(255,0,0), 2);

            //Mundhöhe
            long mh = (upper-lower).length();

            noteNumber = (mh-10) / 8;
            if (noteNumber > 12) {
                noteNumber = 12;
            }
            else if (noteNumber < 0) {
                noteNumber = 0;
            }
        //}
        // end Lippen

        // Augenbrauen
        //if (AugTog) {
            // rechts
            for (int i = 23; i < 26; ++i) {
                firstX = d.part(i).x();
                firstY = d.part(i).y();
                secondX = d.part(i-1).x();
                secondY = d.part(i-1).y();
                first = Point(firstX, firstY);
                second = Point(secondX, secondY);
                line(mat, first, second, Scalar(0,100,255), 2);
            }

            // links
            for (int i = 19; i <= 21; ++i) {
                firstX = d.part(i).x();
                firstY = d.part(i).y();
                secondX = d.part(i-1).x();
                secondY = d.part(i-1).y();
                first = Point(firstX, firstY);
                second = Point(secondX, secondY);
                line(mat, first, second, Scalar(120,120,255), 2);
            }

            firstX = d.part(21).x();
            firstY = d.part(21).y();
            secondX = d.part(22).x();
            secondY = d.part(22).y();
            first = Point(firstX, firstY);
            second = Point(secondX, secondY);
            line(mat, first, second, Scalar(255,0,0), 2);

             point lowerA = point(0,500);

             for(int i = 19; i < 25; i++) {
                 if (d.part(i).y() < lowerA.y()){
                     lowerA = d.part(i);
                 }
             }

            firstX = d.part(21).x();
            firstY = d.part(21).y();
            secondX = d.part(27).x();
            secondY = d.part(27).y();
            first = Point(firstX, firstY);
            second = Point(secondX, secondY);
            line(mat, first, second, Scalar(0,0,0), 2);
            firstX = d.part(22).x();
            firstY = d.part(22).y();
            secondX = d.part(27).x();
            secondY = d.part(27).y();
            first = Point(firstX, firstY);
            second = Point(secondX, secondY);
            line(mat, first, second, Scalar(0,0,0), 2);

        // end Augenbrauen

        // Augenbrauenhöhe
        int an = d.part(27).y() - lowerA.y();

        octave = (an-35) / 3;
        if (octave > 11) {
            octave = 11;
        }
        else if (octave < 0) {
            octave = 0;
        }
        //}


        note = octave*12 + noteNumber;
        if (note > 127) {
            note = 127;
        }
        qDebug() << note;
    }

    return;
}

int FaceRecognizer::getNote(){
    return note;
}
