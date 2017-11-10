

//OpenCV
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"

//std
#include <iostream>
#include <cstdlib>
#include <vector>

//consts
const unsigned int MIN_NUM_FEATURES = 300; //minimum number of point fetaures

int main(int argc, char *argv[])
{
    //OpenCV video capture object
    cv::VideoCapture camera;
    //OpenCV image object
    cv::Mat image;
    //camera id . Associated to device number in /dev/videoX
	  int cam_id;
    //ORB point feature detector
    cv::Ptr<cv::ORB> orb_detector = cv::ORB::create();
    orb_detector->setMaxFeatures(MIN_NUM_FEATURES);
    //set of point features
    std::vector<cv::KeyPoint> point_set;
    //set of descriptors, for each feature there is an associated descriptor
    cv::Mat descriptor_set;

  	//check user args
  	switch(argc)
  	{
  		case 1: //no argument provided, so try /dev/video0
  			cam_id = 0;
  			break;
  		case 2: //an argument is provided. Get it and set cam_idDRAW_RICH_KEYPOINTS
  			cam_id = atoi(argv[1]);
  			break;
  		default:
  			std::cout << "Invalid number of arguments. Call program as: webcam_capture [video_device_id]. " << std::endl;
  			std::cout << "EXIT program." << std::endl;
  			break;
  	}

  	//advertising to the user
  	std::cout << "Opening video device " << cam_id << std::endl;

    //open the video stream and make sure it's opened
    if( !camera.open(cam_id) )
    {
        std::cout << "Error opening the camera. May be invalid device id. EXIT program." << std::endl;
        return -1;
    }


    //Process loop. Capture anced point feature extraction. User can quit pressing a key
    while(1)
  	{
  		//Read image and check it. Blocking call up to a new image arrives from camera.
      if(!camera.read(image))
  		{
              std::cout << "No image" << std::endl;
              cv::waitKey();
      }

      //**************** Find ORB point fetaures and descriptors ****************************

      // Mask to use for the region of intereset. Type of the mask is CV_8UC1.
      cv::Mat mask = cv::Mat::zeros(image.size(), CV_8UC1);
      // Region of interest where we will look for keypoints.
      cv::Mat roi(mask, cv::Rect(0, 0, image.cols/2, image.rows/2));
      // We need to set to 1 the bits of the regions of interest.
      roi = cv::Scalar(255, 255, 255);

      //clear previous points
      point_set.clear();
      // Detect keypoint on the mask.
      orb_detector->detect(image, point_set, mask);
      // compute detected points.
      orb_detector->compute(image, point_set, descriptor_set);

  	  //**************** Find ORB point fetaures and descriptors ****************************

      //draw points on the image
      cv::drawKeypoints( image, point_set, image, 255, cv::DrawMatchesFlags::DEFAULT );

      //********************************************************************

      //show image
      cv::imshow("ORB (Oriented FAST and Rotated BRIEF) ROI ", image)

  		//Waits 1 millisecond to check if a key has been pressed. If so, breaks the loop. Otherwise continues.
  		if( (unsigned char)(cv::waitKey(30) & 0xff) == 'q' ) break;
    }
}
