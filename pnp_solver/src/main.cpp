#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>

int main() {
    // 相机内参矩阵
    cv::Mat cameraMatrix = (cv::Mat_<double>(3,3) << 1462.3697, 0, 398.59394,
                                                        0, 1469.68385, 110.68997,
                                                        0, 0, 1);

    // 畸变系数
    cv::Mat distCoeffs = (cv::Mat_<double>(5,1) << 0.003518, -0.311778, -0.016581, 0.023682, 0.0000);

    // 3D点（世界坐标）
    cv::Mat objectPoints = (cv::Mat_<double>(4,3) << 
        0, 0, 0,
        10, 0, 0,
        10, 10, 0,
        0, 10, 0);

    // 2D点（图像坐标）
    cv::Mat imagePoints = (cv::Mat_<double>(4,2) << 
        100, 150,
        300, 150,
        300, 300,
        100, 300);

    // 旋转向量和平移向量
    cv::Mat rvec, tvec;

    // 使用solvePnP函数计算位姿
    bool success = cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec);

    if(success) {
        std::cout << "PNP计算成功" << std::endl;

        // 将旋转向量转换为旋转矩阵
        cv::Mat R;
        cv::Rodrigues(rvec, R);

        // 输出旋转矩阵和平移向量
        std::cout << "旋转矩阵R: " << R << std::endl;
        std::cout << "平移向量t: " << tvec << std::endl;

        // 计算距离，使用勾股定理
        double distance = cv::norm(tvec, cv::NORM_L2);

        // 输出距离（转换为米）
        std::cout << "机器人距离摄像头的距离: " << distance / 100.0 << " 米" << std::endl;
    } else {
        std::cout << "PNP计算失败" << std::endl;
    }

    return 0;
}

