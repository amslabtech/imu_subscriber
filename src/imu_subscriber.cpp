//
//	IMUSubscriber example
//	... with using Mosquitto class
//
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <mosquitto.hpp>	// c++ wrapper of mosquitto
#include "imu_structure.hpp"	// imu data structure

using namespace imu;

class MyMosq : public Mosquitto {
  protected:
	ImuStructure data;
	const char* topic;
	void onConnected();
	void onError(const char* _msg) { std::cout << _msg; }
	void onMessage(std::string _topic, void* _data, int _len);
	struct timeval ts;

  public:
	MyMosq(const char* _topic):topic(_topic){}
};

void MyMosq::onConnected()
{
	std::cout << "Connected.\n";
	subscribe(topic);
}

#include <strings.h>
void MyMosq::onMessage(std::string _topic, void* _data, int _len)
{
	gettimeofday(&ts,NULL);
	bcopy(_data, (char*)&data, sizeof(data));		
	data.diff_time(ts);
	std::cout << ",   ";
	data.print3();
}

int main(int argc, char* argv[])
{
	char* ip_addr = (char*)"192.168.0.172";
	// const char* ip_addr  = "192.168.1.25";
	const char* username = "imu_subscriber";

	if(argc>1) {
		ip_addr = argv[1];
	} else {
		std::cout << "usage: " << argv[0] << " ip_addr\n";
	}
	std::cout << "using host: " << ip_addr << std::endl;;

	MyMosq imu_subscriber(topic);

	imu_subscriber.set_username_password(username,password);
	imu_subscriber.connect(ip_addr);
	imu_subscriber.loop_start();

	for(int i=0; i<1000000; i++) {
		std::cout << "mainloop[" << i << "]\n";
		sleep(2);
	}

	imu_subscriber.cleanup_library();
}


