cmake_minimum_required (VERSION 3.10)

project(calibration)

find_package( OpenCV REQUIRED )

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory (src dirCPP)

add_executable(a.out ${dirCPP})

target_link_libraries( a.out ${OpenCV_LIBS} )

target_include_directories(a.out PUBLIC ${OpenCV_INCLUDE_DIRS})
