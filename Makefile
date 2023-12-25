###############
## TARGETS   ##
###############
# target: prerequisites
#	commands

# The commands are a series of steps typically to make the target,
# 	need to start with a tab character, not space
# The prerequisites are file names, separated by spaces.
# 	These files need to exist before the commands for the target are run.

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

#main.o:
#	$(COMPILER_CALL) main.cpp -c
#sum.o:
#	$(COMPILER_CALL) sum.cpp -c

run: build
	./$(BUILD_DIR)/$(EXECUTABLE_NAME)
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/$(EXECUTABLE_NAME)