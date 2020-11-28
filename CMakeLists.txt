cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)
project(dij VERSION 0.1.0)

# include(CTest)
# enable_testing()

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

## allowed commands ##
# add_executable()
# add_library()
# get_target_property()
# set_target_properties()
# target_compile_definitions()
# target_compile_options()
# target_compile_features()
# target_link_options()
# target_link_libraries()
# target_include_directories()
# target_sources()

# static library version
add_library(${PROJECT_NAME}_static STATIC)
target_sources(${PROJECT_NAME}_static
    PRIVATE
        ./src/dij.cpp
)
target_include_directories(${PROJECT_NAME}_static
    PUBLIC
        ./include
)
set_target_properties(${PROJECT_NAME}_static
    PROPERTIES POSITION_INDEPENDENT_CODE 1
)

# shared library version
add_library(${PROJECT_NAME}_shared SHARED)
target_sources(${PROJECT_NAME}_shared
    PRIVATE
        ./src/dij.cpp
)
target_include_directories(${PROJECT_NAME}_shared
    PUBLIC
        ./include
)
set_target_properties(${PROJECT_NAME}_shared
    PROPERTIES POSITION_INDEPENDENT_CODE 1
)

# example app using static library
add_executable(${PROJECT_NAME}_app_static)
target_sources(${PROJECT_NAME}_app_static
    PRIVATE
        example/src/app.cpp
        example/src/duck.cpp
        example/src/skoda.cpp
        example/src/person.cpp
)
target_include_directories(${PROJECT_NAME}_app_static
    PRIVATE
        example/include
)
target_link_libraries(${PROJECT_NAME}_app_static
    PRIVATE
        ${PROJECT_NAME}_static
)

# example app using shared library
add_executable(${PROJECT_NAME}_app_shared)
target_sources(${PROJECT_NAME}_app_shared
    PRIVATE
        example/src/app.cpp
        example/src/duck.cpp
        example/src/skoda.cpp
        example/src/person.cpp
)
target_include_directories(${PROJECT_NAME}_app_shared
    PRIVATE
        example/include
)
target_link_libraries(${PROJECT_NAME}_app_shared
    PRIVATE
        ${PROJECT_NAME}_shared
)