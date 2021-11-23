#pragma once
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include "MathAndConstants.h"

/* Для сравнения чисел и лимит на длину полета(не хотелось бы взорваться вместе с целью:) )
const double eps = 0.01;
const double minDistance = 0.3;
const double maxDistance = 1000.0;
const double g = 9.82;
const int someBmLimit = 10;*/

struct tPoint {
	double x, y;
	tPoint(double p_x = 0, double p_y = 0) : x(p_x), y(p_y) {}
};

template <typename tMover> class tElement {
public:
	double t0;
	tMover mover;

public:
	tElement(const tPoint& p_from, const tPoint& p_to, double p_maxH, double p_t0 = 0)
		: t0(p_t0)
		, mover(p_from, p_to, p_maxH)
	{
		if (isValid()) {
			mover.calculateParams();
		}
	};

	bool isValid() {
		// TODO
		if (mover.maxH < MathAndConstants::get_eps()) {
			std::cout << "Max Height should be more than zero" << std::endl;
			return false;
		}

		if (abs(mover.p_start.x - mover.p_end.x) < MathAndConstants::get_minDistance()) {
			std::cout << "The distance between start and end points is too small" << std::endl;
			return false;
		}

		if (abs(mover.p_start.x - mover.p_end.x) > MathAndConstants::get_maxDistance()) {
			std::cout << "The distance between start and end points is too large" << std::endl;
			return false;
		}

		return true;
	};

	virtual void Move(double t) {
		if (t < t0) return;
		mover.Move(t - t0);
	}

	inline double launch() const {
		return t0;
	}

	inline double boom() const {
		return t0 + mover.flightT();
	}

	inline const tPoint& position() {
		return mover.position();
	}
};

/*
L = 2 *  v0^2 * sina * cosa / g
H =  v0^2 * (sina)^2 / 2g

tga = 4H/L
*/

class Parabola {
public:
	tPoint p_start;
	tPoint p_end;
	tPoint p_current;
	double maxH;
	double v0;
	double angle;
	Parabola(const tPoint& p_from, const tPoint& p_to, double p_maxH);

	void calculateParams();

	double flightT() const;

	const tPoint& position() const;

	void Move(double t);
};


/*int main()
{
tPoint from, to, to1;
double h, t;
from.x = 1;
to.x = 1;
h = 10;
t = 0;
tElement<Parabola> strike(from, to, h, t);
if (strike.isValid()) {
std::cout << "OK" << std::endl;
}

std::cout << strike.boom() << std::endl;
std::cout << strike.launch() << std::endl;
std::cout << strike.position().x << std::endl;
std::cout << strike.position().y << std::endl;
strike.Move(strike.boom() / 11);
std::cout << strike.position().x << std::endl;
std::cout << strike.position().y << std::endl;
std::vector<tElement<Parabola>> BM = strikeBM();
if (maxBMs(BM) <= someBmLimit) {
std::cout << "OK" << std::endl;
}
else {
std::cout << "NOT OK" << std::endl;
}
std::cout << BM[49].launch()<< std::endl;
std::cout << BM[49].boom() << std::endl;
std::cout << BM[49].mover.p_start.x << std::endl;
std::cout << BM[49].mover.p_start.y << std::endl;
std::cout << BM[49].mover.p_end.x << std::endl;
std::cout << BM[49].mover.p_end.y << std::endl;
std::cout << BM[49].mover.maxH << std::endl;
tPoint p = nStrikePosition(BM, 50, 36.5664);
std::cout << p.x << std::endl;
std::cout << p.y << std::endl;
return 0;
}*/


