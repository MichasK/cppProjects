#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include "src/Frame.hpp"
#include "src/AstronomicFrame.hpp"
#include "gtest/gtest.h"

int main( int argc, char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    AstronomicFrame f("/home/michal/CLionProjects/SlitGuide/Frames/GuideFrame_2015_03_10_18_09_02.bmp");
    f.filtrFrame();
    f.computeFrameToVector();
    auto grey=f.getFrame();
    auto tresh = calculateTreshold(f.getvecFrame());
    auto bin=f.computeTrecholdedFrame(tresh);
    bin.computeFrameToVector();
    auto roi = bin.FrameROI();
    cv::namedWindow( "Bin image", CV_WINDOW_AUTOSIZE );
    cv::imshow( "Bin image",roi.getFrame());
    cv::waitKey(0);
    return 0;
}
