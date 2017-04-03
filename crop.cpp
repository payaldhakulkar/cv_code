#include<opencv/highgui.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  int i, j, row=200, col=512, r=0, c, startrow=100, startcol=300;
  Mat image1;
  image1 = imread("/home/payald/opencv/opencv/samples/data/home.jpg", IMREAD_GRAYSCALE);
  Mat ouput_image((row-startrow),(col-startcol), CV_8UC1); //Scalar(0,0,0));
  imshow("Image1", image1);
  waitKey(0);
  unsigned char *temp = (unsigned char *)(image1.data);
  //unsigned char *new_image = (unsigned char *)(ouput_image.data);

  Size s = image1.size();
  int width = s.width;
  int height = s.height;
  for (i=startrow ; i<row ; i++)
  {
   c = 0;
   for(j=startcol ; j<col ; j++)
     {
      ouput_image.data[(r*(col-startcol))+c] = temp[(i*width)+j];
      c++;
     }
     r++;
  }
  printf("value of r c %d %d\n", r, c);


  Size out_size = ouput_image.size();
  int out_width = out_size.width;
  int out_height = out_size.height;
  printf("Output w and h are %d  %d\n", out_width, out_height);
  imshow("Cropped Image", ouput_image);
  waitKey(0);

  //printf("Pointer value %d\n", temp[400]);

  return 0;
}

