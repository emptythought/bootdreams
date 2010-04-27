/*
    This file is part of BootDreams.

    Copyright (C) 2010 Cyle Terry

    BootDreams is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 
    as published by the Free Software Foundation.

    BootDreams is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with BootDreams; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/* static const */ char *typembf[] = {
    unscrambled,
    sh_elf,
    scrambled
};

typedef struct {
    char hardware_id[16]; /* always "SEGA SEGAKATANA " */
    char maker_id[16]; /* always "SEGA ENTERPRISES" */
    /* device_information
    area_symbols
    */
    int mouse
    int gun
    int keyboard
    int expand_analog_vert
    int expand_analog_hor
    int analog_vert_controller
    int analog_hor_controller
    int analog_l_trigger
    int analog_r_trigger
    int expand_dir_buttons
    int z_button
    int y_button
    int x_button
    int d_button
    int c_button
    int start_abdir_buttons
    int memory_card
    int microphone_card
    int purpuru_card
    int other_card
    int vga_box
    int windowsce
    char product_id[10]
    char product_version[5]
    char release_date[8]
    char boot_filname[16]
    char company_name[16]
    char software_name[128]
} typebsf;

typembf read_mbf(char *mbf);
typebsf read_bsf(char *bsf);
