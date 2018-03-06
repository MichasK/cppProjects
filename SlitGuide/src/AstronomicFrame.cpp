//
// Created by michal on 06.03.18.
//
#include "AstronomicFrame.hpp"
#include "Types.hpp"



void AstronomicFrame::filtrFrame(const cv::Mat &frame){
    filtredFrame= frame.clone();
    GaussianBlur(filtredFrame, filtredFrame, cv::Size(5, 5), 3, 3);
    vectorFrame.assign(frame.datastart,frame.dataend);
}

cv::Mat AstronomicFrame::computeTrecholdedFrame(double tresholdValue)const{
    cv::Mat treshFrame;
    threshold(frame,treshFrame, tresholdValue, 255, cv::THRESH_BINARY);
    return treshFrame;
}

double calculateTreshold(std::vector<int> v){
    double sum=std::accumulate(v.begin(),v.end(),0.0);
    double average =  sum / v.size();
    double variance = 0.0;
    std::for_each (std::begin(v), std::end(v), [&](const double d) {
        variance += (d - average) * (d - average);
    });

    double stdev = sqrt(variance / (v.size()-1));
}

