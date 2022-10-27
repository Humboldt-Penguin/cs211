#include <stdio.h>
#include <stdlib.h>
// #include <string.h>



int main(int argc, char *argv[]) {

	////////////////////////////////////////////////////////////////////////////////
	// read training data
	////////////////////////////////////////////////////////////////////////////////

	FILE *fin = fopen(argv[1], "r");
	int check;
	check = fscanf(fin, "%*[^\n]\n");
	int k, n;
	check = fscanf(fin, " %i", &k); // number of attributes
	check = fscanf(fin, " %i", &n); // number of houses
	// printf("%i %i", k, n);
	
	double *X, *Y;
	int xrow = k+1;
	X = malloc(n*(xrow) * sizeof(double)); // n x k+1
	Y = malloc(n*1 * sizeof(double)); // n x 1

	// for each line (representing a house) -- corresponds to X[n*x+y]
	for (int i = 0; i < n; i++) {
		// set first val in X to 1
		X[i*xrow + 0] = 1.0;		
		// for each num in the line
		for (int j = 1; j < k+1; j++) {
			check = fscanf(fin, "%lf", &X[i*xrow + j]);
		}
		check = fscanf(fin, "%lf", &Y[i]);
	}
	check = check+1;

	fclose(fin);

	int Xrowlen = k+1;
	int Xcollen = n;
	// int Ycollen = n;


	// // test inputfile read
	// // print X
	// printf("X\n");
	// for (int i = 0; i < Xcollen; i++) {
	// 	for (int j = 0; j < Xrowlen; j++) {
	// 		printf("%lf ", X[i*Xrowlen + j]); // NOTE that this format gives you standard matrix A_{i,j} style indexing
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// printf("\n");
	
	// printf("\n");
	// // print X^T
	// for (int i = 0; i < Xcollen; i++) {
	// 	for (int j = 0; j < Xrowlen; j++) {
	// 		printf("%lf ", X[i*Xrowlen + j]); // NOTE that this format gives you standard matrix A_{i,j} style indexing
	// 	}
	// 	printf("\n");
	// }





	// // print X indices
	// for (int i = 0; i < Xcollen; i++) {
	// 	for (int j = 0; j < Xrowlen; j++) {
	// 		printf("%i ", i*Xrowlen + j); // NOTE that this format gives you standard matrix A_{i,j} style indexing
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// // print X^T indices
	// for (int i = 0; i < Xrowlen; i++) {
	// 	for (int j = 0; j < Xcollen; j++) {
	// 		printf("%i ", j*Xrowlen + i); // NOTE that this format gives you standard matrix A_{i,j} style indexing
	// 	}
	// 	printf("\n");
	// }

	


	
	
	// // print Y
	// printf("Y\n");
	// for (int i = 0; i < Ycollen; i++) {
	// 	printf("%lf ", Y[i]);
	// 	printf("\n");
	// }
	// printf("\n\n");




	////////////////////////////////////////////////////////////////////////////////
	// read input data
	////////////////////////////////////////////////////////////////////////////////

	fin = fopen(argv[2], "r");
	
	check = fscanf(fin, "%*[^\n]\n");
	
	int newk, m;
	check = fscanf(fin, " %i", &newk); // number of attributes
	if (newk != k) {
		return 1;
	}
	check = fscanf(fin, " %i", &m); // number of houses

	double *input;
	input = malloc(m*(xrow) * sizeof(double));
	// printf("%i\n", m*xrow);

	// for each line (representing a house) -- corresponds to X[n*x+y]
	for (int i = 0; i < m; i++) {
		// set first val in X to 1
		input[i*xrow + 0] = 1.0;		
		// for each num in the line
		for (int j = 1; j < k+1; j++) {
			check = fscanf(fin, "%lf", &input[i*xrow + j]);
		}
	}

	fclose(fin);



	int inputcollen = m;
	int inputrowlen = k+1;

	// // test inputfile read
	// printf("input\n");
	// for (int i = 0; i < inputcollen; i++) {
	// 	for (int j = 0; j < inputrowlen; j++) {
	// 		printf("%lf ", input[i*inputrowlen + j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n\n");



	////////////////////////////////////////////////////////////////////////////////
	// X^T
	////////////////////////////////////////////////////////////////////////////////

	double *XT;
	XT = malloc(Xrowlen * Xcollen * sizeof(double));

	// XT is Xrowlen x Xcollen matrix

	for (int i = 0; i < Xrowlen; i++) {
		for (int j = 0; j < Xcollen; j++) {
			// printf("%i ", j*Xrowlen + i); 
			XT[i*Xcollen + j] = X[j*Xrowlen + i];
		}
		// printf("\n");
	}

	// // test XT
	// for (int i = 0; i < Xrowlen; i++) {
	// 	for (int j = 0; j < Xcollen; j++) {
	// 		printf("%lf ", XT[i*Xcollen + j]); // NOTE that this format gives you standard matrix A_{i,j} style indexing
	// 		// XT[i*Xcollen + j] = X[j*Xrowlen + i];
	// 	}
	// 	printf("\n");
	// }
	
	

	////////////////////////////////////////////////////////////////////////////////
	// X^T * X
	////////////////////////////////////////////////////////////////////////////////

	double *XTX;
	XTX = malloc(Xrowlen * Xrowlen * sizeof(double));

	// XT is Xrowlen x Xcollen matrix
	// X is Xcollen x Xrowlen matrix
	// XTX is Xrowlen x Xrowlen matrix

	for (int i = 0; i < Xrowlen; i++) {
		for (int j = 0; j < Xrowlen; j++) {
			double sum = 0;
			for (int k = 0; k < Xcollen; k++) {
				sum += XT[i*Xcollen + k] * X[k*Xrowlen + j];
			}
			XTX[i*Xrowlen + j] = sum;
		}
	}

	// // print XTX
	// printf("XTX\n");
	// for (int i = 0; i < Xrowlen; i++) {
	// 	for (int j = 0; j < Xrowlen; j++) {
	// 		printf("%lf ", XTX[i*Xrowlen + j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n\n");


	
	////////////////////////////////////////////////////////////////////////////////
	// XTX^-1
	////////////////////////////////////////////////////////////////////////////////

	double *I;
	I = malloc(Xrowlen * Xrowlen * sizeof(double));

	for (int i = 0; i < Xrowlen; i++) {
		for (int j = 0; j < Xrowlen; j++) {
			if (i == j) {
				I[i*Xrowlen + j] = 1.0;
			}
			else {
				I[i*Xrowlen + j] = 0.0;
			}
		}
	}

	// // print I PRE OPERATIONS
	// printf("I\n");
	// for (int i = 0; i < Xrowlen; i++) {
	// 	for (int j = 0; j < Xrowlen; j++) {
	// 		printf("%lf ", I[i*Xrowlen + j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n\n");
	
	// M: XTX is Xrowlen x Xrowlen matrix
	// N: I is Xrowlen x Xrowlen matrix

	n = Xrowlen;

	for (int p = 0; p < n; p++) {
		double f = XTX[p*Xrowlen+p];

		for (int z = 0; z < Xrowlen; z++) {
			XTX[p*Xrowlen + z] /= f;
			I[p*Xrowlen + z] /= f;
		}

		for (int i = p+1; i < n; i++) {
			f = XTX[i*Xrowlen+p];

			for (int z = 0; z < Xrowlen; z++) {
				XTX[i*Xrowlen + z] -= f * XTX[p*Xrowlen + z];
				I[i*Xrowlen + z] -= f * I[p*Xrowlen + z];
			}	
			
		}
	}

	for (int p = n-1; p >= 0; p--) {
		for (int i = p-1; i >= 0; i--) {
			double f = XTX[i*Xrowlen + p];

			for (int z = 0; z < Xrowlen; z++) {
				XTX[i*Xrowlen + z] -= f * XTX[p*Xrowlen + z];
				I[i*Xrowlen + z] -= f * I[p*Xrowlen + z];
			}	
		}
	}


	
	// // print I = XTX^-1
	// printf("XTX^-1\n");
	// for (int i = 0; i < Xrowlen; i++) {
	// 	for (int j = 0; j < Xrowlen; j++) {
	// 		printf("%lf ", I[i*Xrowlen + j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n\n");


	////////////////////////////////////////////////////////////////////////////////
	// I*X^T
	////////////////////////////////////////////////////////////////////////////////

	// I is Xrowlen x Xrowlen matrix
	// XT is Xrowlen x Xcollen matrix
	// IXT is Xrowlen x Xcollen matrix

	double *IXT;
	IXT = malloc(Xrowlen * Xcollen * sizeof(double));

	for (int i = 0; i < Xrowlen; i++) {
		for (int j = 0; j < Xcollen; j++) {
			double sum = 0;
			for (int k = 0; k < Xrowlen; k++) {
				sum += I[i*Xrowlen + k] * XT[k*Xcollen + j];
			}
			IXT[i*Xcollen + j] = sum;
		}
	}


	// // print IXT
	// printf("IXT\n");
	// printf("\n");
	// for (int i = 0; i < Xrowlen; i++) {
	// 	for (int j = 0; j < Xcollen; j++) {
	// 		printf("%lf ", IXT[i*Xcollen + j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// printf("\n");



	////////////////////////////////////////////////////////////////////////////////
	// I*X^T*Y
	////////////////////////////////////////////////////////////////////////////////

	// IXT is Xrowlen x Xcollen matrix
	// Y is a Ylen * 1 matrix

	double *W;
	W = malloc(Xrowlen * sizeof(double));

	for (int i = 0; i < Xrowlen; i++) {
		for (int j = 0; j < 1; j++) {
			double sum = 0;
			for (int k = 0; k < Xcollen; k++) {
				sum += IXT[i*Xcollen + k] * Y[k];
			}
			W[i] = sum;
		}
	}	

	// printf("W\n");
	// for (int i = 0; i < Xrowlen; i++) {
	// 	printf("%lf ", W[i]);
	// }
	// printf("\n\n");

	

	////////////////////////////////////////////////////////////////////////////////
	// input * W
	////////////////////////////////////////////////////////////////////////////////

	// input is inputcollen x inputrowlen matrix
	// W is Xrowlen x 1 matrix

	for (int i = 0; i < inputcollen; i++) {
		for (int j = 0; j < 1; j++) {
			double sum = 0;
			for (int k = 0; k < inputrowlen; k++) {
				sum += input[i*inputrowlen + k] * W[k];
			}
			printf("%i\n", (int)(sum+0.5));
		}
	}

	free(X);	
	free(Y);
	free(input);
	free(XT);
	free(XTX);
	free(I);
	free(IXT);
	free(W);





	

	return 0;

	
}