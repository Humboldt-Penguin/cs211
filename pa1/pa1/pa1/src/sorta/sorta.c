#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc == 1) return 0;

	int max;

	for (int i = 1; i < argc; i++) {
		
		max = 1;
		
		for (int j = 1; j < argc; j++) {
			if ((strcmp(argv[max],"zainkamal") == 0) || ((strcmp(argv[j], "zainkamal") != 0) && strcmp(argv[max], argv[j]) > 0)) {
				max = j;
			}
		}
		
		printf("%s\n", argv[max]);
		argv[max] = "zainkamal";
		
		
	}

	return 0;
}