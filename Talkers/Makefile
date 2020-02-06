########################
### Talkers Makefile ###
########################

# This makefiles compile all available sources (cpp) starting fron this directory and
# including child directories recursively.
# All compiled objects are then assembled in a static library inside the `./build`
# folder.

# MARK: The Target

TARGETNAME := talkers
BUILDDIR := build/
TARGET := $(BUILDDIR)$(TARGETNAME)

# ###########
# MARK: Setup

SRCDIR := .
SRCEXT := cpp
LIBDIR := libs

UNAME_S := $(shell uname -s)

# #########################
# MARK: Find Sources

ifeq ($(OS),Windows_NT)
SOURCES := $(shell tree $(SRCDIR) -type f -name "**.$(SRCEXT)" -not -path "./$(LIBDIR)/*")
else
SOURCES := $(shell find $(SRCDIR) -type f -name "**.$(SRCEXT)" -not -path "./$(LIBDIR)/*")
endif

OBJECTS := $(SOURCES:.$(SRCEXT)=.o)

################
# MARK: - Cross-Plateform Build Settings

# Build Flags
GCCOPTIONS = -g -std=c++17 -Wall -pedantic

# Include Flags
INCFLAGS = -I/usr/local/include/

# Linker Flags
LDFLAGS = -L/usr/local/lib

# Libraries
LDLIBS = -lpb-common \
	 	 -lboost_system \
		 -lboost_program_options \
	 	 -lboost_regex

# #######################
# OS-Dependant Properties

# ifeq ($(OS),Windows_NT)

# MARK: - OS X Build Settings
ifeq ($(UNAME_S),Darwin)

CXX := clang++

INCFLAGS += 

LDFLAGS += -L/usr/local/lib/

LDLIBS += 

# MARK: - UNIX Build Settings
else

CXX := g++

INCFLAGS += -fsanitize=address

LDFLAGS += -std=c++17

LDLIBS += `pkg-config protobuf --libs` \
	  	  -lstdc++fs \
		  -fsanitize=address \
		  -lncurses


endif


CXXFLAGS := $(GCCOPTIONS) -I$(LIBDIR) -I. $(INCFLAGS) -DLOG_LEVEL=1 -DDEBUG=1 -DMACHINE_TALKER

# #######################
# MARK: - Build Sequence
#
# The makefile compiles the objects itself using the defaults CXX and CXXFLAGS.
# We only have to take care of the

$(TARGET): linker

$(info )
$(info ========================================)
$(info    $(TARGETNAME) Makefile )
$(info ========================================)
$(info )

# Link Everything
linker: $(OBJECTS)
	@echo "\n  Compiling ok!"; mkdir -p $(BUILDDIR)
	@echo "\n========================================"
	@echo "   LINKING $(TARGETNAME) on $(UNAME_S)"
	@echo "========================================\n"
	@echo " Working... "; 
	$(CXX) $^ -o $(TARGET) $(LDFLAGS) $(LDLIBS) 
	@echo " Done!\n"
	@echo "\n========================================"
	@echo "   $(TARGETNAME) successfully compiled!"
	@echo "   Type \"./$(TARGET)\" to launch $(TARGETNAME)"
	@echo "========================================\n"

# Remove objects
clean:
	@echo " Cleaning..."; $(RM) -r $(OBJECTS) $(TARGET) $(BUILDDIR)
	@echo " Done!\n"

.PHONY: clean

