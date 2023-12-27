# Cpp Makefile Tutorial

## GCC/Clang Compiler Steps

### Compilation (Assembling)

- Checks the C/C++ language syntax for error
- Generates object files
- Command: g++ main.cc -c
- Produces: main.o

### Linker

- Linking all the source files together, that is all the other object codes in the project.
- Generates the executable file
- Command: g++ main.o -o main
- Produces: main.out (.exe for Windows)

### Compiler Flags

- Debug: ```-g```
- Release: ```-O0 -O1 -O2 -O3 -Og```
- Includes: ```-I```
- Warnings: ```-Wall -Wextra -Wpedantic -Wconversion```

## Makefile Commands of the Template

### Makefile Variables

Convention is naming in upper snake_case.

```make
  VARIABLE_NAME = Value
```

Variables can be called by $(VARIABLE_NAME)

```make
  $(VARIABLE_NAME)
```

### Makefile Targets

Convention is naming in snake_case or camelCase.

```make
  targetName: Dependecies
    Command
```

Targets can be called by the ```make``` command.

```bash
  make targetName
```

### Makefile Phony Target

Sometimes you want your Makefile to run commands that do not represent files, for example the "clean" target. You may potentially have a file named clean in your main directory. In such a case Make will be confused because by default the clean target would be associated with this file and Make will only run it when the file doesn't appear to be up-to-date.

```make
.PHONY: clean
clean:
  rm -rf *.o
```

In terms of Make, a phony target is simply a target that is always out-of-date, so whenever you ask make <phony_target>, it will run, independent from the state of the file system.

### Build the Executable

Create the executable in either Debug or Release mode.

```bash
  make build DEBUG=0 # Build type is debug
  make build DEBUG=1 # Build type is release
```

### Run the Executable

Run the executable in either Debug or Release mode.

```bash
  make execute DEBUG=0 # Build type is debug
  make execute DEBUG=1 # Build type is release
```

### Variables of the Makefile Template

- Debug Mode: 1 (True) or 0 (False)
- ENABLE_WARNINGS: 1 (True) or 0 (False)
- WARNINGS_AS_ERRORS: 1 (True) or 0 (False)
- CPP_STANDARD: c++11, c++14, c++17, etc.

### Important Shortcuts of the Makefile Template

- ```$@```: the file name of the target
- ```$<```: the name of the first dependency
- ```$^```: the names of all dependencies

# CPP_Practice
###############
## TARGETS   ##
###############
# target: prerequisites
#	commands

# The commands are a series of steps typically to make the target,
# 	need to start with a tab character, not space
# The prerequisites are file names, separated by spaces.
# 	These files need to exist before the commands for the target are run.

# Add @ before command if you dont want to see it in console output
# like @rm -f $(BUILD_DIR)/*.o now it will not show command while running it in console

# The Command which need to run together like going folder first and then create file should write like this
# cd build && mkdir -p test
# As all command written under target run parallely in seperate command line

###############
## 	VARIABLE ##
###############
INCLUDE_DIR = include
BUILD_DIR = build
SOURCE_DIR = src
CXX_STANDARD = c++17
CXX_WARNINGS = -Wall -Wextra -Wpedantic
EXECUTABLE_NAME = main
CXX = g++
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STANDARD)
CPPFLAGS = -I $(INCLUDE_DIR)

COMPILER_CALL = $(CXX) $(CXXFLAGS) $(CPPFLAGS)
CXX_SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)      						  		   #Combine all .cpp file 
CXX_OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CXX_SOURCES))    #Combine all object file

build: $(CXX_OBJECTS)
	$(COMPILER_CALL) $(CXX_OBJECTS) -o $(BUILD_DIR)/$(EXECUTABLE_NAME)
##############
## PATTERNS ##
##############
# $@: the file name of the target
# $<: the name of the first dependency
# $^: the names of all prerequisites
# Generalize call to create object files for all .cpp file present 
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(COMPILER_CALL) -c $< -o $@

# main.o:
#	$(COMPILER_CALL) main.cpp -c
# sum.o:
#	$(COMPILER_CALL) sum.cpp -c

run: build
	./$(BUILD_DIR)/$(EXECUTABLE_NAME)
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/$(EXECUTABLE_NAME)
    