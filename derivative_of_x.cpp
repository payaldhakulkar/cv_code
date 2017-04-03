#include<opencv/highgui.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
        int i, j, k, l, r=0 ,c;
        int  sum = 0;
        Mat image1;
        image1 = imread("/home/payald/opencv/opencv/samples/data/lena.jpg", IMREAD_GRAYSCALE);
        imshow("Image1", image1);
        waitKey(0);

        unsigned char *temp = (unsigned char *)(image1.data);
        //printf("Value of pixel is %d %d %d\n", temp[0], temp[262144], temp[524288]);

        signed int array_kernel_x[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
        int channels = image1.channels();
        Size s = image1.size();
        int width = s.width;
        int height = s.height;
        Mat ouput_image(height,width, CV_8UC1, Scalar(0));
        for (i=0 ; i<height ; i++)
        {
                sum = 0;
                for (j=0 ; j<width ; j++)
                        {
                                for(k=0 ; k<3 ; k++)
                                        {
                                                for (l=0; l<3; l++)
                                                        {
                                                                sum = sum + (temp[(i+k) * width + (j+l)] * array_kernel_x[k * 3 + l]);
                                                        }
                                        }
                                if (sum > 255)
                                        ouput_image.data[(i+1) * width + (j+1)] = 255;
                                else
                                        ouput_image.data[(i+1) * width + (j+1)] = sum;
                        }
        }




        Size out_size = ouput_image.size();
        int out_width = out_size.width;
        int out_height = out_size.height;
        printf("Output w and h are %d  %d\n", out_width, out_height);
        imshow("Difference Image", ouput_image);
        waitKey(0);

        return 0;
}
