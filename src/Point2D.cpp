#include "Point2D.h"

Point2D::Point2D()
:
    x_{0.},
    y_{0.}
{}

Point2D::Point2D(double x_coord, double y_coord)
:
    x_{x_coord},
    y_{y_coord}
{}

Point2D::Point2D(const Point2D& point)
:
    x_{point.x_},
    y_{point.y_}
{}


Point2D::Point2D(Point2D&& point) noexcept
:
    x_{(double&&)point.x_},
    y_{(double&&)point.y_}
{}

Point2D::~Point2D()
{}

// methods
double Point2D::X() const
{
    return x_;
}

double Point2D::Y() const
{
    return y_;
}

double Point2D::at(size_t i) const
{
    if(i == 0)
    {
        return x_;
    }
    else if(i == 1)
    {
        return y_;
    }
    else
    {
        throw "Index out of bounds.";
    }
}

double Point2D::magnitude() const
{
    double mag {0.};
    mag = power(x_,2) + power(y_,2);
    return sqrt(mag);
}

void Point2D::print_to_console(std::ostream& os) const
{
    os << "(" << x_ << "," << y_ << ")"<< endl;
}

void Point2D::print_to_file(std::ofstream& ofs) const
{
	ofs << x_ << " " << y_ << endl;
}

void Point2D::set_X(double x_coord)
{
    x_ = x_coord;
}

void Point2D::set_Y(double y_coord)
{
    y_ = y_coord;
}

bool Point2D::operator== (const Point2D& point) const
{
	if((this->X() == point.X()) && (this->Y() == point.Y()))
	{
		return true;
	}
	return false;
}

bool Point2D::operator!= (const Point2D& point) const
{
	return !(*this == point);
}

double& Point2D::operator[] (size_t idx)
{
    if(idx == 0)
    {
        return x_;
    }
    else if(idx == 1)
    {
        return y_;
    }
	else throw "Index out of bounds";
}

const double& Point2D::operator[](size_t idx) const
{
    if(idx == 0)
    {
        return x_;
    }
    else if(idx == 1)
    {
        return y_;
    }
	else throw "Index out of bounds";
}

Point2D& Point2D::operator+=(const Point2D& point)
{
    this->x_ += point.x_;
	this->y_ += point.y_;
    return *this;
}

Point2D& Point2D::operator-=(const Point2D& point)
{
    this->x_ -= point.x_;
    this->y_ -= point.y_;
    return *this;
}

Point2D operator+(Point2D point1, Point2D point2)
{
    return point1+= point2;
}

Point2D operator-(Point2D point1, Point2D point2)
{
    return point1-= point2;
}

Point2D& Point2D::operator= (const Point2D& point)
{
    if(this == &point) return *this;

    this->x_ = point.x_;
    this->y_ = point.y_;
    
    return *this;
}