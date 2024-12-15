cmake_minimum_required (VERSION 3.15)

project (MB_Caso_Final_Integrador_Tema_4)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED True)

add_executable (MB_Caso_Final_Integrador_Tema_4
        Ejercicio/main.cpp
        Ejercicio/variant.cpp
        Ejercicio/variant.h
        Ejercicio/entorno.h)

add_subdirectory (Ejercicio/json11)

target_include_directories (MB_Caso_Final_Integrador_Tema_4
        PRIVATE Ejercicio/json11)
target_compile_features (MB_Caso_Final_Integrador_Tema_4
        PRIVATE cxx_std_17)

target_link_libraries (MB_Caso_Final_Integrador_Tema_4
        json11)