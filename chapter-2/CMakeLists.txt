add_executable(chapter_2 src/main.c)
target_include_directories(chapter_2 PUBLIC inc)
target_compile_options(chapter_2 PRIVATE -Werror -Wall -Wextra -pedantic-errors -g -std=c17)