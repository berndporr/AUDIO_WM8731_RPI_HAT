cmake_minimum_required(VERSION 3.10)

add_library(record hwparam.h hw_setup_record.cpp)
target_link_libraries(record asound)

