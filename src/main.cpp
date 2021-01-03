#include "Point2D.h"
#include "Polygon2D.h"
#include "indexList.h"
#include "basicArithmetic.h"
#include "Point2DHelper.h"
#include "pair.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;
using std::map;

const Point2D inf_point{ INFINITY, INFINITY };
const Point2D origin{ 0,0 };

bool is_inside(Polygon2D& polygon, const Point2D& point);
bool out_of_bounding_box(const Polygon2D& polygon, const Point2D& point);

void sort_clockwise(vector<Point2D>& rectangle);
void sort_counterclockwise(vector<Point2D>& rectangle);

//double illuminated_length(const Polygon2D& coordinates, const Point2D& point);
void get_sorted_coordinates_for_ray_intersections(vector<Point2D>& coordinates, const Point2D& source, const Direction& dir);
vector<Line2D> ray_vector(const vector<Point2D>& coordinates, const Point2D& source);
void clear_up(vector<Point2D>& pointVec, const Point2D& point, const Direction& dir);

template<class IteratorClass, class Value = Point2D>
bool has_intersected_before(Line2D Ray, IteratorClass it1, IteratorClass it2);

template<typename T>
vector<T> slice(const vector<T>& v, size_t m, size_t n);
template<typename T>
void combine(vector<T>& vec1, const vector<T>& vec2);

double get_illuminated_length(vector<Point2D> building, vector<Line2D> rays, const Point2D& source, const Direction& dir);

void sort_by_x(vector<Point2D>& pointVec);
void sort_by_y(vector<Point2D>& pointVec);

void print(const vector<Point2D>& pointVec)
{
	for (size_t idx{ 0 }; idx != pointVec.size(); idx++)
	{
		std::cout << pointVec[idx];
	}
}

void print(const vector<Line2D>& lineVec)
{
	for (size_t idx{ 0 }; idx != lineVec.size(); idx++)
	{
		std::cout << "{\n" << lineVec[idx].Begin << lineVec[idx].End << "}" << std::endl;
	}
}

int main(int argc, char **argv)
{
	std::cout.precision(10);

    Polygon2D Polygon1;
	Polygon2D Polygon2;

    Polygon1.append({0,0});  // 0
    Polygon1.append({10,0}); // 1
	Polygon1.append({10,5}); // 2
    Polygon1.append({9,3});  // 3
    Polygon1.append({8,6});  // 4
	Polygon1.append({7,2});  // 5
	Polygon1.append({6,5});  // 6
	Polygon1.append({5,3});  // 7
	Polygon1.append({3,2});  // 8
	Polygon1.append({2,5});  // 9
	Polygon1.append({0,4});  // 10

	Point2D P1{6,4};
	Point2D P2{9.0000001,3.000001};
	Point2D P3{5,3};
	Point2D P4{12,3};
	
	vector<Point2D> building;
	building.push_back({ 5, 0 });
	building.push_back({3, 0});
	building.push_back({5, 3});
	building.push_back({3, 3});
	building.push_back({5.2, 0});
	building.push_back({5.2, 5});
	building.push_back({7.1, 0});
	building.push_back({7.1, 5});
	building.push_back({9, 0});
	building.push_back({9, 4});
	building.push_back({12.54, 0});
	building.push_back({12.54, 4});
	building.push_back({ 2,0 });
	building.push_back({ 2,4 });
	building.push_back({ 1,4 });
	building.push_back({ 1,0 });
	building.push_back({ 17,0 });
	building.push_back({ 17,6 });
	building.push_back({ 15,6 });
	building.push_back({ 15,0 });

	Point2D source{ 8,8 };
	//Point2D source{ 7,8 };
	//Point2D source{ 9,8 };
	//Point2D source{ 6,8 };

	vector<Point2D> east_building{building};
	vector<Point2D> west_building{building};

	get_sorted_coordinates_for_ray_intersections(west_building, source, Direction::West);
	get_sorted_coordinates_for_ray_intersections(east_building, source, Direction::East);

	std::cout << "east\n";
	clear_up(east_building, source, Direction::East);
	print(east_building);

	std::cout << "west\n";
	clear_up(west_building, source, Direction::West);
	print(west_building);

	vector<Line2D> east_rays = ray_vector(east_building, source);
	vector<Line2D> west_rays = ray_vector(west_building, source);

	double exposed_len_west = get_illuminated_length(west_building ,west_rays, source, Direction::West);
	double exposed_len_east = get_illuminated_length(east_building, east_rays, source, Direction::East);
	std::cout << "East Length in sunlight = "<< exposed_len_east << '\n';
	std::cout << "West Length in sunlight = "<< exposed_len_west << '\n';


	std::cout << "Source " << source;
	
	//std::cout << "P1 = " << P1 << "P2 = " << P2 << "P3 = " << P3 << "P4 = " << P4 << '\n';
	//std::cout << "P1 is inside Polygon1: " << std::boolalpha << is_inside(Polygon1, P1) << '\n';
	//std::cout << "P2 is inside Polygon1: " << std::boolalpha << is_inside(Polygon1, P2) << '\n';
	//std::cout << "P3 is inside Polygon1: " << std::boolalpha << is_inside(Polygon1, P3) << '\n';	
	std::cin.get();

    return 0;
}

bool is_inside(Polygon2D& polygon, const Point2D& point)
{
	if(out_of_bounding_box(polygon, point))
	{
		return false;
	}
	else
	{
		Point2D start = Point2D{0.1*(point - start).magnitude(),0} + Point2D{polygon.east_bound()};
		std::cout << start;
		size_t count{0};
		for(size_t idx{0}; idx != polygon.get_size(); idx++)
		{
			if(intersect_closed_interval(polygon[idx], polygon[(idx+1)%polygon.get_size()], point, start))
			{
				count++;
			}
		}

		std::cout << count << '\n';
		return (count%2==1);
	}
}

template <class IteratorClass, class Value = Point2D>
bool has_intersected_before(Line2D Ray, IteratorClass it1, IteratorClass it2)
{
	size_t count{ 0 };
	Value prevVal;
	bool intersected{ false };

	while (it1 != it2)
	{
		if ((count+1)%4 != 0 && *it1 != Ray.Begin && *it1 != Ray.End \
			&& intersect_open_interval(Ray.Begin, Ray.End, prevVal, *it1))
		{
			intersected = true;
			break;
		}
		count++;
		prevVal = *it1;
		it1++;
	}

	return intersected;
}

bool out_of_bounding_box(const Polygon2D& polygon, const Point2D& point)
{
	if((point.X() > polygon.east_bound().X()) || (point.X() < polygon.west_bound().X()))
	{
		return true;
	}
	else if((point.Y() > polygon.north_bound().Y()) || (point.Y() < polygon.south_bound().Y()))
	{
		return true;
	}
	else return false;
}

// sort in clockwise or counter-clockwise manner four coordinates at a time to
// get ray intersections in proper order
void get_sorted_coordinates_for_ray_intersections(vector<Point2D>& coordinates, const Point2D& source, const Direction& dir)
{
	vector<Point2D> tmpArr;
	size_t arrSize{coordinates.size()};

	switch (dir)
	{
		case Direction::East:
		{
			sort_by_x(coordinates);
			for (size_t idx{ 0 }; idx != arrSize; idx++)
			{
				if (idx % 4 == 0)
				{
					tmpArr = slice(coordinates, idx, idx + 3);
					sort_clockwise(tmpArr);
					combine(coordinates, tmpArr);
				}
			}
			coordinates.erase(coordinates.begin(), coordinates.begin() + arrSize);
			break;
		}
		case Direction::West:
		{
			sort_by_x(coordinates);
			for (size_t idx{ arrSize }; idx != 2; idx--)
			{
				if ((idx + 1)% 4 == 0)
				{
					tmpArr = slice(coordinates, idx -3, idx);
					sort_counterclockwise(tmpArr);
					combine(coordinates, tmpArr);
				}
			}
			coordinates.erase(coordinates.begin(), coordinates.begin() + arrSize);
			break;
		}
	}

	coordinates.erase(std::remove(coordinates.begin(), coordinates.end(), source), coordinates.end());
}

// generates rays for intersection with sorted building coordinates
vector<Line2D> ray_vector(const vector<Point2D>& coordinates, const Point2D& source)
{
	vector<Line2D> Rays;
	Line2D line;
	vector<Point2D> in_between;

	line.Begin = source;
	for (size_t idx{ 0 }; idx != coordinates.size(); idx++)
	{
		if ((idx + 1) % 4 == 0)	continue;
		line.End = coordinates[idx];
		Rays.push_back(line);

		if (coordinates[idx].X() > source.X() && coordinates[idx + 1].X() < source.X())
		{
			in_between.push_back(coordinates[idx - 1]);
			in_between.push_back(coordinates[idx + 2]);
		}

		for (size_t idx{ 0 }; idx != in_between.size(); idx++)
		{
			line.End = in_between[idx];
			Rays.erase(std::remove(Rays.begin(), Rays.end(), line), Rays.end());
		}
	}
	return Rays;
}

// clear unnecessary elements to get east or westward buildings from sorted array by 
// get_sorted_coordinates_for_ray_intersections function
void clear_up(vector<Point2D>& pointVec, const Point2D& point, const Direction& dir)
{
	switch (dir)
	{
		case Direction::East:
		{
			for (size_t idx{ pointVec.size()-1 }; idx >= 0; idx--)
			{
				if ((idx + 2) % 4 == 0 && pointVec[idx].X() == point.X())
				{
				pointVec.erase(pointVec.begin(), pointVec.begin() + idx + 2);
				break;
				}
				else if (pointVec[idx].X() < point.X())
				{
				pointVec.erase(pointVec.begin(), pointVec.begin() + idx + 1);
				break;
				}
				else if ((pointVec[idx].X() > point.X() && pointVec[idx - 1].X() < point.X()) && (idx + 2) % 4 == 0)
				{
				pointVec.erase(pointVec.begin(), pointVec.begin() + idx + 2);
				break;
				}
			}
			break;
		}
		case Direction::West:
		{
			for (size_t idx{ 0 }; idx != pointVec.size(); idx++)
			{
				if ((idx + 2) % 4 == 0 && pointVec[idx].X() == point.X())
				{
					pointVec.erase(pointVec.begin(), pointVec.begin() + idx + 2);
					break;
				}
				else if (pointVec[idx].X() <= point.X())
				{
					pointVec.erase(pointVec.begin(), pointVec.begin() + idx);
					break;
				}
				else if (((pointVec[idx].X() >= point.X()) && (pointVec[idx + 1].X() < point.X())) && (idx + 2) % 4 == 0)
				{
					pointVec.erase(pointVec.begin(), pointVec.begin() + idx - 1);
					break;
				}
			}
			break;
		}
	}
}

bool in_between_case(const vector<Point2D>& west_coordinates, const Point2D& source)
{
	return (source.X() < west_coordinates[1].X() && source.X() > west_coordinates[2].X());
}

double get_illuminated_length(vector<Point2D> building, vector<Line2D> rays, const Point2D& source, const Direction& dir)
{
	double illuminated_len{ 0 };
	size_t count{ 0 };
	Line2D side;
	Point2D intersection_point;
	vector<Point2D> intersections;
	Point2D previous_intersection{ inf_point };

	for (size_t idx{ 0 }; idx != building.size(); idx++)
	{
		if ((idx + 1) % 4 != 0)
		{
			side.Begin = building[idx];
			side.End = building[idx + 1];

			for (size_t jdx{ 0 }; jdx != idx - count + 1; jdx++)
			{
				if (!has_intersected_before(rays[jdx], building.begin(), building.begin() + idx))
				{
					try
					{
						intersection_point = ray_segment_intersection(rays[jdx], side);
						if (((idx + 2) % 4 == 0) && (building[idx] != intersection_point)) continue;
						intersections.push_back(intersection_point);
					}
					catch (const char* msg)
					{
						std::cerr << "Point index = " << idx << " Ray index = " << jdx << '\n' << msg << std::endl;
						continue;
					}
				}
			}
		}
		else count++;
	}

	print(intersections);
	
	for (size_t idx{ 0 }; idx != intersections.size() - 1; idx++)
	{
		if (!(intersections[idx].X() != intersections[idx+1].X()) !=
			!(intersections[idx].Y() != intersections[idx+1].Y()))
		{
			std::cout << intersections[idx] << " , " << intersections[idx+1] << '\n';
			illuminated_len += (intersections[idx] - intersections[idx+1]).magnitude();
		}
	}

	return illuminated_len;
}

void sort_by_x(vector<Point2D>& pointVec)
{
	bool is_sorted;

	for (size_t idx{ 0 }; idx != pointVec.size() - 1; idx++)
	{
		is_sorted = false;
		for (size_t jdx{ 0 }; jdx != pointVec.size() - idx - 1; jdx++)
		{
			if (pointVec[jdx][0] > pointVec[jdx + 1][0])
			{
				std::swap(pointVec[jdx], pointVec[jdx + 1]);
				is_sorted = true;
			}
			else
			{
				continue;
			}
		}
		if (!is_sorted) break;
	}
}

void sort_by_y(vector<Point2D>& pointVec)
{
	bool is_sorted;

	for (size_t idx{ 0 }; idx != pointVec.size() - 1; idx++)
	{
		is_sorted = false;
		for (size_t jdx{ 0 }; jdx != pointVec.size() - idx - 1; jdx++)
		{
			if (pointVec[jdx][1] > pointVec[jdx + 1][1])
			{
				std::swap(pointVec[jdx], pointVec[jdx + 1]);
				is_sorted = true;
			}
			else
			{
				continue;
			}
		}
		if (!is_sorted) break;
	}
}

void sort_clockwise(vector<Point2D>& rectangle)
{
	sort_by_y(rectangle);
	sort_by_x(rectangle);
	if(rectangle[3].Y() > rectangle[2].Y()) swap(rectangle[3], rectangle[2]);
}

void sort_counterclockwise(vector<Point2D>& rectangle)
{
	sort_clockwise(rectangle);
	std::reverse(rectangle.begin(), rectangle.end());
}

template<typename T>
vector<T> slice(const vector<T>& v, size_t m, size_t n)
{
	auto first = v.cbegin() + m;
	auto last = v.cbegin() + n + 1;

	vector<T> vec(first, last);
	return vec;
}

template<typename T>
void combine(vector<T>& vec1, const vector<T>& vec2)
{
	for (const auto& ele : vec2)
	{
		vec1.push_back(ele);
	}
}