//
// Created by Михаил on 2019-03-20.
//

#include "../include/Path.h"
#include <string>
#include <iostream>
#include <algorithm>
using std::string;

void Path::setPath(string fullPath) {
    // Temporary variables for storing parts of the path
    string tempDir, tempName, tempExt;
    // Path without dots is a path without extension, so it's incorrect
    if(std::count(fullPath.begin(), fullPath.end(), '.') == 0) {
        std::cerr << "Incorect string presented\n";
        std::cerr << "No path was set";
        return;
    }
    // fileName or extension have no '/'
    // So only directory can have it
    size_t dirSize = fullPath.find_last_of("/");
    if(dirSize != string::npos) {
        tempDir = fullPath.substr(0, dirSize);
        fullPath.erase(0, dirSize + 1);
    } else {
        tempDir = "";
    }
    // Part after '/' and before '.' is name
    size_t nameSize = fullPath.find(".");
    tempName = fullPath.substr(0, nameSize);
    fullPath.erase(1, nameSize);
    // Part after '.' is an extension
    if(std::count(fullPath.begin(), fullPath.end(), '.') != 0 ) {
        std::cerr << "Incorect string presented\n";
        std::cerr << "No path was set";
        return;
    }
    tempExt = fullPath.substr(1);
    //Save results
    dir = tempDir;
    name = tempName;
    ext = tempExt;
}
void Path::setDirName(string dir_) {
    if(dir_.size() > 0 && dir_[ dir_.size() - 1] == '/')
        dir_.erase(dir_.size() - 1);

    dir = dir_;
}
void Path::setFileName(string name_) {
    // File name should not contain /
    if(name_.find("/") == string::npos) {
        // Remove extension and process it
        size_t extStart = name_.find(".");
        if(extStart != string::npos) {
            ext = name_.substr(extStart + 1);
            name_.erase(extStart);
            name = name_;
        } else {
            name = name_;
        }

    } else {
        std::cerr << "Incorect string presented\n";
        std::cerr << "No name was set";
        return;
    }
}
void Path::setFileExt(string ext_) {
    if(ext_.size() > 0 && ext_[0] == '.')
        ext_.erase(0,1);
    ext = ext_;
}
string Path::getPath() {

    string tempDir = dir.size() > 0 ? dir + "/" : "./";
    string tempExt = ext.size() > 0 ? '.' + ext : "";

    if(name.size() > 0)
        return tempDir + name + tempExt;
    return tempDir;
}
string Path::getDirName() {
    return dir.size() > 0 ? dir : ".";
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