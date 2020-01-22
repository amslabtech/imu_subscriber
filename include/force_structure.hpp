//
//	force_structure.hpp
//
#ifndef _FORCE_STRUCTURE_HPP_
#define _FORCE_STRUCTURE_HPP_

#include <iostream>
#include <iomanip>
#include <time.h>
#include <sys/time.h>

struct ForceStructure {
	int32_t id;
	int32_t sec;
	int32_t usec;
	float  force[6];	// orientation (roll, pitch, yaw)

	void print() {
		std::cout
		<< std::setw( 6) << id
//		<< std::setw(12) << ts.tv_sec
//		<< std::setw(10) << ts.tv_usec
		<< std::setw(12) << force [0]
		<< std::setw(12) << force [1]
		<< std::setw(12) << force [2]
		<< std::setw(12) << force [3]
		<< std::setw(12) << force [4]
		<< std::setw(12) << force [5]
		<< std::endl;
	}

	void diff_time(struct timeval ts) {
		double t1 =  sec+ usec/1000000.0;
		double t2 = ts.tv_sec+ts.tv_usec/1000000.0;
		std::cout << std::setprecision(10) << t2 - t1;
	}
};

namespace force {
	const char* topic    = "force";
	const char* password = "mqtt";
};




#endif	// _FORCE_STRUCTURE_HPP_
