# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "F:\Program Files\JetBrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "F:\Program Files\JetBrains\CLion 2017.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\PC\Desktop\Exercises OOP\Zichara"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\PC\Desktop\Exercises OOP\Zichara\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Zichara.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Zichara.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Zichara.dir/flags.make

CMakeFiles/Zichara.dir/main.cpp.obj: CMakeFiles/Zichara.dir/flags.make
CMakeFiles/Zichara.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\PC\Desktop\Exercises OOP\Zichara\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Zichara.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Zichara.dir\main.cpp.obj -c "C:\Users\PC\Desktop\Exercises OOP\Zichara\main.cpp"

CMakeFiles/Zichara.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Zichara.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\PC\Desktop\Exercises OOP\Zichara\main.cpp" > CMakeFiles\Zichara.dir\main.cpp.i

CMakeFiles/Zichara.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Zichara.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\PC\Desktop\Exercises OOP\Zichara\main.cpp" -o CMakeFiles\Zichara.dir\main.cpp.s

CMakeFiles/Zichara.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Zichara.dir/main.cpp.obj.requires

CMakeFiles/Zichara.dir/main.cpp.obj.provides: CMakeFiles/Zichara.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Zichara.dir\build.make CMakeFiles/Zichara.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Zichara.dir/main.cpp.obj.provides

CMakeFiles/Zichara.dir/main.cpp.obj.provides.build: CMakeFiles/Zichara.dir/main.cpp.obj


# Object files for target Zichara
Zichara_OBJECTS = \
"CMakeFiles/Zichara.dir/main.cpp.obj"

# External object files for target Zichara
Zichara_EXTERNAL_OBJECTS =

Zichara.exe: CMakeFiles/Zichara.dir/main.cpp.obj
Zichara.exe: CMakeFiles/Zichara.dir/build.make
Zichara.exe: CMakeFiles/Zichara.dir/linklibs.rsp
Zichara.exe: CMakeFiles/Zichara.dir/objects1.rsp
Zichara.exe: CMakeFiles/Zichara.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\PC\Desktop\Exercises OOP\Zichara\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Zichara.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Zichara.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Zichara.dir/build: Zichara.exe

.PHONY : CMakeFiles/Zichara.dir/build

CMakeFiles/Zichara.dir/requires: CMakeFiles/Zichara.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Zichara.dir/requires

CMakeFiles/Zichara.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Zichara.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Zichara.dir/clean

CMakeFiles/Zichara.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\PC\Desktop\Exercises OOP\Zichara" "C:\Users\PC\Desktop\Exercises OOP\Zichara" "C:\Users\PC\Desktop\Exercises OOP\Zichara\cmake-build-debug" "C:\Users\PC\Desktop\Exercises OOP\Zichara\cmake-build-debug" "C:\Users\PC\Desktop\Exercises OOP\Zichara\cmake-build-debug\CMakeFiles\Zichara.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Zichara.dir/depend

