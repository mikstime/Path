//
// Created by Михаил on 2019-03-20.
//

#ifndef PATH_PATH_H
#define PATH_PATH_H

#include <string>
using std::string;

class Path {
    string rawPath, dir, name, ext;

    bool __separateDir(string&);
    bool __separateName(string&);
    bool __separateExt(string&);
public:
    // Set full path to file
    void setPath(string);
    // Set directory i.e. ../lib or ../lib/
    void setDirName(string);
    // Set file name i.e. test.txt or test
    void setFileName(string);
    // set file ext i.e. .txt or txt
    void setFileExt(string);

    // Works only if setPath(string); was used for path settings
    // Otherwise returns an empty string
    string getRawPath();
    // Return full path to file i.e. ../lib/test.txt or ../lib/
    string getPath();
    // Return directory name i.e. ../lib (not ../lib/)
    string getDirName();
    // Return file name i.e. test (not test.txt)
    string getFileName();
    // Return file ext i.e. txt (not .txt)
    string getFileExt();
    // reset stored values to ""
    void resetPath();
};


#endif //PATH_PATH_H
