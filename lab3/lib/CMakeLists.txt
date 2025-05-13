# Собираем библиотеку из исходников
add_library(sandpile_lib
    Sandpile.cpp
        writeToBmp.cpp
)

target_include_directories(sandpile_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
