//
// Created by patgi on 2018-11-27.
//

#ifndef INC_3512A2_CITY_HPP
#define INC_3512A2_CITY_HPP

#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class city {
private :
    string name;
    double x;
    double y;

public:
    city(string name, double x, double y);
    string get_name();
    double get_x();
    double get_y();
};

#endif //INC_3512A2_CITY_HPP
