#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int w_count = 1;
int f_check;

/* help message */
void print_help()
{
	puts("usage:");
	puts("\t$ upper [options] [text]");
	puts("options:");
	puts("\t-f\tfirst character only");
	exit(1);
}

int main(int argc, char *argv[])
{
	/* if there is no arguments print help message */
	if (argc < 2) 
		print_help();

	/* if option '-f' is enable */
	if (!strcmp(argv[1], "-f")) {
		/* option '-f' will be in argv[1] so the first word will be 2 */
		w_count = 2;
		f_check = 1;
	}

	/* print each word separately */
	while (w_count < argc) {
		/* if '-f' in middle exit with help message */
		if(w_count != 1 && !strcmp(argv[w_count], "-f"))
			print_help();
		/*print characters for each word */
		for (int j = 0; j < strlen(argv[w_count]); j += 1) {
			/* 
			 * if '-f' option is enable 
			 * then print uppercase first character only (arg[i][0])
			 * if '-f' option isn't enable
			 * then print uppercase all characters
			 */
			if (f_check == 1 && j == 0)
				putchar(toupper(argv[w_count][j]));
			else if (f_check == 1)
				putchar(argv[w_count][j]);
			else
				putchar(toupper(argv[w_count][j]));
		}
		/* put space after word if isn't the last word */
		if (w_count != (argc - 1))
			fputs(" ", stdout);
		/* move to the next word */
		w_count += 1;
	}
	return 0;
}
