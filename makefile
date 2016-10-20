####
#### Generic Makefile for C or C++ projects
####
#### This file is public domain.
#### Jamie Bullock 2014 <jamie@jamiebullock.com>
####

###################################
### User configurable variables ###
###################################

CXX = g++

#### It is best not to modify this file
#### Instead override these variables in a separate Make.config file if needed

# The name of the product to build (default uses parent directory name)
NAME ?= nes
# The file suffix of source files, can be .c or .cpp
SUFFIX ?= .cpp
# List of directories containing source files to be compiled
DIRS ?= src
# Flags to pass to the compiler for release builds
FLAGS ?= -O3 -Wall
# Flags to pass to the compiler for debug builds
DEBUG_FLAGS ?= -O0 -g -Wall
# Flags to pass to the linker
LDFLAGS ?=

##############################################
### Do not modify anything below this line ###
##############################################

OUT_DIR := build
SRC := $(foreach dir, $(DIRS), $(wildcard $(dir)/*$(SUFFIX)))
OBJ_ := $(SRC:$(SUFFIX)=.o)
OBJ := $(addprefix $(OUT_DIR)/,$(OBJ_))
DEPS := $(OBJ:.o=.d)
OUT = $(NAME)

COMPILER := $(CXX)

.SUFFIXES:
.PHONY: debug release clean

$(OUT): $(OBJ)
	@$(COMPILER) $^ $(LDFLAGS) -o $@

debug: FLAGS = $(DEBUG_FLAGS)
debug: $(OUT)

release: $(OUT)

$(OUT_DIR)/%.o: %$(SUFFIX)
	@mkdir -p $(dir $@)
	@$(COMPILER) $(CXXFLAGS) $(FLAGS) -MMD -MP -fPIC -c $< -o $@

clean:
	@$(RM) -r $(OUT) $(OUT_DIR)

-include: $(DEPS)
