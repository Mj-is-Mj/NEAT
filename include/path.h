/*
    Mj
*/

#ifndef _PATH_H_
#define _PATH_H_

#define PATH_SIZE 256

// Returns true if the path matches a file or directory
bool directoryExists(char* const path);

// Returns the suffix appended to the path, or 0 if the directory is available
int getNextAvailPath(char* const path, char const* const fmt = nullptr);

// mkdir
void makeDir(const char* const path);

// Makes a directory at the next available path
void makeNextAvailDir(char* const path);

#endif