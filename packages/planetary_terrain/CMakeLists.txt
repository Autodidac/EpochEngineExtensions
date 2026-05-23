cmake_minimum_required(VERSION 3.28)

project(epoch_extension_planetary_terrain LANGUAGES CXX)

add_library(epoch_extension_planetary_terrain STATIC
    src/planetary_terrain.cpp
)

target_include_directories(epoch_extension_planetary_terrain
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(epoch_extension_planetary_terrain PUBLIC cxx_std_23)
set_target_properties(epoch_extension_planetary_terrain PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_executable(epoch_extension_planetary_terrain_self_test
    tests/planetary_terrain_self_test.cpp
)

target_link_libraries(epoch_extension_planetary_terrain_self_test
    PRIVATE epoch_extension_planetary_terrain
)

target_compile_features(epoch_extension_planetary_terrain_self_test PRIVATE cxx_std_23)
