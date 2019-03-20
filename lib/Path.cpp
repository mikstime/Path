//
// Created by Михаил on 2019-03-20.
//

#include "../include/Path.h"
#include <string>
#include <iostream>
#include <algorithm>
using std::string;

void Path::setPath(string fullPath) {
    // Copy previous values to restore on failure
    string dirCopy = dir, nameCopy = name, extCopy = ext;
    // Copy fullPath to change rawPath on success
    string pathCopy = fullPath;
    // fullPath is changing during these manipulations!!!
    if(__separateDir(fullPath) && __separateName(fullPath) && __separateExt(fullPath)) {
        rawPath = pathCopy;
    } else {
        dir = dirCopy;
        name = nameCopy;
        ext = extCopy;
        std::cerr << "Incorect path provided. Path was not changed!\n";
    }
}
bool Path::__separateDir(string& pathWithDir) {
    // Since name and extension can't contain '/'
    // dir should end  with '/' or be empty
    size_t dirSize = pathWithDir.find_last_of('/');
    // Dir should end with / or be empty
    if(dirSize == string::npos) {
        //Just let dir be empty
        dir = "";
    } else {
        //Otherwise  dir is all before the last '/'
        dir = pathWithDir.substr(0, dirSize);
        // Remove dir from path for easier separation later
        // dirSize can't be larger than pathWithDir
        if(dirSize < pathWithDir.size()) {
            pathWithDir.erase(0, dirSize + 1);
        }  else {
            pathWithDir.erase(0, dirSize);
        }
    }

    return true;
}
bool Path::__separateName(string &pathWithoutDir) {
    // Let's assume that all fileName has a length greater than zero and
    // fileNames and extensions has no '/' symbols
    // Since extension can contain an only dot we should find the last one
    size_t nameSize  = pathWithoutDir.find_last_of('.');

    if(nameSize != string::npos &&
       nameSize > 0) {
        name = pathWithoutDir.substr(0, nameSize);
        // Since period was found, erasing won't cause error
        pathWithoutDir.erase(0, nameSize + 1);
    } else {
        // Sometimes files can have no extension
        // So no period appears
        if(!pathWithoutDir.empty()) {
            name = pathWithoutDir;
            pathWithoutDir.clear();
            return true;
        }
        return false;
    }

    return true;
}
bool Path::__separateExt(string &pathWithoutDirAndName) {
    // since files can have no extension
    ext = pathWithoutDirAndName;
    return true;
}

void Path::setDirName(string dir_) {
    __separateDir(dir_);
}
void Path::setFileName(string name_) {
    __separateName(name_);
    // If format was name.ext
    if(!name_.empty())
        __separateExt(name_);
}
void Path::setFileExt(string ext_) {
    __separateExt(ext_);
}
string Path::getPath() {

    string tempDir = !dir.empty() ? dir + "/" : "./";
    string tempExt = !ext.empty() > 0 ? '.' + ext : "";

    if(!name.empty())
        return tempDir + name + tempExt;
    return tempDir;
}
string Path::getDirName() {
    return !dir.empty() ? dir : ".";
}
string Path::getFileName() {
    return name;
}
string Path::getFileExt() {
    return ext;
}
void Path::resetPath() {
    dir = name = ext = "";
}
string Path::getRawPath() {
    return rawPath;
}