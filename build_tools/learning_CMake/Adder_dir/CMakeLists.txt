#Names a new library and tells it what to compile from
add_library(Adder_dir "adder.cpp" "adder.h")

find_library(
    #My given name followed by the library name
    yaml_cpp_path yaml-cpp
    NAMES libyaml-cppd libyaml
    PATHS "C:/Users/Student/Documents/C++home/C++External_directories/yaml-cpp/build/"
)