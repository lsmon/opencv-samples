# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lsmon/Developer/qt/sampling

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lsmon/Developer/qt/sampling/sampling-build

# Include any dependencies generated for this target.
include CMakeFiles/sampling.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sampling.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sampling.dir/flags.make

CMakeFiles/sampling.dir/SobelDemo.cpp.o: CMakeFiles/sampling.dir/flags.make
CMakeFiles/sampling.dir/SobelDemo.cpp.o: ../SobelDemo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/lsmon/Developer/qt/sampling/sampling-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sampling.dir/SobelDemo.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sampling.dir/SobelDemo.cpp.o -c /Users/lsmon/Developer/qt/sampling/SobelDemo.cpp

CMakeFiles/sampling.dir/SobelDemo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sampling.dir/SobelDemo.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/lsmon/Developer/qt/sampling/SobelDemo.cpp > CMakeFiles/sampling.dir/SobelDemo.cpp.i

CMakeFiles/sampling.dir/SobelDemo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sampling.dir/SobelDemo.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/lsmon/Developer/qt/sampling/SobelDemo.cpp -o CMakeFiles/sampling.dir/SobelDemo.cpp.s

CMakeFiles/sampling.dir/SobelDemo.cpp.o.requires:
.PHONY : CMakeFiles/sampling.dir/SobelDemo.cpp.o.requires

CMakeFiles/sampling.dir/SobelDemo.cpp.o.provides: CMakeFiles/sampling.dir/SobelDemo.cpp.o.requires
	$(MAKE) -f CMakeFiles/sampling.dir/build.make CMakeFiles/sampling.dir/SobelDemo.cpp.o.provides.build
.PHONY : CMakeFiles/sampling.dir/SobelDemo.cpp.o.provides

CMakeFiles/sampling.dir/SobelDemo.cpp.o.provides.build: CMakeFiles/sampling.dir/SobelDemo.cpp.o

CMakeFiles/sampling.dir/CustomOpenCV.cpp.o: CMakeFiles/sampling.dir/flags.make
CMakeFiles/sampling.dir/CustomOpenCV.cpp.o: ../CustomOpenCV.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/lsmon/Developer/qt/sampling/sampling-build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sampling.dir/CustomOpenCV.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sampling.dir/CustomOpenCV.cpp.o -c /Users/lsmon/Developer/qt/sampling/CustomOpenCV.cpp

CMakeFiles/sampling.dir/CustomOpenCV.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sampling.dir/CustomOpenCV.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/lsmon/Developer/qt/sampling/CustomOpenCV.cpp > CMakeFiles/sampling.dir/CustomOpenCV.cpp.i

CMakeFiles/sampling.dir/CustomOpenCV.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sampling.dir/CustomOpenCV.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/lsmon/Developer/qt/sampling/CustomOpenCV.cpp -o CMakeFiles/sampling.dir/CustomOpenCV.cpp.s

CMakeFiles/sampling.dir/CustomOpenCV.cpp.o.requires:
.PHONY : CMakeFiles/sampling.dir/CustomOpenCV.cpp.o.requires

CMakeFiles/sampling.dir/CustomOpenCV.cpp.o.provides: CMakeFiles/sampling.dir/CustomOpenCV.cpp.o.requires
	$(MAKE) -f CMakeFiles/sampling.dir/build.make CMakeFiles/sampling.dir/CustomOpenCV.cpp.o.provides.build
.PHONY : CMakeFiles/sampling.dir/CustomOpenCV.cpp.o.provides

CMakeFiles/sampling.dir/CustomOpenCV.cpp.o.provides.build: CMakeFiles/sampling.dir/CustomOpenCV.cpp.o

# Object files for target sampling
sampling_OBJECTS = \
"CMakeFiles/sampling.dir/SobelDemo.cpp.o" \
"CMakeFiles/sampling.dir/CustomOpenCV.cpp.o"

# External object files for target sampling
sampling_EXTERNAL_OBJECTS =

sampling: CMakeFiles/sampling.dir/SobelDemo.cpp.o
sampling: CMakeFiles/sampling.dir/CustomOpenCV.cpp.o
sampling: CMakeFiles/sampling.dir/build.make
sampling: CMakeFiles/sampling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sampling"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sampling.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sampling.dir/build: sampling
.PHONY : CMakeFiles/sampling.dir/build

CMakeFiles/sampling.dir/requires: CMakeFiles/sampling.dir/SobelDemo.cpp.o.requires
CMakeFiles/sampling.dir/requires: CMakeFiles/sampling.dir/CustomOpenCV.cpp.o.requires
.PHONY : CMakeFiles/sampling.dir/requires

CMakeFiles/sampling.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sampling.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sampling.dir/clean

CMakeFiles/sampling.dir/depend:
	cd /Users/lsmon/Developer/qt/sampling/sampling-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lsmon/Developer/qt/sampling /Users/lsmon/Developer/qt/sampling /Users/lsmon/Developer/qt/sampling/sampling-build /Users/lsmon/Developer/qt/sampling/sampling-build /Users/lsmon/Developer/qt/sampling/sampling-build/CMakeFiles/sampling.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sampling.dir/depend

