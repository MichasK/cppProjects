//
// Created by michal on 06.03.18.
//

#ifndef SLITGUIDE_ASTRONOMICFRAME_HPP
#define SLITGUIDE_ASTRONOMICFRAME_HPP
#include "Frame.hpp"

#include <opencv/cv.hpp>

namespace AstronomicFrame{
    double calcTreshold(const cv::Mat& img){

    }

class AstronomicFrame:public Frame{
private:

public:
    AstronomicFrame(std::string s):Frame(s){};
    AstronomicFrame(cv::Mat m):Frame(m){};

    void filtrFrame();
    std::vector<uchar> Mat2Vec(const cv::Mat img);
};
}
#endif //SLITGUIDE_ASTRONOMICFRAME_HPP
