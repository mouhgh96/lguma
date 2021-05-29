# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/mohamed/projects/lua-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohamed/projects/lua-cpp/build

# Include any dependencies generated for this target.
include deps/Heap-Layers/CMakeFiles/heaplayers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include deps/Heap-Layers/CMakeFiles/heaplayers.dir/compiler_depend.make

# Include the progress variables for this target.
include deps/Heap-Layers/CMakeFiles/heaplayers.dir/progress.make

# Include the compile flags for this target's objects.
include deps/Heap-Layers/CMakeFiles/heaplayers.dir/flags.make

deps/Heap-Layers/CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.o: deps/Heap-Layers/CMakeFiles/heaplayers.dir/flags.make
deps/Heap-Layers/CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.o: ../deps/Heap-Layers/threads/cpuinfo.cpp
deps/Heap-Layers/CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.o: deps/Heap-Layers/CMakeFiles/heaplayers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mohamed/projects/lua-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object deps/Heap-Layers/CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.o"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT deps/Heap-Layers/CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.o -MF CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.o.d -o CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.o -c /home/mohamed/projects/lua-cpp/deps/Heap-Layers/threads/cpuinfo.cpp

deps/Heap-Layers/CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.i"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/projects/lua-cpp/deps/Heap-Layers/threads/cpuinfo.cpp > CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.i

deps/Heap-Layers/CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.s"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/projects/lua-cpp/deps/Heap-Layers/threads/cpuinfo.cpp -o CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.s

deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/ilog2.cpp.o: deps/Heap-Layers/CMakeFiles/heaplayers.dir/flags.make
deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/ilog2.cpp.o: ../deps/Heap-Layers/utility/ilog2.cpp
deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/ilog2.cpp.o: deps/Heap-Layers/CMakeFiles/heaplayers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mohamed/projects/lua-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/ilog2.cpp.o"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/ilog2.cpp.o -MF CMakeFiles/heaplayers.dir/utility/ilog2.cpp.o.d -o CMakeFiles/heaplayers.dir/utility/ilog2.cpp.o -c /home/mohamed/projects/lua-cpp/deps/Heap-Layers/utility/ilog2.cpp

deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/ilog2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/heaplayers.dir/utility/ilog2.cpp.i"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/projects/lua-cpp/deps/Heap-Layers/utility/ilog2.cpp > CMakeFiles/heaplayers.dir/utility/ilog2.cpp.i

deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/ilog2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/heaplayers.dir/utility/ilog2.cpp.s"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/projects/lua-cpp/deps/Heap-Layers/utility/ilog2.cpp -o CMakeFiles/heaplayers.dir/utility/ilog2.cpp.s

deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/testalign.cpp.o: deps/Heap-Layers/CMakeFiles/heaplayers.dir/flags.make
deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/testalign.cpp.o: ../deps/Heap-Layers/utility/testalign.cpp
deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/testalign.cpp.o: deps/Heap-Layers/CMakeFiles/heaplayers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mohamed/projects/lua-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/testalign.cpp.o"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/testalign.cpp.o -MF CMakeFiles/heaplayers.dir/utility/testalign.cpp.o.d -o CMakeFiles/heaplayers.dir/utility/testalign.cpp.o -c /home/mohamed/projects/lua-cpp/deps/Heap-Layers/utility/testalign.cpp

deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/testalign.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/heaplayers.dir/utility/testalign.cpp.i"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/projects/lua-cpp/deps/Heap-Layers/utility/testalign.cpp > CMakeFiles/heaplayers.dir/utility/testalign.cpp.i

deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/testalign.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/heaplayers.dir/utility/testalign.cpp.s"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && /bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/projects/lua-cpp/deps/Heap-Layers/utility/testalign.cpp -o CMakeFiles/heaplayers.dir/utility/testalign.cpp.s

# Object files for target heaplayers
heaplayers_OBJECTS = \
"CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.o" \
"CMakeFiles/heaplayers.dir/utility/ilog2.cpp.o" \
"CMakeFiles/heaplayers.dir/utility/testalign.cpp.o"

# External object files for target heaplayers
heaplayers_EXTERNAL_OBJECTS =

deps/Heap-Layers/libheaplayers.so: deps/Heap-Layers/CMakeFiles/heaplayers.dir/threads/cpuinfo.cpp.o
deps/Heap-Layers/libheaplayers.so: deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/ilog2.cpp.o
deps/Heap-Layers/libheaplayers.so: deps/Heap-Layers/CMakeFiles/heaplayers.dir/utility/testalign.cpp.o
deps/Heap-Layers/libheaplayers.so: deps/Heap-Layers/CMakeFiles/heaplayers.dir/build.make
deps/Heap-Layers/libheaplayers.so: deps/Heap-Layers/CMakeFiles/heaplayers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mohamed/projects/lua-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libheaplayers.so"
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heaplayers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deps/Heap-Layers/CMakeFiles/heaplayers.dir/build: deps/Heap-Layers/libheaplayers.so
.PHONY : deps/Heap-Layers/CMakeFiles/heaplayers.dir/build

deps/Heap-Layers/CMakeFiles/heaplayers.dir/clean:
	cd /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers && $(CMAKE_COMMAND) -P CMakeFiles/heaplayers.dir/cmake_clean.cmake
.PHONY : deps/Heap-Layers/CMakeFiles/heaplayers.dir/clean

deps/Heap-Layers/CMakeFiles/heaplayers.dir/depend:
	cd /home/mohamed/projects/lua-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohamed/projects/lua-cpp /home/mohamed/projects/lua-cpp/deps/Heap-Layers /home/mohamed/projects/lua-cpp/build /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers /home/mohamed/projects/lua-cpp/build/deps/Heap-Layers/CMakeFiles/heaplayers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : deps/Heap-Layers/CMakeFiles/heaplayers.dir/depend
