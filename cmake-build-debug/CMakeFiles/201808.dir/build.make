# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = C:\Users\gladh\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\182.3684.76\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\gladh\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\182.3684.76\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\gladh\CLionProjects\201808

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gladh\CLionProjects\201808\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/201808.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/201808.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/201808.dir/flags.make

CMakeFiles/201808.dir/main.cpp.obj: CMakeFiles/201808.dir/flags.make
CMakeFiles/201808.dir/main.cpp.obj: CMakeFiles/201808.dir/includes_CXX.rsp
CMakeFiles/201808.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gladh\CLionProjects\201808\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/201808.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\201808.dir\main.cpp.obj -c C:\Users\gladh\CLionProjects\201808\main.cpp

CMakeFiles/201808.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/201808.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gladh\CLionProjects\201808\main.cpp > CMakeFiles\201808.dir\main.cpp.i

CMakeFiles/201808.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/201808.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gladh\CLionProjects\201808\main.cpp -o CMakeFiles\201808.dir\main.cpp.s

CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.obj: CMakeFiles/201808.dir/flags.make
CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.obj: CMakeFiles/201808.dir/includes_CXX.rsp
CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.obj: ../CodeforcesWorldFinals.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gladh\CLionProjects\201808\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\201808.dir\CodeforcesWorldFinals.cpp.obj -c C:\Users\gladh\CLionProjects\201808\CodeforcesWorldFinals.cpp

CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gladh\CLionProjects\201808\CodeforcesWorldFinals.cpp > CMakeFiles\201808.dir\CodeforcesWorldFinals.cpp.i

CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gladh\CLionProjects\201808\CodeforcesWorldFinals.cpp -o CMakeFiles\201808.dir\CodeforcesWorldFinals.cpp.s

# Object files for target 201808
201808_OBJECTS = \
"CMakeFiles/201808.dir/main.cpp.obj" \
"CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.obj"

# External object files for target 201808
201808_EXTERNAL_OBJECTS =

201808.exe: CMakeFiles/201808.dir/main.cpp.obj
201808.exe: CMakeFiles/201808.dir/CodeforcesWorldFinals.cpp.obj
201808.exe: CMakeFiles/201808.dir/build.make
201808.exe: CMakeFiles/201808.dir/linklibs.rsp
201808.exe: CMakeFiles/201808.dir/objects1.rsp
201808.exe: CMakeFiles/201808.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gladh\CLionProjects\201808\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 201808.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\201808.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/201808.dir/build: 201808.exe

.PHONY : CMakeFiles/201808.dir/build

CMakeFiles/201808.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\201808.dir\cmake_clean.cmake
.PHONY : CMakeFiles/201808.dir/clean

CMakeFiles/201808.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gladh\CLionProjects\201808 C:\Users\gladh\CLionProjects\201808 C:\Users\gladh\CLionProjects\201808\cmake-build-debug C:\Users\gladh\CLionProjects\201808\cmake-build-debug C:\Users\gladh\CLionProjects\201808\cmake-build-debug\CMakeFiles\201808.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/201808.dir/depend
