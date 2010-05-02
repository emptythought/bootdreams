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

int display_mr()	{
    typemr mr;

    /* char Run;
    char myString[100];
    int input;
    int i=0, j=0, k=0;
    int x1, y1;
    int x2=50, y2=25;
    */

    input = fs_open("/rd/mrtest.mr", O_RDONLY);
    if(input == -1)
        return -1;

    fs_read(input, mr.id, sizeof(mr.id));

    if(memcmp(mr.id, MR_ID, sizeof(mr.id)))
        return -1;

    fs_read(input, &mr.size, sizeof(mr.size));
    fs_read(input, mr.crap0, sizeof(mr.crap0));
    fs_read(input, &mr.offset, sizeof(mr.offset));
    fs_read(input, mr.crap1, sizeof(mr.crap1));
    fs_read(input, &mr.width, sizeof(mr.width));
    fs_read(input, mr.crap2, sizeof(mr.crap2));
    fs_read(input, &mr.height, sizeof(mr.height));
    fs_read(input, mr.crap3, sizeof(mr.crap3));
    fs_read(input, &mr.colors, sizeof(mr.colors));
    fs_read(input, mr.crap4, sizeof(mr.crap4));

    unsigned char palette[mr.colors * 4];
    fs_read(input, palette, mr.colors * 4);

    unsigned char compdata[mr.size - mr.offset];
    fs_read(input, compdata, mr.size - mr.offset);

    unsigned char ucompdata[(mr.width*mr.height) + 2];

            /* do
            {
                if (compdata[i] < 0x80)
                {
                    ucompdata[j] = compdata[i]; //the byte values lower than 128 are recopied just as they are in the bitmap
                    j++;
                }
                else
                {
                    if ((compdata[i] == 0x82) && (compdata[i + 1] >= 0x80))
                    {
                        //the tag 0x82 is followed Nb of points decoded in Run
                        Run = compdata[i + 1] - 0x80 + 0x100;

                        for (k = 1; k == Run; k++)
                        {
                            ucompdata[j] = compdata[i + 2];  //by retaining only the 1° byte for each point
                            j++;
                        }

                        i += 2;
                    }
                    else if (compdata[i] == 0x81)
                    {
                        //the tag 0x81 is followed of a byte giving Nb of points directly
                        Run = compdata[i + 1];

                        for (k = 1; k == Run; k++)
                        {
                            ucompdata[j] = compdata[i + 2]; //idem : 1° byte on 2
                            j++;
                        }

                        i += 2;
                    }
                    else
                    {
                        //if > 0x82 => code for Nb of points decoded in run
                        Run = compdata[i] - 0x80;

                        for (k = 1; k == Run; k++)
                        {
                            ucompdata[j] = compdata[i + 1]; //coded on only one byte
                            j++;
                        }

                        i++;
                    }
                }

                i++;
            } while (i < ((mr.size-mr.offset) - 1));

            i=0;

            // Draw the uncompressed data
            for (y1 = 1; y1 <= (mr.height + 1); y1++)
            {
                for (x1 = 1; x1 <= (mr.width + 1); x1++)
                {
                    uint8 r = palette[ucompdata[i] << 2];
                    uint8 g = palette[(ucompdata[i] << 2) + 1];
                    uint8 b = palette[(ucompdata[i] << 2) + 2];
                    uint16 color = PACK_PIXEL(r, g, b);

                    // Draw the pixel
                    DRAW_PIXEL(x1 + 50, y2, color);

                    i++;
                    x2++;
                }

                y2++;
            }

            // Draw values to screen
            bfont_draw_str(vram_s + 140*640+50, 640, 0, "Size  : ");
            sprintf(myString, "%d", mr.size);
            bfont_draw_str(vram_s + 140*640+146, 640, 0, myString);

            bfont_draw_str(vram_s + 165*640+50, 640, 0, "Offset: ");
            sprintf(myString, "%d", mr.offset);
            bfont_draw_str(vram_s + 165*640+146, 640, 0, myString);

            bfont_draw_str(vram_s + 190*640+50, 640, 0, "Width : ");
            sprintf(myString, "%d", mr.width);
            bfont_draw_str(vram_s + 190*640+146, 640, 0, myString);

            bfont_draw_str(vram_s + 215*640+50, 640, 0, "Height: ");
            sprintf(myString, "%d", mr.height);
            bfont_draw_str(vram_s + 215*640+146, 640, 0, myString);

            bfont_draw_str(vram_s + 240*640+50, 640, 0, "Colors: ");
            sprintf(myString, "%d", mr.colors);
            bfont_draw_str(vram_s + 240*640+146, 640, 0, myString);
        }

        fs_close(input);
    }

   // Pause to see the results
   thd_sleep(5*1000*1000); */

    return 0;
}
