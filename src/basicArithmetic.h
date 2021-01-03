#pragma once
//#include "indexList.h"
#include "Point2D.h"
#include <cstddef>

enum class Direction{East, West, North, South};

enum class Coordinate{x, y};

const double small_val = 1e-15;

double power(double val, int expo);

double abs(double val);

double sqrt(double num);

void swap(size_t& a, size_t& b);

void swap(ssize_t& a, ssize_t& b);

double max(const double& val1, const double& val2);

double min(const double& val1, const double& val2);

double determinant(const double& a, const double& b, const double& c, const double& d);
