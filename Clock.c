#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<windows.h>

int main(){

   int hours = 0;
   int minutes = 0;
   int seconds = 0; 
   
     while(1){

        printf("\r%02d : %02d : %02d ", hours , minutes , seconds );
        fflush(stdout);
        seconds++;

        if (seconds == 60){
            seconds = 0;
            minutes++;
        }

        if (minutes == 60){
            minutes = 0;
            hours++;
        }

        if (hours == 24){
            hours = 0;
            minutes = 0;
            seconds = 0;
        }

        Sleep(1000);
      
    }

    return 0;
}