cmake_minimum_required(VERSION 3.14)

project(RtlTest LANGUAGES CXX)

# ... (other parts of your CMakeLists.txt)

# Manually specify the include directory for RTL-SDR
include_directories(/usr/include)

# Manually specify the RTL-SDR library
link_directories(/usr/lib/x86_64-linux-gnu)

add_executable(RtlTest main.cpp)

# Link the RTL-SDR library
target_link_libraries(RtlTest Qt${QT_VERSION_MAJOR}::Core rtlsdr)

# ... (rest of your CMakeLists.txt)
find_package(Qt6Core REQUIRED)
target_link_libraries(RtlTest Qt6::Core)
