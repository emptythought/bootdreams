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
