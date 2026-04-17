add_library(RtsUiLib)
target_sources(RtsUiLib PRIVATE
        GridWidget.cpp)

target_include_directories(RtsUiLib PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(RtsUiLib
        Qt::Widgets)