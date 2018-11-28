//
// Created by patgi on 2018-11-27.
//

#include "city.hpp"

/**
 * City constructor
 * param name, double x, double y: Name of the city, x and y coordinate.
 */
city::city(string name, double x, double y) : name(name), x(x), y(y) {}

/**
 * Gets city name
 * returns name of this city.
 */
string city::get_name() {
    return this->name;
}

/**
 * Gets y coordinate of the city
 * returns y or latitude of the city.
 */
double city::get_y() {
    return this->y;
}


/**
* Gets x coordinate of the city
* returns x or longitude of the city.
*/
double city::get_x() {
    return this->x;
}
