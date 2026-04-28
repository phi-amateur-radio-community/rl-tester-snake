add_library(RtsUtilLib)
target_sources(RtsUtilLib PRIVATE
        UnorderList.cpp
        Logger.cpp)

target_include_directories(RtsUtilLib PUBLIC ${CMAKE_SOURCE_DIR}/include)