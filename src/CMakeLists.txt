file (GLOB_RECURSE HEADER_LIST "${saudacao_SOURCE_DIR}/include/saudacao/*.hh")
file (GLOB_RECURSE SRC_LIST "*.cc")

# Para criar a biblioteca. Será estática ou dinâmica com base nas configurações do usuário
add_library(saudacao ${SRC_LIST} ${HEADER_LIST})

# Precisamos deste diretório e os usuários desta biblioteca também precisarão
target_include_directories(saudacao PUBLIC ../include)

# Para adicionar uma dependência usando o FetchContent
# FetchContent_Declare(
#   fmtlib
#   GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#   GIT_TAG 8.0.1)
# FetchContent_MakeAvailable(fmtlib)
# target_link_libraries(saudacao PRIVATE fmt::fmt)

target_compile_features(saudacao PUBLIC cxx_std_11)

# IDEs irão colocar os headers em uma pasta adequada
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

# Para instalar a biblioteca
install(TARGETS saudacao DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include)