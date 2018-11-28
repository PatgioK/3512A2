//
// Created by patgi on 2018-11-27.
//

#ifndef INC_3512A2_TOUR_HPP
#define INC_3512A2_TOUR_HPP

#include "city.hpp"
#include <ctime>
#include <cstdlib>
#include <cmath>

#define CITIES_IN_TOUR 32
#define POP_SIZE 32
#define SHUFFLES 64
#define ITERATIONS 1000
#define MAP_BOUNDARY 1000
#define PARENT_POOL_SIZE
#define MUTATION_RATE
#define FITNESS 100000
/**
 * Prototype of tour
 */
class tour {
private:
    vector<city> city_list;
public:
    explicit tour(vector<city> tour_cities);
    void shuffle_cities();
    bool contains_city(string name);
    double get_distance(city a, city b);
    double base_distance();
    double fullTourDistance();
    double fitness();
    vector<city> get_cities();
};


#endif //INC_3512A2_TOUR_HPP
