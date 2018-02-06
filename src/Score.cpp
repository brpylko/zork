/*COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142*/
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

#include <cstdio>
#include "funcs.hpp"
#include "vars.hpp"

/* SCORE-- PRINT OUT CURRENT SCORE */

/* DECLARATIONS */

void score_(int flg) {
	/* Initialized data */

	static const int rank[10] = {20, 19, 18, 16, 12, 8, 4, 2, 1, 0};
	static const int erank[5] = {20, 15, 10, 5, 0};

	/* System generated locals */
	int i__1;

	/* Local variables */
	int i, as;

	as = advs_1.ascore[play_1.winner - 1];

	if (findex_1.endgmf) {
		goto L60;
	}
	/* 						!ENDGAME? */
	more_output(NULL);
	printf("Your score ");
	if (flg)
		printf("would be");
	else
		printf("is");
	printf(" %d [total of %d points], in %d move", as, state_1.mxscor,
		state_1.moves);
	if (state_1.moves != 1)
		printf("s");
	printf(".\n");

	for (i = 1; i <= 10; ++i) {
		if (as * 20 / state_1.mxscor >= rank[i - 1]) {
			goto L50;
		}
		/* L10: */
	}
L50:
	i__1 = i + 484;
	rspeak_(i__1);
	return;

L60:
	more_output(NULL);
	printf("Your score in the endgame ");
	if (flg)
		printf("would be");
	else
		printf("is");
	printf(" %d [total of %d points], in %d moves.\n", state_1.egscor,
		state_1.egmxsc, state_1.moves);

	for (i = 1; i <= 5; ++i) {
		if (state_1.egscor * 20 / state_1.egmxsc >= erank[i - 1]) {
			goto L80;
		}
		/* L70: */
	}
L80:
	i__1 = i + 786;
	rspeak_(i__1);
} /* score_ */

/* SCRUPD- UPDATE WINNER'S SCORE */

/* DECLARATIONS */

void scrupd_(int n) {
	if (findex_1.endgmf) {
		goto L100;
	}
	/* 						!ENDGAME? */
	advs_1.ascore[play_1.winner - 1] += n;
	/* 						!UPDATE SCORE */
	state_1.rwscor += n;
	/* 						!UPDATE RAW SCORE */
	if (advs_1.ascore[play_1.winner - 1] < state_1.mxscor - state_1.deaths *
		10) {
		return;
	}
	cevent_1.cflag[cindex_1.cevegh - 1] = TRUE_;
	/* 						!TURN ON END GAME */
	cevent_1.ctick[cindex_1.cevegh - 1] = 15;
	return;

L100:
	state_1.egscor += n;
	/* 						!UPDATE EG SCORE. */
} /* scrupd_ */
