#include <iostream>
#include "include/Path.h"

void printSplittedPath(Path*);

int main() {
    Path* path = new Path;
    path->setPath("../videos/cats/dog-2.03.20.12.avi");
    printSplittedPath(path);
    path->setDirName("../lib");
    printSplittedPath(path);
    path->setPath("log");
    printSplittedPath(path);
    path->setPath("games/");
    printSplittedPath(path);
    return 0;
}
void printSplittedPath(Path* path) {
    std::cout <<   "Raw path: " << path->getRawPath();
    std::cout << "\nFull path: " << path->getPath();
    std::cout << "\nDir name: " << path->getDirName();
    std::cout << "\nFile name: " << path->getFileName();
    std::cout << "\nExtension name: " << path->getFileExt();
    // leave an empty line
    std::cout << "\n\n";
}