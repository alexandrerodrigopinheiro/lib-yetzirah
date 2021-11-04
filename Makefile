####### Platform specifics

PLATFORM_OS		:= $(shell uname)
PLATFORM_ARCH	:= $(shell getconf LONG_BIT)

####### Compiler, tools and options

DEL_FILE		= rm -f
CHKDIR			= test -d
MKDIR			= mkdir -p
COPY			= cp -f
COPY_DIR		= cp -f -R
DEL_DIR			= rmdir
MOVE			= mv -f
STRIP			= strip

####### Flags

CC				= gcc
GXX			    = g++
CFLAGS			= -pipe -Wall -Wextra -pedantic -fmessage-length=0 -std=c99 $(DEFINES)
CXXFLAGS		= -pipe -Wall -Wextra -pedantic -fmessage-length=0 -std=c++11 $(DEFINES)
DEFINES			= -D_BSD_SOURCE -D_GNU_SOURCE

####### Files

TARGET        = build/app
DIR_BUILD     = build
DIR_SRC       = sources
DIR_INC       = headers

SOURCES       = $(wildcard $(DIR_SRC)/*/*.cpp)
HEADERS       = $(wildcard $(DIR_INC)/*/*.h)
OBJECTS       = $(patsubst $(DIR_SRC)/%.cpp,$(DIR_BUILD)/%.o,$(wildcard $(DIR_SRC)/*/*.cpp))

ifeq ($(PLATFORM_ARCH), 32)
INCS			= -I./headers/ -I/usr/include/ -I/usr/include/GL/ -I/usr/include/SDL2/ -fabi-version=2 -fno-omit-frame-pointer -I/usr/include/mysql
LIBS			= -L/usr/lib/ -L/usr/lib/i386-linux-gnu/ -lGL -lGLEW -lSDL2-2.0 -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_net -lSDL2_ttf -lcrypto -lssl -lblkid -lmysqlclient -lpthread -lz -m32
endif
ifeq ($(PLATFORM_ARCH), 64)
INCS			= -I./headers/ -I/usr/include/ -I/usr/include/GL/ -I/usr/include/SDL2/ -fabi-version=2 -fno-omit-frame-pointer -I/usr/include/mysql
LIBS			= -L/usr/lib/ -L/usr/lib/x86_64-linux-gnu/ -lGL -lGLEW -lSDL2-2.0 -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_net -lSDL2_ttf -lcrypto -lssl -lblkid -lmysqlclient -lpthread -lz -m64
endif

####### Build rules

.PHONY: all clean upload

upload:
	@echo Update...
	@git add Makefile headers/ sources/ extras/; git commit -m "Compile and update"; git push origin master
	@echo Done.

all: $(OBJECTS)
	@echo Done.

clean:
	@$(DEL_FILE) build/*/*
	@echo Clean.

####### Compile

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.cpp $(DIR_INC)/%.h
	@$(CHKDIR) $(DIR_BUILD) | $(MKDIR) $(DIR_BUILD)
	@$(CHKDIR) $(dir $@) | $(MKDIR) $(dir $@)
	@$(GXX) $(CXXFLAGS) -c $< -o $@ $(INCS) $(LIBS)
	@echo Done $@