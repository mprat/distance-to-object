#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;

int main(int, char**)
{
    Mat left_hand; 
    left_hand = imread("left-hand.jpg", CV_LOAD_IMAGE_COLOR);

    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        //manipulate frame

        // detect hand
        Mat detect_hand;
        matchTemplate(frame, left_hand, detect_hand, CV_TM_SQDIFF_NORMED);
        // normalize( detect_hand, detect_hand, 0, 1, NORM_MINMAX, -1, Mat() );

        /// Localizing the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        Point matchLoc;

        // best match is minimum because CV_TM_SQDIFF is used
        minMaxLoc(detect_hand, &minVal, &maxVal, &minLoc, &maxLoc);

        // detect_hand will have 1s in it where it thinks the hand is


        // for( size_t i = 0; i < contours.size(); i++ ) {
        //     double area = contourArea(contours[i]);
        //     std::cout << "area = " << i << " is " << area << std::endl;
        // }

        // do ratio calculation

        // frame.grabCut()
        imshow("frame", detect_hand);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}