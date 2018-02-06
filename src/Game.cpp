/* GAME- MAIN COMMAND LOOP FOR DUNGEON */

/*COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142*/
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

#include <cstdio>
#include <cstring>
#include "funcs.hpp"
#include "vars.hpp"

/* Do all systems have <string.h>?  Don't use it, just in case */

static int xvehic_(int);
static void xendmv_(int);

void game_() {
	/* Local variables */
	int f;
	int i;

	/* START UP, DESCRIBE CURRENT LOCATION. */

	rspeak_(1);
	/* 						!WELCOME ABOARD. */
	f = rmdesc_(3);
	/* 						!START GAME. */

	/* NOW LOOP, READING AND EXECUTING COMMANDS. */

    while (true) {
	    play_1.winner = aindex_1.player;
	    /* 						!PLAYER MOVING. */
	    play_1.telflg = FALSE_;
	    /* 						!ASSUME NOTHING TOLD. */
	    if (prsvec_1.prscon <= 1) {
		    rdline_(input_1.inbuf, 1);
	    }

    #ifdef ALLOW_GDT

	    if (strcmp(input_1.inbuf + prsvec_1.prscon - 1, "GDT") == 0) {
		    /* 						!CALL ON GDT? */
		    gdt_();
		    /* 						!YES, INVOKE. */
		    continue;
	    }

    #endif /* ALLOW_GDT */

	    ++state_1.moves;
	    prsvec_1.prswon = parse_(input_1.inbuf, 1);
	    if (prsvec_1.prswon && !xvehic_(1)) {
	        /* 						!VEHICLE HANDLE? */

	        if (prsvec_1.prsa == vindex_1.tellw) {
		        goto L2000;
	        }
	        /* 						!TELL? */
        L300:
	        if (prsvec_1.prso == oindex_1.valua || prsvec_1.prso == oindex_1.every) {
	            valuac_(oindex_1.valua);
	        }
	        if (prsvec_1.prso == oindex_1.valua || prsvec_1.prso == oindex_1.every || vappli_(prsvec_1.prsa)) {
	        /* 						!VERB OK? */
            L350:
                if (!findex_1.echof && play_1.here == rindex_1.echor) {do {
	                rdline_(input_1.inbuf, 0);
	                ++state_1.moves;
	                /* 						!CHARGE FOR MOVES. */
	                if (strcmp(input_1.inbuf, "ECHO") != 0) {
	                    prsvec_1.prswon = parse_(input_1.inbuf, 0);
	                    if (!prsvec_1.prswon || prsvec_1.prsa != vindex_1.walkw) {
	                    } else if (findxt_(prsvec_1.prso, play_1.here)) {
		                    goto L300;
	                    }
	                    /* 						!VALID EXIT? */
	                    more_output(input_1.inbuf);
	                    play_1.telflg = TRUE_;
	                }
                    } while (strcmp(input_1.inbuf, "ECHO") != 0);
	                rspeak_(571);
	                /* 						!KILL THE ECHO. */
	                findex_1.echof = TRUE_;
	                objcts_1.oflag2[oindex_1.bar - 1] &= ~SCRDBT;
	                prsvec_1.prswon = TRUE_;
	                /* 						!FAKE OUT PARSER. */
	                prsvec_1.prscon = 1;
	                /* 						!FORCE NEW INPUT. */
	                goto L400;
	                /* 						!MORE ECHO ROOM. */
	                /* GAME, PAGE 4 */

	                /* SPECIAL CASE-- TELL <ACTOR>, NEW COMMAND */
	                /* NOTE THAT WE CANNOT BE IN THE ECHO ROOM. */
                }
                f = rappli_(rooms_1.ractio[play_1.here - 1]);
            }
        }
    L400:
	    xendmv_(play_1.telflg);
	    /* 						!DO END OF MOVE. */
	    if (!lit_(play_1.here)) {
		    prsvec_1.prscon = 1;
	    }
    }
	/* GAME, PAGE 3 */

	/* SPECIAL CASE-- ECHO ROOM. */
	/* IF INPUT IS NOT 'ECHO' OR A DIRECTION, JUST ECHO. */

L2000:
	if ((objcts_1.oflag2[prsvec_1.prso - 1] & ACTRBT) != 0) {
		goto L2100;
	}
	rspeak_(602);
	/* 						!CANT DO IT. */
	goto L350;
	/* 						!VAPPLI SUCCEEDS. */

L2100:
	play_1.winner = oactor_(prsvec_1.prso);
	/* 						!NEW PLAYER. */
	play_1.here = advs_1.aroom[play_1.winner - 1];
	/* 						!NEW LOCATION. */
	if (prsvec_1.prscon <= 1) {
		goto L2700;
	}
	/* 						!ANY INPUT? */
	if (parse_(input_1.inbuf, 1)) {
		goto L2150;
	}
L2700:
	i = 341;
	/* 						!FAILS. */
	if (play_1.telflg) {
		i = 604;
	}
	/* 						!GIVE RESPONSE. */
	rspeak_(i);
L2600:
	play_1.winner = aindex_1.player;
	/* 						!RESTORE STATE. */
	play_1.here = advs_1.aroom[play_1.winner - 1];
	goto L350;

L2150:
	if (aappli_(advs_1.aactio[play_1.winner - 1])) {
		goto L2400;
	}
	/* 						!ACTOR HANDLE? */
	if (xvehic_(1)) {
		goto L2400;
	}
	/* 						!VEHICLE HANDLE? */
	if (prsvec_1.prso == oindex_1.valua || prsvec_1.prso == oindex_1.every) {
		goto L2900;
	}
	if (!vappli_(prsvec_1.prsa)) {
		goto L2400;
	}
	/* 						!VERB HANDLE? */
	/* L2350: */
	f = rappli_(rooms_1.ractio[play_1.here - 1]);

L2400:
	xendmv_(play_1.telflg);
	/* 						!DO END OF MOVE. */
	goto L2600;
	/* 						!DONE. */

L2900:
	valuac_(oindex_1.valua);
	/* 						!ALL OR VALUABLES. */
	goto L350;

} /* game_ */

/* XENDMV-	EXECUTE END OF MOVE FUNCTIONS. */

/* DECLARATIONS */

static void xendmv_(int flag) {
    if (!(flag)) {
		rspeak_(341);
	}
	/* 						!DEFAULT REMARK. */
	if (hack_1.thfact) {
		thiefd_();
	}
	/* 						!THIEF DEMON. */
	if (hack_1.swdact) {
		swordd_();
	}
	/* 						!SWORD DEMON. */
	if (prsvec_1.prswon) {
		fightd_();
		clockd_();
		xvehic_(2);
	}
	/*!FIGHT DEMON. */
	/*!CLOCK DEMON. */
	/*!VEHICLE READOUT. */
} /* xendmv_ */

/* XVEHIC- EXECUTE VEHICLE FUNCTION */

/* DECLARATIONS */

static int xvehic_(int n) {
	int av = advs_1.avehic[play_1.winner - 1];
	return av ? oappli_(objcts_1.oactio[av - 1], n) : false;
} /* xvehic_ */
