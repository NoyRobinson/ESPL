#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  /* TODO: Complete during task 2.a */
  for(int i = 0; i < array_length; i++)
    mapped_array[i] = f(array[i]);
  return mapped_array;
}

//Task 2b

/* Ignores c, reads and returns a character from stdin using fgetc. */
char my_get(char c){
  return fgetc(stdin);
}

/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c
 followed by a new line. Otherwise, cprt prints the dot ('.') character. 
 After printing, cprt returns the value of c unchanged. */
char cprt(char c){
  if(c > 0x20 && c < 0x7E)
    printf("%c \n", c);
  else
    printf(".\n");
  return c;
}

/* Gets a char c and returns its encrypted form by adding 1 to its value. 
If c is not between 0x20 and 0x7E it is returned unchanged */
char encrypt(char c){
  if(c > 0x20 && c < 0x7E)
    return c + 1;
  return c;
}

/* Gets a char c and returns its decrypted form by reducing 1 from its value. 
If c is not between 0x20 and 0x7E it is returned unchanged */
char decrypt(char c){
  if(c > 0x20 && c < 0x7E)
    return c - 1;
  return c;
}

/* xprt prints the value of c in a hexadecimal representation followed by a new line, 
and returns c unchanged. */
char xprt(char c){
  printf("%x\n", c);
  return c;
}

struct fun_desc{
  char* name;
  char (*fun)(char);
};

int main(int argc, char **argv){
//Task 3
  char* carray = malloc(5);
  struct fun_desc menu[] = {{"Get string", my_get}, {"Print string", cprt}, {"Encrypt", encrypt}, {"Decrypt", decrypt}, {"Print hex", xprt}, {NULL, NULL}};
  int menu_size = sizeof(menu) / sizeof(struct fun_desc) - 1;
  
  while(!feof(stdin)){ //until ctrl+D is pressed
    printf("Select operation from the following menu:\n");
    for(int i = 0; i < menu_size; i++)
      printf("%d) %s\n", i, menu[i].name);

    int option;
    char input[100];
    printf("option: ");
    fgets(input, 100, stdin);
    option = input[0] - '0';
    printf("\n");

    if(option < 0 || option > menu_size - 1){
        printf("Not within bounds\n");
        break;
    }
    printf("Within bounds\n");
    carray = map(carray, 5, menu[option].fun);
    printf("Done.\n");
    printf("\n");
  }
  free(carray);

  /* TODO: Test your code */
 //test task 2a
// char arr1[] = {'H','E','Y','!'};
// char* arr2 = map(arr1, 4, xprt);
// printf("%s\n", arr2);
// free(arr2);

  //test task 2b
  // int base_len = 5;
  // char arr1[base_len];
  // char* arr2 = map(arr1, base_len, my_get);
  // char* arr3 = map(arr2, base_len, cprt);
  // char* arr4 = map(arr3, base_len, xprt);
  // char* arr5 = map(arr4, base_len, encrypt);
  // char* arr6 = map(arr5, base_len, decrypt);
  // printf(arr2);
  // printf(arr3);
  // printf(arr4);
  // printf(arr5);
  // printf(arr6);
  // free(arr2);
  // free(arr3);
  // free(arr4);
  // free(arr5);
  // free(arr6);
}

