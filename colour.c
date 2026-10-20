#include<stdio.h>
#include<math.h>
#include<string.h>

void hextorgb();
void rgbtohex();

int main(){

    int choice = 0 ;

    do{
        printf("\n*** MENU ***");
        printf("\n\n1.Colour code ( Hex code ) to RGB values ");
        printf("\n2.RGB values to colour code ( Hex code )");
        printf("\n3.Exit");
        printf("\n\nEnter your choice ( 1 / 2 / 3 ) : ");
        scanf("%d",&choice);
        
        switch(choice){

            case 1:

                hextorgb();
                break;
            case 2:

                rgbtohex();
                break;
            case 3:

                break;
            default:
                printf("\n\nInvalid Choice !");

        }
        

    }while(choice != 3);

    return 0 ;
}

void hextorgb(){

    char hex[10];
    char *ph = NULL;
    int r;
    int g;
    int b;

    printf("\n\nEnter the hex code ( or colour code ) : ");
    scanf(" %9s" , hex);
    ph = hex;
    if (hex[0] == '#'){
        ph++;
    }
    if (strlen(ph) != 6){
        printf("\n\nInvalid hex code length ! ");
    }
    sscanf( ph , "%2x%2x%2x" , &r , &g , &b );

    printf("\n\nThe Red ( r ) value for the entered hex code : %d ", r);
    printf("\n\nThe Green ( g ) value for the entered hex code : %d ", g);
    printf("\n\nThe Blue ( b ) value for the entered hex code : %d \n", b);

}

void rgbtohex(){

    int r;
    int g;
    int b;

    printf("\n\nEnter the Red ( r ) value : ");
    scanf("%d" , &r);
    printf("\n\nEnter the Green ( g ) value : ");
    scanf("%d" , &g);
    printf("\n\nEnter the Blue ( b ) value : ");
    scanf("%d" , &b);

    if ( r > 255 || r < 0 || b > 255 || b < 0 || g > 255 || g < 0 ){
        printf("\n\nInvalid RGB values ! \n");
    }
    else{
        printf("\n\nThe Hex code for the given RGB values is #%02X%02X%02X \n", r,g,b);
    }

}