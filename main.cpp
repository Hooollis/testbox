#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
    // 读取图像
    cv::Mat img = cv::imread("test.png");
    if (img.empty()) {
        std::cout << "Could not load image!" << std::endl;
        return -1;
    }
    cv::imshow("img", img);

    // 转换为灰度图并阈值处理
    cv::Mat gray, thresh;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, thresh, 200, 255, cv::THRESH_BINARY);
    
    // 查找轮廓
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hier;
    cv::findContours(thresh, contours, hier, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    
    // 遍历轮廓
    for (const auto& c : contours) {
        // 绘制轴对齐边界矩形
        cv::Rect rect = cv::boundingRect(c);
        cv::rectangle(img, rect, cv::Scalar(0, 255, 0), 2);
        
        // 计算最小面积旋转矩形
        cv::RotatedRect minRect = cv::minAreaRect(c);
        cv::Point2f vertices[4];
        minRect.points(vertices);
        
        // 转换为整数点
        std::vector<cv::Point> box;
        for (int i = 0; i < 4; i++) {
            box.push_back(cv::Point(static_cast<int>(vertices[i].x), 
                                   static_cast<int>(vertices[i].y)));
        }
        
        // 绘制旋转矩形
        std::vector<std::vector<cv::Point>> contours_to_draw = {box};
        cv::drawContours(img, contours_to_draw, 0, cv::Scalar(0, 0, 255), 3);        
    }
    
    // 显示结果
    cv::imshow("contours", img);
    cv::waitKey(0);
    
    return 0;
}
