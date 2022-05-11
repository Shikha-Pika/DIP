#include "hist_header.h"

Mat highpass_filter(Mat image) {
    Mat filtered_img = image.clone();
    int laplace_mask[3][3] = { { 0, -1, 0 }, { -1, 4, -1 }, { 0, -1, 0 } };
    int temp = 0;
    int counterX = 0;
    int counterY = 0;

    for (int i = 1; i < image.rows - 1; i++) {
        for (int j = 1; j < image.cols - 1; j++) {

            for (int k = i - 1; k < i + 2; k++) {
                for (int l = j - 1; l < j + 2; l++) {
                    temp += laplace_mask[counterX][counterY] * static_cast<int>(image.at<uchar>(k, l));
                    counterX++;
                }
                counterY++;
            }

            filtered_img.at<uchar>(i - 1, j - 1) = temp / 9;
            temp = 0;
            counterX = 0;
            counterY = 0;
        }
    }
    return filtered_img;
}