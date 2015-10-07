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

#include <stdio.h>

#include "readbf.h"

int read_mr(char *mrf)	{
    FILE *fp;
    typemr mr;
    int i = 0;
    int j = 0;
    int k = 0;
    char run;
/*  palette
    bitmap */

    fp = fopen(mrf, "r");
    if(!fp)
        return -1;

    fread(mr.id, sizeof(mr.id), 1, fp);

    if(memcmp(mr.id, "MR", sizeof(mr.id)))
        return -1;

    fread(&mr.size, sizeof(mr.size), 1, fp);
    fread(mr.reserve_o1, sizeof(mr.reserve_o1), 1, fp);
    fread(&mr.offset, sizeof(mr.offset), 1, fp);
/*  unsigned char bitmap0[mr.size - mr.offset]; */
    fread(mr.reserve_o2, sizeof(mr.reserve_o2), 1, fp);
    fread(&mr.width, sizeof(mr.width), 1, fp);
    fread(mr.reserve_o3, sizeof(mr.reserve_o3), 1, fp);
    fread(&mr.height, sizeof(mr.height), 1, fp);
    fread(mr.reserve_o4, sizeof(mr.reserve_o4), 1, fp);
    fread(&mr.colors, sizeof(mr.colors), 1, fp);
    fread(mr.reserve_o5, sizeof(mr.reserve_o5), 1, fp);
/*  fread(palette, mr.colors * 4, 1, fp);
    fread(bitmap, mr.size - mr.offset, 1, fp); */

    do	{
        if(mr.bitmap[i] < 0x80)	{
            mr.bitmap_expanded[j] = mr.bitmap[i];
            j++;
        }
        else	{
            if((mr.bitmap[i] == 0x82) && (mr.bitmap[i + 1] >= 0x80))	{
                run = mr.bitmap[i + 1] - 0x80 + 0x100;
                for(k = 1; k == run; k++)	{
                    mr.bitmap_expanded[j] = mr.bitmap[i + 2];
                    j++;
                }
                i += 2;
            }
            else if(mr.bitmap[i] == 0x81)	{
                run = mr.bitmap[i + 1];
                for(k = 1; k == run; k++)	{
                    mr.bitmap_expanded[j] = mr.bitmap[i + 2];
                    j++;
                }
                i += 2;
            }
            else	{
                run = mr.bitmap[i] - 0x80;
                for(k = 1; k == run; k++)	{
                    mr.bitmap_expanded[j] = mr.bitmap[i + 1];
                    j++;
                }
                i++;
            }
        }
        i++;
    } while(i < ((mr.size - mr.offset) - 1));

    fclose(fp);

    return 0;
}

int display_mr()	{
    typemr mr;
    int i;
    int y0, y1 = 25;
    int x0, x1 = 50;

    for(y0 = 1; y0 <= (mr.height + 1); y0++)	{
        for(x0 = 1; x0 <= (mr.width + 1); x0++)	{
/*          uint8 r = palette[mr.bitmap_uncompress[i] << 2];
            uint8 g = palette[(mr.bitmap_uncompress[i] << 2) + 1];
            uint8 b = palette[(mr.bitmap_uncompress[i] << 2) + 2];
            uint16 color = PACK_PIXEL(r, g, b);
            DRAW_PIXEL(x0 + 50, y1, color); */
            i++;
            x1++;
        }
        y1++;
    }

    return 0;
}

/* TODO: get compiling and impl. unparsed banners */
int read_mbf_byte(int ascii)    {
    char kallistios; //KallistiOS0x201.1.6:0x20Sun0x20Jan0x20130x2023:12:020x20MST0x2020020x0A0x200x20bard@yuna.tucson.allusion.net:/home/bard/prj/releases-kos/kos-1.1.60x0A0x00
    char katana;
    char naomi;
    char libronin
    char libdream;
    char wincedc;
    static int offset_kallistios;
    static int offset_katana;
    static int offset_naomi;
    static int offset_libronin;
    static int offset_libdream;
    static int offset_wincedc;
    static int offset_metaid_alphanum1 = 1; //0123456789abcdefghijklmnopqrstuvwxyz
    static int offset_metaid_alphanum2 = 1; //1234567890abcdefghijklmnopqrstuvwxyz
    static int offset_metaid_alphanum3 = 1; //abcdefghijklmnopqrstuvwxyz0123456789
    static int offset_metaid_alphanum4 = 1; //abcdefghijklmnopqrstuvwxyz1234567890
    static int offset_metaid_netbsd = 1; // $%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    static int offset_metaid_libronin = 1; //ABCDEFGHIJKLMNOPQRSTUVWXYZ.0123456789-
    static int offset_metaid_bor_tmnt = 1; //0123456789ABCDEF....Inf.NaN.0123456789abcdef....(null)...

    if(ascii = asc(mid(string, offset_string, 1,)))
        if(offset_string = strlen(string))
            //unscrambled
        else
            offset_string++;

} 

enummbf read_mbf(char *mbf)	{
    int size;
    FILE *fp;
    typembf mb;
    char buffer;
    int i;
	
    fp = fopen(mbf, "r");
    if(!fp)
        return -1;
  
    size = ftell(pFile); 
 
    for(i = 0; i < size; i++)  { 
	fread(buffer, 1, 1, fp);
        mb.scambled = read_mbf_byte(buffer);
    } 
 
    close(fp);
    
    return 0;
}

int read_bsf_peripheral(int ascii, int *FLAG1, int *FLAG2, int *FLAG3,
      int *FLAG4)	{
    switch(ascii)	{
        case '1': /* 10001100 */
            *FLAG1 = 1;
            if(FLAG2 != NULL)
                *FLAG2 = 0;
            if(FLAG3 != NULL)
                *FLAG3 = 0;
            if(FLAG4 != NULL)
                *FLAG4 = 0;
            break;
        case '2': /* 01001100 */
            *FLAG1 = 0;
            *FLAG2 = 1;
            *FLAG3 = 0;
            *FLAG4 = 0;
            break;
        case '3': /* 11001100 */
            *FLAG1 = 1;
            *FLAG2 = 1;
            *FLAG3 = 0;
            *FLAG4 = 0;
            break;
        case '4': /* 00101100 */
            *FLAG1 = 0;
            *FLAG2 = 0;
            *FLAG3 = 1;
            *FLAG4 = 0;
            break;
        case '5': /* 10101100 */
            *FLAG1 = 1;
            *FLAG2 = 0;
            *FLAG3 = 1;
            *FLAG4 = 0;
            break;
        case '6': /* 01101100 */
            *FLAG1 = 0;
            *FLAG2 = 1;
            *FLAG3 = 1;
            *FLAG4 = 0;
            break;
        case '7': /* 11101100 */
            *FLAG1 = 1;
            *FLAG2 = 1;
            *FLAG3 = 1;
            *FLAG4 = 0;
            break;
        case '8': /* 00011100 */
            *FLAG1 = 0;
            *FLAG2 = 0;
            *FLAG3 = 0;
            *FLAG4 = 1;
            break;
        case '9': /* 10011100 */
            *FLAG1 = 1;
            *FLAG2 = 0;
            *FLAG3 = 0;
            *FLAG4 = 1;
            break;
        case 'A': /* 10000010 */
            *FLAG1 = 0;
            *FLAG2 = 1;
            *FLAG3 = 0;
            *FLAG4 = 1;
            break;
        case 'B': /* 01000010 */
            *FLAG1 = 1;
            *FLAG2 = 1;
            *FLAG3 = 0;
            *FLAG4 = 1;
            break;
        case 'C': /* 11000010 */
            *FLAG1 = 0;
            *FLAG2 = 0;
            *FLAG3 = 1;
            *FLAG4 = 1;
            break;
        case 'D': /* 00100010 */
            *FLAG1 = 1;
            *FLAG2 = 0;
            *FLAG3 = 1;
            *FLAG4 = 1;
            break;
        case 'E': /* 10100010 */
            *FLAG1 = 0;
            *FLAG2 = 1;
            *FLAG3 = 1;
            *FLAG4 = 1;
            break;
        case 'F': /* 01100010 */
            *FLAG1 = 1;
            *FLAG2 = 1;
            *FLAG3 = 1;
            *FLAG4 = 1;
            break;
        default: /* 0000110 or other */
            *FLAG1 = 0;
            if(FLAG2 != NULL)
                *FLAG2 = 0;
            if(FLAG3 != NULL)
                *FLAG3 = 0;
            if(FLAG4 != NULL)
                *FLAG4 = 0;
            break;
    }

    return 0;
}

int read_bsf(char *bsf)	{
    FILE *fp;
    typebsf bs;

    fp = fopen(bsf, "r");
    if(!fp)
        return -1;

    fread(bs.hardware_id, sizeof(bs.hardware_id) - 1, 1, fp);
    fread(bs.maker_id, sizeof(bs.maker_id) - 1, 1, fp);
    fread(bs.checksum, sizeof(bs.checksum) - 1, 1, fp);
    fseek(fp, 1, SEEK_CUR);
    fread(bs.disc_info, sizeof(bs.disc_info) - 1, 1, fp);
    fread(bs.area_symbols, sizeof(bs.area_symbols) - 1, 1, fp);
    fseek(fp, 5, SEEK_CUR);
    fread(bs.peripherals, sizeof(bs.peripherals) - 1, 1, fp);
    read_bsf_peripheral(bs.peripherals[0], &bs.expand_analog_vert,
          &bs.keyboard, &bs.gun, &bs.mouse);
    read_bsf_peripheral(bs.peripherals[1], &bs.analog_l_trigger,
          &bs.analog_vert_controller, &bs.analog_hor_controller,
          &bs.expand_analog_hor);
    read_bsf_peripheral(bs.peripherals[2], &bs.y_button,
          &bs.expand_dir_buttons, &bs.z_button, &bs.analog_r_trigger);
    read_bsf_peripheral(bs.peripherals[3], &bs.start_abdir_buttons,
          &bs.d_button, &bs.c_button, &bs.x_button);
    read_bsf_peripheral(bs.peripherals[4], &bs.other, &bs.microphone_card,
          &bs.purupuru_card, &bs.memory_card);
    read_bsf_peripheral(bs.peripherals[5], &bs.vga_box, NULL, NULL, NULL);
    read_bsf_peripheral(bs.peripherals[6], &bs.windowsce, NULL, NULL, NULL);
    fseek(fp, 1, SEEK_CUR);
    fread(bs.product_id, sizeof(bs.product_id) - 1, 1, fp);
    fseek(fp, 1, SEEK_CUR);
    fread(bs.product_version, sizeof(bs.product_version) - 1, 1, fp);
    fread(bs.release_date, sizeof(bs.release_date) - 1, 1, fp);
    fseek(fp, 8, SEEK_CUR);
    fread(bs.boot_filname, sizeof(bs.boot_filname) - 1, 1, fp);
    fread(bs.company_name, sizeof(bs.company_name) - 1, 1, fp);
    fread(bs.software_name, sizeof(bs.software_name) - 1, 1, fp);
    fseek(fp, 8556, SEEK_CUR);
    fread(bs.mr_trademark, sizeof(bs.mr_trademark), 1, fp);
    fread(bs.mr_sega, sizeof(bs.mr_sega), 1, fp);
    fseek(fp, 946, SEEK_CUR);
    fread(bs.mr_user, sizeof(bs.mr_user), 1, fp);

    fclose(fp);

    return 0;
}
