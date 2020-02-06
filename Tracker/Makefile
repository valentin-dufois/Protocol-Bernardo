#############################################
### Protocol Bernardo Tracker Makefile ###
#############################################

# This makefiles compile all available sources (cpp) starting fron this directory and
# including child directories recursively.
# All compiled objects are then assembled in a static library inside the `./build`
# folder.

# MARK: The Target

TARGETNAME := pb-tracker
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
         -lOpenNI2 \
		 -lNiTE2


# #######################
# OS-Dependant Properties

# ifeq ($(OS),Windows_NT)

# MARK: - OS X Build Settings
ifeq ($(UNAME_S),Darwin)

CXX := clang++

INCFLAGS += -I/usr/local/include/ni2/ \

LDFLAGS += -L/usr/local/lib/

LDLIBS += -lopencv_core \
	  -lopencv_highgui \
	  -lopencv_imgproc \
	  -lncursesw \
	  -lOpenNI2


# MARK: - UNIX Build Settings
else

CXX := g++

INCFLAGS += `pkg-config libopenni2 --cflags` \

LDFLAGS += -std=c++17

LDLIBS += `pkg-config libopenni2 --libs` \
	  `pkg-config protobuf --libs` \
	  -lstdc++fs \
	  -lncurses 

endif


CXXFLAGS := $(GCCOPTIONS) -I$(LIBDIR) -I. $(INCFLAGS)  -DPB_TRACKER -DDEBUG -DLOG_LEVEL=1

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
	@echo " Copying Files 1/2"; cp -R "libs/NiTE2" "$(BUILDDIR)"
#	@echo " Copying Files 2/2\n"; cp -R "../libs/OpenNI2/." "$(BUILDDIR)"
	@echo "\n========================================"
	@echo "   $(TARGETNAME) successfully compiled!"
	@echo "   Type \"./$(TARGET)\" to launch $(TARGETNAME)"
	@echo "========================================\n"

# Remove objects
clean:
	@echo " Cleaning..."; $(RM) -r $(OBJECTS) $(TARGET) $(BUILDDIR)
	@echo " Done!\n"

.PHONY: clean

