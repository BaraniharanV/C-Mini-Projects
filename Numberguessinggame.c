#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

int main(){

    srand(time(NULL));
    int num = 0;
    int choice = 0;
    int nos = 0;
    char toplay = 'y';

    num = rand()%100 + 1 ;

    printf("*** WELCOME TO NUMBER GUESSING GAME ***");
    

    while( toplay == 'y'){

            while ( nos < 7){

                printf("\n\nEnter a number between 1 and 100 : ");
                scanf("%d", &choice);
                nos++;


                if ( choice > 100 || choice < 1){
                    printf("\n\nInvalid choice !");
                    nos--;
                }
                else if ( choice < num){
                    printf("\n\nYour guess is too low !");
       
                }
    
                else if ( choice > num ){
                    printf("\n\nYour choice is too high !");
        
                }
    
                else{
                    printf("\n\n*** HURRAY ! ***");
                    printf("\nYOU WON !");
                    printf("\nYOU TOOK %d ATTEMPTS TO WIN THE GAME",nos);
                    printf("\n\nWanna play again ? ( y / n ) : ");
                    scanf(" %c" , &toplay);
                    toplay = tolower(toplay);
                    nos = 0;

                    if ( toplay == 'n'){
                        break;
                    }

                }
        
            }
            while( toplay != 'n'){
                printf("\n\n*** OOPS ! ***");
                printf("\nYOU LOST !");
                printf("\nYOU RAN OUT OF GUESSES !");
                printf("\n\nWanna play again ? ( y / n ) : ");
                scanf(" %c" , &toplay);
                toplay = tolower(toplay);
                nos = 0;
                break;
            }

        if ( toplay != 'y' && toplay != 'n' ){
            printf("\n\nInvalid choice !");
            printf("\nWanna play the game again ?( y / n ) : ");
            scanf(" %c", &toplay);
        }
        
    
    }

    printf("\nThankyou for playing the game !");

    return 0;
}
    