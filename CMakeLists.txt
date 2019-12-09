cmake_minimum_required(VERSION 2.8)
project(imu_subscriber)

set(CMAKE_CXX_FLAGS "-O2 -std=c++11 -Wall")
set(MOSQUITTO_DIR "/home/parallels/dev/MqttClass")

add_executable(imu_subscriber src/imu_subscriber.cpp)

target_include_directories(imu_subscriber   
	PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	PUBLIC $<BUILD_INTERFACE:${MOSQUITTO_DIR}/include>
)

target_link_libraries(imu_subscriber mosquitto)

INSTALL(
	TARGETS imu_subscriber
	EXPORT ${PROJECT_NAME}-export
	RUNTIME DESTINATION bin/${PROJECT_NAME}
)

INSTALL(
	EXPORT ${PROJECT_NAME}-export
	FILE ${PROJECT_NAME}-config.cmake
	DESTINATION share/cmake/${PROJECT_NAME}
)

