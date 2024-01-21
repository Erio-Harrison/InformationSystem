cmake_minimum_required(VERSION 3.27)
project(InformationSystem)

set(CMAKE_CXX_STANDARD 17)
include_directories(./EasyX/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/HeadFile)
link_directories(./EasyX/lib64)
link_libraries(easyx)

set(SOURCE_FILES
        MainFile/Management.cpp
        MainFile/Window.cpp
        MainFile/Table.cpp
        MainFile/Member.cpp
        MainFile/BasicWidget.cpp
        MainFile/PushButton.cpp
        main.cpp
)

file(COPY ${CMAKE_SOURCE_DIR}/images/member.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images)
file(COPY ${CMAKE_SOURCE_DIR}/images/test.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images)

add_executable(InformationSystem ${SOURCE_FILES})
