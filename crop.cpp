#include<opencv/highgui.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  int i, j, row=300, col=400;
  Mat image1;
  image1 = imread("/home/payald/opencv/programs/range_SPV_C500-grayscale.jpg");
  Mat output_image(600,400, CV_8UC1, Scalar(0,0,255));
  imshow("Image1", image1);
  waitKey(0);
  cv::Size s = image1.size();
  //row = s.height;
  //col = s.width;
  printf("Size %d %d\n", s.width, s.height);
  for(i=40;i<=row;i++)
  {
   for(j=80;j<=col;j++)
       {
         output_image.at<uchar>(i, j) = image1.at<uchar>(i, j);
       }
  }

  imshow("Cropped Image", output_image);
  waitKey(0);
  return 0;
}
