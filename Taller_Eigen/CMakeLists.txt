cmake_minimum_required(VERSION 3.5)

project(Taller_Eigen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### Variable de fuentes

set(project_sources
    main.cpp
    Logica/logica.cpp
    )

### Variable de interfaces

set(project_headers
    Logica/logica.h
    )

add_executable(${PROJECT_NAME}
               ${project_sources}
               ${project_headers})
