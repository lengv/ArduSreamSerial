/* 
 * File:   forkReader.hpp
 * Author: murobocup42
 *
 * Created on 30 October 2013, 4:20 PM
 * 
 * IO unit, used to break down string sent by the Arduino
 */

#ifndef FORKREADER_HPP
#define	FORKREADER_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class forkReader {
public:
    forkReader();
    forkReader(const forkReader& orig);
    virtual ~forkReader();
    
    void process(char* rawData);
private:
    string time, date;
    double mast_height, mast_dist;
    double x_orient, y_orient, z_orient;
    int count_l, count_r;
    int can_steer_angle;
//    double can_vel;
};

#endif	/* FORKREADER_HPP */

