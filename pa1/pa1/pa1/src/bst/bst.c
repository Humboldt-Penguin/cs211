#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int size = 0;
char s[500] = "";


struct Node {
	int val;
	struct Node *left;
	struct Node *right;
};


struct Node* newNode(int x) {
	struct Node *nood = malloc(sizeof(struct Node));
	nood->val = x;
	nood->left = NULL;
	nood->right = NULL;
	// printf("newNode\n");
	size++;
	return nood;
}



struct Node* insert(struct Node *root, int x) {
	struct Node *ptr = root;
	struct Node *prev = ptr;

	if (root == NULL) {
		// struct Node *newnode;
		// newnode = newNode(x);
		// root = newnode;
		root = newNode(x);
		// printf("inserted (root)\n");
		printf("inserted\n");
		return root;
	}

	int dir;

	while (ptr != NULL) {
		if (x == ptr->val) {
			printf("not inserted\n");
			return root;
		}
		else if (x < ptr->val) {
			prev = ptr;
			ptr = ptr->left;
			dir = 0;
		}
		else {
			prev = ptr;
			ptr = ptr->right;
			dir = 1;
		}
	}

	struct Node *newnode;
	newnode = newNode(x);
	if (dir == 0) {
		prev->left = newnode;
		// printf("inserted (left)\n");
		printf("inserted\n");
	}
	else {
		prev->right = newnode;
		// printf("inserted (right)\n");
		printf("inserted\n");
	}
	return root;
}



int search(struct Node *root, int x) {
	struct Node *ptr = root;
	while (ptr != NULL) {
		if (x == ptr->val) {
			return 1;
		}
		else if (x < ptr->val) {
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;
		}
	}
	return 0;
}




struct Node* findMin(struct Node* ptr) {
	struct Node* cur = ptr;
	while (cur && cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}


struct Node* delete(struct Node *root, int target) {
	if (root == NULL)
		return root;
	
	if (target > root->val) {
		root->right = delete(root->right,target);
	}
	else if (target < root->val) {
		root->left = delete(root->left,target);
	}
	else {
		if (root->left == NULL) {
			struct Node* meow = root->right;
			free(root);
			return meow;
		}
		else if (root->right == NULL) {
			struct Node* meow = root->left;
			free(root);
			return meow;
		}
		struct Node* meow = findMin(root->right);
		root->val = meow->val;
		root->right = delete(root->right, meow->val);
	}
	return root;
}









void print(struct Node *ptr) {
	// if (ptr->left == NULL && ptr->right == NULL) {
	// 	// char str[100];
	// 	int check = sprintf(s, "(%i)", ptr->val);
	// 	return s;
	// }
	// else {
	// 	// char str[100];
	// 	int check = sprintf(s, "(%s%i%s)", print(ptr->left, s), ptr->val, print(ptr->right, s));
	// 	return s;
	// }
	strcat(s, "(");
	if (ptr != NULL) {
		if (ptr->left != NULL) {
			print(ptr->left);
		}
		char ss[1000];
		sprintf(ss, "%i", ptr->val);
		strcat(s,ss);
		if (ptr->right != NULL) {
			print(ptr->right);
		}
	}
	strcat(s,")");
	if (strcmp(s, "()") == 0) {
		memset(s,0,strlen(s));
	}
	
}

void freeall (struct Node *root) {
	if (root == NULL) {
		return;
	}
	if (root->left != NULL) {
		freeall(root->left);
	}
	if (root->right != NULL) {
		freeall(root->right);
	}
	free(root);
}











int main(int argc, char *argv[]) {

	
	// struct Node *root = NULL;
	// root = newNode(1);
	// int i = insert(root, 2);
	// printf("%i\n", root->right->val);

	// struct Node *root = NULL;
	// int i = insert(root, 1);




	struct Node *root = NULL;

	char cmd;
	int n;
	int check;

	while (1) {
		// check = scanf(" %c %i", &cmd, &n);
		check = scanf(" %c", &cmd);
		if (check < 1) {break;}
		
		if (cmd == 'i') {
			check = scanf(" %i", &n);
			root = insert(root, n);
		}

		if (cmd == 's') {
			check = scanf(" %i", &n);
			int found = search(root, n);
			if (found) {
				printf("present\n");
			}
			else {
				printf("absent\n");
			}
		}

		if (cmd == 'p') {
			// char s[size*3+10];
			// memset(s, '\0', sizeof(s));
			// struct Node *ptr = root;
			// char *s1 = print(ptr, s);
			// printf("%s", s);

			struct Node *ptr = root;
			memset(s,0,strlen(s));
			print(ptr);
			printf("%s\n", s);
			
			
		}

		if (cmd == 'd') {
			check = scanf(" %i", &n);
			int present = search(root, n);
			if (!present) {
				printf("absent\n");
			}
			else {
				// struct Node *ptr = root;
				root = delete(root, n);
				printf("deleted\n");
				// delete(root,n);
			}
		}

		
		

		
	}

	freeall(root);
	

	
	return 0;
}