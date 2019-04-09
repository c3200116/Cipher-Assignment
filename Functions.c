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
        printf("\nEnter encryption key value between -25 to 25:\n");      //takes the encryption key value
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


/*  FALL BACK OPTION IN CASE OF FUCK UP
        switch(x){
        case 65:x=subs[0]; return x; break;       
        case 66:x=subs[1]; return x; break;
        case 67:x=subs[2]; return x; break;
        case 68:x=subs[3]; return x; break;
        case 69:x=subs[4]; return x; break;
        case 70:x=subs[5]; return x; break;
        case 71:x=subs[6]; return x; break;
        case 72:x=subs[7]; return x; break;
        case 73:x=subs[8]; return x; break;
        case 74:x=subs[9]; return x; break;
        case 75:x=subs[10]; return x; break;
        case 76:x=subs[11]; return x; break;
        case 77:x=subs[12]; return x; break;
        case 78:x=subs[13]; return x; break;
        case 79:x=subs[14]; return x; break;
        case 80:x=subs[15]; return x; break;
        case 81:x=subs[16]; return x; break;
        case 82:x=subs[17]; return x; break;
        case 83:x=subs[18]; return x; break;
        case 84:x=subs[19]; return x; break;
        case 85:x=subs[20]; return x; break;
        case 86:x=subs[21]; return x; break;
        case 87:x=subs[22]; return x; break;
        case 88:x=subs[23]; return x; break;
        case 89:x=subs[24]; return x; break;
        case 90:x=subs[25]; return x; break;
        default: return x;
  }   */
 