#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
int main(){
    srand(time(NULL));
    char arr[][50] = {"Rock" , "Paper" , "Scissors"};
    int choice = 0;
    char play = '\0';
    int player = 0;

    do{
        
        printf("\n***WELCOME TO ROCK PAPER SCISSOR GAME***");
        printf("\n\n***MENU***");
        printf("\n1.Rock");
        printf("\n2.Paper");
        printf("\n3.Scissors");
        printf("\n\nEnter your choice ( 1 / 2 / 3 ) : ");
        scanf(" %d",&choice);
        int ch = rand()%3 + 1;
        if ( choice == 1 ){
            if( ch == 3){
                printf("\nComputer chose Paper \nYou Lost !");
            }
            else{
                printf("\nComputer chose Scissors \nYou Won !");
            }
        }
        else if( choice == 2){
            if( ch == 3){
               printf("\nComputer chose Scissors \nYou Lost !"); 
            }
            else{
                printf("\nComputer chose Rock \nYou Won !");
            }
        }
        else if( choice == 3){
            if( ch == 1){
                printf("\nComputer chose Rock \nYou Lost !");
            }
            else{
                printf("\nComputer chose Paper \nYou Won !");
            }
        }
        else{
            printf("\nYou and computer chose %s \nIt\'s a Tie !" , arr[choice - 1]);
        }
        printf("\n\nDo you want to play again ( y / n ) : ");
        scanf(" %c",&play);
        play = tolower(play);
        if ( play!= 'n' && play!= 'y'){
            printf("\nPlease enter a valid choice ( y / n ) : ");
            scanf(" %c" , &play);
        }

    }while( play!= 'n');
    return 0;
}