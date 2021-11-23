#pragma once

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include "Strike.h"

class MathAndConstants {
public:
	static double get_g();

	static double deg_to_rad(double deg);

	static double rad_to_deg(double rad);

	static double get_random_from_range(double min, double max);

	static double get_eps();

	static double get_minDistance();

	static double get_maxDistance();

	static int get_someBmLimit();
};
