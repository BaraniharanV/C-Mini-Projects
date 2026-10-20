#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<windows.h>

int main(){

   int hours = 0;
   int minutes = 0;
   int seconds = 0; 

   printf("Enter the hours in the format ( hh ) : ");
   scanf("%d",&hours);

   printf("\nEnter the minutes in the format ( mm ) : ");
   scanf("%d", &minutes);

   printf("\nEnter the seconds in the format ( ss ) : ");
   scanf("%d",&seconds);
   printf("\n");

    while( hours != 0 || minutes != 0 || seconds != 0){

        printf("\r%02d : %02d : %02d  ", hours , minutes , seconds );
        fflush(stdout);
        seconds--;

        if (minutes == 0){
            ;
        }
        else{
            if (seconds == 0){
                seconds = 59;
                minutes--;
            }
        }

        if (hours == 0){
            ;
        }
        else{
            if (minutes == 0){
                minutes = 59;
            hours--;
            }
        }

        Sleep(1000);
      
    }

    printf("\033[2K\r");
    printf("00 : 00 : 00");
    printf("\n\n*** TIME OVER ***\n");

    return 0;
}