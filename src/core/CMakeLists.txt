add_library(RtsCoreLib)
target_sources(RtsCoreLib PRIVATE
        Session.cpp)

target_include_directories(RtsCoreLib PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(RtsCoreLib
        Qt::Widgets)