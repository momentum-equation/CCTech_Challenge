#include "Point2DHelper.h"

double slope(const Point2D& point1, const Point2D& point2)
{
	if(point1.X() - point2.X() == 0)
	{
		return INFINITY; 
	}
	else
	{
		return (point1.Y() - point2.Y())/(point1.X() - point2.X()); // + small_val);
	}
}

double inverse_slope(const Line2D& line)
{
	return 1. / slope(line.Begin, line.End);
}

int orientation(const Point2D& point1, const Point2D& point2, const Point2D& point3)
{
	double val = (point2.Y() - point1.Y())*(point3.X() - point2.X()) - \
		(point2.X() - point1.X())*(point3.Y() - point2.Y());
	if(val == 0) return 0;
	return (val > 0) ? 1:-1;
}

bool on_segment_closed_interval(const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	if(p3.X() <= max(p1.X(), p2.X()) && p3.X() >= min(p1.X(), p2.X()) && \
		p3.Y() <= max(p1.Y(), p2.Y()) && p3.Y() >= min(p1.Y(), p2.Y()))
			return true;
	return false;
}

bool on_segment_open_interval(const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	if (p3.X() < max(p1.X(), p2.X()) && p3.X() > min(p1.X(), p2.X()) && \
		p3.Y() < max(p1.Y(), p2.Y()) && p3.Y() > min(p1.Y(), p2.Y()))
		return true;
	return false;
}

bool intersect_closed_interval(const Point2D& p1, const Point2D& p2, const Point2D& p3,\
	const Point2D& p4)
{
	int ori1 = orientation(p1, p2, p3);
	int ori2 = orientation(p1, p2, p4);
	int ori3 = orientation(p3, p4, p1);
	int ori4 = orientation(p3, p4, p2);
	
	bool are_intersecting{ false };
	
	if(ori1 != ori2 && ori3 != ori4)
	{
		are_intersecting = true;
	}
	else if(ori1 == 0 && on_segment_closed_interval(p1, p2, p3))
	{
		are_intersecting = true;
	}
	else if(ori2 == 0 && on_segment_closed_interval(p1, p2, p4))
	{
		are_intersecting = true;
	}
	else if(ori3 == 0 && on_segment_closed_interval(p3, p4, p1))
	{
		are_intersecting = true;
	}
	else if(ori4 == 0 && on_segment_closed_interval(p3, p4, p2))
	{
		are_intersecting = true;
	}
	return are_intersecting;
}

bool intersect_open_interval(const Point2D& p1, const Point2D& p2, const Point2D& p3, \
	const Point2D& p4)
{
	int ori1 = orientation(p1, p2, p3);
	int ori2 = orientation(p1, p2, p4);
	int ori3 = orientation(p3, p4, p1);
	int ori4 = orientation(p3, p4, p2);

	bool are_intersecting{ false };

	if (ori1 != ori2 && ori3 != ori4)
	{
		are_intersecting = true;
	}
	else if (ori1 == 0 && on_segment_open_interval(p1, p2, p3))
	{
		are_intersecting = true;
	}
	else if (ori2 == 0 && on_segment_open_interval(p1, p2, p4))
	{
		are_intersecting = true;
	}
	else if (ori3 == 0 && on_segment_open_interval(p3, p4, p1))
	{
		are_intersecting = true;
	}
	else if (ori4 == 0 && on_segment_open_interval(p3, p4, p2))
	{
		are_intersecting = true;
	}
	else
	{
		are_intersecting = false;
	}
	return are_intersecting;
}

Point2D multiply(const Point2D& point, double val)
{
	Point2D tmp;
	tmp[0] = val*point[0];
	tmp[1] = val*point[1];
	return tmp;
}

// intersection of a ray (first argument) and a line segment (second argument)
Point2D ray_segment_intersection(const Line2D& line1, const Line2D& line2)
{
	Point2D sol;
	double m1 = line1.slope();
	double m2 = line2.slope();

	double y11 = line1.Begin.Y();
	double y21 = line2.Begin.Y();
	
	double x11 = line1.Begin.X();
	double x21 = line2.Begin.X();
	
	double c1 = y11 - m1*x11;
	double c2 = y21 - m2*x21;
	
	double D = determinant(-m1, 1, -m2, 1);
	
	if(m1 == m2) throw "Parallel or coincident lines. No unique solution.";
	
	if(m1 == INFINITY && m2 != INFINITY)
	{
		sol[0] = x11;
		sol[1] = m2*x11 + y21 - m2*x21;
	}
	else if(m2 == INFINITY && m1 != INFINITY)
	{
		sol[0] = x21;
		sol[1] = m1*x21 + y11 - m1*x11;
	}
	else
	{
		sol[0] = determinant(c1, 1, c2, 1)/D;
		sol[1] = determinant(-m1, c1, -m2, c2)/D;		
	}
	
	if(!(on_segment_closed_interval(line2.Begin, line2.End, sol)))
	{
		throw "Solution out of limits of the line segment.";
	}
	
	return sol;
}

Point2D line_intersection(const Line2D& line1, const Line2D& line2)
{
	Point2D sol;
	double m1 = line1.slope();
	double m2 = line2.slope();

	double y11 = line1.Begin.Y();
	double y21 = line2.Begin.Y();
	
	double x11 = line1.Begin.X();
	double x21 = line2.Begin.X();
	
	double c1 = y11 - m1*x11;
	double c2 = y21 - m2*x21;
	
	double D = determinant(-m1, 1, -m2, 1);
	
	if(m1 == m2) throw "Parallel or coincident lines. No unique solution.";
	
	if(m1 == INFINITY && m2 != INFINITY)
	{
		sol[0] = x11;
		sol[1] = m2*x11 + y21 - m2*x21;
	}
	else if(m2 == INFINITY && m1 != INFINITY)
	{
		sol[0] = x21;
		sol[1] = m1*x21 + y11 - m1*x11;
	}
	else
	{
		sol[0] = determinant(c1, 1, c2, 1)/D;
		sol[1] = determinant(-m1, c1, -m2, c2)/D;		
	}
	
	return sol;
}

void swap(Point2D& p1, Point2D& p2)
{
	Point2D tmp{p1};
	p1 = p2;
	p2 = tmp;
}