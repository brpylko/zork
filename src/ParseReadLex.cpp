/* RDLINE-	READ INPUT LINE */

/*COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142*/
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include "funcs.hpp"
#include "vars.hpp"

static int lex_(char *, int *, int *, int);

void rdline_(char* buffer, int who) {
	/* Local variables */
	char *z, *zlast;

	/* Function Body */
	do {
		if (who == 1) {
		/* 						!SEE WHO TO PROMPT FOR. */
			printf(">");
		}
		/* 						!PROMPT FOR GAME. */
		fflush(stdout);
		if (fgets(buffer, 78, stdin) == NULL) {
			exit_();
		}
		more_input();

		if (buffer[0] == '!') {
			system(buffer + 1);
		} else {
			zlast = buffer - 1;
			for (z = buffer; *z != '\0' && *z != '\n'; z++) {
				if (*z != ' ')
					zlast = z;
				if (islower(*z)) {
					*z = toupper(*z);
				}
			}
			z = zlast + 1;
		}
	} while(z == buffer);
	*z = '\0';

	prsvec_1.prscon = 1;
	/* 						!RESTART LEX SCAN. */
} /* rdline_ */

/* PARSE-	TOP LEVEL PARSE ROUTINE */

/* THIS ROUTINE DETAILS ON BIT 0 OF PRSFLG */

int parse_(char* inbuf, int vbflag) {
	/* System generated locals */
	int i__1;
	int ret_val;

	/* Local variables */
	int outbuf[40], outlnt;

	/* Parameter adjustments */
	--inbuf;

	/* Function Body */
	ret_val = false;
	/* 						!ASSUME FAILS. */
	prsvec_1.prsa = 0;
	/* 						!ZERO OUTPUTS. */
	prsvec_1.prsi = 0;
	prsvec_1.prso = 0;

	if (!lex_(inbuf + 1, outbuf, &outlnt, vbflag)) {
		prsvec_1.prscon = 1;
		return false;
	}
	if ((i__1 = sparse_(outbuf, outlnt, vbflag)) < 0) {
		prsvec_1.prscon = 1;
		return false;
	} else if (i__1 == 0) {
		goto L200;
	} else {
		goto L300;
	}
	/* 						!DO SYN SCAN. */

	/* PARSE REQUIRES VALIDATION */

L200:
	if (!(vbflag)) {
		goto L350;
	}
	/* 						!ECHO MODE, FORCE FAIL. */
	if (!synmch_()) {
		prsvec_1.prscon = 1;
		return false;
	}
	/* 						!DO SYN MATCH. */
	if (prsvec_1.prso > 0 & prsvec_1.prso < xsrch_1.xmin) {
		last_1.lastit = prsvec_1.prso;
	}

	/* SUCCESSFUL PARSE OR SUCCESSFUL VALIDATION */

L300:
	ret_val = true;
L350:
	orphan_(0, 0, 0, 0, 0);
	/* 						!CLEAR ORPHANS. */
	return ret_val;

} /* parse_ */

/* ORPHAN- SET UP NEW ORPHANS */

/* DECLARATIONS */

void orphan_(int o1, int o2, int o3, int o4, int o5) {
	orphs_1.oflag = o1;
	/* 						!SET UP NEW ORPHANS. */
	orphs_1.oact = o2;
	orphs_1.oslot = o3;
	orphs_1.oprep = o4;
	orphs_1.oname = o5;
} /* orphan_ */

/* LEX-	LEXICAL ANALYZER */

/* THIS ROUTINE DETAILS ON BIT 1 OF PRSFLAG */

static int lex_(char* inbuf, int* outbuf, int* op, int vbflag) {
	/* Initialized data */

	static const char dlimit[9] = {'A', 'Z', 'A' - 1,
		'1', '9', '1' - 31,
		'-', '-', '-' - 27};

	/* System generated locals */
	int ret_val;

	/* Local variables */
	int i;
	char j;
	int k, j1, j2, cp;

	/* Parameter adjustments */
	--outbuf;
	--inbuf;

	/* Function Body */

	for (i = 1; i <= 40; ++i) {
		/* 						!CLEAR OUTPUT BUF. */
		outbuf[i] = 0;
		/* L100: */
	}

	ret_val = false;
	/* 						!ASSUME LEX FAILS. */
	*op = -1;
	/* 						!OUTPUT PTR. */
	while (true) {
		*op += 2;
		/* 						!ADV OUTPUT PTR. */
		cp = 0;
		/* 						!CHAR PTR=0. */

		while (true) {
			j = inbuf[prsvec_1.prscon];
			/* 						!GET CHARACTER */

			if (j != '\0') {
				/* 						!END OF INPUT? */

				++prsvec_1.prscon;
				/* 						!ADVANCE PTR. */

				if (j != '.' && j != ',') {
					/* 						!END OF COMMAND? */
					if (j == ' ' && cp != 0) {
						break;
					}
					/* 						!SPACE? */
					for (i = 1; i <= 9; i += 3) {
						/* 						!SCH FOR CHAR. */
						if (j >= dlimit[i - 1] & j <= dlimit[i]) {
							goto L4000;
						}
						/* L500: */
					}

					if (vbflag) {
						rspeak_(601);
					}
					/* 						!GREEK TO ME, FAIL. */
					return ret_val;
				}
			}
			/* END OF INPUT, SEE IF PARTIAL WORD AVAILABLE. */

		L1000:
			if (inbuf[prsvec_1.prscon] == '\0') {
				prsvec_1.prscon = 1;
			}
			/* 						!FORCE PARSE RESTART. */
			if (cp == 0 & *op == 1) {
				return ret_val;
			}
			if (cp == 0) {
				*op += -2;
			}
			/* 						!ANY LAST WORD? */
			return true;

			/* LEGITIMATE CHARACTERS: LETTER, DIGIT, OR HYPHEN. */

		L4000:
			j1 = j - dlimit[i + 1];
			if (cp < 6) {
				/* 						!IGNORE IF TOO MANY CHAR. */
				k = *op + cp / 3;
				/* 						!COMPUTE WORD INDEX. */
				/* 						!BRANCH ON CHAR. */
				if (cp % 3 == 0) {
					j2 = j1 * 780;
					/* 						!CHAR 1... *780 */
					outbuf[k] = outbuf[k] + j2 + j2;
				}
				/* 						!*1560 (40 ADDED BELOW). */
				if (cp % 3 == 0 || cp % 3 == 1) {
					outbuf[k] += j1 * 39;
				}
				/* 						!*39 (1 ADDED BELOW). */
				outbuf[k] += j1;
				/* 						!*1. */
				++cp;
				/* 						!GET NEXT CHAR. */
			}
		}
		/* 						!ANY WORD YET? */
	}
	/* 						!YES, ADV OP. */

} /* lex_ */
