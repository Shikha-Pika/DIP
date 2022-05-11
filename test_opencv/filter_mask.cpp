#include "hist_header.h"
#define a 3 //window size (5 x 5)

Mat averaging_filter(Mat image) {
	Mat filtered_img = image.clone();
    Scalar intensity1 = 0;
 
    for (int i = 0; i < image.rows - a; i++)
    {
        for (int j = 0; j < image.cols - a; j++)
        {
            Scalar intensity2 = 0;
            for (int p = 0; p < a; p++)
            {
                for (int q = 0; q < a; q++)
                {
                    intensity1 = image.at<uchar>(i + p, j + q);
                    intensity2.val[0] += intensity1.val[0];
                }
            }
            filtered_img.at<uchar>(i + (a - 1) / 2, j + (a - 1) / 2) = intensity2.val[0] / (a * a);
        }
    }
    return filtered_img;
}


