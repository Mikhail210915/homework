//-----------------------------------------------------------------------
//  Source      : main.cpp
//  Created     : 15.09.2021
//  Author      : Mikhail Eskin
//-----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <vector>
#include <ctime>
#include <algorithm>
#include "omp.h"

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include "Point.h"
#include "MyMath.h"

using namespace std;

const int SETW_SIZE_NAME = 12;  // field's width for printing the name of the curve
const int SETW_SIZE_POINT = 25;  // field's width for printing the coordinates of points

const int CURVER_NUMBER = 100;  // Curves number for creating

/// <summary>
/// Function-comparator for sorting list in ascending order of radii.
/// </summary>
bool sortCircles(const Curve* ptr1, const Curve* ptr2)
{
    return (((Circle*)ptr2)->radius > ((Circle*)ptr1)->radius);
}


int main()
{
    // Part 2    ****************************************************************************************
    // Populate a container (e.g. vector or list) of objects of these types created in random manner with
    // random parameters.

    list<Curve*> curves;
    double radius;
    double radiusX;
    double radiusY;
    double step;
    int curveType;

    srand((unsigned int)time(0));

    // Creating curve objects 
    for (int i = 0; i < CURVER_NUMBER; i++)
    {
        curveType = 1 + rand() % 3;  // Curve type generation (1 - Circle, 2 - Ellipse, 3 - Helix)
        switch (curveType)
        {
        case 1:  // Creating circles
            radius = 1.0 + rand() % 10;
            curves.push_back(new Circle(radius));
            break;

        case 2:  // Creating ellipses
            radiusX = 11.0 + rand() % 10;
            radiusY = 1.0 + rand() % 10;
            curves.push_back(new Ellipse(radiusX, radiusY));
            break;

        case 3:  // Creating helixes
            radius = 1.0 + rand() % 10;
            step = -5.0 + rand() % 11;
            curves.push_back(new Helix(radius, step));
        }
    }


    // Part 3    ****************************************************************************************
    // Print coordinates of points and derivatives of all curves in the container at t=PI/4.

    cout.setf(ios::left);

    // Printing curve table header
    cout << setw(SETW_SIZE_NAME) << "Curve type"
        << setw(SETW_SIZE_POINT) << "| Coordinates for PI/4"
        << setw(SETW_SIZE_POINT) << "| First derivative for PI/4" << endl;
    cout << setfill('-') << setw(SETW_SIZE_NAME) << " " << setw(SETW_SIZE_POINT) << "|" << setw(SETW_SIZE_POINT) << "|" << endl;
    cout << setfill(' ');

    // Printing curve table body
    list<Curve*>::iterator iterator = curves.begin();
    while (iterator != curves.end())
    {
        cout << setw(SETW_SIZE_NAME) << (*iterator)->getName()
            << setw(SETW_SIZE_POINT) << "| " + (*iterator)->getPoint(PI / 4).toString()
            << setw(SETW_SIZE_POINT) << "| " + (*iterator)->getFirstDerivative(PI / 4).toString() << endl;

        iterator++;
    }

    // Part 4    ****************************************************************************************
    // Populate a second container that would contain only circles from the first container. Make sure the
    // second container shares (i.e. not clones) circles of the first one, e.g. via pointers.

    // Selecting circles from all curves
    vector<Curve*> circles;
    for (iterator = curves.begin(); iterator != curves.end(); iterator++)
    {
        if ((*iterator)->getName() == "Circle")
        {
            circles.push_back(*iterator);
        }
    }

    // Part 5    ****************************************************************************************
    // Sort the second container in the ascending order of circles’ radii. That is, the first element has the
    // smallest radius, the last - the greatest.

    // Sorting circles in ascending order of radii
    sort(circles.begin(), circles.end(), sortCircles);

    cout << "\n======================================================================" << endl;
    cout << "Sorted circles:" << endl;
    for (int i = 0; i < (int)circles.size(); i++)
    {
        cout << "radius: " << ((Circle*)circles[i])->radius << endl;
    }

    // Part 6    ****************************************************************************************
    // Compute the total sum of radii of all curves in the second container.

    double sum = 0;
    #pragma omp parallel
    {
        double localSum = 0;

        #pragma omp for
        for (int i = 0; i < (int)circles.size(); i++)
            localSum += ((Circle*)circles[i])->radius;

        #pragma omp atomic
        sum += localSum;
    }

    cout << "----------------" << endl;
    cout << "Summa = " << fixed << sum << endl;

    return 0;
}


