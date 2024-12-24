Project(OS-ClassDesign)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(app ${SRC})