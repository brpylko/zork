/* vars.cpp -- variables for dungeon */

/* These variable definitions are really ugly because they are actually
 * translations of FORTRAN common blocks.  In the original FORTRAN source
 * the common blocks were included many times by each function that
 * needed them; I have changed this to define them all in this one file,
 * and include this in every source file.  It's less modular, and it
 * makes everything slower to compile, but it's easier on me.
 * A few structures used only by the parsing routines are in parse.h.
 */
#include "vars.hpp"

prsvec_t prsvec_;

orphs_t orphs_;

last_t last_;

play_t play_;

rooms_t rooms_;

const rindex_t rindex_ = {2, 8, 9, 10, 11, 25, 30, 31, 33, 36, 40, 42, 44, 49, 61, 76,
77, 79, 80, 83, 91, 94, 96, 97, 100, 102, 103, 107, 108, 109,
101, 112, 113, 114, 120, 119, 121, 122, 126, 127, 128, 129, 130,
131, 132, 133, 135, 140, 141, 142, 143, 144, 145, 146, 147, 148,
151, 153, 154, 155, 157, 158, 159, 160, 161, 162, 163, 164, 165,
166, 167, 171, 172, 173, 174, 176, 177, 179, 182, 183, 184, 185,
186, 188, 189, 190};

const xsrch_t xsrch_ = {1024, 16384, 10240, 9216, 1024, 5120, 13312, 14336, 3072, 7168};

objcts_t objcts_;

oroom2_t oroom2_;

const oindex_t oindex_ = {2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
20, 21, 23, 30, 26, 33, 34, 35, 36, 39, 42, 45, 46, 47, 48, 51,
54, 55, 56, 57, 58, 59, 61, 62, 63, 65, 66, 71, 78, 79, 75, 85,
86, 87, 88, 89, 90, 92, 94, 96, 98, 99, 97, 101, 102, 103, 105,
107, 109, 110, 111, 112, 113, 119, 123, 124, 125, 126, 127, 132,
133, 134, 137, 138, 139, 140, 141, 142, 145, 148, 149, 151, 152,
154, 155, 156, 157, 158, 159, 161, 164, 171, 172, 173, 175, 178,
185, 186, 187, 188, 189, 200, 198, 201, 196, 202, 197, 192, 194,
195, 193, 205, 209, 215};

cevent_t cevent_;

const cindex_t cindex_ = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
18, 19, 20, 21, 22, 23, 24};

advs_t advs_;

const aflags_t aflags_= {32768};

const aindex_t aindex_= {1, 2, 3};

const vindex_t vindex_ = {1, 2, 3, 4, 5, 6, 7, 8, 101, 100, 102, 103, 104, 105, 106,
107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132,
133, 134, 135, 136, 137, 138, 139, 141, 140, 142, 143, 144, 145,
146, 147, 148, 89, 91, 73, 85, 151, 152, 153, 154, 155, 156, 157,
158, 159};

findex_t findex_;

debug_t debug_;

hack_t hack_;

vill_t vill_;

state_t state_;

curxt_t curxt_;

const xpars_t xpars_ = {255, 31744, 3, 256, 256, {1, 2, 3, 3}, 1, 2, 3, 4, 32768};

star_t star_;

input_t input_;

screen_t screen_ = {0, 0, 0, {1024, 153, 5120, 154, 3072, 152, 7168, 151},
{151, 207, 3072, 152, 208, 7168, 153, 206, 5120, 154, 205,
1024}};

rmsg_t rmsg_;

const vers_t vers_ = {2, 7, 'A'};

struct_time_t time_;

const hyper_t hyper_ = {500};

exits_t exits_;

puzzle_t puzzle_ = {{1024, -8, 2048, -7, 3072, 1, 4096, 9, 5120, 8, 6144, 7,
7168, -1, 8192, -9},
{205, -8, 206, 8, 207, 1, 208, -1},
{1, 1, 1, 1, 1, 1, 1, 1,
1, 0, -1, 0, 0, -1, 0, 1,
1, -1, 0, 1, 0, -2, 0, 1,
1, 0, 0, 0, 0, 1, 0, 1,
1, -3, 0, 0, -1, -1, 0, 1,
1, 0, 0, -1, 0, 0, 0, 1,
1, 1, 1, 0, 0, 0, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1}};

const bats_t bats_ = {66, 67, 68, 69, 70, 71, 72, 65, 73};
