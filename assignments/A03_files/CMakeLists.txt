# CMakeLists.txt
# CMake is a program that sets up what the compiler needs to build your program
# As programs get more complicated with more files, libraries, and external code, it gets more
# difficult and cumbersome to build your program on the command-line. CMake turns what
# could be dozens or hundreds of commands into basically two steps:
#
# 1. Configure - reads CMakeLists.txt (this file) and generates whatever files it
#                needs to build. It will detect your compiler, or you can specify a specific compiler.
# 2. Generate -  CMake will generate the files for a specific build system. One used a lot
#                for C/C++ is `make` which CMake will generate a Makefile. CMake can also generate
#                the project files for many IDEs like Microsoft's Visual Studio and Apple's Xcode.
#                I prefer CLion for teaching C++, but there is a CMake extension for
#                VS Code that takes a bit more to setup but is also an option
#
# For many assignments/projects you won't need to do anything with this file. For this
# assignment, I wanted to show you a little bit of the build process, and how something
# like CMake can make things easier.

# Declaring which version of CMake to use is required as the first command in a CMakeLists.txt.
# It is rare this will matter, although I've encountered some weird issues. If CMake creates an
# error from this, you are safe to change the version to whatever your version of CMake is and
# it is unlikely to cause an issue.
cmake_minimum_required(VERSION 3.28)


# CMake needs to have a name for your project. A project groups together what are commonly
# called `targets`. A target is basically the output of compiling and then linking together
# source files into one binary file. Most of our projects will contain one target, and
# most of those targets will be an executable. It is also possible to have a target be a
# library, which is still binary, but it doesn't have an entry point like an executable,
# and it doesn't run on its own. Usually you have an executable target `link` to a library.
# On windows you might see library files with the extension .dll or .lib. Those are
# different kinds of libraries, sometimes called `dynamic` and `static`. We may eventually
# make our own library and have our executable link to it.
project(cs3100_files_solution)

# There are different C++ standards, and different compilers support or don't support certain
# versions of the standard. C++20 is a little older now, it became the current standard
# in 2020. You can look up more if you want, but newer standards add new features and
# they might also deprecate older ones.
set(CMAKE_CXX_STANDARD 20)

get_filename_component(CURRENT_DIR_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
get_filename_component(PARENT_DIR_NAME "${PARENT_DIR}" NAME)

if(CURRENT_DIR_NAME STREQUAL "starter" OR CURRENT_DIR_NAME STREQUAL "solution")
    set(TARGET_NAME "${PARENT_DIR_NAME}_${CURRENT_DIR_NAME}")
else()
    set(TARGET_NAME "${CURRENT_DIR_NAME}")
endif()

# This is probably the most relevant command for us. This is where we say we want to
# have an executable and what files it depends on. In this case, `main.cpp` and `dice.cpp`.
# You may also include `dice.h` here, but since it is being included into main.cpp, it
# will already be compiled when main.cpp is compiled. The `add_executable` command needs the
# first argument to be the filename to output as our .exe file.
add_executable(${TARGET_NAME}
        main.cpp
        # put required filenames here
        dice.cpp
)
