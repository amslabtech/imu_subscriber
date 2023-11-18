cmake_minimum_required(VERSION 2.8)
project(imu_subscriber)

set(CMAKE_CXX_FLAGS "-O2 -std=c++11 -Wall")

find_package(PkgConfig)
pkg_check_modules(libmosquitto REQUIRED libmosquitto)

include_directories(${libmosquitto_INCLUDE_DIRS})
find_package(mqttclass REQUIRED)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

add_executable(imu_subscriber src/imu_subscriber.cpp)
add_executable(force_subscriber src/force_subscriber.cpp)

target_include_directories(imu_subscriber
	PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_include_directories(force_subscriber
	PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(imu_subscriber
	mqttclass
	${libmosquitto_LIBRARIES}
)
target_link_libraries(force_subscriber
	mqttclass
	${libmosquitto_LIBRARIES}
)

add_library(libimu_subscriber INTERFACE)
target_include_directories(lib${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

INSTALL(
	TARGETS imu_subscriber force_subscriber libimu_subscriber
	EXPORT ${PROJECT_NAME}-export
	RUNTIME DESTINATION bin
)

INSTALL(
	FILES include/imu_structure.hpp include/force_structure.hpp
	DESTINATION include
)


INSTALL(
	EXPORT ${PROJECT_NAME}-export
	FILE ${PROJECT_NAME}-config.cmake
	DESTINATION share/cmake/${PROJECT_NAME}
)
