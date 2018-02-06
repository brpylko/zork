/* vars.h -- variables for dungeon */

/* These variable definitions are really ugly because they are actually
 * translations of FORTRAN common blocks.  In the original FORTRAN source
 * the common blocks were included many times by each function that
 * needed them; I have changed this to define them all in this one file,
 * and include this in every source file.  It's less modular, and it
 * makes everything slower to compile, but it's easier on me.
 * A few structures used only by the parsing routines are in parse.h.
 */

#ifndef VARS_H
#define VARS_H

extern struct prsvec_t {
	int prsa, prsi, prso;
	int prswon;
	int prscon;
} prsvec_;

#define prsvec_1 prsvec_

extern struct orphs_t {
	int oflag, oact, oslot, oprep, oname;
} orphs_;

#define orphs_1 orphs_
#define orp ((int *)&orphs_1)

extern struct last_t {
	int lastit;
} last_;

#define last_1 last_

extern struct play_t {
	int winner, here;
	int telflg;
} play_;

#define play_1 play_

extern struct rooms_t {
	int rlnt, rdesc1[200], rdesc2[200], rexit[200], ractio[200],
		rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_
#define eqr ((int *)&rooms_1 + 1)
#define rrand ((int *)&rooms_1 + 601)

/* Room flags */

#define RSEEN (32768)
#define RLIGHT (16384)
#define RLAND (8192)
#define RWATER (4096)
#define RAIR (2048)
#define RSACRD (1024)
#define RFILL (512)
#define RMUNG (256)
#define RBUCK (128)
#define RHOUSE (64)
#define RNWALL (32)
#define REND (16)

extern const struct rindex_t {
	int whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3,
		clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome,
		mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas,
		rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr,
		mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3,
		ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr,
		mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant,
		mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge,
		mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant,
		cpout, cpuzz;
} rindex_;

#define rindex_1 rindex_

extern const struct xsrch_t {
	int xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast,
		xwest;
} xsrch_;

#define xsrch_1 xsrch_

extern struct objcts_t {
	int olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[
		220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
			, oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_
#define eqo ((int *)&objcts_1 + 1)

extern struct oroom2_t {
	int r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

/* Object flags (oflags) */

#define VISIBT (32768)
#define READBT (16384)
#define TAKEBT (8192)
#define DOORBT (4096)
#define TRANBT (2048)
#define FOODBT (1024)
#define NDSCBT (512)
#define DRNKBT (256)
#define CONTBT (128)
#define LITEBT (64)
#define VICTBT (32)
#define BURNBT (16)
#define FLAMBT (8)
#define TOOLBT (4)
#define TURNBT (2)
#define ONBT (1)
#define FINDBT (32768)
#define SLEPBT (16384)
#define SCRDBT (8192)
#define TIEBT (4096)
#define CLMBBT (2048)
#define ACTRBT (1024)
#define WEAPBT (512)
#define FITEBT (256)
#define VILLBT (128)
#define STAGBT (64)
#define TRYBT (32)
#define NOCHBT (16)
#define OPENBT (8)
#define TCHBT (4)
#define VEHBT (2)
#define SCHBT (1)

extern const struct oindex_t {
	int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope,
		knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys,
		ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell,
		book, candl, match, tube, putty, wrenc, screw, cyclo, chali,
		thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot,
		statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo,
		recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse,
		gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut,
		flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot,
		ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana,
		ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8,
		warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat,
		teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_;

#define oindex_1 oindex_

extern struct cevent_t {
	int clnt, ctick[25], cactio[25];
	int cflag[25];
} cevent_;

#define cevent_1 cevent_
#define eqc ((int *)&cevent_1 + 1)

extern const struct cindex_t {
	int cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus,
		cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor,
		cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_;

#define cindex_1 cindex_

extern struct advs_t {
	int alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[
		4], aflag[4];
} advs_;

#define advs_1 advs_
#define eqa ((int *)&advs_1 + 1)

extern const struct aflags_t {
	int astag;
} aflags_;

#define aflags_1 aflags_

extern const struct aindex_t {
	int player, arobot, amastr;
} aindex_;

#define aindex_1 aindex_

extern const struct vindex_t{
	int cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw,
		readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew,
		raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw,
		knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw,
		closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw,
		eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw,
		putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow,
		hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw,
		trntow;
} vindex_;

#define vindex_1 vindex_

extern struct findex_t {
	int trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf,
		echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef,
		gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf,
		grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf,
		endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f,
		mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
	int btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand,
		ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell,
		pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_
#define flags ((int *)&findex_1)
#define switch_ ((int *)&findex_1 + 46)

extern struct debug_t {
	int dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

extern struct hack_t {
	int thfpos;
	int thfflg, thfact, swdact;
	int swdsta;
} hack_;

#define hack_1 hack_

extern struct vill_t {
	int vlnt, villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
} vill_;

#define vill_1 vill_
#define eqv ((int *)&vill_1 + 1)

extern struct state_t {
	int moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs,
		egscor, egmxsc;
} state_;

#define state_1 state_

extern struct curxt_t {
	int xtype, xroom1, xstrng, xactio, xobj;
} curxt_;

#define curxt_1 curxt_
#define xflag ((int *)&curxt_1 + 4)

extern const struct xpars_t {
	int xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno,
		xcond, xdoor, xlflag;
} xpars_;

#define xpars_1 xpars_

extern struct star_t {
	int mbase, strbit;
} star_;

#define star_1 star_

extern struct input_t {
	int inlnt;
	char inbuf[78];
} input_;

#define input_1 input_

extern struct screen_t {
	int fromdr, scolrm, scolac;
	const int scoldr[8], scolwl[12];
} screen_;

#define screen_1 screen_

extern struct rmsg_t {
	int mlnt, mrloc, rtext[1050];
} rmsg_;

#define rmsg_1 rmsg_

extern const struct vers_t {
	int vmaj, vmin, vedit;
} vers_;

#define vers_1 vers_

extern struct struct_time_t {
	int pltime, shour, smin, ssec;
} time_;

#define time_1 time_

extern const struct hyper_t {
	int hfactr;
} hyper_;

#define hyper_1 hyper_

extern struct exits_t {
	int xlnt, travel[900];
} exits_;

#define exits_1 exits_

extern struct puzzle_t {
	const int cpdr[16], cpwl[8];
	int cpvec[64];
} puzzle_;

#define puzzle_1 puzzle_

extern const struct bats_t {
	const int batdrp[9];
} bats_;

#define bats_1 bats_

#endif
