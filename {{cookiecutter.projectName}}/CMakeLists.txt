cmake_minimum_required(VERSION 3.2)
project({{cookiecutter.projectName}} VERSION {{cookiecutter.projectVersion}} DESCRIPTION {{cookiecutter.projectDescription}})

set(CMAKE_CXX_STANDARD 20)

# add externals libs
include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/external)

ExternalProject_Add(PISTACHE
        GIT_REPOSITORY https://github.com/oktal/pistache.git
        BUILD_COMMAND cd ${CMAKE_CURRENT_BINARY_DIR}/PISTACHE-prefix/src/PISTACHE && meson setup build --buildtype=release --prefix=${EXTERNAL_INSTALL_LOCATION} && meson compile -C build
        INSTALL_COMMAND cd ${CMAKE_CURRENT_BINARY_DIR}/PISTACHE-prefix/src/PISTACHE && meson install -C build
)

ExternalProject_Add(NLOHMANN
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

ExternalProject_Add(REDISCPP
        GIT_REPOSITORY https://github.com/tdv/redis-cpp.git
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib/aarch64-linux-gnu)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)


include_directories(include)
file(GLOB_RECURSE SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
add_dependencies(${PROJECT_NAME} PISTACHE NLOHMANN REDISCPP)

target_link_libraries(${PROJECT_NAME} pistache redis-cpp pthread)
