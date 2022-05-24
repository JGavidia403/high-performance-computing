cmake_minimum_required(VERSION 3.5)

project(ModeloLR LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### Variable de fuentes

set(project_sources
    main.cpp
    EXTRACTION/extractiondata.cpp
    regresionlineal.cpp


    )

### Variable de interfaces

set(project_headers
    EXTRACTION/extractiondata.h
    regresionlineal.h
    )

add_executable(${PROJECT_NAME}
               ${project_sources}
               ${project_headers})
