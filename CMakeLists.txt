cmake_minimum_required(VERSION 3.29)
project(sistema_alunos_e_notas_3_0 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(sistema_alunos_e_notas_3_0
    main.c
    usuarios.h)
