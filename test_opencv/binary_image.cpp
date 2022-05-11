#include "hist_header.h"


Mat binary_image(Mat image) {
    Mat filtered_img = image.clone();
    for (int x = 0; x < image.rows; x++) {
        for (int y = 0; y < image.cols; y++) {
            if (image.at<uchar>(x, y) > calc_threshold(image))
                filtered_img.at<uchar>(x, y) = 255;
            else filtered_img.at<uchar>(x, y) = 0;
        }
    }
    return filtered_img;
}


int calc_threshold(Mat image) {
    int start = 0;
    int end = 255;

    const double tolerance = 1 ; // max error that we want to allow
    int thres = 127;  // initial estimate for threshold

    while (true) {

        int meanLeft = mean_range(0, thres);
        int meanRight = mean_range(thres, 256);
        int newMean = (int)(meanLeft + meanRight) / 2.0f;
        if (abs(newMean - thres) <= tolerance) break;// the difference is very small so it's ok to assume
                                                     // we found the estimate for threshold
        thres = newMean; // otherwise keep searching
    }
    return thres;
}

int mean_range(int start, int end) {
    int sum = 0, num = end - start + 1;
    for (int i = start; i < end; i++) {
        sum += i;
    }
    return sum / num;
}
