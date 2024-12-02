#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    
    Mat src = imread("test.jpg", IMREAD_GRAYSCALE); 
    if (src.empty()) {
        cout << "Could not read the image" << endl;
        return 1;
    }

    
    Mat binary;
    threshold(src, binary, 100, 255, THRESH_BINARY); 

    
    Mat blurred;
    GaussianBlur(src, blurred, Size(5, 5), 0); 

    
    Mat dilated;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(blurred, dilated, kernel); 

    
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", src);

    namedWindow("Binary Image", WINDOW_AUTOSIZE);
    imshow("Binary Image", binary);

    namedWindow("Blurred Image", WINDOW_AUTOSIZE);
    imshow("Blurred Image", blurred);

    namedWindow("Dilated Image", WINDOW_AUTOSIZE);
    imshow("Dilated Image", dilated);

    
    waitKey(0);
    return 0;
}

