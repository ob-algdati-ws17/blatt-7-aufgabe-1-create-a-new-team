# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug

# Include any dependencies generated for this target.
include googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/includes_CXX.rsp
googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: googletest-src/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-build\googlemock\gtest && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest.dir\src\gtest-all.cc.obj -c C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-src\googletest\src\gtest-all.cc

googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-build\googlemock\gtest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-src\googletest\src\gtest-all.cc > CMakeFiles\gtest.dir\src\gtest-all.cc.i

googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-build\googlemock\gtest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-src\googletest\src\gtest-all.cc -o CMakeFiles\gtest.dir\src\gtest-all.cc.s

googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires:

.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires

googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides: googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires
	$(MAKE) -f googletest-build\googlemock\gtest\CMakeFiles\gtest.dir\build.make googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides.build
.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides

googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides.build: googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

googletest-build/googlemock/gtest/libgtestd.a: googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
googletest-build/googlemock/gtest/libgtestd.a: googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/build.make
googletest-build/googlemock/gtest/libgtestd.a: googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtestd.a"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-build\googlemock\gtest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-build\googlemock\gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/build: googletest-build/googlemock/gtest/libgtestd.a

.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/build

googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/requires: googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires

.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/requires

googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-build\googlemock\gtest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/clean

googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-src\googletest C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-build\googlemock\gtest C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\googletest-build\googlemock\gtest\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : googletest-build/googlemock/gtest/CMakeFiles/gtest.dir/depend

