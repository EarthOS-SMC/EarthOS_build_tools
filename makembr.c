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
	for(i=0; i < (4096-(fsize+1)); i++)
	{
		putc('0',fw);
	}
	fclose(fw);
	return 0;
}
