cmake_minimum_required (VERSION 3.1)

project(pnp_solver)

find_package( OpenCV REQUIRED )

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory (src mycpp)

add_executable (pnp_solver ${mycpp})

target_link_libraries( pnp_solver ${OpenCV_LIBS} )

target_include_directories(pnp_solver PUBLIC ${OpenCV_INCLUDE_DIRS})
