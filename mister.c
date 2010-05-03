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

#include "mister.h"

int read_mr(char *mrf)	{
    typemr mr;

    input = fs_open(mrf, O_RDONLY);
    if(input == -1)
        return -1;

    fs_read(input, mr.id, sizeof(mr.id));

    if(memcmp(mr.id, MR_ID, sizeof(mr.id)))
        return -1;

    fs_read(input, &mr.size, sizeof(mr.size));
    fs_read(input, mr.crap0, sizeof(mr.crap0));
    fs_read(input, &mr.offset, sizeof(mr.offset));
    unsigned char bitmap0[mr.size - mr.offset];
    unsigned char bitmap1[(mr.width * mr.height) + 2];
    fs_read(input, mr.crap1, sizeof(mr.crap1));
    fs_read(input, &mr.width, sizeof(mr.width));
    fs_read(input, mr.crap2, sizeof(mr.crap2));
    fs_read(input, &mr.height, sizeof(mr.height));
    fs_read(input, mr.crap3, sizeof(mr.crap3));
    fs_read(input, &mr.colors, sizeof(mr.colors));
    unsigned char palette[mr.colors * 4];
    fs_read(input, mr.crap4, sizeof(mr.crap4));
    fs_read(input, palette, mr.colors * 4);
    fs_read(input, bitmap0, mr.size - mr.offset);


    /*
    sprintf(myString, "%d", mr.size);
    bfont_draw_str(vram_s + 140*640+50, 640, 0, "Size  : ");
    bfont_draw_str(vram_s + 140*640+146, 640, 0, myString);

    sprintf(myString, "%d", mr.offset);
    bfont_draw_str(vram_s + 165*640+50, 640, 0, "Offset: ");
    bfont_draw_str(vram_s + 165*640+146, 640, 0, myString);

    sprintf(myString, "%d", mr.width);
    bfont_draw_str(vram_s + 190*640+50, 640, 0, "Width : ");
    bfont_draw_str(vram_s + 190*640+146, 640, 0, myString);

    sprintf(myString, "%d", mr.height);
    bfont_draw_str(vram_s + 215*640+50, 640, 0, "Height: ");
    bfont_draw_str(vram_s + 215*640+146, 640, 0, myString);

    sprintf(myString, "%d", mr.colors);
    bfont_draw_str(vram_s + 240*640+50, 640, 0, "Colors: ");
    bfont_draw_str(vram_s + 240*640+146, 640, 0, myString);
    */

    fs_close(input);

    return 0;
}

int display_mr()	{
    typemr mr;

    /* char Run;
    char myString[100];
    int input;
    int i=0, j=0, k=0;
    int x1, y1;
    int x2=50, y2=25;
    */

    do	{
        if(compdata[i] < 0x80)	{
            ucompdata[j] = compdata[i];
            j++;
        }
        else	{
            if((compdata[i] == 0x82) && (compdata[i + 1] >= 0x80)	{
                Run = compdata[i + 1] - 0x80 + 0x100;
                for(k = 1; k == Run; k++)	{
                    ucompdata[j] = compdata[i + 2];
                    j++;
                }
                i += 2;
            }
            else if(compdata[i] == 0x81)	{
                Run = compdata[i + 1];
                for(k = 1; k == Run; k++)	{
                    ucompdata[j] = compdata[i + 2];
                    j++;
                }
                i += 2;
            }
            else	{
                Run = compdata[i] - 0x80;
                for(k = 1; k == Run; k++)	{
                    ucompdata[j] = compdata[i + 1];
                    j++;
                }
                i++;
            }
        }
        i++;
    } while(i < ((mr.size-mr.offset) - 1));

    i = 0;

    for(y1 = 1; y1 <= (mr.height + 1); y1++)	{
        for(x1 = 1; x1 <= (mr.width + 1); x1++)	{
            /* uint8 r = palette[ucompdata[i] << 2];
            uint8 g = palette[(ucompdata[i] << 2) + 1];
            uint8 b = palette[(ucompdata[i] << 2) + 2];
            uint16 color = PACK_PIXEL(r, g, b);
            DRAW_PIXEL(x1 + 50, y2, color);
            */
            i++;
            x2++;
        }
        y2++;
    }

    return 0;
}
