# c++ boost library sample codes.

## Setup compilation env

- To compile sample under Ubunto, following packages are required.
```bash
sudo apt-get install libboost-dev libboost-system-dev libboost-timer-dev libboost-thread-dev libboost-log-dev
```

## Build the boost library with Visual Studio 2013
* Unzip boost source.
* Build boost source
```
cd <VS12 installation dir>\Common7\Tools\Shortcuts
"VS2013 x86 Native Tools Command Prompt.lnk"
cd <boost source dir>
bootstrap
b2
```
* Remove unnecessary files: delete all folder except "<boost source rootdir>/boost" and "<boost source rootdir>/stage"
  * boost header : "<boost source rootdir>/boost"
  * boost library : "<boost source rootdir>/stage"
* Add library path to "Project Setting/Linker/General/Additional Library Directories"
  <boost source rootdir>/stage/lib
* Add include path to Project Setting/VC++ Directories/Include Directories
  <boost source rootdir>
