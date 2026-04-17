set(RTS_SELF_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(rl_tester_snake main.cpp)
target_link_libraries(rl_tester_snake
        Qt::Core
        Qt::Gui
        Qt::Widgets
        RtsUiLib
)

add_subdirectory(ui)