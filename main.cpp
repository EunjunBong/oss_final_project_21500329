#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main () {
	CascadeClassifier face_classifier;
	Mat frame, grayframe;
	vector<Rect> faces;
	int i;

	//open webcam
	VideoCapture cpa(0);

	//check if succeed
	if(!cap.isOpen()) {
		cout << "Could not open camera" << endl;
		return -1;
	}

	//face detection configuration
	face_classifier.load("haarcascade_frontalface_alt.xml");

	while(true) {
		//get a new frame from webcam
		cap >> frame;

		//convert captured frame to gray scale & equalize
		cvtColor(frame, grayframe, CV_BGR2GRAY);
		equalizeHist(grayframe, grayframe);

		face_classifier.detectMultiScale(
				grayframe,
				faces,
				1.1, //increase search scale by 10% each pass / if 1.5 the 50 percent
				3, //merge groups of three detections
				0, //not used for a new cascade
				Size(30, 30) //min size
				);

		//draw the result
		for(i = 0; i < faces.size(); i++) {
			Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height); //left bottom
			Point tr(faces[i].x, faces[i].y); //right top
			rectangle(frame, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
		}

		//show output
		imshow("Face Detection", frame);
		if(waitKey(33) == 27) break;
	}
	return 0;
}

	
