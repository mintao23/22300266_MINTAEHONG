#include <stdio.h>

int main(void){
    int size;
    int stars, blank1, blank2;
    int i,j;
    scanf("%d",&size);
    stars=size*2;
    blank1=size*2-2;
    blank2=0;
    for(i=0;i<size;i++){
        for(j=0;j<i;j++){
            printf(" ");
        }
        printf("*");
        for(j=0;j<blank1;j++){
            printf(" ");
        }
        printf("*");
        blank1-=2;
        printf("\n");
    }
    for(i=0;i<size;i++){
        for(j=0;j<size*2;j++){
            printf("*");
        }
        printf("\n");
    }
    for(i=0;i<size;i++){
        for(j=0;j<blank2;j++){
            printf(" ");
        }
        for(j=0;j<stars;j++){
            printf("*");
        }
        blank2++;
        stars-=2;
        printf("\n");
    }
    for(i=0;i<size*2;i++){
        printf("*");
    }
}