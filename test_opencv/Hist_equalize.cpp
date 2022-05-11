#include "hist_header.h"

Mat equalize_hist(Mat image) {
    int count[256];
    for (int i = 0; i < 256; ++i) count[i] = 0;

    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            count[image.at<uchar>(i, j)]++;
        }
    }

    const long double nPixels = ((long double)image.cols) * ((long double)image.rows);
    double pdf[256];
    for (int i = 0; i < 256; i++) {
        pdf[i] = count[i] / nPixels;
    }


    double cdf[256];
    cdf[0] = pdf[0];
    for (int i = 1; i < 256; i++) {
        cdf[i] = pdf[i] + cdf[i - 1];
    }

    uchar hist_level[256];
    for (int i = 0; i < 256; i++) {
        assert(round(cdf[i] * 255) < 256);
        hist_level[i] = uchar(round(cdf[i] * 255));
    }

    Mat hist_img = image.clone();
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            int val = image.at<uchar>(i, j);
            hist_img.at<uchar>(i, j) = hist_level[val];
        }
    }
    return hist_img;
}