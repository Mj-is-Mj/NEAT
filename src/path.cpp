/*
    Mj
*/

#include "path.h"

#include <cstdio>
#include <cstring>
#include <sys/stat.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <direct.h>
    #define mkdir(path, mode) _mkdir(path)
#endif

// Returns true if the path matches a file or directory
bool directoryExists(char* const path) {
    struct stat info;

    if (stat(path, &info) != 0)
        return false;

    return true;
}

// Returns the suffix appended to the path, or 0 if the directory is available
int getNextAvailPath(char* const path, char const* const fmt) {    
    static const char DEFAULT_FMT[] = "-%d";
    
    if (!directoryExists(path))
        return 0;
    
    const int len = strlen(path);
    char* const ssuffix = path + len;
    int isuffix = 0;

    do {
        ++isuffix;
        sprintf(ssuffix, (fmt != nullptr ? fmt : DEFAULT_FMT), isuffix);
    } while(directoryExists(path));

    return isuffix;
}

void makeDir(const char* const path) {
    mkdir(path, 0755);
};

// Makes a directory at the next available path
void makeNextAvailDir(char* const path) {
    getNextAvailPath(path);
    makeDir(path);
}