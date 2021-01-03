#pragma once
#include "PrintInterface.h"
#include "basicArithmetic.h"

using std::cout;
using std::cin;
using std::endl;

class Point2D: public PrintInterface
{
private:
    double x_;
    double y_;
	
public:
    Point2D();
    Point2D(double x_coord, double y_coord);
    Point2D(const Point2D& point);
    Point2D(Point2D&& point) noexcept;
    virtual ~Point2D();

    // methods
    double X() const;
    double Y() const;
    double at(size_t i) const;
    double magnitude() const;	
	
    virtual void print_to_console(std::ostream& os) const override;
    virtual void print_to_file(std::ofstream& ofs) const override;
    
    void set_X(double x_coord);
    void set_Y(double y_coord);

    double& operator[] (size_t idx);
    const double& operator[] (size_t idx) const;
    
	bool operator== (const Point2D& point) const;
	bool operator!= (const Point2D& point) const;
	
    Point2D& operator= (const Point2D& point);
    Point2D& operator+= (const Point2D& point);
    Point2D& operator-= (const Point2D& point);
    // Point2D& operator= (Point2D&& point);
    friend Point2D operator+ (Point2D point1, Point2D point2);
    friend Point2D operator- (Point2D point, Point2D point2);

    friend std::istream operator>> (std::istream& is, Point2D& point);
    friend std::ifstream operator>> (std::ifstream& ifs, Point2D& point);
};
