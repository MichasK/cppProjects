//
// Created by michal on 06.03.18.
//
#include "AstronomicFrame.hpp"
#include "Types.hpp"



void AstronomicFrame::filtrFrame(){
    filtredFrame= frame.clone();
    cv::medianBlur(filtredFrame,filtredFrame,3);
    vectorFrame.assign(frame.datastart,frame.dataend);
    if(vectorFrame.empty()) throw std::runtime_error("Error during converting Frame to vector");
}

cv::Mat AstronomicFrame::computeTrecholdedFrame(double tresholdValue)const{
    cv::Mat treshFrame;
    threshold(frame,treshFrame, tresholdValue, 255, cv::THRESH_BINARY);
    // Remove salt&pepper Noise
    cv::medianBlur(treshFrame,treshFrame,3);
    return treshFrame;
}

double calculateTreshold(std::vector<int> v){
    double sum=std::accumulate(v.begin(),v.end(),0.0);
    double average =  (double)sum / v.size();
    double variance = 0.0;
    std::for_each (std::begin(v), std::end(v), [&](const double d) {
        variance += (d - average) * (d - average);
    });
    double stdev = sqrt((double)variance / (v.size()-1));
    return average + 3*stdev;//Astronomical dependence
}

