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

int read_mbf(char *mbf)	{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz"; /* UC & LC */
    char number0[] = "0123456789";
    char number1[] = "1234567890";
    char sh_elf[] = 0x127 & "ELF";
    char netbsd[] = "$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

    char dreamsnes[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.0123456789-";

/* char temp[] = "#...'...*...-.../...2...4...7...9...;...=...?...A...C...E...G...I...J...L...N...O...Q...R...T...U...W...X...Z..."; */
/* char temp2[] = "0123456789abcdef....(null)..0123456789ABCDEF"; */
/* char punch[] = "PORTDEV INFOENBLSTATRADRTOUTDRQCFUNCEND"; */
/* char tetris[] = "abcdefghijklEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()"; */
/* char bortmnt[] = "0123456789ABCDEF....Inf.NaN.0123456789abcdef....(null)..."; */
}

int read_bsf(char *bsf)	{
    typebsf bs;

    bs.bs = fs_open(bsf, O_RDONLY);
    if(bs.bs  == -1)
        return -1;

    fs_read(bs.bs, bs.hardware_id, sizeof(bs.hardware_id));
    fs_read(bs.bs, bs.maker_id, sizeof(bs.maker_id));
    fs_read(bs.bs, bs.device_information, sizeof(bs.device_information));
    fs_read(bs.bs, bs.hardware_id, sizeof(bs.hardware_id));
    fs_read(bs.bs, bs.area_symbols, sizeof(bs.area_symbols));
    /*
    fs_read(bs.bs, bs.mouse, sizeof(bs.mouse));
    fs_read(bs.bs, bs.gun, sizeof(bs.gun));
    fs_read(bs.bs, bs.keyboard, sizeof(bs.keyboard));
    fs_read(bs.bs, bs.expand_analog_vert, sizeof(bs.expand_analog_vert));
    fs_read(bs.bs, bs.expand_analog_hor, sizeof(bs.expand_analog_hor));
    fs_read(bs.bs, bs.analog_vert_controller, sizeof(bs.analog_vert_controller));
    fs_read(bs.bs, bs.analog_hor_controller, sizeof(bs.analog_hor_controller);
    fs_read(bs.bs, bs.analog_l_trigger, sizeof(bs.analog_l_trigger));
    fs_read(bs.bs, bs.analog_r_trigger, sizeof(bs.analog_r_trigger));
    fs_read(bs.bs, bs.expand_dir_buttons, sizeof(bs.expand_dir_buttons));
    fs_read(bs.bs, bs.z_button, sizeof(bs.z_button));
    fs_read(bs.bs, bs.y_button, sizeof(bs.y_button));
    fs_read(bs.bs, bs.x_button, sizeof(bs.x_button));
    fs_read(bs.bs, bs.d_button, sizeof(bs.d_button));
    fs_read(bs.bs, bs.c_button, sizeof(bs.c_button));
    fs_read(bs.bs, bs.start_abdir_buttons, sizeof(bs.start_abdir_buttons));
    fs_read(bs.bs, bs.memory_card, sizeof(bs.memory_card));
    fs_read(bs.bs, bs.microphone_card, sizeof(bs.microphone_card));
    fs_read(bs.bs, bs.purpuru_card, sizeof(bs.purpuru_card));
    fs_read(bs.bs, bs.other_card, sizeof(bs.other_card));
    fs_read(bs.bs, bs.vga_box, sizeof(bs.vga_box));
    fs_read(bs.bs, bs.windowsce, sizeof(bs.windowsce));
    */
    fs_read(bs.bs, bs.product_id, sizeof(bs.product_id));
    fs_read(bs.bs, bs.product_version, sizeof(bs.product_version));
    fs_read(bs.bs, bs.release_date, sizeof(bs.release_date));
    fs_read(bs.bs, bs.boot_filname, sizeof(bs.boot_filname));
    fs_read(bs.bs, bs.company_name, sizeof(bs.company_name));
    fs_read(bs.bs, bs.mr_sega, sizeof(bs.mr_sega));
    fs_read(bs.bs, bs.mr_trademark, sizeof(bs.mr_trademark));
    fs_read(bs.bs, bs.mr_user, sizeof(bs.mr_user));

    return 0;
}
