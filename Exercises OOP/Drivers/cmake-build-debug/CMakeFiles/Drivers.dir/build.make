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
CMAKE_SOURCE_DIR = "C:\Users\PC\Desktop\Exercises OOP\Drivers"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\PC\Desktop\Exercises OOP\Drivers\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Drivers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Drivers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Drivers.dir/flags.make

CMakeFiles/Drivers.dir/main.c.obj: CMakeFiles/Drivers.dir/flags.make
CMakeFiles/Drivers.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\PC\Desktop\Exercises OOP\Drivers\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Drivers.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Drivers.dir\main.c.obj   -c "C:\Users\PC\Desktop\Exercises OOP\Drivers\main.c"

CMakeFiles/Drivers.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Drivers.dir/main.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\PC\Desktop\Exercises OOP\Drivers\main.c" > CMakeFiles\Drivers.dir\main.c.i

CMakeFiles/Drivers.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Drivers.dir/main.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\PC\Desktop\Exercises OOP\Drivers\main.c" -o CMakeFiles\Drivers.dir\main.c.s

CMakeFiles/Drivers.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Drivers.dir/main.c.obj.requires

CMakeFiles/Drivers.dir/main.c.obj.provides: CMakeFiles/Drivers.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Drivers.dir\build.make CMakeFiles/Drivers.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Drivers.dir/main.c.obj.provides

CMakeFiles/Drivers.dir/main.c.obj.provides.build: CMakeFiles/Drivers.dir/main.c.obj


# Object files for target Drivers
Drivers_OBJECTS = \
"CMakeFiles/Drivers.dir/main.c.obj"

# External object files for target Drivers
Drivers_EXTERNAL_OBJECTS =

Drivers.exe: CMakeFiles/Drivers.dir/main.c.obj
Drivers.exe: CMakeFiles/Drivers.dir/build.make
Drivers.exe: CMakeFiles/Drivers.dir/linklibs.rsp
Drivers.exe: CMakeFiles/Drivers.dir/objects1.rsp
Drivers.exe: CMakeFiles/Drivers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\PC\Desktop\Exercises OOP\Drivers\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Drivers.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Drivers.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Drivers.dir/build: Drivers.exe

.PHONY : CMakeFiles/Drivers.dir/build

CMakeFiles/Drivers.dir/requires: CMakeFiles/Drivers.dir/main.c.obj.requires

.PHONY : CMakeFiles/Drivers.dir/requires

CMakeFiles/Drivers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Drivers.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Drivers.dir/clean

CMakeFiles/Drivers.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\PC\Desktop\Exercises OOP\Drivers" "C:\Users\PC\Desktop\Exercises OOP\Drivers" "C:\Users\PC\Desktop\Exercises OOP\Drivers\cmake-build-debug" "C:\Users\PC\Desktop\Exercises OOP\Drivers\cmake-build-debug" "C:\Users\PC\Desktop\Exercises OOP\Drivers\cmake-build-debug\CMakeFiles\Drivers.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Drivers.dir/depend

