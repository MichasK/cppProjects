//
// Created by michal on 06.03.18.
//

#ifndef SLITGUIDE_ASTRONOMICFRAME_HPP
#define SLITGUIDE_ASTRONOMICFRAME_HPP
#include "Frame.hpp"
#include "Types.hpp"

#include <opencv/cv.hpp>

class AstronomicFrame:public Frame{
private:
    cv::Mat filtredFrame;
    std::vector<int> vectorFrame;

public:
    AstronomicFrame(std::string s):Frame(s){};
    void filtrFrame();
    std::vector<int>  getmatrixFrame()const{return vectorFrame;};
    cv::Mat computeTrecholdedFrame(double)const;

};
double calculateTreshold(std::vector<int>);
#endif //SLITGUIDE_ASTRONOMICFRAME_HPP
