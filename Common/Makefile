#################################################
### Protocol Bernardo Common Library Makefile ###
#################################################

# This makefiles compile all available sources (cpp) starting fron this directory and
# including child directories recursively.
# All compiled objects are then assembled in a dynamic library inside the `./build`
# folder. 

# MARK: The Target

ifeq ($(UNAME_S),Darwin)
ARCHIVEEXTENSION := .dylib
else
ARCHIVEEEXTENSION := .so
endif

TARGETNAME := libpb-common$(ARCHIVEEEXTENSION)
BUILDDIR := build/
TARGET := $(BUILDDIR)$(TARGETNAME)

INSTALLDIR := /usr/local/lib/

# ###########
# MARK: Setup

CXX := g++
SRCDIR := .
SRCEXT := cpp
SRCEXTALT := cc

UNAME_S := $(shell uname -s)

# #########################
# MARK: Find Sources

ifeq ($(OS),Windows_NT)
SOURCES := $(shell tree $(SRCDIR) -type f -name "**.$(SRCEXT)" -not -path "./$(LIBDIR)/*")
else
SOURCES := $(shell find $(SRCDIR) -type f -name "**.$(SRCEXT)" -o -name "**.cc" -not -path "./$(LIBDIR)/*")
endif

OBJECTS := $(SOURCES:.$(SRCEXT)=.o)
OBJECTS := $(OBJECTS:.cc=.o)


# Protos
PROTOSRCDIR := ./Messages/protos
PROTOEXT := proto
PROTOOUTDIR := ./Messages/cpp/

PROTOS := $(shell find $(PROTOSSRCDIR) -type f -name "**.$(PROTOSEXT)")
PROTOSCC := $(SOURCES:.$(PROTOS)=.cc)

################
# MARK: - Cross-Plateform Build Settings

# Build Flags
GCCOPTIONS = -g -std=c++17 -Wall -pedantic -O2 -fPIC

# Include Flags
INCFLAGS = -I/usr/local/include/

# Linker Flags
LDFLAGS = -shared -L/usr/local/lib

# Libraries
LDLIBS =


# #######################
# OS-Dependant Properties

# ifeq ($(OS),Windows_NT)

# MARK: - OS X Build Settings
ifeq ($(UNAME_S),Darwin)

INCFLAGS += -I/usr/local/include
LDFLAGS +=
LDLIBS +=

# MARK: - UNIX Build Settings
else

INCFLAGS +=
LDFLAGS +=
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

# Build protoc messages

# Link Everything
linker: protos $(OBJECTS)
	@echo "\n  Compiling ok!"; mkdir -p $(BUILDDIR)
	@echo "\n========================================"
	@echo "   ARCHIVING"
	@echo "========================================\n"
	@echo " Working... "; 
	$(CXX) -shared $(LDFLAGS) -Wl,-rpath /usr/local/lib -o $(TARGET) $(OBJECTS)
# 	@echo "  Cleaning objects..."
# 	@$(RM) -r $(OBJECTS)
	@echo "\n========================================"
	@echo "   $(TARGETNAME) successfully compiled!"
	@echo "   Type \"./$(TARGET)\" to launch $(TARGETNAME)"
	@echo "========================================\n"

protos:
	protoc --cpp_out=./Messages/cpp --proto_path=./Messages/protos/ ./Messages/protos/*
#	$(OBJECTS) += $(shell find ./Messages/cpp/ -type f -name "**.$(cc)")



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
