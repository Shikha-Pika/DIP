
#include "hist_header.h"

int main(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, "{@input | lena.jpg | input image}");
    Mat image = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);
    if (image.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    cvtColor(image, image, COLOR_BGR2GRAY);
    imshow("Source image", image);
  
    Mat dst = binary_image(image);  //replace appropriate functions for output
    imshow("output Image", dst);
    waitKey(0);
    return 0;
}
