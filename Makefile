#-
# ==========================================================================
# Copyright 1995,2006,2008 Autodesk, Inc. All rights reserved.
#
# Use of this software is subject to the terms of the Autodesk
# license agreement provided at the time of installation or download,
# or which otherwise accompanies this software in either electronic
# or hard copy form.
# ==========================================================================
#+

# NOTE: MAYA_LOCATION on Mac OS X points to Maya.app/Contents
export MAYA_LOCATION=/Applications/Autodesk/maya2011/Maya.app/Contents
export DYLD_LIBRARY_PATH=$MAYA_LOCATION/MacOS
export DYLD_FRAMEWORK_PATH=$MAYA_LOCATION/Frameworks

# Change location if you have a non standard install.
DEVKIT_LOCATION = $(MAYA_LOCATION)/../../devkit

# Make sure this is in your path.
C++			= g++-4.0

# By default, we will try to build a universal binary to match the same
# architectures as the installed Maya binary. If you only want one specific
# architecture (e.g i386 or x86_64) then set it below.


PREFERRED_ARCHITECTURE	=


# Determine the architectures to build.
MAYABIN = ${MAYA_LOCATION}/bin/maya
MAYA_ARCHES = $(shell lipo -info $(MAYABIN) | sed 's/^.*://')

ifneq ($(PREFERRED_ARCHITECTURE),)
	MAYA_ARCHES = $(filter $(PREFERRED_ARCHITECTURE),$(MAYA_ARCHES))

	ifeq ($(MAYA_ARCHES),)
		$(error $(MAYABIN) does not support the '$(PREFERRED_ARCHITECTURE)' architecture.)
	endif
endif

ARCH_FLAGS = $(patsubst %,-arch %,$(MAYA_ARCHES))
CFLAGS	= -dynamiclib -DAW_NEW_IOSTREAMS -DCC_GNU_ -DOSMac_ -DOSMacOSX_ \
		-DOSMac_MachO_ -DREQUIRE_IOSTREAM -fno-gnu-keywords -fpascal-strings -O3 \
		$(ARCH_FLAGS) -D_LANGUAGE_C_PLUS_PLUS -isysroot /Developer/SDKs/MacOSX10.5.sdk \
C++FLAGS	= $(CFLAGS)
INCLUDES	= -I. -I$(MAYA_LOCATION)/../../devkit/include -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/JavaVM.framework/Versions/1.6.0/Headers -I$(MAYA_LOCATION)/../../devkit/include/maya
LD		= $(MAYA_LOCATION)/../../devkit/bin/mayald MAYA_ARCHES="$(MAYA_ARCHES)" MAYA_LOCATION="$(MAYA_LOCATION)"


#OUTPUTDIR 	= ./bin/
#DEP		= mayaSpiegel*.o
#
#Sources=mayaSpiegel.cpp
#DynamicLibrary=libMayaSpiegel.dylib

#srcDir=src/
#binDir=bin/
#objDir=obj/

#Objects=$(Sources:.cpp=.o)

#Includes=$(addprefix -I,$(INCLUDES))
#CSources=$(addprefix $(srcDir),$(Sources))
#CObjects=$(addprefix $(objDir),$(Objects))
#CLibrary=$(addprefix $(binDir),$(DynamicLibrary))

#TARGET= $(CLibrary) $(CSources)

app = libMayaSpiegel.dylib

srcExt = cpp
srcDir = src
objDir = obj
binDir = bin
inc    = inc

debug = 1

ifeq ($(degug),1)
	debug=-g
else
	debug=
endif

RM = rm

sources := $(shell find $(srcDir) -name '*.$(srcExt)')
srcDirs := $(shell find . -name '*.$(srcExt)' -exec dirname {} \; | uniq)
objects := $(patsubst %.$(srcExt),$(objDir)/%.o,$(sources))

.phony: all clean distclean

all: $(binDir)/$(app)

$(binDir)/$(app): buildrepo $(objects)
	@mkdir -p 'dirname $@'
	@echo "Linking $@..."
	@$(LD) -lOpenMayaFX -dynamiclib $(objects) -o $@

$(objDir)/%.o: %.$(srcExt)
	@echo "Generating dependencies for $<..."
	@$(call make-depend,$<,$@,$(subst .o,.d,$@))
	@echo "Compiling $<..."
	@$(C++) -c $(C++FLAGS) $(INCLUDES) $<

clean:
	$(RM) -r $(objDir)

distclean: clean
	$(RM) -r $(binDir)/$(app)

buildrepo:
	@$(call make-repo)

define make-repo
	for dir in $(srcDirs);  \
	do\
		mkdir -p $(objDir)/$$dir;\
	done
endef

define make-depend
	$(C++) -MM	 \
		-MF $3	 \
		-MP 	 \
		-MT $2	 \
		$(C++FLAGS) \
		$(INCLUDES) \
		$1

endef

##.SUFFIXES: .cpp .cc .o .c

##.cc.o:
#	$(C++) -c $(C++FLAGS) $(INCLUDES) $<

#.cpp.o:
#	$(C++) -c $(C++FLAGS) $(INCLUDES) $<

#all: $(TARGET)

#$(CLibrary): $(CObjects)  
#	echo $(CObjects)
#	$(LD) -lOpenMayaFX -dynamiclib $(CObjects) -o $@ 

#$(objDir)%.o: $(srcDir)%.cpp
#	$(C++) -c $(C++FLAGS) $(INCLUDES) $< 

#clean:
#	rm -f $(CObjects) 

#Clean:
#	rm -f $(TARGETS) *.o *.bak 