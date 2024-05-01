#include <stdio.h>
#include <stdlib.h>
int main() {

    printf("*******************************************************************\nGPA CALCULATOR\n");
    printf("*******************************************************************");
    int courses;
    printf("\nEnter number of courses: ");
    scanf("%d",&courses);

    int *grades,*credits;
    int i=0;
    float total=0.0;

    grades = malloc(courses*sizeof(int));
    if ( grades == NULL ){
        printf("Failed to allocate memory.");
        exit(1);
    }

    credits = malloc(courses*sizeof(int));
    if ( credits == NULL ){
        printf("Failed to allocate memory.");
        exit(1);
    }

    for(i=0; i<courses; i++) {
        printf("Enter grade for course %d: ", i + 1);
        scanf("%d", (grades + i));
    }

    int totalcredits=0;
    printf("\n");

    for(i=0; i<courses; i++){
        printf("Enter credit for course %d: ",i+1);
        scanf("%d",(credits+i));
        totalcredits += *(credits+i);
    }
    for(i=0; i<courses; i++){
        if (*(grades+i) >=90)
            total += *(credits+i)*4.0;
        else if (*(grades+i) >=85)
            total += *(credits+i)*3.50;
        else if (*(grades+i) >=80)
            total += *(credits+i)*3.0;
        else if (*(grades+i) >=75)
            total += *(credits+i)*2.5;
        else if (*(grades+i) >=70)
            total += *(credits+i)*2.0;
        else if (*(grades+i) >=65)
            total += *(credits+i)*1.50;
        else if (*(grades+i) >=60)
            total += *(credits+i)*1.0;
        else if (*(grades+i) >=50)
            total += *(credits+i)*0.5;
        else
            total += *(credits+i)*0.0;

    }

    float gpa;
    gpa = (float)total/totalcredits;
    printf("GPA=%.2f\n",gpa);

    free(grades);
    free(credits);
    return 0;
}
