# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/ubuntu/Downloads/clion-2020.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ubuntu/Downloads/clion-2020.1.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ubuntu/Desktop/Caro/Client test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/main.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Client.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/main.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/main.c"

CMakeFiles/Client.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/main.c" > CMakeFiles/Client.dir/main.c.i

CMakeFiles/Client.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/main.c" -o CMakeFiles/Client.dir/main.c.s

CMakeFiles/Client.dir/exchange/src/clientHeper.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/exchange/src/clientHeper.c.o: ../exchange/src/clientHeper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Client.dir/exchange/src/clientHeper.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/exchange/src/clientHeper.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/exchange/src/clientHeper.c"

CMakeFiles/Client.dir/exchange/src/clientHeper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/exchange/src/clientHeper.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/exchange/src/clientHeper.c" > CMakeFiles/Client.dir/exchange/src/clientHeper.c.i

CMakeFiles/Client.dir/exchange/src/clientHeper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/exchange/src/clientHeper.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/exchange/src/clientHeper.c" -o CMakeFiles/Client.dir/exchange/src/clientHeper.c.s

CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.o: ../exchange/src/communicateWithServer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/exchange/src/communicateWithServer.c"

CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/exchange/src/communicateWithServer.c" > CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.i

CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/exchange/src/communicateWithServer.c" -o CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.s

CMakeFiles/Client.dir/exchange/src/handleClient.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/exchange/src/handleClient.c.o: ../exchange/src/handleClient.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Client.dir/exchange/src/handleClient.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/exchange/src/handleClient.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/exchange/src/handleClient.c"

CMakeFiles/Client.dir/exchange/src/handleClient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/exchange/src/handleClient.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/exchange/src/handleClient.c" > CMakeFiles/Client.dir/exchange/src/handleClient.c.i

CMakeFiles/Client.dir/exchange/src/handleClient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/exchange/src/handleClient.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/exchange/src/handleClient.c" -o CMakeFiles/Client.dir/exchange/src/handleClient.c.s

CMakeFiles/Client.dir/exchange/src/initClient.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/exchange/src/initClient.c.o: ../exchange/src/initClient.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Client.dir/exchange/src/initClient.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/exchange/src/initClient.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/exchange/src/initClient.c"

CMakeFiles/Client.dir/exchange/src/initClient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/exchange/src/initClient.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/exchange/src/initClient.c" > CMakeFiles/Client.dir/exchange/src/initClient.c.i

CMakeFiles/Client.dir/exchange/src/initClient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/exchange/src/initClient.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/exchange/src/initClient.c" -o CMakeFiles/Client.dir/exchange/src/initClient.c.s

CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.o: ../views/src/handleLogicAppScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicAppScreen.c"

CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicAppScreen.c" > CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.i

CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicAppScreen.c" -o CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.s

CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.o: ../views/src/handleLogicGameScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicGameScreen.c"

CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicGameScreen.c" > CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.i

CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicGameScreen.c" -o CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.s

CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.o: ../views/src/handleLogicHomeScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicHomeScreen.c"

CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicHomeScreen.c" > CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.i

CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicHomeScreen.c" -o CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.s

CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.o: ../views/src/handleLogicLoginScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicLoginScreen.c"

CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicLoginScreen.c" > CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.i

CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicLoginScreen.c" -o CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.s

CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.o: ../views/src/handleLogicMainScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicMainScreen.c"

CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicMainScreen.c" > CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.i

CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicMainScreen.c" -o CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.s

CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.o: ../views/src/handleLogicRegisterScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicRegisterScreen.c"

CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicRegisterScreen.c" > CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.i

CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/views/src/handleLogicRegisterScreen.c" -o CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.s

CMakeFiles/Client.dir/views/src/initScreen.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/views/src/initScreen.c.o: ../views/src/initScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/Client.dir/views/src/initScreen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/views/src/initScreen.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/views/src/initScreen.c"

CMakeFiles/Client.dir/views/src/initScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/views/src/initScreen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/views/src/initScreen.c" > CMakeFiles/Client.dir/views/src/initScreen.c.i

CMakeFiles/Client.dir/views/src/initScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/views/src/initScreen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/views/src/initScreen.c" -o CMakeFiles/Client.dir/views/src/initScreen.c.s

CMakeFiles/Client.dir/views/src/styleScreen.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/views/src/styleScreen.c.o: ../views/src/styleScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/Client.dir/views/src/styleScreen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/views/src/styleScreen.c.o   -c "/home/ubuntu/Desktop/Caro/Client test/views/src/styleScreen.c"

CMakeFiles/Client.dir/views/src/styleScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/views/src/styleScreen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ubuntu/Desktop/Caro/Client test/views/src/styleScreen.c" > CMakeFiles/Client.dir/views/src/styleScreen.c.i

CMakeFiles/Client.dir/views/src/styleScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/views/src/styleScreen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ubuntu/Desktop/Caro/Client test/views/src/styleScreen.c" -o CMakeFiles/Client.dir/views/src/styleScreen.c.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/main.c.o" \
"CMakeFiles/Client.dir/exchange/src/clientHeper.c.o" \
"CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.o" \
"CMakeFiles/Client.dir/exchange/src/handleClient.c.o" \
"CMakeFiles/Client.dir/exchange/src/initClient.c.o" \
"CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.o" \
"CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.o" \
"CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.o" \
"CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.o" \
"CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.o" \
"CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.o" \
"CMakeFiles/Client.dir/views/src/initScreen.c.o" \
"CMakeFiles/Client.dir/views/src/styleScreen.c.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/main.c.o
Client: CMakeFiles/Client.dir/exchange/src/clientHeper.c.o
Client: CMakeFiles/Client.dir/exchange/src/communicateWithServer.c.o
Client: CMakeFiles/Client.dir/exchange/src/handleClient.c.o
Client: CMakeFiles/Client.dir/exchange/src/initClient.c.o
Client: CMakeFiles/Client.dir/views/src/handleLogicAppScreen.c.o
Client: CMakeFiles/Client.dir/views/src/handleLogicGameScreen.c.o
Client: CMakeFiles/Client.dir/views/src/handleLogicHomeScreen.c.o
Client: CMakeFiles/Client.dir/views/src/handleLogicLoginScreen.c.o
Client: CMakeFiles/Client.dir/views/src/handleLogicMainScreen.c.o
Client: CMakeFiles/Client.dir/views/src/handleLogicRegisterScreen.c.o
Client: CMakeFiles/Client.dir/views/src/initScreen.c.o
Client: CMakeFiles/Client.dir/views/src/styleScreen.c.o
Client: CMakeFiles/Client.dir/build.make
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd "/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ubuntu/Desktop/Caro/Client test" "/home/ubuntu/Desktop/Caro/Client test" "/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug" "/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug" "/home/ubuntu/Desktop/Caro/Client test/cmake-build-debug/CMakeFiles/Client.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

