#include <sqlite3.h>
#include <stdio.h>

typedef void (*entrypoint)(void);

int sqlite3_compress_init(sqlite3* db, char** pzErrMsg, const sqlite3_api_routines* pApi);
int sqlite3_http_init(sqlite3* db, char** pzErrMsg, const sqlite3_api_routines* pApi);
int sqlite3_percentile_init(sqlite3* db, char** pzErrMsg, const sqlite3_api_routines* pApi);
int sqlite3_sha_init(sqlite3* db, char** pzErrMsg, const sqlite3_api_routines* pApi);
int sqlite3_uuid_init(sqlite3* db, char** pzErrMsg, const sqlite3_api_routines* pApi);
int sqlite3_vsv_init(sqlite3* db, char** pzErrMsg, const sqlite3_api_routines* pApi);

void beefysqlite_init() {
    sqlite3_initialize();
    sqlite3_auto_extension((entrypoint)sqlite3_compress_init);
    sqlite3_auto_extension((entrypoint)sqlite3_http_init);
    sqlite3_auto_extension((entrypoint)sqlite3_percentile_init);
    sqlite3_auto_extension((entrypoint)sqlite3_sha_init);
    sqlite3_auto_extension((entrypoint)sqlite3_uuid_init);
    sqlite3_auto_extension((entrypoint)sqlite3_vsv_init);
}
