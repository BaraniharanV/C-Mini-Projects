#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    int choice = 0;
    int chnum = 0;
    int num = 0;
    int current = 0;
    char task[101];
    char buffer[101];
    FILE *pfile;
    FILE *temp;

    do{

        printf("***** MENU *****\n\n");
        printf("1.Add a task \n");
        printf("2.Remove a task \n");
        printf("3.View the to do list \n");
        printf("4.Exit \n\n");
        printf("Enter your choice ( 1 / 2 / 3 / 4 ) : ");
        scanf("%d",&choice);
        while(getchar()!= '\n');
            
        switch(choice){

            case 1:

                printf("\nEnter the task to be added (1 -100 characters) : ");
                fgets(task,sizeof(task),stdin);
                num++;

                pfile = fopen("todos.txt","a");

                 if ( pfile == NULL ){
                    printf("\nError in opening the file !");
                }

                fputs(task,pfile);
                fclose(pfile);

                printf("\nTask added successfully !\n\n");

                break;
            case 2:

                pfile = fopen("todos.txt","r");
            
                printf("\n*** YOUR TO DO LIST ***\n\n");
                num = 1;
                while(fgets(buffer,sizeof(buffer),pfile) != NULL){
                
                    printf("%d . %s", num , buffer);
                    num++;
                }
           
                fclose(pfile);

                printf("\nEnter the number for the task to be removed : ");
                scanf(" %d",&chnum);

                pfile = fopen("todos.txt","r");

                num = 0;

                while(fgets(task,sizeof(task),pfile)!= NULL){
                    num++;
                }

                while(getchar()!= '\n');

                fclose(pfile);

                if (chnum > num){
                    printf("\nEnter a valid serial number for the task to be removed ( 1 - %d ) : " , num);
                    scanf(" %d" , &chnum);
                }

                pfile = fopen("todos.txt","r");
                temp = fopen("temp.txt","w");

                if ( pfile == NULL || temp == NULL){
                    printf("\nError in opening the file !\n");
                }
                current = 1;

                while(fgets(task,sizeof(task),pfile) != NULL){

                    if (chnum != current){
                        fputs(task,temp);
                    }
                    current++;
                 }

                 fclose(pfile);
                 fclose(temp);

                 remove("todos.txt");
                 rename("temp.txt","todos.txt");

                 printf("\nTask removed successfully !\n\n");

                break;
            case 3:

                pfile = fopen("todos.txt","r");

                printf("\n*** YOUR TO DO LIST ***\n\n");
                num = 1;
                while(fgets(buffer,sizeof(buffer),pfile) != NULL){
                
                    printf("%d . %s", num , buffer);
                    num++;
                }
                printf("\n***********************\n\n");
                fclose(pfile);

                break;
            case 4:

                break;

            default :

                printf("\nInvalid choice !\n\n");
        }
    }while( choice != 4);

    return 0;

}


    

