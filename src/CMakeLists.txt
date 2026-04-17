set(RTS_SELF_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(core)
add_subdirectory(ui)

add_executable(rl_tester_snake main.cpp)

add_custom_command(TARGET rl_tester_snake POST_BUILD
        COMMAND windeployqt $<TARGET_FILE:rl_tester_snake>
)

target_link_libraries(rl_tester_snake
        Qt::Core
        Qt::Gui
        Qt::Widgets
        RtsCoreLib
        RtsUiLib
)