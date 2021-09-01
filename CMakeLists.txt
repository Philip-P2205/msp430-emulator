cmake_minimum_required(VERSION 3.0.0)
project(MSP430-Emulator VERSION 0.1.0)

include(CTest)
enable_testing()


add_library(Hardware hardware/msp.cpp)
#add_library(Interpreter interpreter/interpreter.cpp)


add_executable(MSP430-Emulator main.cpp)
target_link_libraries(MSP430-Emulator Hardware)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
