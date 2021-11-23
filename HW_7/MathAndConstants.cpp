#pragma once
#include <math.h>
#include "MathAndConstants.h"

double MathAndConstants::get_g() {
	return 9.82;
}

double MathAndConstants::deg_to_rad(double deg) {
	return deg * 3.14 / 180;
}

double MathAndConstants::rad_to_deg(double rad) {
	return rad * 180 / 3.14;
}

double MathAndConstants::get_random_from_range(double min, double max) {
	return min + rand() / (double)RAND_MAX * (max - min);
}

double MathAndConstants::get_eps() {
	return 0.01;
}

double MathAndConstants::get_minDistance() {
	return 0.3;
}

double MathAndConstants::get_maxDistance() {
	return 1000.0;
}

int MathAndConstants::get_someBmLimit() {
	return 10;
}