#include "hist_header.h"

Mat visited;
void init_visited(Mat& image) {
    visited = image.clone();
    for (int x = 0; x < image.rows; x++) {
        for (int y = 0; y < image.cols; y++) {
            visited.at<uchar>(x, y) = false;
        }
    }
}

bool isIndexValid(Mat& image, int x, int y) {
    return x >= 0 && y >= 0 && x < image.rows && y < image.cols;
}

void dfs(Mat& image, int x, int y, uchar color) {
    image.at<uchar>(x, y) = color;
    visited.at<uchar>(x, y) = true;// this cell has been visited now.
    if (isIndexValid(image, x + 1, y) == 1 && image.at<uchar>(x + 1, y) == 255)
        dfs(image, x + 1, y, color);
    if (isIndexValid(image, x - 1, y) == 1 && image.at<uchar>(x - 1, y) == 255)
        dfs(image, x - 1, y, color);
    if (isIndexValid(image, x, y + 1) == 1 && image.at<uchar>(x, y + 1) == 255)
        dfs(image, x, y + 1, color);
    if (isIndexValid(image, x, y - 1) == 1 && image.at<uchar>(x, y - 1) == 255)
        dfs(image, x, y - 1, color);
}

int connected_components(Mat& image) {
    int count = 0;
    init_visited(image);
    uchar color = 10;
    for (int x = 0; x < image.rows; x++) {
        for (int y = 0; y < image.cols; y++) {
            if (visited.at<uchar>(x, y) == 0 && image.at<uchar>(x, y) == 255) {
                // we have found a new unexplored island (a white cell that has not been visited)
                color += 2;
                dfs(image, x, y, color);
                count++;
            }
        }
    }
    return count;
}
