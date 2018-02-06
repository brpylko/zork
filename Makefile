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
CFLAGS = -g #-static
# On SCO Unix Development System 3.2.2a, the const type qualifier does
# not work correctly when using cc.  The following line will cause it
# to not be used and should be uncommented.
# CFLAGS= -O -Dconst=

##################################################################

CPP = g++

# Source files
CSRC =	actors.cpp ballop.cpp clockr.cpp demons.cpp dgame.cpp dinit.cpp dmain.cpp\
	dso1.cpp dso2.cpp dso3.cpp dso4.cpp dso5.cpp dso6.cpp dso7.cpp dsub.cpp dverb1.cpp\
	dverb2.cpp gdt.cpp lightp.cpp local.cpp nobjs.cpp np.cpp np1.cpp np2.cpp np3.cpp\
	nrooms.cpp objcts.cpp rooms.cpp sobjs.cpp supp.cpp sverbs.cpp verbs.cpp villns.cpp vars.cpp parse.cpp

# Object files
OBJS =	actors.o ballop.o clockr.o demons.o dgame.o dinit.o dmain.o\
	dso1.o dso2.o dso3.o dso4.o dso5.o dso6.o dso7.o dsub.o dverb1.o\
	dverb2.o gdt.o lightp.o local.o nobjs.o np.o np1.o np2.o np3.o\
	nrooms.o objcts.o rooms.o sobjs.o supp.o sverbs.o verbs.o villns.o vars.o parse.o

default: dungeon

install: zork dtextc.dat
	mkdir -p $(BINDIR) $(LIBDIR) $(MANDIR)/man6
	cp zork $(BINDIR)
	cp dtextc.dat $(DATADIR)
	cp dungeon.6 $(MANDIR)/man6/

clean:
	rm -f $(OBJS) zork core dsave.dat *~

dtextc.dat:
	cat dtextc.uu1 dtextc.uu2 dtextc.uu3 dtextc.uu4 | uudecode

%.o: %.cpp funcs.h vars.h
	$(CPP) $(CFLAGS) $(GDTFLAG) -DTEXTFILE=\"$(DATADIR)/dtextc.dat\" -c $< -o $@

dungeon: $(OBJS) dtextc.dat
	$(CPP) $(CFLAGS) -o zork $(OBJS) $(LIBS)
