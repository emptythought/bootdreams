/*
    This file is part of BootDreams.

    Copyright (C) 2010, 2015 Cyle Terry

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

#define MR_USER_MAX_SIZE 8192 /* bleem!cast is like 10675 */
#define MR_USER_MAX_WIDTH 320
#define MR_USER_MAX_HEIGHT 90

#define MR_SEGA_SIZE 4311
#define MR_SEGA_WIDTH 291
#define MR_SEGA_HEIGHT 89

#define MR_TRADEMARK_SIZE 299
#define MR_TRADEMARK_WIDTH 22
#define MR_TRADEMARK_HEIGHT 12

typedef enum {
    unscrambled,
    scrambled
} enummbf;

typedef struct {
/* bs.mr.user.cache
bs.mr.user.id
bs.mr.user.offset
bs.mr.user.width
bs.mr.user.height
bs.mr.user.colors
bs.mr.user.bitmap.compressed
bs.mr.user.bitmap.uncompressed
bs.mr.user.bitmap.offset
bs.mr.user.bitmap.palette */
    char mr[MR_USER_MAX_SIZE];
    char id[2];
    unsigned short size;
    char reserve_o1[6];
    unsigned short offset;
    char reserve_o2[2];
    unsigned short width;
    char reserve_o3[2];
    unsigned short height;
    char reserve_o4[6];
    unsigned short colors;
    char reserve_o5[2];
    char palette[MR_MAX_COLORS * 4];
    char bitmap[MR_USER_MAX_SIZE - 1];
    char bitmap_expanded[MR_USER_WIDTH * MR_USER_HEIGHT];
} typemr;

typedef struct {
    char hardware_id[17]; /* always "SEGA SEGAKATANA " */
    char maker_id[17]; /* always "SEGA ENTERPRISES" */
    char checksum[5];
    char disc_info[12];
    char area_symbols[4];
    char peripherals[8];
    int mouse;
    int gun;
    int keyboard;
    int expand_analog_vert;
    int expand_analog_hor;
    int analog_vert_controller;
    int analog_hor_controller;
    int analog_l_trigger;
    int analog_r_trigger;
    int expand_dir_buttons;
    int z_button;
    int y_button;
    int x_button;
    int d_button;
    int c_button;
    int start_abdir_buttons;
    int memory_card;
    int microphone_card;
    int purupuru_card;
    int other;
    int vga_box;
    int windowsce;
    char product_id[11];
    char product_version[6];
    char release_date[9];
    char boot_filname[17];
    char company_name[17];
    char software_name[129];
    char mr_trademark[MR_TRADEMARK_SIZE];
    char mr_sega[MR_SEGA_SIZE];
    char mr_user[MR_USER_MAX_SIZE];
} typebsf;

enummbf read_mbf(char *mbf);
int read_mr(char *mrf);
int display_mr();
int read_bsf(char *bsf);
