#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 5

struct Students
{
    int studentNumber;
    float quiz1;
    float quiz2;
    float midFinal1;
    float midFinal2;
    float average;
    char letterGrade[10];
};

void input(struct Students * arr);
void computeGrade(struct Students * arr);
void output(struct Students * arr);

int main()
{    
    struct Students arr_student[MAX];
    input(arr_student);

    return 0;
}

void input(struct Students * arr)
{
    int i = 0;

    while(i < 5)
    {
        i++;

        printf("\nEnter student number: ");
        scanf("%d", &arr[i].studentNumber);

        printf("Enter two ten point quizes: ");
        scanf("%f %f", &arr[i].quiz1, &arr[i].quiz2);

        printf("Enter the midterm and final exam grades. These are 100 point tests: ");  
        scanf("%f %f", &arr[i].midFinal1, &arr[i].midFinal2);
    }

    printf("\n"); 

    computeGrade(arr);
}

void output(struct Students * arr)
{
    int i;

    for(i = 1; i <= MAX; i++)
    {
        printf("The record for student number: %d\nThe quiz grades are: %.0f %.0f\nThe midterm and exam grades are: %.0f %.0f\nThe numeric average is: %.2f\nand the letter grade assigned is %s\n\n", arr[i].studentNumber, arr[i].quiz1, arr[i].quiz2, arr[i].midFinal1, arr[i].midFinal2, arr[i].average, arr[i].letterGrade);
    }
}

void computeGrade(struct Students * arr)
{
    int i;
    
    for(i = 1; i <= MAX; i++)   
    {
        arr[i].average = ((arr[i].quiz1 * 10) + (arr[i].quiz2 * 10) + arr[i].midFinal1 + arr[i].midFinal2) / 4;
        
        if(arr[i].average >= 90) 
        {
            strcpy(arr[i].letterGrade, "A");    
        }
        else if(arr[i].average >= 80 && arr[i].average < 90) 
        {
            strcpy(arr[i].letterGrade, "B");    
        }
        else if(arr[i].average >= 70 && arr[i].average < 80) 
        {
            strcpy(arr[i].letterGrade, "C");   
        }
        else if(arr[i].average >= 60 && arr[i].average < 70) 
        {
            strcpy(arr[i].letterGrade, "D");   
        }
        else 
        {
            strcpy(arr[i].letterGrade, "F");   
        }
    }
    output(arr);
}   