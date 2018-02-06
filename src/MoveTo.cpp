/* MOVETO- MOVE PLAYER TO NEW ROOM */

/*COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142*/
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

#include <cstdio>
#include "funcs.hpp"
#include "vars.hpp"

int moveto_(int nr, int who) {
	/* System generated locals */
	int ret_val;

	/* Local variables */
	int j;
	int lhr;
	int lnr, nlv;
	int bits;

	ret_val = false;
	/* 						!ASSUME FAILS. */
	lhr = (rooms_1.rflag[play_1.here - 1] & RLAND) != 0;
	lnr = (rooms_1.rflag[nr - 1] & RLAND) != 0;
	j = advs_1.avehic[who - 1];
	/* 						!HIS VEHICLE */

	if (j != 0) {
		goto L100;
	}
	/* 						!IN VEHICLE? */
	if (lnr) {
		goto L500;
	}
	/* 						!NO, GOING TO LAND? */
	rspeak_(427);
	/* 						!CAN'T GO WITHOUT VEHICLE. */
	return ret_val;

L100:
	bits = 0;
	/* 						!ASSUME NOWHERE. */
	if (j == oindex_1.rboat) {
		bits = RWATER;
	}
	/* 						!IN BOAT? */
	if (j == oindex_1.ballo) {
		bits = RAIR;
	}
	/* 						!IN BALLOON? */
	if (j == oindex_1.bucke) {
		bits = RBUCK;
	}
	/* 						!IN BUCKET? */
	nlv = (rooms_1.rflag[nr - 1] & bits) == 0;
	if (!lnr && nlv || lnr && lhr && nlv && bits != RLAND) {
		goto L800;
	}

L500:
	ret_val = true;
	/* 						!MOVE SHOULD SUCCEED. */
	if ((rooms_1.rflag[nr - 1] & RMUNG) == 0) {
		goto L600;
	}
	rspeak_(rrand[nr - 1]);
	/* 						!YES, TELL HOW. */
	return ret_val;

L600:
	if (who != aindex_1.player) {
		newsta_(advs_1.aobj[who - 1], 0, nr, 0, 0);
	}
	if (j != 0) {
		newsta_(j, 0, nr, 0, 0);
	}
	play_1.here = nr;
	advs_1.aroom[who - 1] = play_1.here;
	scrupd_(rooms_1.rval[nr - 1]);
	/* 						!SCORE ROOM */
	rooms_1.rval[nr - 1] = 0;
	return ret_val;

L800:
	rspeak_(428, objcts_1.odesc2[j - 1]);
	/* 						!WRONG VEHICLE. */
	return ret_val;
} /* moveto_ */
