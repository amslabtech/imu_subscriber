cmake_minimum_required(VERSION 2.8)
project(imu_subscriber)

set(CMAKE_CXX_FLAGS "-O2 -std=c++11 -Wall")
set(MOSQUITTO_DIR "/home/parallels/dev/MqttClass")

include_directories(
	${PROJECT_SOURCE_DIR}/include
	PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	PUBLIC $<BUILD_INTERFACE:${MOSQUITTO_DIR}/include>
)

add_executable(imu_subscriber src/imu_subscriber.cpp)
add_executable(force_subscriber src/force_subscriber.cpp)

target_include_directories(imu_subscriber   
	PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	PUBLIC $<BUILD_INTERFACE:${MOSQUITTO_DIR}/include>
)

target_include_directories(force_subscriber   
	PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	PUBLIC $<BUILD_INTERFACE:${MOSQUITTO_DIR}/include>
)

target_link_libraries(imu_subscriber mosquitto)
target_link_libraries(force_subscriber mosquitto)

INSTALL(
	TARGETS imu_subscriber force_subscriber
	RUNTIME DESTINATION /usr/local/bin
)

INSTALL(
	FILES include/imu_structure.hpp include/force_structure.hpp
	DESTINATION /usr/local/include
)

