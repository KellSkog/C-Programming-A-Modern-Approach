set(COMPILER_FLAGS -Werror -Wall -W -Wextra -pedantic-errors -g -std=c17)
#add_library(book STATIC src/book.c)

add_executable(chapter_2 src/main.c src/book.c)
target_include_directories(chapter_2 PUBLIC inc)
target_compile_options(chapter_2 PRIVATE ${COMPILER_FLAGS})

# add_executable(test src/test_book.c src/book.c)
# target_include_directories(test PUBLIC inc)
# target_compile_options(test PRIVATE ${COMPILER_FLAGS})

add_executable(unitTest test/unit_book.c src/book.c)
target_include_directories(unitTest PUBLIC inc ../Unity/src)
target_compile_options(unitTest PRIVATE ${COMPILER_FLAGS})
target_link_libraries(unitTest -L../Unity/)
target_link_libraries(unitTest libunity.a)