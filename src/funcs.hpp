/* funcs.h -- functions for dungeon */

#ifndef FUNCS_H
#define FUNCS_H

/* Try to guess whether we need "rb" to open files in binary mode.
 * If this is unix, it doesn't matter.  Otherwise, assume that if
 * __STDC__ is defined we can use "rb".  Otherwise, assume that we
 * had better use "r" or fopen will fail.
 */

#ifdef unix
#define BINREAD "r"
#define BINWRITE "w"
#else /* ! unix */
#ifdef __STDC__
#define BINREAD "rb"
#define BINWRITE "wb"
#else /* ! __STDC__ */
#define BINREAD "r"
#define BINWRITE "w"
#endif /* ! __STDC__ */
#endif /* ! unix */

#define abs(x) ((x) >= 0 ? (x) : -(x))
#define min(a,b) ((a) <= (b) ? (a) : (b))
#define max(a,b) ((a) >= (b) ? (a) : (b))

void
more_init(),
more_output(const char *),
more_input();

void
bug_(int, int),
cevapp_(int),
cpgoto_(int),
cpinfo_(int, int),
encryp_(const char *, char *),
exit_(),
fightd_(),
game_(),
gdt_(),
gttime_(int *),
invent_(int),
itime_(int *, int *, int *),
jigsup_(int),
newsta_(int, int, int, int, int),
orphan_(int, int, int, int, int),
princo_(int, int),
princr_(int, int),
rdline_(char *, int),
rspeak_(int n, int y = 0, int z = 0, int l = 1),
rstrgm_(),
savegm_(),
score_(int),
scrupd_(int),
swordd_(),
thiefd_(),
valuac_(int);
int
blow_(int, int, int, int, int),
fights_(int, int),
fwim_(int, int, int, int, int, int),
getobj_(int, int, int),
schlst_(int, int, int, int, int, int),
mrhere_(int),
oactor_(int),
rnd_(int),
robadv_(int, int, int, int),
robrm_(int, int, int, int, int),
sparse_(const int *, int, int),
vilstr_(int),
weight_(int, int, int);
int
aappli_(int),
ballop_(int),
clockd_(void),
cyclop_(int),
drop_(int),
findxt_(int, int),
ghere_(int, int),
lightp_(int),
lit_(int),
moveto_(int, int),
nobjs_(int, int),
oappli_(int, int),
objact_(void),
opncls_(int, int, int),
parse_(char *, int),
prob_(int, int),
put_(int),
rappli_(int),
rappl1_(int),
rappl2_(int),
rmdesc_(int),
sobjs_(int, int),
sverbs_(int),
synmch_(void),
take_(int),
thiefp_(int),
trollp_(int),
qempty_(int),
qhere_(int, int),
vappli_(int),
walk_(),
winnin_(int, int),
yesno_(int, int, int);
bool  init_(void);

#endif
