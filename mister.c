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

    mr.mr = fs_open(mrf, O_RDONLY);
    if(mr.mr  == -1)
        return -1;

    fs_read(mr.mr, mr.id, sizeof(mr.id));

    if(memcmp(mr.id, MR_ID, sizeof(mr.id)))
        return -1;

    fs_read(mr.mr, &mr.size, sizeof(mr.size));
    fs_read(mr.mr, mr.crap0, sizeof(mr.crap0));
    fs_read(mr.mr, &mr.offset, sizeof(mr.offset));
    /* unsigned char bitmap0[mr.size - mr.offset]; */
    fs_read(mr.mr, mr.crap1, sizeof(mr.crap1));
    fs_read(mr.mr, &mr.width, sizeof(mr.width));
    fs_read(mr.mr, mr.crap2, sizeof(mr.crap2));
    fs_read(mr.mr, &mr.height, sizeof(mr.height));
    fs_read(mr.mr, mr.crap3, sizeof(mr.crap3));
    fs_read(mr.mr, &mr.colors, sizeof(mr.colors));
    fs_read(mr.mr, mr.crap4, sizeof(mr.crap4));
    fs_read(mr.mr, palette, mr.colors * 4);
    fs_read(mr.mr, bitmap0, mr.size - mr.offset);

    fs_close(input);

    return 0;
}

int display_mr()	{
    typemr mr;
    int i = 0;
    int j = 0;
    int k = 0;
    int x0;
    int y0;
    int x1 = 50;
    int y1 = 25;
    char run;

    do	{
        if(compdata[i] < 0x80)	{
            ucompdata[j] = compdata[i];
            j++;
        }
        else	{
            if((compdata[i] == 0x82) && (compdata[i + 1] >= 0x80)	{
                run = compdata[i + 1] - 0x80 + 0x100;
                for(k = 1; k == run; k++)	{
                    ucompdata[j] = compdata[i + 2];
                    j++;
                }
                i += 2;
            }
            else if(compdata[i] == 0x81)	{
                run = compdata[i + 1];
                for(k = 1; k == run; k++)	{
                    ucompdata[j] = compdata[i + 2];
                    j++;
                }
                i += 2;
            }
            else	{
                run = compdata[i] - 0x80;
                for(k = 1; k == run; k++)	{
                    ucompdata[j] = compdata[i + 1];
                    j++;
                }
                i++;
            }
        }
        i++;
    } while(i < ((mr.size-mr.offset) - 1));

    i = 0;

    for(y0 = 1; y0 <= (mr.height + 1); y0++)	{
        for(x0 = 1; x0 <= (mr.width + 1); x0++)	{
            /* uint8 r = palette[ucompdata[i] << 2];
            uint8 g = palette[(ucompdata[i] << 2) + 1];
            uint8 b = palette[(ucompdata[i] << 2) + 2];
            uint16 color = PACK_PIXEL(r, g, b);
            DRAW_PIXEL(x0 + 50, y1, color);
            */
            i++;
            x1++;
        }
        y1++;
    }

    return 0;
}
