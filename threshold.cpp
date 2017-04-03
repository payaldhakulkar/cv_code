#include<opencv/highgui.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
        int i, j, k, r=0,c;
        int  value = 0;
        Mat image1;
        image1 = imread("/home/payald/opencv/opencv/samples/data/lena.jpg", IMREAD_COLOR);
        imshow("Image1", image1);
        waitKey(0);

        cout<<"Mat type: "<<image1.type();
        cout<<"original image channels: "<<image1.channels();
        printf("\n");
        unsigned char *temp = (unsigned char *)(image1.data);
        //printf("Value of pixel is %d %d %d\n", temp[0], temp[262144], temp[524288]);

        int channels = image1.channels();
        Size s = image1.size();
        int width = s.width;
        int height = s.height;
        Mat ouput_image(height,width, CV_8UC1); //Scalar(0,0,0));
        for (i=0 ; i<height ; i++)
        {
                for(j=0 ; j<width ; j++)
                {
                        value = 0;
                        for(k=0 ; k<channels ; k++)
                        {
                                //printf("Value is %d \n", temp[(((k*height)+j)*width)+i]);
                                value = value + temp[k + (i * width + j) * channels];
                                //printf("Rgb value %d \n",value);
                        }
                        //printf("Rgb value %d \n",value);
                        unsigned char avg = (unsigned char) (value / 3);
                        if (avg >= 130)
                                ouput_image.data[(i * width) + j] = 255;
                        else
                                ouput_image.data[(i * width) + j] = 0;
                        //printf("Average is %d \n", ouput_image.data[(r*512)+c]);
                        value = 0;
                }
        }




        Size out_size = ouput_image.size();
        int out_width = out_size.width;
        int out_height = out_size.height;
        printf("Output w and h are %d  %d\n", out_width, out_height);
        imshow("Gray Image", ouput_image);
        waitKey(0);

        //printf("Pointer value %d\n", temp[400]);

        return 0;
}
