# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tony/CLionProjects/DoodleJump

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tony/CLionProjects/DoodleJump/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DoodleJump.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DoodleJump.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DoodleJump.dir/flags.make

CMakeFiles/DoodleJump.dir/main.cpp.o: CMakeFiles/DoodleJump.dir/flags.make
CMakeFiles/DoodleJump.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/CLionProjects/DoodleJump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DoodleJump.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DoodleJump.dir/main.cpp.o -c /home/tony/CLionProjects/DoodleJump/main.cpp

CMakeFiles/DoodleJump.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DoodleJump.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/CLionProjects/DoodleJump/main.cpp > CMakeFiles/DoodleJump.dir/main.cpp.i

CMakeFiles/DoodleJump.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DoodleJump.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/CLionProjects/DoodleJump/main.cpp -o CMakeFiles/DoodleJump.dir/main.cpp.s

# Object files for target DoodleJump
DoodleJump_OBJECTS = \
"CMakeFiles/DoodleJump.dir/main.cpp.o"

# External object files for target DoodleJump
DoodleJump_EXTERNAL_OBJECTS =

DoodleJump: CMakeFiles/DoodleJump.dir/main.cpp.o
DoodleJump: CMakeFiles/DoodleJump.dir/build.make
DoodleJump: CMakeFiles/DoodleJump.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tony/CLionProjects/DoodleJump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DoodleJump"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DoodleJump.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DoodleJump.dir/build: DoodleJump

.PHONY : CMakeFiles/DoodleJump.dir/build

CMakeFiles/DoodleJump.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DoodleJump.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DoodleJump.dir/clean

CMakeFiles/DoodleJump.dir/depend:
	cd /home/tony/CLionProjects/DoodleJump/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tony/CLionProjects/DoodleJump /home/tony/CLionProjects/DoodleJump /home/tony/CLionProjects/DoodleJump/cmake-build-debug /home/tony/CLionProjects/DoodleJump/cmake-build-debug /home/tony/CLionProjects/DoodleJump/cmake-build-debug/CMakeFiles/DoodleJump.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DoodleJump.dir/depend

