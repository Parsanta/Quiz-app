#include<stdio.h>
#include<string.h>
int main(){
    char name[10] = "salman ali";
    for(int i = 0;i<10;i++){
        printf("%c",name[i]);
    }
    printf("\n\nnew\n\n");
    for(int i =0;i<10;i++){
        name[i] = 0;
    }
    for(int i = 0;i<10;i++){
        printf("%c",name[i]);
    }
}