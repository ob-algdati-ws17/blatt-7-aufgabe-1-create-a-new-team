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
include test/CMakeFiles/test_avl_tree.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_avl_tree.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_avl_tree.dir/flags.make

test/CMakeFiles/test_avl_tree.dir/main.cpp.obj: test/CMakeFiles/test_avl_tree.dir/flags.make
test/CMakeFiles/test_avl_tree.dir/main.cpp.obj: test/CMakeFiles/test_avl_tree.dir/includes_CXX.rsp
test/CMakeFiles/test_avl_tree.dir/main.cpp.obj: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_avl_tree.dir/main.cpp.obj"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test_avl_tree.dir\main.cpp.obj -c C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\test\main.cpp

test/CMakeFiles/test_avl_tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_avl_tree.dir/main.cpp.i"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\test\main.cpp > CMakeFiles\test_avl_tree.dir\main.cpp.i

test/CMakeFiles/test_avl_tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_avl_tree.dir/main.cpp.s"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\test\main.cpp -o CMakeFiles\test_avl_tree.dir\main.cpp.s

test/CMakeFiles/test_avl_tree.dir/main.cpp.obj.requires:

.PHONY : test/CMakeFiles/test_avl_tree.dir/main.cpp.obj.requires

test/CMakeFiles/test_avl_tree.dir/main.cpp.obj.provides: test/CMakeFiles/test_avl_tree.dir/main.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\test_avl_tree.dir\build.make test/CMakeFiles/test_avl_tree.dir/main.cpp.obj.provides.build
.PHONY : test/CMakeFiles/test_avl_tree.dir/main.cpp.obj.provides

test/CMakeFiles/test_avl_tree.dir/main.cpp.obj.provides.build: test/CMakeFiles/test_avl_tree.dir/main.cpp.obj


test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj: test/CMakeFiles/test_avl_tree.dir/flags.make
test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj: test/CMakeFiles/test_avl_tree.dir/includes_CXX.rsp
test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj: ../test/test_avl_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test_avl_tree.dir\test_avl_tree.cpp.obj -c C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\test\test_avl_tree.cpp

test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.i"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\test\test_avl_tree.cpp > CMakeFiles\test_avl_tree.dir\test_avl_tree.cpp.i

test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.s"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\test\test_avl_tree.cpp -o CMakeFiles\test_avl_tree.dir\test_avl_tree.cpp.s

test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj.requires:

.PHONY : test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj.requires

test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj.provides: test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\test_avl_tree.dir\build.make test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj.provides.build
.PHONY : test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj.provides

test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj.provides.build: test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj


test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj: test/CMakeFiles/test_avl_tree.dir/flags.make
test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj: test/CMakeFiles/test_avl_tree.dir/includes_CXX.rsp
test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj: ../avl_tree/avl_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test_avl_tree.dir\__\avl_tree\avl_tree.cpp.obj -c C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\avl_tree\avl_tree.cpp

test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.i"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\avl_tree\avl_tree.cpp > CMakeFiles\test_avl_tree.dir\__\avl_tree\avl_tree.cpp.i

test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.s"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\avl_tree\avl_tree.cpp -o CMakeFiles\test_avl_tree.dir\__\avl_tree\avl_tree.cpp.s

test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj.requires:

.PHONY : test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj.requires

test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj.provides: test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\test_avl_tree.dir\build.make test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj.provides.build
.PHONY : test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj.provides

test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj.provides.build: test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj


# Object files for target test_avl_tree
test_avl_tree_OBJECTS = \
"CMakeFiles/test_avl_tree.dir/main.cpp.obj" \
"CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj" \
"CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj"

# External object files for target test_avl_tree
test_avl_tree_EXTERNAL_OBJECTS =

test/test_avl_tree.exe: test/CMakeFiles/test_avl_tree.dir/main.cpp.obj
test/test_avl_tree.exe: test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj
test/test_avl_tree.exe: test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj
test/test_avl_tree.exe: test/CMakeFiles/test_avl_tree.dir/build.make
test/test_avl_tree.exe: googletest-build/googlemock/gtest/libgtestd.a
test/test_avl_tree.exe: googletest-build/googlemock/libgmockd.a
test/test_avl_tree.exe: test/CMakeFiles/test_avl_tree.dir/linklibs.rsp
test/test_avl_tree.exe: test/CMakeFiles/test_avl_tree.dir/objects1.rsp
test/test_avl_tree.exe: test/CMakeFiles/test_avl_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_avl_tree.exe"
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_avl_tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_avl_tree.dir/build: test/test_avl_tree.exe

.PHONY : test/CMakeFiles/test_avl_tree.dir/build

test/CMakeFiles/test_avl_tree.dir/requires: test/CMakeFiles/test_avl_tree.dir/main.cpp.obj.requires
test/CMakeFiles/test_avl_tree.dir/requires: test/CMakeFiles/test_avl_tree.dir/test_avl_tree.cpp.obj.requires
test/CMakeFiles/test_avl_tree.dir/requires: test/CMakeFiles/test_avl_tree.dir/__/avl_tree/avl_tree.cpp.obj.requires

.PHONY : test/CMakeFiles/test_avl_tree.dir/requires

test/CMakeFiles/test_avl_tree.dir/clean:
	cd /d C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test && $(CMAKE_COMMAND) -P CMakeFiles\test_avl_tree.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/test_avl_tree.dir/clean

test/CMakeFiles/test_avl_tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\test C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test C:\Users\dimik\CLionProjects\blatt-7-aufgabe-1-create-a-new-team\cmake-build-debug\test\CMakeFiles\test_avl_tree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_avl_tree.dir/depend

