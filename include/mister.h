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

#define MR_MAX_COLORS 127

#define MR_USER_MAX_SIZE 8192
#define MR_USER_WIDTH 320
#define MR_USER_HEIGHT 90

#define MR_SEGA_SIZE 4311
#define MR_SEGA_WIDTH 291
#define MR_SEGA_HEIGHT 89

#define MR_TRADEMARK_SIZE 299
#define MR_TRADEMARK_WIDTH 22
#define MR_TRADEMARK_HEIGHT 12

typedef struct {
    char mr[MR_USER_MAX_SIZE];
    char id[2];
    unsigned short size;
    char crap0[6];
    unsigned short offset;
    char crap1[2];
    unsigned short width;
    char crap2[2];
    unsigned short height;
    char crap3[6];
    unsigned short colors;
    char crap4[2];
    char palette[MR_MAX_COLORS * 4];
    char bitmap[MR_USER_MAX_SIZE - 1];
    char bitmap_expanded[MR_USER_WIDTH * MR_USER_HEIGHT];
} typemr;

int read_mr(char *mrf);
int display_mr();
