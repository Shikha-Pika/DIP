#include "hist_header.h"
#define a 5

Mat sobel_filter(Mat image) {
    Mat filtered_img = image.clone();
    int sum = 0, gradX, gradY;

    for (int x = 1; x < image.rows - 1; x++) {
        for (int y = 1; y < image.cols - 1; y++) {
            filtered_img.at<uchar>(y, x) = 0;
        }
    }

    for (int x = 1; x < image.rows - 1; x++) {
        for (int y = 1; y < image.cols - 1; y++) {
            gradX = xGradient(image, x, y);
            gradY = yGradient(image, x, y);
            sum = abs(gradX) + abs(gradY);
            sum = sum > 255 ? 255 : sum;
            sum = sum < 0 ? 0 : sum;
            filtered_img.at<uchar>(x, y) = sum;
        }
    }
    return filtered_img;
}

int xGradient(Mat image, int x, int y)
{
    return image.at<uchar>(x + 1, y - 1) +
        2 * image.at<uchar>(x + 1, y) +
        image.at<uchar>(x + 1, y + 1) - (
        image.at<uchar>(x - 1, y - 1) +
        2 * image.at<uchar>(x - 1, y) +
        image.at<uchar>(x - 1, y + 1) );
}

int yGradient(Mat image, int x, int y)
{
    return image.at<uchar>(x - 1, y + 1) +
        2 * image.at<uchar>(x, y + 1) +
        image.at<uchar>(x + 1, y + 1) - (
        image.at<uchar>(x - 1, y - 1) +
        2 * image.at<uchar>(x, y - 1) +
        image.at<uchar>(x + 1, y - 1) );
}