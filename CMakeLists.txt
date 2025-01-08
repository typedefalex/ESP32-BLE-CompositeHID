file(GLOB_RECURSE srcs "main.cpp" "*.cpp")

idf_component_register(
    SRCS
        "${srcs}"
    INCLUDE_DIRS "."
    REQUIRES esp-nimble-cpp
)
