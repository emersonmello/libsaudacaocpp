add_executable(demo demo.cc)
target_compile_features(demo PRIVATE cxx_std_11)

# Para adicionar uma dependência usando o FetchContent
# FetchContent_Declare(
#   fmtlib
#   GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#   GIT_TAG 8.0.1)
# FetchContent_MakeAvailable(fmtlib)
# target_link_libraries(demo PRIVATE saudacao fmt::fmt)

target_link_libraries(demo PRIVATE saudacao)