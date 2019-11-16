cmake_minimum_required(VERSION 3.15)
project(Project_opengl)

set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )

add_executable(Project_opengl
        main.cpp
        #test.cpp
        )
target_link_libraries(Project_opengl -lglfw  -lGLEW  -lGL)
target_link_libraries( Project_opengl ${OpenCV_LIBS} )
include_directories(/usr/include/glm/)