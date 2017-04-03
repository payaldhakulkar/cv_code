#include<opencv/highgui.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  int i, j;
  Mat image1, image2;
  image1 = imread("/home/payald/opencv/opencv/samples/data/board.jpg", IMREAD_GRAYSCALE);
  image2 = imread("/home/payald/opencv/opencv/samples/data/aero1.jpg", IMREAD_GRAYSCALE);
  imshow("Image1", image1);
  waitKey(0);
  imshow("Image2", image2);
  waitKey(0);

  unsigned char *temp1 = (unsigned char *)(image1.data);
  unsigned char *temp2 = (unsigned char *)(image2.data);
  //unsigned char *new_image = (unsigned char *)(ouput_image.data);

  Size s = image1.size();
  int width = s.width;
  int height = s.height;
  Mat ouput_image(height,width, CV_8UC1); //Scalar(0,0,0));
  for (i=0 ; i<height ; i++)
  {
   for(j=0 ; j<width ; j++)
     {
      if(temp1[(i*width)+j] + temp2[(i*width)+j] > 255)
      ouput_image.data[(i*width)+j] = 255;
      else
      ouput_image.data[(i*width)+j] = temp1[(i*width)+j] + temp2[(i*width)+j];
     }
  }

  Size out_size = ouput_image.size();
  int out_width = out_size.width;
  int out_height = out_size.height;
  printf("Output w and h are %d  %d\n", out_width, out_height);
  imshow("Blend Image", ouput_image);
  waitKey(0);

  //printf("Pointer value %d\n", temp[400]);

  return 0;
}
