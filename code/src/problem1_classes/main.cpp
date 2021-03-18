#include <iostream>
#include <cmath>

#include "polarcoordinate.h"

const double EPS = 1e-6;

bool checkFields(const PolarCoordinate& p, double corrRad, double corrAng)
{
    return std::abs(p.getRadius() - corrRad) < EPS && std::abs(p.getAngle() - corrAng) < EPS;
}


bool testConstructor()
{
    PolarCoordinate a;
    bool defConstr = checkFields(a, 0, 0);
    
    double testRad = 1.52;
    PolarCoordinate b(testRad);
    bool singleConstr = checkFields(b, testRad, 0);
    
    double testAng = M_PI;
    PolarCoordinate c(testRad, testAng);
    bool doubleConstr = checkFields(c, testRad, testAng);
    
    return defConstr && singleConstr && doubleConstr;
}


bool testAdditionConst(const PolarCoordinate& a, const PolarCoordinate& b, double rad, double ang)
{
    PolarCoordinate c = a + b;
    return checkFields(c, rad, ang);
}


bool testAddition()
{
    PolarCoordinate a(10, 0);
    PolarCoordinate b(10, M_PI_2);
    return testAdditionConst(a, b, 10*std::sqrt(2), M_PI_4);
}

bool testSubtractionConst(const PolarCoordinate& a, const PolarCoordinate& b, double rad, double ang)
{
    PolarCoordinate c = a + b;
    return checkFields(c, rad, ang);
}

bool testSubtraction()
{
    PolarCoordinate a(10, 0);
    PolarCoordinate b(10, M_PI_2);
    return testSubtractionConst(a, b, 10*std::sqrt(2), M_PI_4 + M_PI_2);
}


bool testEverything()
{
    bool constructors = testConstructor();
    
    if (!constructors)
    {
        std::cout << "Error in constructors\n";
        return false;
    }
    
    bool addition = testAddition();
    if (!addition)
    {
        std::cout << "Error in addition\n";
        return false;
    }

    bool subtraction = testSubtraction();
    if (!subtraction)
    {
        std::cout << "Error in subtraction\n";
        return false;
    }
    return true;

}

int main()
{

    bool success = testEverything();
    if (success)
    {
        std::cout << "All tests have been passed successfully.\n";
    }
    else
    {
        std::cout << "Some tests have failed. Execution of the following tests stopped.\n";
    }
    return 0;
}
