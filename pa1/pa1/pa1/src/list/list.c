#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[]) {


	struct Node {
		int val;
		struct Node *next;
	};
	
	
	struct Node *head = NULL;

	char cmd;
	int n;
	int check;

	while (1) {
		
		check = scanf(" %c %i", &cmd, &n);
		
		if (check != 2) {break;}


		
		if (cmd == 'i') {
			// printf("input\n");			

			// empty
			if (head == NULL) {
				// printf("write\n");
				head = malloc(sizeof(struct Node));
				head->val = n;
				head->next = NULL;
			}
			// insert before head
			else if (n < head->val) {
				// printf("newhead\n");
				struct Node *newnode = malloc(sizeof(struct Node));
				newnode->val = n;
				newnode->next = head;
				head = newnode; // pointers here idk?
			}
			// IF MIDDLE OR END
			else {

				int inserted = 0;

				struct Node *ptr1 = head;
				struct Node *prev = ptr1;
				
				while (ptr1 != NULL) {
					if (ptr1->val == n) {
						inserted = 1;
						break;
					}
				
					// insert in middle
					if (n < ptr1->val) {
						struct Node *newnode = malloc(sizeof(struct Node));
						newnode->val = n;
						newnode->next = ptr1;
						prev->next = newnode;
						inserted = 1;
						break;
					}
					prev = ptr1;
					ptr1 = ptr1->next;
				}

				// insert at end
				if (!inserted) {
					struct Node *newnode = malloc(sizeof(struct Node));
					newnode->val = n;
					newnode->next = ptr1;
					prev->next = newnode;
				}

				// free(ptr1);
				// free(prev);
				
			}

		}


		

		if (cmd == 'd') {

			struct Node *ptr1 = head;
			struct Node *prev = ptr1;
			
			while (ptr1 != NULL) {
			
				if (n == ptr1->val) {
					if (ptr1->val == prev->val) {
						head = head->next;
					}
					else {
						prev->next = ptr1->next;
					}
					free(ptr1);
					break;
				}
				prev = ptr1;
				ptr1 = ptr1->next;
			}


			
		}


		// printf("%i\n", head->val);
		int length = 0;
		struct Node *ptr1 = head; // pointers here idk?	// ALSO WTF I THOUGHT YOU COUDLN'T DECLARE MORE THAN ONCE LULWA
		while (ptr1 != NULL) {
			length++;
			ptr1 = ptr1->next;
		}

		printf("%i :", length);

		struct Node *ptr2 = head;
		while (ptr2 != NULL) {
			printf(" %i", ptr2->val);
			ptr2 = ptr2->next;
		}
		printf("\n");
		
	}

	struct Node *a = head;
	struct Node *b = a;
	
	while (a != NULL) {
		b = a->next;
		free(a);
		a = b;
	}


	return 0;

}