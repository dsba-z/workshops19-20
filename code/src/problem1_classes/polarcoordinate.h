#ifndef POLARCOORDINATE_H
#define POLARCOORDINATE_H


class PolarCoordinate
{
    double radius;
    double angle;

public:
    PolarCoordinate();
    PolarCoordinate(double radius);
    PolarCoordinate(double radius, double angle);
    
    double getRadius() const {return radius;}
    double getAngle() const {return angle;}
    
    PolarCoordinate operator+(const PolarCoordinate& b) const;
    PolarCoordinate operator-(const PolarCoordinate& b) const;
};

#endif // POLARCOORDINATE_H
