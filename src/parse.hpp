/* parse.h -- header file for parsing structures used by dungeon */

/* These structures are only used by the parsing routines.  They are in
 * their own file since they are so large.
 */

#ifndef PARSE_H
#define PARSE_H

extern struct pv_t {
	int act, o1, o2, p1, p2;
} pv_;

#define pv_1 pv_
#define pvec ((int *)&pv_1)
#define objvec ((int *)&pv_1 + 1)
#define prpvec ((int *)&pv_1 + 3)

extern struct syntax_t {
	int vflag, dobj, dfl1, dfl2, dfw1, dfw2, iobj, ifl1, ifl2, ifw1, ifw2;

} syntax_;

#define syntax_1 syntax_
#define syn ((int *)&syntax_1)

/* Object flags (objflg) */

#define VABIT (16384)
#define VRBIT (8192)
#define VTBIT (4096)
#define VCBIT (2048)
#define VEBIT (1024)
#define VFBIT (512)
#define VPMASK (511)

/* Syntax flags (synflg) */

#define SDIR (16384)
#define SIND (8192)
#define SSTD (4096)
#define SFLIP (2048)
#define SDRIV (1024)
#define SVMASK (511)

/* BUZZ WORDS--	IGNORED IN SYNTACTIC PROCESSING */

extern const struct buzvoc_t {
	int bvoc[20];
} buzvoc_;

#define buzvoc_1 buzvoc_

/* PREPOSITIONS--	MAPS PREPOSITIONS TO INDICES */

extern const struct prpvoc_t {
	int pvoc[45];
} prpvoc_;

#define prpvoc_1 prpvoc_

/* DIRECTIONS--	MAPS DIRECTIONS TO INDICES */

extern const struct dirvoc_t {
	int dvoc[75];
} dirvoc_;

#define dirvoc_1 dirvoc_

/* ADJECTIVES--	MAPS ADJECTIVES TO OBJECT NUMBERS */

/* EACH ENTRY IS VARIABLE LENGTH AND CONSISTS OF A TWO WORD */
/* ADJECTIVE IN RADIX-50 FOLLOWED BY ONE OR MORE OBJECT NUMBERS. */
/* NOTE THAT ADJECTIVES CAN BE DISTINGUISHED FROM OBJECTS AS */
/* FOLLOWS-- ALL ADJECTIVES ARE .GE. 1RA (1600), WHILE ALL OBJECTS */
/* ARE .LE. OLNT (255 MAX). */

extern const int avoc[];

/* VERBS--	MAPS VERBS TO SYNTAX SLOTS */

/* EACH ENTRY IS VARIABLE LENGTH AND CONSISTS OF ONE OR MORE */
/* TWO WORD VERBS IN RADIX-50 FOLLOWED BY A SYNTAX WORD COUNT */
/* FOLLOWED BY ONE OR MORE SYNTAXES.  NOTE THAT VERBS CAN BE */
/* DISTINGUISHED FROM WORD COUNTS AS FOLLOWS-- */
/* ALL VERBS ARE .GE. 1RA (1600), WHILE ALL SYNTAX WORD COUNTS */
/* ARE .LE. 255. */

/* SYNTAX ENTRIES CONSIST OF A FLAG WORD FOLLOWED BY 0, 1, OR 2 */
/* OBJECT DESCRIPTIONS.  THE FLAG WORD HAS THE FOLLOWING FORMAT-- */

/* BIT <14>	IF 1, SYNTAX INCLUDES DIRECT OBJECT */
/* BIT <13>	IF 1, SYNTAX INCLUDES INDIRECT OBJECT */
/* BIT <12>	IF 1, DIRECT OBJECT IS IMPLICIT (STANDARD FORM) */
/* BIT <11>	IF 1, DIRECT AND INDIRECT OBJECT MUST BE SWAPPED */
/* 			AFTER SYNTAX PROCESSING */
/* BIT <10>	IF 1, THIS IS DEFAULT SYNTAX FOR ORPHANERY */
/* BITS <8:0>	VERB NUMBER FOR VAPPLI */

/* OBJECT DESCRIPTIONS CONSIST OF A FLAG WORD AND TWO FWIM WORDS. */
/* THE FLAG WORD HAS THE FOLLOWING FORMAT-- */

/* BIT <14>	IF 1, SEARCH ADVENTURER FOR OBJECT */
/* BIT <13>	IF 1, SEARCH ROOM FOR OBJECT */
/* BIT <12>	IF 1, PARSER WILL TRY TO TAKE OBJECT */
/* BIT <11>	IF 1, ADVENTURER MUST HAVE OBJECT */
/* BIT <10>	IF 1, QUALIFYING BITS (NORMALLY -1,-1) ARE SAME */
/* 			AS FWIM BITS */
/* BIT <9>	IF 1, OBJECT MUST BE REACHABLE */
/* BITS <8:0>	PREPOSITION NUMBER FOR SYNMCH */

/* THE FWIM WORDS HAVE THE SAME FORMAT AS THE TWO OBJECT FLAG WORDS. */

/* NOTE THAT BITS 12 AND 11 OF OBJECT DESCRIPTIONS ACTUALLY HAVE */
/* FOUR DISTINCT STATES-- */

/* 	BIT 12	BIT 11	MDLDESC		INTERPRETATION */
/* 	------	------	-------		--------------- */

/* 	  0	  0	 --		NO PARSER ACTION */
/* 	  0	  1	 HAVE		ADVENTURER MUST HAVE OBJECT */
/* 	  1	  0	 TRY		TRY TO TAKE, DONT CARE IF FAIL */
/* 	  1	  1	 TAKE		TRY TO TAKE, CARE IF FAIL */

extern const int vvoc[];

/* OBJECTS--	MAPS OBJECTS TO OBJECT INDICES */

/* SAME FORMAT AS AVOC. */

extern const int ovoc[];

#endif
