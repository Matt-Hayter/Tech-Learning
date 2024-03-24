cmake_minimum_required(VERSION 3.21.3)

#Names the project which can be accessed with a ${PROJECT_NAME} variable throughout file
project(project_1)

add_subdirectory(Adder_dir)

add_executable(${PROJECT_NAME} main.cpp)

#Need to both include and link directories
target_include_directories( 
    ${PROJECT_NAME} PUBLIC Adder_dir
)
#Don't actually need this here...
target_link_directories(
    ${PROJECT_NAME} PUBLIC Adder_dir
)
#Need to both add and link  libraries
#Linking library added in lower level cmake file (adder) with the library created in this top level cmake file
target_link_libraries(${PROJECT_NAME} 
    PRIVATE Adder_dir PRIVATE ${yaml_cpp_path}

)
