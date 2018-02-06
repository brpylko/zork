# Makefile for dungeon
# Where to install the program
BINDIR = /usr/games

# Where to install the data file
DATADIR = /usr/games/lib

# Where to install the man page
MANDIR = /usr/share/man

# The dungeon program provides a ``more'' facility which tries to
# figure out how many rows the terminal has.  Several mechanisms are
# supported for determining this; the most common one has been left
# uncommented.  If you have trouble, especially when linking, you may
# have to select a different option.

# more option 1: use the termcap routines.  On some systems the LIBS
# variable may need to be set to -lcurses.  On some it may need to
# be /usr/lib/termcap.o.  These options are commented out below.
#LIBS = -ltermcap
#TERMFLAG =
# LIBS = -lcurses
# LIBS = /usr/lib/termcap.o

# more option 2: use the terminfo routines.  On some systems the LIBS
# variable needs to be -lcursesX, but probably all such systems support
# the termcap routines (option 1) anyhow.
LIBS = -lcurses
TERMFLAG = -DMORE_TERMINFO

# more option 3: assume all terminals have 24 rows
# LIBS =
# TERMFLAG = -DMORE_24

# more option 4: don't use the more facility at all
# LIBS =
# TERMFLAG = -DMORE_NONE

# End of more options

# Uncomment the following line if you want to have access to the game
# debugging tool.  This is invoked by typing "gdt".  It is not much
# use except for debugging.
GDTFLAG = -DALLOW_GDT

# Compilation flags
CXXFLAGS = -g $(GDTFLAG) -DTEXTFILE=\"$(DATADIR)/dtextc.dat\" #-static
# On SCO Unix Development System 3.2.2a, the const type qualifier does
# not work correctly when using cc.  The following line will cause it
# to not be used and should be uncommented.
# CFLAGS= -O -Dconst=

##################################################################

CXX = g++

SOURCES = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.hpp)
OBJECTS = $(patsubst src/%.cpp,src/%.o,$(wildcard src/*.cpp))

default: dungeon

install: bin/zork dtextc.dat
	mkdir -p $(BINDIR) $(LIBDIR) $(MANDIR)/man6
	cp bin/zork $(BINDIR)
	cp dtextc.dat $(DATADIR)
	cp dungeon.6 $(MANDIR)/man6/

clean:
	rm -f $(OBJECTS) bin/zork core dsave.dat src/*~

dtextc.dat:
	cat dtextc.uu1 dtextc.uu2 dtextc.uu3 dtextc.uu4 | uudecode

dungeon: $(OBJECTS) dtextc.dat
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/zork $(OBJECTS) $(LIBS)
