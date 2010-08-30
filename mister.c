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

#include <stdio.h>

#include "mister.h"

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
    fread(mr.crap0, sizeof(mr.crap0), 1, fp);
    fread(&mr.offset, sizeof(mr.offset), 1, fp);
    /* unsigned char bitmap0[mr.size - mr.offset]; */
    fread(mr.crap1, sizeof(mr.crap1), 1, fp);
    fread(&mr.width, sizeof(mr.width), 1, fp);
    fread(mr.crap2, sizeof(mr.crap2), 1, fp);
    fread(&mr.height, sizeof(mr.height), 1, fp);
    fread(mr.crap3, sizeof(mr.crap3), 1, fp);
    fread(&mr.colors, sizeof(mr.colors), 1, fp);
    fread(mr.crap4, sizeof(mr.crap4), 1, fp);
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
    } while(i < ((mr.size-mr.offset) - 1));

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
            /* uint8 r = palette[mr.bitmap_uncompress[i] << 2];
            uint8 g = palette[(mr.bitmap_uncompress[i] << 2) + 1];
            uint8 b = palette[(mr.bitmap_uncompress[i] << 2) + 2];
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
