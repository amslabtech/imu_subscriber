//
//	ForceSubscriber example
//	... with using Mosquitto class
//
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <mosquitto.hpp>	// c++ wrapper of mosquitto
#include "force_structure.hpp"	// imu data structure

using namespace force;

class MyMosq : public Mosquitto {
  protected:
	ForceStructure data;
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
	data.print();
}

int main(int argc, char* argv[])
{
	char* ip_addr = (char*)"192.168.0.172";
	// const char* ip_addr  = "192.168.1.25";
	const char* username = "force_subscriber";

	if(argc>1) {
		ip_addr = argv[1];
	} else {
		std::cout << "usage: " << argv[0] << " ip_addr\n";
	}
	std::cout << "using host: " << ip_addr << std::endl;;

	MyMosq force_subscriber(topic);

	force_subscriber.set_username_password(username,password);
	force_subscriber.connect(ip_addr);
	force_subscriber.loop_start();

	for(int i=0; i<1000000; i++) {
		std::cout << "mainloop[" << i << "]\n";
		sleep(2);
	}

	force_subscriber.cleanup_library();
}


