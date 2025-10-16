**OpenCV最小范围框选测试项目**

一个基于OpenCV和C++的简单最小范围框选测试项目，可以在Ubuntu系统下运行。该项目能够从图像对图像进行两种形式的最小范围框选。


**功能特性**

· 原始图像读取

· 将图像转换为灰度图并阈值处理

· 查找图片轮廓

· 绘制对齐边界矩形和旋转矩形

· 对图像进行逻辑运算

· 分离结果保存功能


**环境要求**

系统要求

· Ubuntu 18.04 或更高版本


依赖库

· OpenCV 4.0 或更高版本

· C++17 兼容编译器


**安装步骤**

1. 安装依赖

    bash

    sudo apt update

    sudo apt install build-essential cmake git

    sudo apt install libopencv-dev

2. 克隆项目

　　bash

　　git clone https://github.com/Hooollis/testbox.git

　　cd testbox

3. 编译项目

	bash

	mkdir build

	cd build

	cmake ..

	make

	
**使用方法**

基本使用

	Bash

	# 使用默认摄像头进行最小范围框选

	./testbox


交互式控制

程序运行后，会出现两个窗口：

· Original：显示原始图像

· Out：显示最小范围框选后的图像


**代码示例**

主要的最小范围框选逻辑：

	Cpp
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
        
**项目结构**

Text

	Testbox

    ├── CMakeLists.txt

    ├── main.cpp

    ├── test.png

    └──README.md

    
**故障排除**

常见问题

1. OpenCV 未找到

o确认 OpenCV 安装：pkg-config --modversion opencv4

o如果使用自定义安装路径，修改 CMakeLists.txt

2. 编译错误

o确保 GCC 版本支持 C++17

o检查 OpenCV 版本兼容性


**调试模式**

启用调试输出：

	bash

	./testbox –debug

	
**贡献指南**

欢迎提交Issue 和 Pull Request！

1. Fork 本项目

2. 创建特性分支

3. 提交更改

4. 推送到分支

5. 创建Pull Request


**许可证**

本项目采用MIT许可证 – 查看LICENSE文件了解详情


**更新日志**

V1.0.0（2024-01-01）

· 初始版本发布

· 支持图像进行最小范围框选


**联系方式**

· 项目主页：https://github.com/Hooollis /testbox

· 问题反馈：https://github.com/Hooollis /testbox/issues


**致谢**

· 感谢 OpenCV 社区提供的优秀计算机视觉库

· 感谢所有贡献者的支持与帮助
