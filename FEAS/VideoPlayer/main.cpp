#include "videoplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VideoPlayer w;
    w.show();

    return a.exec();


}

/*
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <QThread>
#include <qDebug>
#include <facerecognizer.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "midiinput.h"

using namespace dlib;
using namespace std;
using namespace drumstick::rt;


int main()
{
    int tmp;
    int frameCount = 1;
    try
    {
        MIDIOutput midiOutput;
        midiOutput.open("Microsoft GS Wavetable Synth");
        // videocapture
        cv::VideoCapture cap(0);

        if (!cap.isOpened())
        {
            cerr << "Unable to connect to camera" << endl;
            return 1;
        }

        image_window win;  // TODO: von außen aufrufen
        // Load face detection and pose estimation models.
        frontal_face_detector detector = get_frontal_face_detector();
        shape_predictor pose_model;

        deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;

        // Grab and process frames until the main window is closed by the user.

        while(!win.is_closed())
        {
            frameCount++;

            // schleife erstmal nur für einen Frame ausführen
            if (true){
                // Grab a frame
                cv::Mat temp;
                cap >> temp;
                // Turn OpenCV's Mat into something dlib can deal with.  Note that this just
                // wraps the Mat object, it doesn't copy anything.  So cimg is only valid as
                // long as temp is valid.  Also don't do anything to temp that would cause it
                // to reallocate the memory which stores the image as that will make cimg
                // contain dangling pointers.  This basically means you shouldn't modify temp
                // while using cimg

                   cv_image<bgr_pixel> cimg(temp);

                    // Detect faces
                    std::vector<rectangle> faces = detector(cimg);


                    // Find the pose of each face.
                    std::vector<full_object_detection> shapes;
                    for (unsigned long i = 0; i < faces.size(); ++i) {
                        shapes.push_back(pose_model(cimg, faces[i]));
                    }



                    // Display it all on the screen
                    win.clear_overlay();
                    win.set_image(cimg);


                    // calculate overlay
                    FaceRecognizer recog = FaceRecognizer();
                    std::vector<image_window::overlay_line> lines = recog.calculateOverlay(shapes);

                if (frameCount >= 5) {
                    int note = recog.getNote();

                    if(note > tmp+1 || note < tmp-1){
                       midiOutput.sendNoteOn(2, note, 80);
                    }
                    tmp = note;
                    frameCount = 0;
                }
                    // add overlay
                    win.add_overlay(lines);




            }
        }
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

*/

