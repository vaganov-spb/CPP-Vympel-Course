#pragma once
#include "Singleton.h"

Singleton::Singleton(int argc, const char** argv) : N(50), S(100), R(500), H(400), T(100), log_type("TRACE") {
	if (argc == 7) {
		N = atoi(argv[1]);
		S = atoi(argv[2]);
		R = atoi(argv[3]);
		H = atoi(argv[4]);
		T = atoi(argv[5]);
		log_type = argv[6];
	}
};

Singleton& Singleton::Instance(int argc, const char** argv) {
	static Singleton sngl(argc, argv);
	return sngl;
}