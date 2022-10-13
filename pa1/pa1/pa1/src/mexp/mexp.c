#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char *argv[]) {

	FILE *fin = fopen(argv[1], "r");

	int dim = 0;
	int check = fscanf(fin, " %i", &dim);
	check = check + 1;
	// printf("%i\n", dim);

	int *arr1;
	arr1 = malloc(dim*dim * sizeof(int));
	
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			check = fscanf(fin, "%i", &arr1[i*dim + j]);		
		}
	}

	int pow;
	check = fscanf(fin, "%i", &pow);
	check = check + 1;
	fclose(fin);


	
	// // TEST text file read

	// printf("%i\n", dim);
	
	// for (int i = 0; i < dim; i++) {
	// 	for (int j = 0; j < dim; j++) {
	// 		printf("%i ", arr1[i*dim + j]);
	// 	}
	// 	printf("\n");
	// }

	// printf("%i\n", pow);

	if (pow == 0) {
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if (i==j) {
					printf("1 ");
				}
				else {
					printf("0 ");
				}
			}
			printf("\n");
		}
		return 0;
	}


	
	// deep copy arr1 into arr2
	int *arr2;
	arr2 = malloc(dim*dim * sizeof(int));
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			arr2[i*dim + j] = arr1[i*dim + j];
		}
	}

	for (int p = 0; p < pow-1; p++) {
		int *arr3;
		arr3 = malloc(dim*dim * sizeof(int));

		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				int sum = 0;
				for (int k = 0; k < dim; k++) {
					sum += arr1[i*dim + k] * arr2[k*dim + j];
				}
				arr3[i*dim + j] = sum;
			}
		}
		free(arr1);
		arr1 = arr3;
		// free(arr3);

	}
	free(arr2);




	
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			printf("%i", arr1[i*dim + j]);
			if (j < dim-1) printf(" ");
		}
		printf("\n");
	}
	free(arr1);



	

	

	return 0;

}