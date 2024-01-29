file(GLOB EXAMPLES_HEADERS "*.h")

function(add_example SOURCE)
    get_filename_component(NAME ${SOURCE} NAME_WE)
    set(NAME "${NAME}_example")
    add_executable(${NAME} ${EXAMPLES_HEADERS} ${SOURCE})

    target_include_directories(${NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/lib/include
    )

    target_link_libraries(${NAME}
    PUBLIC
        dft
    PRIVATE
        CommonConfiguration
    )
endfunction()

file(GLOB SOURCES "*.c")

foreach(SOURCE ${SOURCES})
    add_example(${SOURCE})
endforeach()
