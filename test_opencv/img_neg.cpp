#include "hist_header.h"

Mat image_neg(Mat image) {

    Mat neg_img = image;
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            int val = image.at<uchar>(i, j);
            neg_img.at<uchar>(i, j) = 255 - val;
        }
    }
    return neg_img;
}