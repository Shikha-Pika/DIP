#ifndef HIST_H
#define HIST_H
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <cmath>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;

Mat equalize_hist(Mat image);
Mat image_neg(Mat image);
Mat averaging_filter(Mat image);
Mat weighted_filter(Mat image);
Mat median_filter(Mat image);
Mat highpass_filter(Mat image);
Mat sobel_filter(Mat image);
Mat laplace_filter(Mat image);
Mat binary_image(Mat image);
int connected_components(Mat& image);
Mat color_image();

void insertionSort(int window[9]);
int l_gradient(Mat image, int x, int y);
int xGradient(Mat image, int x, int y);
int yGradient(Mat image, int x, int y);
int calc_threshold(Mat image);
int mean_range(int start, int end);
void init_visited(Mat& image);
bool isIndexValid(Mat& image, int x, int y);
void dfs(Mat& image, int x, int y, uchar color);

#endif
