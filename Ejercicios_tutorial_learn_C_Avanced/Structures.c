#include <stdio.h>


/* struct point {
    int x;
    int y;
};

 draws a point at 10, 5 
int x = 10;
int y = 5;
draw(x, y);

 draws a point at 10, 5 
struct point p;
p.x = 10;
p.y = 5;
draw(p);

typedef struct {
    int x;
    int y;
} point;

point p;

typedef struct {
    char * brand;
    int model;
} vehicle;

vehicle mycar;
mycar.brand = "Ford";
mycar.model = 2007; 
*/

/* define the person struct here using the typedef syntax */
typedef struct {
    char * name;
    int age;
} person;

int main() {
    person john;

    /* testing code */
    john.name = "John";
    john.age = 27;
    printf("%s is %d years old.", john.name, john.age);
}
