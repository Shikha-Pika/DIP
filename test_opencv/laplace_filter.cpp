#include "hist_header.h"

Mat laplace_filter(Mat image) {
    Mat filtered_img = image.clone();
    int window[9];

    for (int x = 1; x < image.rows - 1; x++) {
        for (int y = 1; y < image.cols - 1; y++) {
            int laplace_operator = l_gradient(image, x, y);
            filtered_img.at<uchar>(x, y) = image.at<uchar>(x, y) - laplace_operator;
        }
    }
    return filtered_img;
}

int l_gradient(Mat image, int x, int y) {
    return (image.at<uchar>(x, y - 1)
        + image.at<uchar>(x - 1, y)
        + image.at<uchar>(x + 1, y)
        + image.at<uchar>(x, y + 1)) 
        - (4 * image.at<uchar>(x, y));
}
