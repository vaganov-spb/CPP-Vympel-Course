// HW_7.cpp : Defines the entry point for the console application.
//
#pragma once

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Singleton.h"
#include "Logger.h"
#include "Strike.h"
#include "MathAndConstants.h"

std::vector<tElement<Parabola>> strikeBM()
{
	int N = Singleton::Instance().get_N();     // количество БР в ударе
	double S = Singleton::Instance().get_S(); // максимальное удаление точки старта от [0;0]
	double R = Singleton::Instance().get_R(); // максимальная дальность полёта
	double H = Singleton::Instance().get_H(); // максимальная высота полёта
	double T = Singleton::Instance().get_T(); // максимальная задержка времени старта
	std::vector<tElement<Parabola>> strike;

	tPoint from, to;
	double h, t;
	for (int i = 0; i < N; ++i) {
		from.x = (S*rand()) / RAND_MAX;
		to.x = from.x + (R*rand()) / RAND_MAX;
		h = (H*rand()) / RAND_MAX;
		t = (T*rand()) / RAND_MAX;
		tElement<Parabola> oneStrike(from, to, h, t);
		//std::cout << oneStrike.isValid() << std::endl;
		if (oneStrike.isValid()) {
			strike.push_back(oneStrike);
		}
		else {
			//std::cout << "NOT OK" << std::endl;
		}
	}
	//std::cout << "strike size: " << strike.size() << '\n';
	return strike;
};

int maxBMs(const std::vector<tElement<Parabola>>& p_strike) {
	// TODO
	int max = 0;
	int n = 0;
	std::map<double, int> maxBM;
	for (auto const& val : p_strike) {
		++maxBM[val.launch()];
		--maxBM[val.boom()];
	}

	for (auto i : maxBM) {
		n += i.second;
		if (n > max) max = n;
	}

	std::cout << "MAX BM: " << max << std::endl;
	return max;
};

tPoint nStrikePosition(std::vector<tElement<Parabola>>& p_strike, int num, double t) {
	p_strike[num - 1].Move(t);
	return p_strike[num - 1].position();
};


int main(int argc, const char** argv)
{
	/*Singleton obj = Singleton::Instance(argc, argv);
	std::cout << obj.get_N() << std::endl;
	Singleton obj2 = Singleton::Instance();
	std::cout << obj2.get_N() << std::endl;
	UserLogger::self().log(Logger::WARN, "some message");
	SystemLogger::self().log(Logger::WARN, "some message2");

	tPoint from, to, to1;
	double h, t;
	from.x = 1;
	to.x = 3;
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
	strike.Move((-t + strike.boom()) / 1.5 + t);
	std::cout << strike.position().x << std::endl;
	std::cout << strike.position().y << std::endl;
	std::vector<tElement<Parabola>> BM = strikeBM();
	if (maxBMs(BM) <= MathAndConstants::get_someBmLimit()) {
	std::cout << "OK" << std::endl;
	}
	else {
	std::cout << "NOT OK" << std::endl;
	}
	std::cout << BM[49].launch() << std::endl;
	std::cout << BM[49].boom() << std::endl;
	std::cout << BM[49].mover.p_start.x << std::endl;
	std::cout << BM[49].mover.p_start.y << std::endl;
	std::cout << BM[49].mover.p_end.x << std::endl;
	std::cout << BM[49].mover.p_end.y << std::endl;
	std::cout << BM[49].mover.maxH << std::endl;
	tPoint p = nStrikePosition(BM, 50, 36.5664);
	std::cout << p.x << std::endl;
	std::cout << p.y << std::endl;
	return 0;*/
}


