#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include "Singleton.h"

class Logger {
public:
	enum Level {
		TRACE,
		DEBUG,
		INFO,
		WARN,
		ERROR,
	};

public:
	template <typename T>
	static T& self() {
		static T instance;
		return instance;
	};

	void log(Level p_level, const std::string& p_message);

	virtual void print(const std::string& p_message) = 0;

protected:
	Logger();
private:
	Level c_level;
};

class SystemLogger : public Logger {
public:
	static Logger& self();
protected:
	void print(const std::string& p_message) override;

};

class UserLogger : public Logger {
public:
	static Logger& self();
protected:
	void print(const std::string& p_message) override;
};