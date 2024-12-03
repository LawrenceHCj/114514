#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat detectColor(const Mat& image, const Scalar& lower, const Scalar& upper) {
    Mat hsv, mask;
    cvtColor(image, hsv, COLOR_BGR2HSV);
    inRange(hsv, lower, upper, mask);
    return mask;
}

void enhanceLowLightImage(Mat& image) {
    Mat img32;
    image.convertTo(img32, CV_32F, 1./255);
    for (int i = 0; i < img32.rows; i++) {
        for (int j = 0; j < img32.cols; j++) {
            for (int k = 0; k < 3; k++) {
                img32.at<float>(i, j * 3 + k) = pow(img32.at<float>(i, j * 3 + k), 1.2);
            }
        }
    }
    img32.convertTo(image, CV_8UC3, 255);
}

int main() {
    Mat image = imread("path_to_your_image.png");
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    enhanceLowLightImage(image);

    Scalar lowerBlue(100, 150, 0), upperBlue(130, 255, 255);
    Scalar lowerYellow(20, 150, 0), upperYellow(30, 255, 255);

    Mat blueMask = detectColor(image, lowerBlue, upperBlue);
    Mat yellowMask = detectColor(image, lowerYellow, upperYellow);

    vector<vector<Point>> contours;
    findContours(blueMask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    drawContours(image, contours, -1, Scalar(255, 0, 0), 2);

    findContours(yellowMask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    drawContours(image, contours, -1, Scalar(0, 255, 255), 2);

    imshow("Detected Colors", image);
    waitKey(0);

    return 0;
}


