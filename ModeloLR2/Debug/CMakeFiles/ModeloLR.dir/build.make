# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jofre/Documentos/HPC3/ModeloLR2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jofre/Documentos/HPC3/ModeloLR2/Debug

# Include any dependencies generated for this target.
include CMakeFiles/ModeloLR.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ModeloLR.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ModeloLR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ModeloLR.dir/flags.make

CMakeFiles/ModeloLR.dir/main.cpp.o: CMakeFiles/ModeloLR.dir/flags.make
CMakeFiles/ModeloLR.dir/main.cpp.o: ../main.cpp
CMakeFiles/ModeloLR.dir/main.cpp.o: CMakeFiles/ModeloLR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jofre/Documentos/HPC3/ModeloLR2/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ModeloLR.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ModeloLR.dir/main.cpp.o -MF CMakeFiles/ModeloLR.dir/main.cpp.o.d -o CMakeFiles/ModeloLR.dir/main.cpp.o -c /home/jofre/Documentos/HPC3/ModeloLR2/main.cpp

CMakeFiles/ModeloLR.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ModeloLR.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jofre/Documentos/HPC3/ModeloLR2/main.cpp > CMakeFiles/ModeloLR.dir/main.cpp.i

CMakeFiles/ModeloLR.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ModeloLR.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jofre/Documentos/HPC3/ModeloLR2/main.cpp -o CMakeFiles/ModeloLR.dir/main.cpp.s

CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.o: CMakeFiles/ModeloLR.dir/flags.make
CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.o: ../EXTRACTION/extractiondata.cpp
CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.o: CMakeFiles/ModeloLR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jofre/Documentos/HPC3/ModeloLR2/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.o -MF CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.o.d -o CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.o -c /home/jofre/Documentos/HPC3/ModeloLR2/EXTRACTION/extractiondata.cpp

CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jofre/Documentos/HPC3/ModeloLR2/EXTRACTION/extractiondata.cpp > CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.i

CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jofre/Documentos/HPC3/ModeloLR2/EXTRACTION/extractiondata.cpp -o CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.s

CMakeFiles/ModeloLR.dir/regresionlineal.cpp.o: CMakeFiles/ModeloLR.dir/flags.make
CMakeFiles/ModeloLR.dir/regresionlineal.cpp.o: ../regresionlineal.cpp
CMakeFiles/ModeloLR.dir/regresionlineal.cpp.o: CMakeFiles/ModeloLR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jofre/Documentos/HPC3/ModeloLR2/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ModeloLR.dir/regresionlineal.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ModeloLR.dir/regresionlineal.cpp.o -MF CMakeFiles/ModeloLR.dir/regresionlineal.cpp.o.d -o CMakeFiles/ModeloLR.dir/regresionlineal.cpp.o -c /home/jofre/Documentos/HPC3/ModeloLR2/regresionlineal.cpp

CMakeFiles/ModeloLR.dir/regresionlineal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ModeloLR.dir/regresionlineal.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jofre/Documentos/HPC3/ModeloLR2/regresionlineal.cpp > CMakeFiles/ModeloLR.dir/regresionlineal.cpp.i

CMakeFiles/ModeloLR.dir/regresionlineal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ModeloLR.dir/regresionlineal.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jofre/Documentos/HPC3/ModeloLR2/regresionlineal.cpp -o CMakeFiles/ModeloLR.dir/regresionlineal.cpp.s

# Object files for target ModeloLR
ModeloLR_OBJECTS = \
"CMakeFiles/ModeloLR.dir/main.cpp.o" \
"CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.o" \
"CMakeFiles/ModeloLR.dir/regresionlineal.cpp.o"

# External object files for target ModeloLR
ModeloLR_EXTERNAL_OBJECTS =

ModeloLR: CMakeFiles/ModeloLR.dir/main.cpp.o
ModeloLR: CMakeFiles/ModeloLR.dir/EXTRACTION/extractiondata.cpp.o
ModeloLR: CMakeFiles/ModeloLR.dir/regresionlineal.cpp.o
ModeloLR: CMakeFiles/ModeloLR.dir/build.make
ModeloLR: CMakeFiles/ModeloLR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jofre/Documentos/HPC3/ModeloLR2/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ModeloLR"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ModeloLR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ModeloLR.dir/build: ModeloLR
.PHONY : CMakeFiles/ModeloLR.dir/build

CMakeFiles/ModeloLR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ModeloLR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ModeloLR.dir/clean

CMakeFiles/ModeloLR.dir/depend:
	cd /home/jofre/Documentos/HPC3/ModeloLR2/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jofre/Documentos/HPC3/ModeloLR2 /home/jofre/Documentos/HPC3/ModeloLR2 /home/jofre/Documentos/HPC3/ModeloLR2/Debug /home/jofre/Documentos/HPC3/ModeloLR2/Debug /home/jofre/Documentos/HPC3/ModeloLR2/Debug/CMakeFiles/ModeloLR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ModeloLR.dir/depend

