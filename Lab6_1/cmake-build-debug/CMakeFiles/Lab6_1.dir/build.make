# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/andrii/Bodio/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/andrii/Bodio/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrii/CLionProjects/Lab6_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrii/CLionProjects/Lab6_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab6_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab6_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab6_1.dir/flags.make

CMakeFiles/Lab6_1.dir/main.c.o: CMakeFiles/Lab6_1.dir/flags.make
CMakeFiles/Lab6_1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrii/CLionProjects/Lab6_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab6_1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab6_1.dir/main.c.o   -c /home/andrii/CLionProjects/Lab6_1/main.c

CMakeFiles/Lab6_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab6_1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrii/CLionProjects/Lab6_1/main.c > CMakeFiles/Lab6_1.dir/main.c.i

CMakeFiles/Lab6_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab6_1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrii/CLionProjects/Lab6_1/main.c -o CMakeFiles/Lab6_1.dir/main.c.s

CMakeFiles/Lab6_1.dir/main.c.o.requires:

.PHONY : CMakeFiles/Lab6_1.dir/main.c.o.requires

CMakeFiles/Lab6_1.dir/main.c.o.provides: CMakeFiles/Lab6_1.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Lab6_1.dir/build.make CMakeFiles/Lab6_1.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Lab6_1.dir/main.c.o.provides

CMakeFiles/Lab6_1.dir/main.c.o.provides.build: CMakeFiles/Lab6_1.dir/main.c.o


CMakeFiles/Lab6_1.dir/Lab6_1.c.o: CMakeFiles/Lab6_1.dir/flags.make
CMakeFiles/Lab6_1.dir/Lab6_1.c.o: ../Lab6_1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrii/CLionProjects/Lab6_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Lab6_1.dir/Lab6_1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab6_1.dir/Lab6_1.c.o   -c /home/andrii/CLionProjects/Lab6_1/Lab6_1.c

CMakeFiles/Lab6_1.dir/Lab6_1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab6_1.dir/Lab6_1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrii/CLionProjects/Lab6_1/Lab6_1.c > CMakeFiles/Lab6_1.dir/Lab6_1.c.i

CMakeFiles/Lab6_1.dir/Lab6_1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab6_1.dir/Lab6_1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrii/CLionProjects/Lab6_1/Lab6_1.c -o CMakeFiles/Lab6_1.dir/Lab6_1.c.s

CMakeFiles/Lab6_1.dir/Lab6_1.c.o.requires:

.PHONY : CMakeFiles/Lab6_1.dir/Lab6_1.c.o.requires

CMakeFiles/Lab6_1.dir/Lab6_1.c.o.provides: CMakeFiles/Lab6_1.dir/Lab6_1.c.o.requires
	$(MAKE) -f CMakeFiles/Lab6_1.dir/build.make CMakeFiles/Lab6_1.dir/Lab6_1.c.o.provides.build
.PHONY : CMakeFiles/Lab6_1.dir/Lab6_1.c.o.provides

CMakeFiles/Lab6_1.dir/Lab6_1.c.o.provides.build: CMakeFiles/Lab6_1.dir/Lab6_1.c.o


# Object files for target Lab6_1
Lab6_1_OBJECTS = \
"CMakeFiles/Lab6_1.dir/main.c.o" \
"CMakeFiles/Lab6_1.dir/Lab6_1.c.o"

# External object files for target Lab6_1
Lab6_1_EXTERNAL_OBJECTS =

Lab6_1: CMakeFiles/Lab6_1.dir/main.c.o
Lab6_1: CMakeFiles/Lab6_1.dir/Lab6_1.c.o
Lab6_1: CMakeFiles/Lab6_1.dir/build.make
Lab6_1: CMakeFiles/Lab6_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrii/CLionProjects/Lab6_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Lab6_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab6_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab6_1.dir/build: Lab6_1

.PHONY : CMakeFiles/Lab6_1.dir/build

CMakeFiles/Lab6_1.dir/requires: CMakeFiles/Lab6_1.dir/main.c.o.requires
CMakeFiles/Lab6_1.dir/requires: CMakeFiles/Lab6_1.dir/Lab6_1.c.o.requires

.PHONY : CMakeFiles/Lab6_1.dir/requires

CMakeFiles/Lab6_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab6_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab6_1.dir/clean

CMakeFiles/Lab6_1.dir/depend:
	cd /home/andrii/CLionProjects/Lab6_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrii/CLionProjects/Lab6_1 /home/andrii/CLionProjects/Lab6_1 /home/andrii/CLionProjects/Lab6_1/cmake-build-debug /home/andrii/CLionProjects/Lab6_1/cmake-build-debug /home/andrii/CLionProjects/Lab6_1/cmake-build-debug/CMakeFiles/Lab6_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab6_1.dir/depend
