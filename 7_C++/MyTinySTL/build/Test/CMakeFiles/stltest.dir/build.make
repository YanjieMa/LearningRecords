# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/admin/MyComputerStudy/study/C++/MyTinySTL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/admin/MyComputerStudy/study/C++/MyTinySTL/build

# Include any dependencies generated for this target.
include Test/CMakeFiles/stltest.dir/depend.make

# Include the progress variables for this target.
include Test/CMakeFiles/stltest.dir/progress.make

# Include the compile flags for this target's objects.
include Test/CMakeFiles/stltest.dir/flags.make

Test/CMakeFiles/stltest.dir/test.cpp.o: Test/CMakeFiles/stltest.dir/flags.make
Test/CMakeFiles/stltest.dir/test.cpp.o: ../Test/test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/admin/MyComputerStudy/study/C++/MyTinySTL/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Test/CMakeFiles/stltest.dir/test.cpp.o"
	cd /home/admin/MyComputerStudy/study/C++/MyTinySTL/build/Test && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/stltest.dir/test.cpp.o -c /home/admin/MyComputerStudy/study/C++/MyTinySTL/Test/test.cpp

Test/CMakeFiles/stltest.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stltest.dir/test.cpp.i"
	cd /home/admin/MyComputerStudy/study/C++/MyTinySTL/build/Test && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/admin/MyComputerStudy/study/C++/MyTinySTL/Test/test.cpp > CMakeFiles/stltest.dir/test.cpp.i

Test/CMakeFiles/stltest.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stltest.dir/test.cpp.s"
	cd /home/admin/MyComputerStudy/study/C++/MyTinySTL/build/Test && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/admin/MyComputerStudy/study/C++/MyTinySTL/Test/test.cpp -o CMakeFiles/stltest.dir/test.cpp.s

Test/CMakeFiles/stltest.dir/test.cpp.o.requires:
.PHONY : Test/CMakeFiles/stltest.dir/test.cpp.o.requires

Test/CMakeFiles/stltest.dir/test.cpp.o.provides: Test/CMakeFiles/stltest.dir/test.cpp.o.requires
	$(MAKE) -f Test/CMakeFiles/stltest.dir/build.make Test/CMakeFiles/stltest.dir/test.cpp.o.provides.build
.PHONY : Test/CMakeFiles/stltest.dir/test.cpp.o.provides

Test/CMakeFiles/stltest.dir/test.cpp.o.provides.build: Test/CMakeFiles/stltest.dir/test.cpp.o

# Object files for target stltest
stltest_OBJECTS = \
"CMakeFiles/stltest.dir/test.cpp.o"

# External object files for target stltest
stltest_EXTERNAL_OBJECTS =

../bin/stltest: Test/CMakeFiles/stltest.dir/test.cpp.o
../bin/stltest: Test/CMakeFiles/stltest.dir/build.make
../bin/stltest: Test/CMakeFiles/stltest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/stltest"
	cd /home/admin/MyComputerStudy/study/C++/MyTinySTL/build/Test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stltest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Test/CMakeFiles/stltest.dir/build: ../bin/stltest
.PHONY : Test/CMakeFiles/stltest.dir/build

Test/CMakeFiles/stltest.dir/requires: Test/CMakeFiles/stltest.dir/test.cpp.o.requires
.PHONY : Test/CMakeFiles/stltest.dir/requires

Test/CMakeFiles/stltest.dir/clean:
	cd /home/admin/MyComputerStudy/study/C++/MyTinySTL/build/Test && $(CMAKE_COMMAND) -P CMakeFiles/stltest.dir/cmake_clean.cmake
.PHONY : Test/CMakeFiles/stltest.dir/clean

Test/CMakeFiles/stltest.dir/depend:
	cd /home/admin/MyComputerStudy/study/C++/MyTinySTL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/admin/MyComputerStudy/study/C++/MyTinySTL /home/admin/MyComputerStudy/study/C++/MyTinySTL/Test /home/admin/MyComputerStudy/study/C++/MyTinySTL/build /home/admin/MyComputerStudy/study/C++/MyTinySTL/build/Test /home/admin/MyComputerStudy/study/C++/MyTinySTL/build/Test/CMakeFiles/stltest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Test/CMakeFiles/stltest.dir/depend
