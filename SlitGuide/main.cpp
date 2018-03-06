#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include "src/Frame.hpp"
#include "src/AstronomicFrame.hpp"
#include "src/Types.hpp"
#include "gtest/gtest.h"

int main( int argc, char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    cv::Mat s= cv::imread("/home/michal/CLionProjects/SlitGuide/Frames/GuideFrame_2015_03_10_18_09_02.bmp");
    AstronomicFrame f("/home/michal/CLionProjects/SlitGuide/Frames/GuideFrame_2015_03_10_18_09_02.bmp");
    f.filtrFrame();
    auto grey=f.getFrame();
    auto tresh=calculateTreshold(f.getmatrixFrame());
    auto bin=f.computeTrecholdedFrame(tresh);

    std::vector<cv::Vec3f> circles;

    /// Apply the Hough Transform to find the circles
    HoughCircles( bin, circles, CV_HOUGH_GRADIENT, 1, bin.rows/8, 200, 5, 10, bin.rows/8 );

    /// Draw the circles detected
    for( size_t i = 0; i < circles.size(); i++ )
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        // circle center
        circle( s, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
        // circle outline
        circle( s, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
    }
    cv::namedWindow( "Bin image", CV_WINDOW_AUTOSIZE );
    cv::imshow( "Bin image", bin );
    cv::namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );
    cv::imshow( "Gray image",s );
    cv::waitKey(0);
    return 0;
}
