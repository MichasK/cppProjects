#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include "src/Frame.hpp"
#include "src/AstronomicFrame.hpp"
#include "src/Types.hpp"

int main( int argc, char** argv )
{
    AstronomicFrame f("/home/michal/Downloads/panda.jpg");
    auto tresh=calculateTreshold(f.getmatrixFrame());
    auto bin=f.computeTrecholdedFrame(tresh);
    cv::namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );
    imshow( "Gray image", bin );
    cv::waitKey(0);
    return 0;
}
