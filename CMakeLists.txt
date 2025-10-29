cmake_minimum_required(VERSION 3.10)
project(F0X-win)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Pure standard C++

# -----------------------------
# Directories
# -----------------------------
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(OBJ_DIR ${CMAKE_SOURCE_DIR}/bin)

include_directories(${INCLUDE_DIR})
# Add Assimp include path

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
# Linker flags
# -----------------------------
if(WIN32)
    # Windows + MinGW
    # Use static linking to avoid missing DLLs
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "-static-libgcc -static-libstdc++"
    )

    target_link_libraries(${PROJECT_NAME}
        ${LIB_DIR}/libglfw3.a  # Precompiled GLFW for MinGW
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

    # Find Assimp
    find_package(assimp REQUIRED)
    include_directories(${ASSIMP_INCLUDE_DIRS})

    # Link libraries
    target_link_libraries(${PROJECT_NAME}
        ${GLFW_LIBRARIES}   # GLFW
        ${ASSIMP_LIBRARIES} # Assimp
        GL                  # OpenGL
        pthread             # Threads
        X11                 # X11 (for GLFW)
        dl                  # Dynamic loader
        m                   # Math
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
