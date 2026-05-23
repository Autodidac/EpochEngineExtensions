cmake_minimum_required(VERSION 3.28)

project(epoch_extension_fft_ocean LANGUAGES CXX)

add_library(epoch_extension_fft_ocean STATIC
    src/fft_ocean.cpp
)

target_include_directories(epoch_extension_fft_ocean
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(epoch_extension_fft_ocean PUBLIC cxx_std_23)
set_target_properties(epoch_extension_fft_ocean PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_executable(epoch_extension_fft_ocean_self_test
    tests/fft_ocean_self_test.cpp
)

target_link_libraries(epoch_extension_fft_ocean_self_test
    PRIVATE epoch_extension_fft_ocean
)

target_compile_features(epoch_extension_fft_ocean_self_test PRIVATE cxx_std_23)
