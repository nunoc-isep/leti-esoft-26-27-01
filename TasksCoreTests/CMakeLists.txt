project(TasksCoreTests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(TasksCoreTests domain/model/CategoryTests.cpp domain/model/CategoryContainerTests.cpp domain/model/PersonTests.cpp domain/shared/StringUtilsTests.cpp)

target_link_libraries(TasksCoreTests TasksCore)
target_link_libraries(TasksCoreTests gtest gtest_main)