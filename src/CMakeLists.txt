add_library(
    structure
    ${SOURCES}
    ${HEADERS}
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads REQUIRED)

add_executable(
    APP
    ${PROJECT_SOURCE_DIR}/main.cpp
)

target_link_libraries(
    APP
    structure
    ${CMAKE_THREAD_LIBS_INIT}
)