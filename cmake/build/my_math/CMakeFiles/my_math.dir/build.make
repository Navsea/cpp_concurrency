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
CMAKE_SOURCE_DIR = /home/kenneth/Projects/udemy/cpp_concurrency/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build

# Include any dependencies generated for this target.
include my_math/CMakeFiles/my_math.dir/depend.make

# Include the progress variables for this target.
include my_math/CMakeFiles/my_math.dir/progress.make

# Include the compile flags for this target's objects.
include my_math/CMakeFiles/my_math.dir/flags.make

my_math/CMakeFiles/my_math.dir/src/addition.cpp.o: my_math/CMakeFiles/my_math.dir/flags.make
my_math/CMakeFiles/my_math.dir/src/addition.cpp.o: ../my_math/src/addition.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object my_math/CMakeFiles/my_math.dir/src/addition.cpp.o"
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math && /bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_math.dir/src/addition.cpp.o -c /home/kenneth/Projects/udemy/cpp_concurrency/cmake/my_math/src/addition.cpp

my_math/CMakeFiles/my_math.dir/src/addition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_math.dir/src/addition.cpp.i"
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kenneth/Projects/udemy/cpp_concurrency/cmake/my_math/src/addition.cpp > CMakeFiles/my_math.dir/src/addition.cpp.i

my_math/CMakeFiles/my_math.dir/src/addition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_math.dir/src/addition.cpp.s"
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kenneth/Projects/udemy/cpp_concurrency/cmake/my_math/src/addition.cpp -o CMakeFiles/my_math.dir/src/addition.cpp.s

my_math/CMakeFiles/my_math.dir/src/division.cpp.o: my_math/CMakeFiles/my_math.dir/flags.make
my_math/CMakeFiles/my_math.dir/src/division.cpp.o: ../my_math/src/division.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object my_math/CMakeFiles/my_math.dir/src/division.cpp.o"
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math && /bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_math.dir/src/division.cpp.o -c /home/kenneth/Projects/udemy/cpp_concurrency/cmake/my_math/src/division.cpp

my_math/CMakeFiles/my_math.dir/src/division.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_math.dir/src/division.cpp.i"
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kenneth/Projects/udemy/cpp_concurrency/cmake/my_math/src/division.cpp > CMakeFiles/my_math.dir/src/division.cpp.i

my_math/CMakeFiles/my_math.dir/src/division.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_math.dir/src/division.cpp.s"
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kenneth/Projects/udemy/cpp_concurrency/cmake/my_math/src/division.cpp -o CMakeFiles/my_math.dir/src/division.cpp.s

# Object files for target my_math
my_math_OBJECTS = \
"CMakeFiles/my_math.dir/src/addition.cpp.o" \
"CMakeFiles/my_math.dir/src/division.cpp.o"

# External object files for target my_math
my_math_EXTERNAL_OBJECTS =

my_math/libmy_math.a: my_math/CMakeFiles/my_math.dir/src/addition.cpp.o
my_math/libmy_math.a: my_math/CMakeFiles/my_math.dir/src/division.cpp.o
my_math/libmy_math.a: my_math/CMakeFiles/my_math.dir/build.make
my_math/libmy_math.a: my_math/CMakeFiles/my_math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libmy_math.a"
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math && $(CMAKE_COMMAND) -P CMakeFiles/my_math.dir/cmake_clean_target.cmake
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_math.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
my_math/CMakeFiles/my_math.dir/build: my_math/libmy_math.a

.PHONY : my_math/CMakeFiles/my_math.dir/build

my_math/CMakeFiles/my_math.dir/clean:
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math && $(CMAKE_COMMAND) -P CMakeFiles/my_math.dir/cmake_clean.cmake
.PHONY : my_math/CMakeFiles/my_math.dir/clean

my_math/CMakeFiles/my_math.dir/depend:
	cd /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kenneth/Projects/udemy/cpp_concurrency/cmake /home/kenneth/Projects/udemy/cpp_concurrency/cmake/my_math /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math /home/kenneth/Projects/udemy/cpp_concurrency/cmake/build/my_math/CMakeFiles/my_math.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : my_math/CMakeFiles/my_math.dir/depend

