#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL));

    int *num = malloc(sizeof(int));
    int *length = malloc(sizeof(int));
    char symbols[95];

    for(int i=0; i<95; i++){
        symbols[i]=(char)(i + 32);
    }

    do{
    printf("Enter the length of the password you want ( 4 - 50 ):");
    scanf("%d",length);

    if(*length <= 50 && *length >= 4){
        break;
    }
    else{
        printf("Choose a length between 4 and 50 ");
    }

    }while(*length < 4 || *length > 50);
    printf("Generating your password please wait!");
    char password[*length +1];

    for(int q=0;q< *length;q++){
        *num = (rand() % 95);
        password[q]= symbols[*num];
    }
    
    password[*length] = '\0';
    printf("\nYour generated password is : %s ",password);
    
    return 0;
}