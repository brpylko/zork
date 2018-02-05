/* DUNGEON-- MAIN PROGRAM */

/*COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142*/
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

#define EXTERN
#define INIT

#include "funcs.h"
#include "vars.h"

int main(int argc, char** argv) {
	if (init_()) {
		game_();
	}
	exit_();
	return 0;
}
