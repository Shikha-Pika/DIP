#include "hist_header.h"

Mat median_filter(Mat image) {
	Mat filtered_img = image.clone();
	int window[9];

	for (int x = 1; x < image.rows - 1; x++) {
		for (int y = 1; y < image.cols - 1; y++) {
            window[0] = image.at<uchar>(x - 1, y - 1);
            window[1] = image.at<uchar>(x, y - 1);
            window[2] = image.at<uchar>(x + 1, y - 1);
            window[3] = image.at<uchar>(x - 1, y);
            window[4] = image.at<uchar>(x, y);
            window[5] = image.at<uchar>(x + 1, y);
            window[6] = image.at<uchar>(x - 1, y + 1);
            window[7] = image.at<uchar>(x, y + 1);
            window[8] = image.at<uchar>(x + 1, y + 1);

            insertionSort(window);
            filtered_img.at<uchar>(x, y) = window[4];
		}
	}
    return filtered_img;
}

void insertionSort(int window[9])
{
    int temp, i, j;
    for (i = 0; i < 9; i++) {
        temp = window[i];
        for (j = i - 1; j >= 0 && temp < window[j]; j--) {
            window[j + 1] = window[j];
        }
        window[j + 1] = temp;
    }
}