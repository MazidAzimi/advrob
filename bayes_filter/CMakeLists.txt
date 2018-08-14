# minimum cmake version required
cmake_minimum_required( VERSION 2.8 )

# declare a cmake project
project( bayesFilter )

# set compilation mode to Debug
set( CMAKE_BUILD_TYPE "Debug" )

# add a executable from .cpp file with main() function
add_executable( ${PROJECT_NAME} bayesFilter.cpp )

# you can also assign a name for the executable directly
# add_executable( bayesFilter bayesFilter.cpp )
