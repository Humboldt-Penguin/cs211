#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


struct Node *head;


struct Node {
	int val;
	struct Node *next;
};


void push(int x) {
	if (head == NULL) {
		head = malloc(sizeof(struct Node));
		head->val = x;
		head->next = NULL;
	}
	else {
		struct Node *ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		struct Node *newnode = malloc(sizeof(struct Node));
		newnode->val = x;
		newnode->next = NULL;
		ptr->next = newnode;
	}
}

int pop() {
	if (head == NULL) 
		return -1234;
	else {
		struct Node *ptr = head;
		struct Node *pre = head;

		while (ptr->next != NULL) {
			pre = ptr;
			ptr = ptr->next;
		}
		int x = ptr->val;
		pre->next = NULL;
		if (ptr == head) {
			head = NULL;
		}
		free(ptr);
		
		return x;
	}
	return -1234;
}


void display() {
	struct Node *ptr = head;
	while (ptr != NULL) {
		printf("%i ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");
}

// struct Node* newNode(int x) {
// 	struct Node *newnode = malloc(sizeof(struct Node));
// 	newnode->val = x;
// 	newnode->left = NULL;
// 	newnode->right = NULL;
// 	return newnode;
// }



int main(int argc, char *argv[]) {

	if (argc != 2) {return 1;}
	char *input = argv[1];


	// // check if it's just a single input
	// int aa;
	// char *aaa;
	// int check = sscanf(input, "%i%s", &aa, aaa);
	// if (check == 2) {
	// 	printf("%i\n", aa);
	// 	return 0;
	// }
	// int didanything;
	
	
	
	// struct Node *ptr = head;
	char num[50] = "";
	
	for (int i = 0; i < strlen(input); i++) {

		if (isdigit(input[i])) {
			char temp[2] = {input[i], '\0'};
			strcat(num, temp);
		}
		else { // non digit
			// didanything = 1;
			// if we're finishing a digit, push to stack
			if (strcmp(num, "") != 0) {
				push(atoi(num));
				strcpy(num, "");
			}

			// display();

			//// handle special characters

			// comma
			if (input[i] == ',') {
				continue;
			}
			else {

				int b = pop();
				int a = pop();
				if (a == -1234 || b == -1234) {
					printf("error: not enough digits\n");
					return 1;
				}

				switch (input[i]) {
					case '+':
						push(a+b);
						break;
					case '-':
						push(a-b);
						break;
					case 'x':
						push(a*b);
						break;
					case '/':
						push((int)(a/b));
						break;
					default:
						printf("error: character is not a valid rpn operator\n");
						return 1;
				}


				

				// if (strcmp(input[i], "+") == 0) {
				// 	push(a+b);
				// }
				// else if (strcmp(input[i], "-") == 0) {
				// 	push(a-b);
				// }
				// else if (strcmp(input[i], "*") == 0) {
				// 	push(a*b);
				// }
				// else if (strcmp(input[i], "/") == 0) {
				// 	push((int)(a/b));
				// }
				// else {
				// 	printf("error: character is not a valid rpn operator\n");
				// 	return 1;
				// }



				
			}



		}
	}


	// display();
	// printf("%i\n", pop());
	// display();


	int fuck; char you = 'z';
	int check = sscanf(input, "%i%c", &fuck, &you);
	check += 1;
	
	if (you == 'z') {
		printf("%i\n", fuck);
	}
	else {

		if (strcmp(num, "") != 0) {
			printf("error: number at end (or standalone number?)\n");
			return 1;
		}
	
	
	
		int result = pop();
	
		if (pop() != -1234) {
			printf("error: numbers still in stack\n");
			return 1;
		}
	
		printf("%i\n",result);
	}

	
	struct Node *ptr = head;
	struct Node *ptrr = head;
	while (ptr != NULL) {
		free(ptr);
		ptr = ptrr->next;
	}
	
	

	return 0;
}