#include<stdio.h>
#include <stdlib.h>


/*typedef struct {
    char * name;
    int age;
} person;

person * myperson = (person *) malloc(sizeof(person));

myperson->name = "John";
myperson->age = 27;

free(myperson); */

typedef struct {
  int x;
  int y;
} point;

int main() {
  //point * mypoint = NULL;

  // Dynamically allocate a new point
  //   struct which mypoint points to here
  point * mypoint = (point *) malloc(sizeof(point));

  mypoint->x = 10;
  mypoint->y =5 ;
  printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);

  free(mypoint);
  return 0;
}