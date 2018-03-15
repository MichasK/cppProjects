//
// Created by michal on 05.03.18.
//

#ifndef SLITGUIDE_FRAME_HPP
#define SLITGUIDE_FRAME_HPP

#include <opencv/cv.hpp>

#include <vector>
#include <string>
#include <exception>
typedef std::vector<int> row;
typedef std::vector<row> Matrix;

class Frame{
protected:
    cv::Mat frame;
    std::string frameName;
public:
    int cols;
    int rows;
    Frame(std::string);
    Frame(cv::Mat m): frame(m),cols(m.cols),rows(m.rows){};
    Frame(){throw std::invalid_argument("Empty frame must not be created");}
    cv::Mat getFrame()const{ return frame;};
};
#endif //SLITGUIDE_FRAME_HPP
