#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {return 1;}
	for (int i = 0; i < strlen(argv[1]); i++) {
		// printf("%i\n", argv[1][i]);
		if (argv[1][i] >= 65 && argv[1][i] < 65+26) {
			printf("%c", (argv[1][i]-65+13)%26+65);
		}
		else if (argv[1][i] >= 97 && argv[1][i] < 97+26) {
			printf("%c", (argv[1][i]-97+13)%26+97);
		}
		else {
			printf("%c", argv[1][i]);
		}
	}
	printf("\n");
	return 0;
}