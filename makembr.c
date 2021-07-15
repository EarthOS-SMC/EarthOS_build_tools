/*
 * makembr.c
 * This file is part of EarthOS build tools
 *
 * Copyright (C) 2021 - adazem009
 *
 * EarthOS build tools is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * EarthOS build tools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EarthOS build tools. If not, see <http://www.gnu.org/licenses/>.
 */
#include<stdio.h>
#include<stdlib.h>
void print_usage(char *cmdarg)
{
	printf("Usage: %s <filename>\n",cmdarg);
}
int main(int argc, char *argv[])
{
	int fsize,i;
	if(argc != 2)
	{
		print_usage(argv[0]);
		exit(1);
	}
	FILE *fr, *fw;
	fr = fopen(argv[1],"r");
	// Get file size
	fseek(fr,0L,SEEK_END);
	fsize=ftell(fr);
	rewind(fr);
	// Check MBR size
	if(fsize+1 > 4096)
	{
		printf("%s: MBR is too large\n",argv[0]);
		exit(2);
	}
	// Add '0' chars
	fclose(fr);
	fw = fopen(argv[1],"a");
	for(i=0; i < (4096-fsize); i++)
	{
		putc('0',fw);
	}
	fclose(fw);
	return 0;
}
