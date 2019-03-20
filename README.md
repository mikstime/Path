# Path
A simple c++ repository created for simplier interaction with files.

```c++
Path* path = new Path;
path->setPath("../videos/cats/dog-2.03.20.12.avi");
path->getDirName // -> ../videos/cats
path->getFileName(); // -> dog-2.03.20.12
path->getFileExt(); // -> avi
path->setDirName("../lib");
path->getFullPath() // -> ../lib/dog-2.03.20.12.avi
```
