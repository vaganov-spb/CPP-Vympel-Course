#pragma once

#include "Strike.h"
#include "MathAndConstants.h"

Parabola::Parabola(const tPoint& p_from, const tPoint& p_to, double p_maxH) :p_start(p_from), p_end(p_to), maxH(p_maxH) {};

void Parabola::calculateParams() {
	p_current = p_start;
	angle = atan(4 * maxH / (-p_start.x + p_end.x));
	v0 = sqrt(2 * MathAndConstants::get_g()  * maxH) / sin(angle);
}

double Parabola::flightT() const {
	// TODO
	return 2 * v0 * sin(angle) / MathAndConstants::get_g();
}

const tPoint& Parabola::position() const {
	// TODO
	return p_current;
}

void Parabola::Move(double t) {
	// TODO
	if (t > flightT()) {
		p_current.x = p_end.x;
		p_current.y = p_end.y;
	}
	else {
		p_current.x = v0 * cos(angle) * t + p_start.x;
		p_current.y = v0 * sin(angle) * t - MathAndConstants::get_g() * pow(t, 2) / 2 + p_start.y;
	}
}