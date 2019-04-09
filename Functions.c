#include <stdio.h>
#include "Functions.h"

//-------------------------------------------//

char undoSubs (char x, char subs[], char alpha[]){
    int y=0;
    for (y=0; x!=subs[y]; y++);{
        if (x==subs[y]);
            x=alpha[y];
            return x;
        }
    return 0;
}

//-------------------------------------------//

char applySubs (char x, char subs[], char alpha[]){
    int y=0;
    for (y=0; x!=alpha[y]; y++);{
        if (x==alpha[y]);
            x=subs[y];
            return x;
        }
    return 0;  
}


//------------------------------------------//

int countMax(char message[]){
    int x=0, max=0;
    for(x=0; message[x]!='\0'; x++){                      //calculates the total number of digits                                         
        if(message[x]>=0 || message[x]<=127)              //in the string and a
         max++;
        }
    return max;
}

//-----------------------------------------//

char applyKey (char x, int y){
    x=x+y;
        if (x>90)
            x=x-26;
        else if (x<65)
            x=x+26;
    return x;
}


//------------------------------------------------------------------------//

int keycheck(int key, int c){
       while ((key<-25 || key>25) && (c>0)){
        printf("\nEnter encryption key value between -25 to 25:\n");      
        scanf("%d", &key);
             if (key<-25 || key>25){
                  c--;
                  printf("Invalid encryption value, you have %d attempts remaining.\n", c);
                  if (c==0){
                    printf("INVALID INPUT, PLEASE RESTART.\n");
                    return 0;
                  }
             }
             else {
             return key;
             }
        }
        return 0;
}

//-------------------------------------------------------------//

