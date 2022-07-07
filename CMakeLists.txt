cmake_minimum_required(VERSION 3.14)

project(
  saudacao 
  VERSION 0.1.0
  DESCRIPTION "Exemplo de uma biblioteca C++ com CMake"
  LANGUAGES CXX)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # provendo suporte a pasta pelas IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(CTest)
  enable_testing()
endif()

# Adicionando dependências por meio do CPM.cmake 
# https://github.com/cpm-cmake/CPM.cmake
include(cmake/CPM.cmake)

include(FetchContent)

# Código da biblioteca 'saudacao'
add_subdirectory(src)

# Código com aplicação exemplo
add_subdirectory(exemplo)
