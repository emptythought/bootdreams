/*
    This file is part of BootDreams.

    Copyright (C) 2010 Cyle Terry

    BootDreams is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    BootDreams is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with BootDreams.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MAX_COLORS_MR 127
#define MAX_SIZE_USER_MR 8192 /* the second bootstrap is ~10208 bytes 
(bleem!cast's Mister is 12733 bytes) */
#define HEIGHT_USER_MR 90
#define WIDTH_USER_MR 320

typedef struct {
    char id[2];
    WORD size;
    char crap0[6];
    WORD offset;
    char crap1[2];
    WORD width;
    char crap2[2];
    WORD height;
    char crap3[6];
    WORD colors;
    char crap4[2];
    char palette[MAX_COLORS_MR * 4];
    char bitmap0[];
    char bitmap1[WIDTH_USER_MR * HEIGHT_USER_MR]; /* Uncompressed */
} typemr;

int read_mr(char *mrf);
int display_mr();
