# Self-test example program to see what yaml-cpp library provides.

Test with yaml-cpp 0.5.2 and boost_1_59_0.

### Caution while building yaml-cpp with Visual Studio 2010.
* When it is generating the build with Windows CMake,
 error occures because it cannot find boost library.
 "CMake Error at C:/Program Files (x86)/CMake/share/cmake-3.3/Modules/FindBoost.cmake:1245 (message): Unable to find the requested Boost.
* Add Entry two PATH variables.
BOOST_ROOT=C:\path\to\boost_1_58
BOOST_LIBRARYDIR=C:\path\to\boost_1_58\lib

