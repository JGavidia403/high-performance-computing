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
CMAKE_SOURCE_DIR = /home/jofre/Documentos/HPC3/ParcialHPC3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jofre/Documentos/HPC3/ParcialHPC3/Debug

# Include any dependencies generated for this target.
include CMakeFiles/ParcialHPC3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ParcialHPC3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ParcialHPC3.dir/flags.make

CMakeFiles/ParcialHPC3.dir/main.cpp.o: CMakeFiles/ParcialHPC3.dir/flags.make
CMakeFiles/ParcialHPC3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jofre/Documentos/HPC3/ParcialHPC3/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ParcialHPC3.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParcialHPC3.dir/main.cpp.o -c /home/jofre/Documentos/HPC3/ParcialHPC3/main.cpp

CMakeFiles/ParcialHPC3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParcialHPC3.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jofre/Documentos/HPC3/ParcialHPC3/main.cpp > CMakeFiles/ParcialHPC3.dir/main.cpp.i

CMakeFiles/ParcialHPC3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParcialHPC3.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jofre/Documentos/HPC3/ParcialHPC3/main.cpp -o CMakeFiles/ParcialHPC3.dir/main.cpp.s

# Object files for target ParcialHPC3
ParcialHPC3_OBJECTS = \
"CMakeFiles/ParcialHPC3.dir/main.cpp.o"

# External object files for target ParcialHPC3
ParcialHPC3_EXTERNAL_OBJECTS =

ParcialHPC3: CMakeFiles/ParcialHPC3.dir/main.cpp.o
ParcialHPC3: CMakeFiles/ParcialHPC3.dir/build.make
ParcialHPC3: CMakeFiles/ParcialHPC3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jofre/Documentos/HPC3/ParcialHPC3/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ParcialHPC3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ParcialHPC3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ParcialHPC3.dir/build: ParcialHPC3

.PHONY : CMakeFiles/ParcialHPC3.dir/build

CMakeFiles/ParcialHPC3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ParcialHPC3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ParcialHPC3.dir/clean

CMakeFiles/ParcialHPC3.dir/depend:
	cd /home/jofre/Documentos/HPC3/ParcialHPC3/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jofre/Documentos/HPC3/ParcialHPC3 /home/jofre/Documentos/HPC3/ParcialHPC3 /home/jofre/Documentos/HPC3/ParcialHPC3/Debug /home/jofre/Documentos/HPC3/ParcialHPC3/Debug /home/jofre/Documentos/HPC3/ParcialHPC3/Debug/CMakeFiles/ParcialHPC3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ParcialHPC3.dir/depend

