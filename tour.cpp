//
// Created by patgi on 2018-11-27.
//

#include "tour.hpp"
#include <iostream>
using namespace std;

/**
 * Constructor for tour. passes to a city list
 * param vector<city>, is a vector of all cities a tour must visit
 */
tour::tour(vector<city> tour_cities) : city_list(tour_cities) {

}


/**
 * function checks whether name of city appears in a tour.
 * param: string, city name to search for.
 * returns boolean, true if city exists in the tour.
 */
bool tour::contains_city(string name) {
    for (auto iter = city_list.begin(); iter != city_list.end(); iter++) {
        if(iter->get_name() == name) {
            return true;
        }
    }
    return false;
}

/**
 * Returns a vector of cities
 * returns Vector of cities
 */
vector<city> tour::get_cities() {
    return city_list;
}

/**
 * Shuffles cities in the tour
 * returns void
 */
void tour::shuffle_cities() {
    int i = 0;
    while(i <= SHUFFLES) {
        srand(time(NULL) + i);
        int first = rand() % CITIES_IN_TOUR;
        int second = rand() % CITIES_IN_TOUR;
        swap(city_list[first], city_list[second]);
        i++;
    }
}

/**
 * Function returns the distance between two cities. by pythagorus
 * params city A and B that we want to measure distance of.
 * returns a double representing the distance.
 */
double tour::get_distance(city A, city B) {
    double xdis = abs(B.get_x() - A.get_x());
    double ydis = abs(B.get_y() - A.get_y());
    double distance = sqrt(pow(xdis, 2) + pow(ydis, 2));
    return distance;
}

/**
 * Function returns full distance of a tour
 * returns a double, representing full distance in a tour.
 */
double tour::fullTourDistance() {
    double total_tour_distance = 0;
    //goes thru array adding distance
    for(auto iter = city_list.begin(); iter != city_list.end() - 1; iter++) {
        city &A = *iter;
        city &B = *(iter + 1);
        total_tour_distance += get_distance(A, B);
    }
    //add distance between end and start points
    city &start = *city_list.begin();
    city &end = *(city_list.end() - 1);
    total_tour_distance += get_distance(start, end);
    return total_tour_distance;
}

/**
 * Function compares all tours distances and returns the lowest
 * (fittest)
 * param: vector of the tours
 * return: double, lowest base distance
 */
double tour::base_distance() {
    double fit = fullTourDistance();

    for(auto it = city_list.begin() + 1; it != city_list.end(); it++) {
        if(get_distance(*it, *(it + 1)) < fit) {
            fit = get_distance(*it, *(it + 1));
        }
    }
    return fit;
}



/**
 * function determines fitness of a tour
 * returns a double representing a tours fitness
 */
double tour::fitness() {
    double fitness = FITNESS / fullTourDistance();
    return fitness;
}

