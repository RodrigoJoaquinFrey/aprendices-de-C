#include <stdio.h>

/*
void addone(int *n) {
    // n is a pointer here which point to a memory-adress outside the function scope
    (*n)++; // this will effectively increment the value of n
}

int n;
printf("Before: %d\n", n);
addone(&n);
printf("After: %d\n", n);

void move(point * p) {
    (*p).x++;
    (*p).y++;
}

void move(point * p) {
    p->x++;
    p->y++;
} */

typedef struct {
  char * name;
  int age;
} person;

/* function declaration */
void birthday(person * p);

/* write your function here */
void birthday(person * p){
    p->age++;
}

int main() {
  person john;
  john.name = "John";
  john.age = 27;

  printf("%s is %d years old.\n", john.name, john.age);
  birthday(&john);
  printf("Happy birthday! %s is now %d years old.\n", john.name, john.age);

  return 0;
}