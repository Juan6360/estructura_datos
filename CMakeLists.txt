cmake_minimum_required(VERSION 3.27)
project(CLion_code)

set(CMAKE_CXX_STANDARD 17)

add_executable(CLion_code main.cpp
        maquinaDispensadora/maquinaDIspensadora.cpp
        colaImpresion/impresion.cpp
)
