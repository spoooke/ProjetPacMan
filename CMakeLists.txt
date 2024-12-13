cmake_minimum_required(VERSION 3.10)
project(pacman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML path (adjust these paths according to your Homebrew installation)
set(SFML_DIR "/usr/local/Cellar/sfml/2.6.2/lib/cmake/SFML")
set(SFML_INCLUDE_DIR "/usr/local/Cellar/sfml/2.6.2/include")
set(SFML_LIBRARY_DIR "/usr/local/Cellar/sfml/2.6.2/lib")

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add source files
set(SOURCES
    main.cpp
    pacman.cpp
    ghost.cpp
    grilleConfig.cpp
    gameRenderer.cpp
)

# Include directories
include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

# Create executable
add_executable(pacman ${SOURCES})

# Link SFML libraries
target_link_libraries(pacman sfml-graphics sfml-window sfml-system)
