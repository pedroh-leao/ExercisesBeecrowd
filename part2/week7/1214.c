#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int students;
    int *grades;
}Class;

double aboveAverage(int *grades, int n){
    double average = 0;
    for (int i = 0; i < n; i++)
            average += grades[i];

    average /= n;
    
    int sumAboveAverage = 0;
    for (int i = 0; i < n; i++)
        if(grades[i] > average)
            sumAboveAverage++;

    return ((double)sumAboveAverage / n) * 100;
} 

int main(){
    int testCases;
    scanf("%d", &testCases);

    Class class;

    for (int i = 0; i < testCases; i++){
        scanf("%d", &class.students);

        class.grades = (int *) malloc(class.students * sizeof(int));

        for(int j = 0; j < class.students; j++)
            scanf("%d", &class.grades[j]);

        printf("%.3lf%%\n", aboveAverage(class.grades, class.students));
    }
    

    return 0;
}