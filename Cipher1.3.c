
#include <stdio.h> 
#include "Functions.h"



int main() 
{ 
   char message[200];                //initilises an array of size 200
   char subs[200];
   int key=-100;
   int count=0, c=5;
   int max=0, subsmax=0, x=0;
   int menu=0;
   
   printf("Choose from the following options;\n1) Encrypt a message using ROTATION cipher.\n2) Decrypt a message using ROTATION and known key value.\n");
   printf("3) Encrypt a message with SUBSTITUTION cipher.\n4) DECRYPT a message with SUBSTITUTION cipher and known key.\n");
   printf("Enter 1 - 4 followed by <enter>: ");
   scanf("%d", &menu);
   
   switch (menu){
    case 1:{ printf("\nInput message to be ENCRYPTED (max 200 characters):\n");
             scanf(" %[^\n]s", message);   
             break;}                      //takes a string of input including spaces and assigns to array 'str'
    case 2:{ printf("\nInput message to be DECRYPTED (max 200 characters):\n");
             scanf(" %[^\n]s", message); 
             break;}
    case 3:{ printf("\nInput message to be ENCRYPTED (max 200 characters):\n");
             scanf(" %[^\n]s", message); 
             break;}   
    case 4:{ printf("\nInput message to be DECRYPTED (max 200 characters):\n");
             scanf(" %[^\n]s", message); 
             break;}
    default: printf("\nInvalid menu selection, please start again.\n");
    }


    for(x=0; message[x]!='\0'; x++){                      //calculates the total number of digits                                         
         if(message[x]>=0 || message[x]<=127)              //in the string and a
         max++;
        }
    for (count=0; count<=max; count++){    
        if (message[count]>=97 && message[count]<=122)  //checks for lower case and converts to upper case
            message[count] = message[count]-32;
    }


//-----------------------------------------------------------------//
//ROTATION ENCRYTION
   
   if (menu==1){
                       
       key=keycheck(key, c);                                  //function which checks the input key is valid
       
        if (key<-25 || key>25){                               //if no correct key input, kill program            
            printf("INVALID INPUT, PLEASE RESTART.\n");
            return 0;
        }
       
        for(x=0; message[x]!='\0'; x++){                      //calculates the total number of digits                                         
            if(message[x]>=0 || message[x]<=127)              //in the string and assigns it to 'max'
            max++;
        }
       
       
       for (count=0; count<=max; count++){                      //for each digit, checks if it's a letter
           if (message[count]>=65 && message[count]<=90){       //then assigns new value
            message[count] = applyKey(message[count], key);}    //
            
    
      }
     
       printf("\nYour encrytped message reads:\n%s\n", message); 
      
       return 0; 
   }
//-------------------------------------------------------------------------//
//DECRYPTION ALGORITHM - SAME AS ABOVE BUT -KEY INSTEAD OF +KEY TO MESSAGE

   else if (menu==2){
                       
       
       key=keycheck(key, c);                                  //function which checks the input key is valid
       
        if (key<-25 || key>25){                               //if no correct key input, kill program            
            printf("INVALID INPUT, PLEASE RESTART.\n");
            return 0;
        }
       
        for(x=0; message[x]!='\0'; x++){                      //calculates the total number of digits                                         
            if(message[x]>=0 || message[x]<=127)              //in the string and assigns it to 'max'
            max++;
        }

       
       for (count=0; count<=max; count++){                      //for each digit, checks if it's a letter
           if (message[count]>=65 && message[count]<=90){       //then assigns new value
            message[count] = applyKey(message[count], -key);}    //
            
    
      }
     
       printf("\nYour encrytped message reads:\n%s\n", message); 
      
       return 0; 
   }

//--------------------------------------------------------------//
//ENCRYPTION WITH SUBSTITUTION..
    else if (menu==3){
    

    printf("\nInput substitution key (max 26 characters, no spaces):\n");
       scanf(" %[^\n]s", subs);
       
    for(x=0; message[x]!='\0'; x++){                      //calculates the total number of digits                                         
        if(message[x]>=0 || message[x]<=127)              //in the string and assigns it to 'max'
            max++;
        }
        
    for(x=0; subs[x]!='\0'; x++){                      //calculates the total number of digits                                         
        if(subs[x]>=0 || subs[x]<=127)              //in the subs key and assigns it to 'subsmax'
            subsmax++;
    }
    
    if (subsmax!=26){
        printf("Incorrect key format, please try again using exactly 26 characters.\n");
        return 0;
    }

        

    for (count=0; count<=max; count++){
           switch(message[count]){
            case 65:message[count]=subs[0];
            case 66:message[count]=subs[1];
            case 67:message[count]=subs[2];
            case 68:message[count]=subs[3];
            default:printf("test\n");
        }

        printf("\nYour encrytped message reads:\n%s\n", message); 
        return 0;
    }
}

//-------------------------------------------------------------//
//IF NO VALID MENU OPTION IS CHOSEN
    else{
    printf("INVALID CHOICE OR NOT YET IMPLEMENTED.\n");
    return 0;
    }

    
}

