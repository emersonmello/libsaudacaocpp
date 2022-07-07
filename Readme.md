# Exemplo de uma biblioteca C++ com CMake 
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![ubuntu, macOS, windows build](https://github.com/emersonmello/libsaudacaocpp/actions/workflows/cmake.yaml/badge.svg)](https://github.com/emersonmello/libsaudacaocpp/actions/workflows/cmake.yaml)


Neste repositório tem-se um pequeno exemplo sobre como organizar o projeto de uma biblioteca C++ usando o CMake.

## Ferramentas necessárias para compilação

- [Git](https://git-scm.com/downloads)
- [CMake](https://cmake.org) 3.14 ou superior
- Compilador C++11 (i.e. g++)

## Como gerar o sistema de construção (i.e. *Makefile*)

Baixe o código presente neste repositório:
```bash
git clone https://github.com/emersonmello/libsaudacaocpp.git
cd libsaudacaocpp

cmake -S . -B build
``` 

## Como compilar a biblioteca e a aplicação exemplo

Para construir o projeto:
```bash
cmake --build build
```
Serão gerados os seguintes arquivos:

- **Biblioteca estática** (*archive*)
    - `build/src/libsaudacao.a`
- **Aplicação demo**
    - `build/exemplo/demo`

## Para instalar a biblioteca compilada e headers

Caso queira instalar a biblioteca compilada e os arquivos de cabeçalho, faça:

```bash
cmake --install build --strip --config Release
```

## Para fazer uso desta biblioteca em outros projetos 

Se está escrevendo um projeto com [CMake](https://cmake.org/cmake/help/latest/index.html), é possível baixar e usar esta biblioteca por meio do [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html). Inclua as linhas abaixo dentro do arquivo `CMakeLists.txt` de seu projeto:

```cmake
include(FetchContent)

FetchContent_Declare(saudacaocpp
    GIT_REPOSITORY https://github.com/emersonmello/libsaudacaocpp.git
    GIT_TAG 0.1.0
)

FetchContent_MakeAvailable(saudacaocpp)

# considerando que appexemplo é o nome do alvo (target)
target_link_libraries(appexemplo PRIVATE saudacaocpp)
```

Abaixo um exemplo completo do arquivo `CMakeLists.txt` para uma aplicação que faz uso desta biblioteca.

```cmake
cmake_minimum_required(VERSION 3.14)
project(appexemplo VERSION 0.1.0)

add_executable(appexemplo main.cpp)
target_compile_features(appexemplo PRIVATE cxx_std_17)

include(FetchContent)
FetchContent_Declare(saudacaocpp
    GIT_REPOSITORY https://github.com/emersonmello/libsaudacaocpp.git
    GIT_TAG 0.1.0
)
FetchContent_MakeAvailable(saudacaocpp)

target_link_libraries(appexemplo PRIVATE saudacaocpp)
```

E abaixo o código do arquivo `main.cpp`:

```cpp
#include <saudacao/saudacao.hh>
#include <iostream>

int main(int argc, char const **argv) {

    std::string msg = "mundo";
    if (argc == 2){
        msg = argv[1];
    }

    saudacao::Saudacao teste(msg);

    teste.ola_mundo();
}
```