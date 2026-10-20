#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char morsetochar( char *morse);
char *chartomorse( char chara);

char morse[][5]= {
    ".-",      
    "-...",    
    "-.-.",    
    "-..",     
    ".",      
   "..-.",    
    "--.",    
    "....",     
    "..",      
    ".---",    
    "-.-",     
    ".-..",    
    "--",      
    "-.",      
    "---",     
    ".--.",    
    "--.-",    
    ".-.",     
    "...",     
    "-",       
    "..-",     
    "...-",    
    ".--",     
    "-..-",    
    "-.--",    
    "--.."     
};

char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    char cha[10];
    int choice = 0;

    do{
        printf("***** MENU *****\n");
        printf("1.Character to Morse code\n");
        printf("2.Morse code to Character\n");
        printf("3.Exit\n");
        printf("Enter your choice ( 1 / 2 / 3 ) : ");
        scanf("%d",&choice);
        printf("\n");
        getchar();

        switch(choice){
            case 1:
                printf("Enter the character for which you want the morse code : ");
                fgets(cha,sizeof(cha),stdin);
                
                char *resultc = chartomorse(cha[0]);
                if (resultc != NULL ){
                    printf("\nThe Morse code for the entered character is \" %s \" ", resultc);
                    printf("\n\n");
                }
                else{
                    printf("Morse code not found !");
                    printf("\n\n");
                }
                break;

            case 2:
                printf("Enter the morse code for which you want the character : ");
                fgets(cha , sizeof(cha) , stdin);
                cha[strcspn(cha, "\n")] = '\0';
                char resultm = morsetochar(cha);    
                if ( resultm != '\0'){
                    printf("\nThe character for the entered morse code is \" %c \" ", resultm);
                    printf("\n\n");
                }
                else{
                    printf("Character not found !");
                    printf("\n\n");
                }
                break;

            case 3:

                break;

            default:

                printf("Invalid choice !\n");

        }
    } while( choice != 3);

    return 0;
}

char *chartomorse(char cha){

    for (int i= 0 ; i < sizeof(alphabets) -1 ; i++){
        if ( alphabets[i] == cha){
            return morse[i];
        }
    }
    return NULL;
}

char morsetochar(char *cha){

    for (int i =0 ; i < (sizeof(morse) / sizeof(morse[0]))
; i++ ){
        if ( strcmp(morse[i],cha ) == 0){
            return alphabets[i];
        }
}       
    return '\0';    
}