cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

project(beefysqlite VERSION 0.1.0 LANGUAGES C)

add_executable(beefysqlite
    "src/beefysqlite_init.c"
    "thirdparty/sqlite-amalgamation/shell.c"
    "thirdparty/sqlite-amalgamation/sqlite3.c"
    "thirdparty/sqlite/ext/misc/compress.c"
    "thirdparty/sqlite/ext/misc/percentile.c"
    "thirdparty/sqlite/ext/misc/sha1.c"
    "thirdparty/sqlite/ext/misc/uuid.c"
    "thirdparty/vsv.c"
    "thirdparty/http.c"
)

add_subdirectory(thirdparty/zlib)

target_include_directories(beefysqlite PRIVATE
    thirdparty/sqlite-amalgamation
    thirdparty/zlib
    ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/zlib
)

target_compile_definitions(beefysqlite PRIVATE
    SQLITE_CORE
    SQLITE_SHELL_INIT_PROC=beefysqlite_init
    SQLITE_HAVE_ZLIB
    SQLITE_ENABLE_FTS5
    SQLITE_ENABLE_MATH_FUNCTIONS
)

target_link_libraries(beefysqlite PRIVATE zlibstatic)

if(WIN32)
    target_compile_definitions(beefysqlite PRIVATE HTTP_BACKEND_WINHTTP)
    target_link_libraries(beefysqlite PRIVATE winhttp)
else()
    target_compile_definitions(beefysqlite PRIVATE HTTP_BACKEND_CURL)
endif()
