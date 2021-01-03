#pragma once
#include "Point2D.h"
#include <limits>

const double INFINITY = std::numeric_limits<double>::infinity();

struct Line2D
{
	Point2D Begin;
	Point2D End;

	inline double length() const
	{
		return (Begin-End).magnitude();
	}

	double slope() const
	{
		if(Begin.X() == End.X())
		{
			return INFINITY;
		}
		return (Begin.Y() - End.Y())/(Begin.X() - End.X());
	}

	bool operator== (const Line2D& line) const
	{
		return (Begin == line.Begin) && (End == line.End);
	}

	bool operator!= (const Line2D& line) const
	{
		return !(*this == line);
	}
};

enum class Sense{Clockwise, Counterclockwise};

double slope(const Point2D& point1, const Point2D& point2);

double inverse_slope(const Line2D& line);

int orientation(const Point2D& point1, const Point2D& point2, const Point2D& point3);

bool intersect_closed_interval(const Point2D& p1, const Point2D& p2, const Point2D& p3,\
	const Point2D& p4);

bool intersect_open_interval(const Point2D& p1, const Point2D& p2, const Point2D& p3, const Point2D& p4);

bool on_segment_closed_interval(const Point2D& p1, const Point2D& p2, const Point2D& p3);

bool on_segment_open_interval(const Point2D& p1, const Point2D& p2, const Point2D& p3);

Point2D multiply(const Point2D& point, double val);

Point2D ray_segment_intersection(const Line2D& line1, const Line2D& line2);

Point2D line_intersection(const Line2D& line1, const Line2D& line2);

void swap(Point2D& p1, Point2D& p2);