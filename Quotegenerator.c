#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

void generatequote();
void addquote();
void addtofav();
void viewmyfav();
void tocapitalize(char *string);

int main(){

    int choice = 0;

    do{
        printf("*********************\n\n");
        printf("   QUOTE GENERATOR   \n\n");
        printf("*********************\n\n");
        printf("1.Generate a random quote \n");
        printf("2.Add a quote \n");
        printf("3.Add to favourites \n");
        printf("4.View my favourites \n");
        printf("5.Exit \n");
        printf("Enter your choice ( 1 / 2 / 3 / 4 / 5 ) : ");
        scanf("%d",&choice);
        printf("\n");
        getchar();

        switch(choice){
            case 1:

                generatequote();
                break;

            case 2:

                addquote();
                break;

            case 3:

                addtofav();
                break;

            case 4:

                viewmyfav();
                break;

            case 5:

                break;

            default :

                printf(" Invalid Choice !\n");
        }
    }while( choice != 5);

    return 0;
}

void generatequote(){
    /* count the number of quotes , generate a random number within the range of number of quotes .
       access the quote inside the quotes file using the generated random number as the line number.
       print the quote and its respective author using the strtok function and | as the delimiter */
       
    srand(time(NULL));
    FILE *pfile = fopen("quotes.txt", "r");
    char buffer[1024];
    char *quote = NULL;
    char *author = NULL;
    int num;
    int lines = 0 ;
    int countlines = 0;
    int c = 0;
    
    if ( pfile == NULL){

        printf("Unable to open the file !\n\n");
        return;
    }

    while (( c = getc(pfile)) != EOF){
        if ( c == '\n'){
            lines++;
        }
    }

    if (lines == 0){
        printf("No quotes found !\n");
        fclose(pfile);
        return;
    }
    num = rand() % lines + 1 ;

    rewind(pfile);

    while( fgets(buffer , sizeof(buffer) , pfile) !=  NULL){
        countlines++;
        if ( countlines == num ){
            
            char *tempquote = strtok( buffer , "|");
            char *tempauthor = strtok( NULL ,"|");

            if ( tempquote  != NULL){
                quote = malloc(strlen(tempquote) + 1);
                if (quote != NULL){
                    strcpy(quote , tempquote);
                }
            }

            if ( tempauthor != NULL){
                tempauthor[ strcspn(tempauthor,"\n")] = '\0';
                author = malloc(strlen(tempauthor) +2);
                if ( author != NULL){
                    strcpy(author,tempauthor);
                }
            }
            break;
        }
    }

    fclose(pfile);

    if (quote != NULL && author != NULL){
        tocapitalize(quote);
        tocapitalize(author);

        printf("\n*** YOUR QUOTE ***\n\n");
        printf("\" %s \" ", quote );
        printf("\n\t\t - %s\n\n" , author);

        free(quote);
        free(author);
    }
    else{
        printf("Could not retrieve a quote !\n\n");
    }

}

void addquote(){
    /* get the quote and author name from the user and store it in two arrays.
       write the quote and author onto the file with the delimiter |.
       print success message .*/

    FILE *pfile = fopen("quotes.txt", "a");
    char quote[300];
    char author[300];
    char choice;
    int num;
    
    if ( pfile == NULL){

        printf("Unable to open the file !\n\n");
        return;
    }

    do{

    printf("Enter the quote you want to add to Quotes : ");
    fgets(quote,sizeof(quote),stdin);
    quote[strcspn(quote,"\n")] = '\0';
    printf("\nEnter the author for the quote you entered : ");
    fgets(author,sizeof(author),stdin);
    author[strcspn(author,"\n")] = '\0';

    tocapitalize(quote);
    tocapitalize(author);

    fprintf(pfile, "%s|%s\n",quote , author);

    printf("\nDo you want to add another quote ( y / n ) : ");
    scanf(" %c", &choice );
    while(getchar() != '\n');
    choice = tolower(choice);
    printf("\n");

    }while( choice != 'n');

    printf("\n\nYour quote has been successfully added to quotes ! \n\n");

    fclose(pfile);

}

void addtofav(){
    /* get the quote and author name from the user and store it in two arrays.
       write the quote and author onto the favourites file with the delimiter |.
       print success message .*/

    FILE *pfile = fopen("favouritequote.txt", "a");
    char quote[300];
    char author[300];
    char choice;
    int num;
    
    if ( pfile == NULL){

        printf("Unable to open the file !\n\n");
        return;
    }

    do{

    printf("Enter the quote you want to add to favourites : ");
    fgets(quote,sizeof(quote),stdin);
    quote[strcspn(quote,"\n")] = '\0';
    printf("\nEnter the author for the quote you entered : ");
    fgets(author,sizeof(author),stdin);
    author[strcspn(author,"\n")] = '\0';

    tocapitalize(quote);
    tocapitalize(author);

    fprintf(pfile, "%s|%s\n",quote , author);

    printf("\nDo you want to add another quote ( y / n ) : ");
    scanf(" %c", &choice );
    choice = tolower(choice);

    }while( choice != 'n');

    printf("\n\nYour quote has been successfully added to  \" My favourite quotes \" ! \n\n");

    fclose(pfile);

}

void viewmyfav(){
    /* display the favourites file */

    FILE *pfile = fopen("favouritequote.txt" , "r");
    char buffer[1024];
    int num = 1;

    if (pfile == NULL){
        printf("Unable to open the file !\n\n");
        return;
    }
    while(fgets(buffer , sizeof(buffer) , pfile) != NULL){

        char *quote = strtok(buffer , "|");
        char *author = strtok(NULL , "|");

        tocapitalize(quote);
        tocapitalize(author);

        if ( quote != NULL && author != NULL){
            
            author[strcspn(author , "\n")] = '\0';

            printf("%d . \" %s \"", num , quote );
            printf("\n\t\t - %s \n\n", author);
            num++;
        }

    }

    fclose(pfile);
}

void tocapitalize(char *string){

    int ch = 1;

    for ( int i = 0 ; string[i] != '\0' && string[i] != '\n' ; i++){

        if( isspace((unsigned char)string[i])){
            ch = 1;
        }
        else if (ch){
            string[i] = toupper((unsigned char)string[i]);
            ch = 0;
        }
        else{
            string[i] = tolower((unsigned char)string[i]);
        }
    }

}

