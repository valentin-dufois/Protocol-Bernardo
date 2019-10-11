############################################
### PB-Common Makefile ###
############################################

# THIS MAKEFILE IS FOR BUILDING STATIC LIBRARIES

# This makefiles compile all available sources (cpp) starting fron this directory and
# including child directories recursively.
# All compiled objects are then assembled in a **static library** inside the `./build`
# folder. 

# MARK: The Target

ifeq ($(UNAME_S),Darwin)
ARCHIVEEXTENSION := .a
else
ARCHIVEEEXTENSION := .so
endif

TARGETNAME := libPB-Common$(ARCHIVEEEXTENSION)     # <-- Set Product Name here
BUILDDIR := build/
TARGET := $(BUILDDIR)$(TARGETNAME)

INSTALLDIR := /usr/local/lib/					   # <-- Set Install Directory Here

# ###########
# MARK: Setup

CXX := clang++
SRCDIR := .
SRCEXT := cpp

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
GCCOPTIONS = -g -std=c++11 -Wall -pedantic -O2 -pipe -fno-common -fno-strict-aliasing

# Include Flags
INCFLAGS = -I/usr/local/include/ \
		   -I/usr/include/eigen3/

# Linker Flags
LDFLAGS =

# Libraries
LDLIBS =


# #######################
# OS-Dependant Properties

# ifeq ($(OS),Windows_NT)

# MARK: - OS X Build Settings
ifeq ($(UNAME_S),Darwin)

INCFLAGS += -I/usr/local/include/ni2/ \
			-I/usr/local/include/opencv4
LDFLAGS +=
LDLIBS +=

# MARK: - UNIX Build Settings
else

INCFLAGS += `pkg-config opencv --cflags` \
			`pkg-config libopenni2 --cflags` \
LDFLAGS += `pkg-config opencv --libs` \
		   `pkg-config libopenni2 --libs`
LDLIBS +=

endif

CXXFLAGS := $(GCCOPTIONS) -I. $(INCFLAGS)

# #######################
# MARK: - Build Sequence

$(TARGET): linker

$(info )
$(info ========================================)
$(info    COMPILING $(TARGETNAME) on $(UNAME_S))
$(info ========================================)
$(info )

# Link Everything
linker: $(OBJECTS)
	@echo "\n  Compiling ok!"; mkdir -p $(BUILDDIR)
	@echo "\n========================================"
	@echo "   ARCHIVING"
	@echo "========================================\n"
	@echo " Working... "; ar rcs $(TARGET) $^
# 	@echo "  Cleaning objects..."
# 	@$(RM) -r $(OBJECTS)
	@echo "\n========================================"
	@echo "   $(TARGETNAME) successfully compiled!"
	@echo "   Type \"./$(TARGET)\" to launch $(TARGETNAME)"
	@echo "========================================\n"

# Remove objects
clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(OBJECTS) $(TARGET)"; $(RM) -r $(OBJECTS) $(TARGET)

install: linker
	@echo "\n========================================"
	@echo "   INSTALLING $(TARGETNAME) TO $(INSTALLDIR)"
	@echo "========================================\n"
	@echo "..."; cp $(TARGET) $(INSTALLDIR)$(TARGETNAME)

.PHONY: clean
.PHONY: install
