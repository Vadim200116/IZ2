# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/User/technopark/cpp/dz_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/User/technopark/cpp/dz_2

# Include any dependencies generated for this target.
include CMakeFiles/prog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prog.dir/flags.make

CMakeFiles/prog.dir/src/main.cpp.o: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/User/technopark/cpp/dz_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prog.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prog.dir/src/main.cpp.o -c /mnt/c/Users/User/technopark/cpp/dz_2/src/main.cpp

CMakeFiles/prog.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/User/technopark/cpp/dz_2/src/main.cpp > CMakeFiles/prog.dir/src/main.cpp.i

CMakeFiles/prog.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/User/technopark/cpp/dz_2/src/main.cpp -o CMakeFiles/prog.dir/src/main.cpp.s

# Object files for target prog
prog_OBJECTS = \
"CMakeFiles/prog.dir/src/main.cpp.o"

# External object files for target prog
prog_EXTERNAL_OBJECTS =

prog: CMakeFiles/prog.dir/src/main.cpp.o
prog: CMakeFiles/prog.dir/build.make
prog: libiz2_std_lib.a
prog: CMakeFiles/prog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/User/technopark/cpp/dz_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prog.dir/build: prog

.PHONY : CMakeFiles/prog.dir/build

CMakeFiles/prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prog.dir/clean

CMakeFiles/prog.dir/depend:
	cd /mnt/c/Users/User/technopark/cpp/dz_2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/User/technopark/cpp/dz_2 /mnt/c/Users/User/technopark/cpp/dz_2 /mnt/c/Users/User/technopark/cpp/dz_2 /mnt/c/Users/User/technopark/cpp/dz_2 /mnt/c/Users/User/technopark/cpp/dz_2/CMakeFiles/prog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prog.dir/depend

