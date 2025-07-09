cmake_minimum_required(VERSION 3.10)
project(MyDSAProject C)

set(CMAKE_C_STANDARD 11)

# Add your source
add_executable(MyDSAExecutable src/main.c)

# Force final binary into "bin/"
add_custom_command(TARGET MyDSAExecutable POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:MyDSAExecutable>
        ${CMAKE_SOURCE_DIR}/bin/$<TARGET_FILE_NAME:MyDSAExecutable>
)
