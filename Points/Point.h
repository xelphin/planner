#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>



class Point {

    public:
        /*
        * C'tor of Point class
        *
        * @return
        *      A new instance of Point.
        */
        Point(const std::string name, const int month, const int day);

        /*
        * Print Point.
        */
        friend std::ostream& operator<<(std::ostream& os, const Point& point);

        // D'tor
        virtual ~Point() {}

    private:

};

#endif