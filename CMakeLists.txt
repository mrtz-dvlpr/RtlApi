cmake_minimum_required(VERSION 3.14)

project(RtlTest LANGUAGES CXX)

# ... (other parts of your CMakeLists.txt)

# Manually specify the include directory for RTL-SDR
include_directories(/usr/include           ${LIBDVBV5_INCLUDE_DIRS} /usr/include/libdvbv5)
link_directories(/usr/lib/x86_64-linux-gnu ${LIBDVBV5_LIBRARY_DIRS} PRIVATE /usr/include/libdvbv5)
include_directories(/usr/include/libdvbv5)

# Manually specify the RTL-SDR library

add_executable(RtlTest main.cpp)

# Link the RTL-SDR library
target_link_libraries(RtlTest Qt${QT_VERSION_MAJOR}::Core rtlsdr ${LIBDVBV5_LIBRARIES} )

# ... (rest of your CMakeLists.txt)
find_package(Qt6Core REQUIRED)
target_link_libraries(RtlTest Qt6::Core)



# include_directories(${LIBDVBV5_INCLUDE_DIRS})
# link_directories(   ${LIBDVBV5_LIBRARY_DIRS})


find_package(Qt6Core REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBDVBV5 REQUIRED libdvbv5)


