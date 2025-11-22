cmake_minimum_required(VERSION 3.10)
project(F0X)

# -----------------------------
# C++ Standard
# -----------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------
# Directories
# -----------------------------
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(OBJ_DIR ${CMAKE_SOURCE_DIR}/bin)

include_directories(${INCLUDE_DIR})

# -----------------------------
# Source files
# -----------------------------
file(GLOB_RECURSE SOURCES
    ${SRC_DIR}/*.cpp
)
set(GLAD_SRC ${SRC_DIR}/glad.c)

# -----------------------------
# Add executable
# -----------------------------
add_executable(${PROJECT_NAME} ${SOURCES} ${GLAD_SRC})

# -----------------------------
# Windows linking
# -----------------------------
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-static-libgcc -static-libstdc++")

    # Link libraries
    target_link_libraries(${PROJECT_NAME}
        ${LIB_DIR}/libassimp.a    # static Assimp
        ${LIB_DIR}/libglfw3.a     # GLFW
        ${LIB_DIR}/libzlibstatic.a          # zlib for Assimp
        opengl32
        gdi32
        user32
        shell32
    )

elseif(UNIX)
    # Linux / macOS
    find_package(PkgConfig REQUIRED)
    pkg_search_module(GLFW REQUIRED glfw3)
    include_directories(${GLFW_INCLUDE_DIRS})

    find_package(assimp REQUIRED)
    find_package(ZLIB REQUIRED)

    target_link_libraries(${PROJECT_NAME}
        ${GLFW_LIBRARIES}
        ${ASSIMP_LIBRARIES}
        GL
        ZLIB::ZLIB
        pthread
        X11
        dl
        m
    )
endif()

# -----------------------------
# Output directories
# -----------------------------
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${OBJ_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OBJ_DIR}
)
