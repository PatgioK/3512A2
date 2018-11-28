#include <iostream>
#include "city.hpp"
#include "tour.hpp"

/**
 * function creates a vector of tours
 * returns vector of tours
 */
vector<tour> make_tours() {
    vector<tour> tourList;

    for (int k = 0; k < POP_SIZE; k++) { //num of candidate tours

        srand(time(NULL) + k);
        int n = 65;
        vector<city> this_tour;

        //for number of cities in the tour
        for (int i = 0; i < CITIES_IN_TOUR; i++) {

            char asciiname = (char)n + i;
            string name(1, asciiname);

            int x = rand() % MAP_BOUNDARY;
            int y = rand() % MAP_BOUNDARY;

            city CITY(name, x, y);
            this_tour.push_back(CITY);
        }

        tour my_tour(this_tour);
        my_tour.shuffle_cities();
        for (auto &iter : my_tour.get_cities()) {
            cout << "City:" << iter.get_name() << " X:" << iter.get_x() << " Y:" << iter.get_y() << endl;
        }
        cout << " " << endl;
        tourList.push_back(my_tour);
    }
    return tourList;
}


int main() {

    vector<tour> tour = make_tours();
    double dis = tour[0].get_distance(*tour[0].get_cities().begin(), *(tour[0].get_cities().begin()+1) );
    cout << "base distance:" << dis << endl;

    bool containsA = tour[0].contains_city("A");
    cout << containsA << endl;

    return 0;
}