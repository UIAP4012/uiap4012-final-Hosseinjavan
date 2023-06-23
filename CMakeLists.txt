cmake_minimum_required(VERSION 3.16)
project(uiap4012_final_Hosseinjavan)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE PROJECT_SOURCES *.cpp)
file(GLOB_RECURSE PROJECT_HEADERS *.h)

include_directories(${PROJECT_HEADERS})

#add_executable(uiap4012_final_Hosseinjavan ${PROJECT_SOURCES} ${PROJECT_HEADERS})

add_executable(uiap4012_final_Hosseinjavan
        main.cpp
        IPropertyBase.h PropertyManagement.cpp PropertyManagement.h Property.cpp Property.h Menu.cpp Menu.h Person.cpp Person.h User.cpp User.h ReceiptHandler.cpp ReceiptHandler.h)
