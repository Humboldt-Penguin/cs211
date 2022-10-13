#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
    

typedef struct Stack
{
	int data;
	struct Stack *next;
} Stack;

int debug = 0;
int size = 0;

void push(Stack **root, int value);
int pop(Stack **root);
void calculate(Stack** root, char c);



int main() {

	Stack* root = NULL;
   // int d;
   // if (scanf("%d", &d) == 1) {
   //    if (debug == 1) printf("Read from file: %d\n", d);
   //    push(&root, d);   
   // } else {
   //    exit(EXIT_FAILURE);
   // }
   // char c;
   // while (scanf("%c", &c) != EOF) { 
      
   //    if (debug == 1) printf("Read from file: %c\n", c);
      
   //    if (c != ',') {
   //       calculate( &root, c);
   //       int idekrn;
   //       while (scanf("%d", &idekrn) != 1 && scanf("%d", &idekrn) != EOF )
   //       {
   //          char random_name;
   //          if ((scanf("%c", &random_name) != EOF)) {
   //             calculate( &root, random_name);
   //          }
   //       }
   //       push(&root, idekrn);
         
   //    } else {
   //       int d;
   //       if (scanf("%d", &d) == 1) {
   //          if (debug == 1) printf("Read from file: %d\n", d);
   //          push(&root, d);   
   //       } else {
   //          exit(EXIT_FAILURE);
   //       }
   //    }
   // }

   int d;
   while (scanf("%d", &d) != EOF) {
      if (debug == 1) printf("Read from file: %c\n", d);
      push(&root, d); 

      char c;
      int asdfasd = scanf("%c", &c);

      if (c != ',') {
         calculate( &root, c);
      }
   }


   if (debug == 1) printf("%s\n", "REACHED END OF FILE");
   printf("%d\n", pop(&root));
   if (size != 0) {
      exit(EXIT_FAILURE);
   }

   return EXIT_SUCCESS;

}


void push( Stack **root, int value ) {
	Stack* Node = malloc(sizeof(Stack) );

	Node->data = value;
	Node->next = *root;
	*root = Node;
   size++;
   if (debug == 1) printf("Pushed: %d\n", value);

}

int pop( Stack **root) {
	if( *root == NULL ) {
		exit(EXIT_FAILURE);
	} else {
		Stack* top = *root;
		int value = top->data;
		*root = top->next;
		free(top);
      size--;
		return value;
	}
}

void calculate(Stack** root, char c) {
   int placeholder;
   int result;

   switch(c) {
      case '+':
         if (debug == 1) printf("%s\n", "add");
         result = pop(root) + pop(root);
         break;
      case '-':
         if (debug == 1) printf("%s\n", "subtract");
         placeholder = pop(root);
         result = pop(root) - placeholder;
         break;
      case '/':
         if (debug == 1) printf("%s\n", "divide");
         placeholder = pop(root);
         if (placeholder == 0) {
            exit(EXIT_FAILURE);
         }
         result = pop(root) / placeholder;
         break;
      case 'x':
         if (debug == 1) printf("%s\n", "multiply");
         result = pop(root) * pop(root);
         break;
   }
   push(root, result);

}