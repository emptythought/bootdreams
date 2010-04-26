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

typedef stuct {
    int unscrambled
    int sh_elf
    int scrambled
} typembf

typembf read_mbf(char *mbf);
typebsf read_bsf(char *bsf);
