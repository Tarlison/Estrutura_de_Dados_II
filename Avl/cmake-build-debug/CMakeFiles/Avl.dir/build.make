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
CMAKE_COMMAND = /snap/clion/69/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/69/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Avl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Avl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Avl.dir/flags.make

CMakeFiles/Avl.dir/main.cpp.o: CMakeFiles/Avl.dir/flags.make
CMakeFiles/Avl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Avl.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Avl.dir/main.cpp.o -c "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/main.cpp"

CMakeFiles/Avl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Avl.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/main.cpp" > CMakeFiles/Avl.dir/main.cpp.i

CMakeFiles/Avl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Avl.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/main.cpp" -o CMakeFiles/Avl.dir/main.cpp.s

CMakeFiles/Avl.dir/Avl.cpp.o: CMakeFiles/Avl.dir/flags.make
CMakeFiles/Avl.dir/Avl.cpp.o: ../Avl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Avl.dir/Avl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Avl.dir/Avl.cpp.o -c "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/Avl.cpp"

CMakeFiles/Avl.dir/Avl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Avl.dir/Avl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/Avl.cpp" > CMakeFiles/Avl.dir/Avl.cpp.i

CMakeFiles/Avl.dir/Avl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Avl.dir/Avl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/Avl.cpp" -o CMakeFiles/Avl.dir/Avl.cpp.s

# Object files for target Avl
Avl_OBJECTS = \
"CMakeFiles/Avl.dir/main.cpp.o" \
"CMakeFiles/Avl.dir/Avl.cpp.o"

# External object files for target Avl
Avl_EXTERNAL_OBJECTS =

Avl: CMakeFiles/Avl.dir/main.cpp.o
Avl: CMakeFiles/Avl.dir/Avl.cpp.o
Avl: CMakeFiles/Avl.dir/build.make
Avl: CMakeFiles/Avl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Avl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Avl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Avl.dir/build: Avl

.PHONY : CMakeFiles/Avl.dir/build

CMakeFiles/Avl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Avl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Avl.dir/clean

CMakeFiles/Avl.dir/depend:
	cd "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl" "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl" "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/cmake-build-debug" "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/cmake-build-debug" "/home/tarlison/Documentos/UFRR/4 Semestre/Estrutura de Dados II/Estrutura_de_Dados_II/Avl/cmake-build-debug/CMakeFiles/Avl.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Avl.dir/depend

