#pragma once

#include "Logger.h"

void Logger::log(Level p_level, const std::string& p_message) {
	std::string temp = "";
	switch (p_level)
	{
	case 0: temp = "TRACE";
		break;
	case 1: temp = "DEBUG";
		break;
	case 2: temp = "INFO";
		break;
	case 3: temp = "WARN";
		break;
	case 4: temp = "ERROR";
		break;
	default:
		break;
	}

	if (p_level < c_level) return;
	const std::string message = temp + ": " + p_message;
	this->print(message);
};

Logger::Logger() {
	Level level;
	if (Singleton::Instance().get_log_type() == "TRACE") {
		level = Level::TRACE;
	}

	if (Singleton::Instance().get_log_type() == "DEBUG") {
		level = Level::DEBUG;
	}

	if (Singleton::Instance().get_log_type() == "INFO") {
		level = Level::INFO;
	}

	if (Singleton::Instance().get_log_type() == "WARN") {
		level = Level::WARN;
	}

	if (Singleton::Instance().get_log_type() == "ERROR") {
		level = Level::ERROR;
	}

	c_level = level;
};

Logger& SystemLogger::self() {
	return Logger::self<SystemLogger>();
}


void SystemLogger::print(const std::string& p_message) {
	std::cerr << p_message << std::endl;
}

Logger& UserLogger::self() {
	return Logger::self<UserLogger>();
}


void UserLogger::print(const std::string& p_message) {
	std::cout << p_message << std::endl;
}