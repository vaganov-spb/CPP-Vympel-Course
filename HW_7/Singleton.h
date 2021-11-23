#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

class Singleton
{
protected:
	int N, S, R, H, T;
	std::string log_type;

	Singleton(int argc, const char** argv);

public:
	static Singleton& Instance(int argc = 0, const char** argv = nullptr);


	int get_N() {
		return N;
	}

	int get_S() {
		return S;
	}

	int get_H() {
		return H;
	}

	int get_R() {
		return R;
	}

	int get_T() {
		return T;
	}

	std::string get_log_type() {
		return log_type;
	}
};

/*int main(int argc, const char** argv)
{
Singleton obj = Singleton::Instance();
std::cout << obj.get_N() << std::endl;

Singleton obj2 = Singleton::Instance(argc, argv);
std::cout << obj2.get_N() << std::endl;


//std::cout << MathMethods::get_g() << " " << MathMethods::deg_to_rad(30) << " " << MathMethods::rad_to_deg(1) << " " << MathMethods::get_random_from_range(1,3);
for (int count = 0; count < 120; ++count)
{
//std::cout << MathMethods::get_random_from_range(1, 3) << "\t";
}
SystemLogger::self().log(SystemLogger::WARN, "some message1");
UserLogger::self().log(UserLogger::ERROR, "some message2");
return 0;
}*/

