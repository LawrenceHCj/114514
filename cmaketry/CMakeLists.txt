cmake_minimum_required (VERSION 3.10)

project(cmaketry)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory (src dirCPP)

include_directories (include)

add_executable(a.out ${dirCPP})
