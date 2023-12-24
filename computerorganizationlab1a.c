#include <stdio.h> 
int main() 
{ 
 printf("Enter the number of reptitions for the punishment phrase: ");

 int repetitions;

 scanf("%d", &repetitions);

if (repetitions >= 1){
    printf("\n");
}

 int x = 1;

 while(x != 0){
    if (repetitions <= 0){
        printf("You entered an invalid value for the number of repetitions!\n");

        printf("Enter the number of reptitions for the punishment phrase again: ");
        scanf("%d", &repetitions);

        if (repetitions >= 1){
            printf("\n");
        }
    }
    else{
        x = 0;
    }
 }

 printf("Enter the line where you wish to introduce the typo: ");

 int typo;

 scanf("%d", &typo);

 int y = 1;

 while(y != 0){
    if (typo > repetitions || typo <= 0){
        printf("You entered an invalid value for the typo placement!\n");

        printf("Enter the line where you wish to introduce the typo: ");
        scanf("%d", &typo);

        if (typo >= 1 && typo < repetitions){
            printf("\n");
        }
    }
    else{
        y = 0;
    }
 }

 printf("\n");

 for(int i = 1; i <= repetitions; i++){
    if (i == typo){
        printf("Cading in C is fun end intreseting!\n");
    }
    else{
        printf("Coding in C is fun and interesting!\n");
    }
 }
}
