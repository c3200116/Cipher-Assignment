//WEEK 7 LECTURE FOR READING AND WRITING TO FILES INSTEAD OF SCANF


#include <stdio.h> 
#include "Functions.h"



int main() 
{ 
   char message[200];               // -initilises an array of size 200 to store message.
   char subs[200];                  // -array to store substitution encryption key.
   char alpha[26]={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
   int key=-100;                    // -variable to store rotaion key.
   int count=0, c=5;                //
   int max=0, subsmax=0;                  // -counters
   int menu=0;                      //
  
   //------------------------------------------------------------//
   //USER INPUT MENU
   printf("\nChoose from the following options;\n1) Encrypt a message using ROTATION cipher.\n2) Decrypt a message using ROTATION and known key value.\n");
   printf("3) Encrypt a message with SUBSTITUTION cipher.\n4) DECRYPT a message with SUBSTITUTION cipher and known key.\n");
   printf("Enter 1 - 4 followed by <enter>: ");
   scanf("%d", &menu);
   
   
   //------------------------------------------------------------//
   //USER INPUT MESSAGE WITH STDIN - CHECK FOR LOWER CASE AND CONVERT TO UPPER CASE
   //STORE IN 'message' ARRAY
   if (menu==1 || menu ==3){
        printf("\nInput message to be ENCRYPTED (max 200 characters):\n");
        scanf(" %[^\n]s", message);   
        }                      
   else if (menu==2 || menu==4){
        printf("\nInput message to be DECRYPTED (max 200 characters):\n");
        scanf(" %[^\n]s", message); 
        }
   else {
       printf("\nInvalid menu selection, please start again.\n");
       return 0;
    }
    
    max=countMax(message);      //calculates total number of letters in the array
    
    for (count=0; count<=max; count++){    
        if (message[count]>=97 && message[count]<=122)  //checks for lower case and converts to upper case
            message[count] = message[count]-32;
    }


//-----------------------------------------------------------------//
//ROTATION ENCRYTION
   
   if (menu==1 || menu==2){
                       
       key=keycheck(key, c);                //function to input key and check it's within valid range.
       
        if (menu==2){
            key=-key;                       //switches key for DECRYPTION
        }
        for (count=0; count<=max; count++){                      //for each digit, checks if it's a letter
           if (message[count]>=65 && message[count]<=90){       //then assigns new value
            message[count] = applyKey(message[count], key);
            }  
        }
     
        printf("\nYour message reads:\n%s\n", message);
    
        return 0; 
    }
//-------------------------------------------------------------------------//
//ENCRYPTION WITH SUBSTITUTION..
   
   else if (menu==3){
    
        printf("\nInput substitution key (max 26 characters, no spaces):\n");
        scanf(" %[^\n]s", subs);       
        
        subsmax=countMax(subs);
    
        for (count=0; count<=max; count++){    
            if (subs[count]>=97 && subs[count]<=122)  //checks for lower case and converts to upper case
                subs[count] = subs[count]-32;
        }
   
        if (subsmax!=26){
            printf("Incorrect key format, please try again using exactly 26 characters.\n");
            return 0;
        }
    
        for (count=0; count<=max; count++){
            if (message[count]>=65 && message[count]<=90){       
                message[count] = applySubs(message[count], subs, alpha);
            }
        }
        printf("\nYour encrytped message reads:\n%s\n", message); 
        
        return 0;
    }

    //TEST VALUES
    // phqgiumeaylnofdxjkrcvstzwb
    //GIUIFG CEI IPRC TPNN DU CEI QPRCNI
    //GIUIFG CEI IPRC TPNN DU CEI QPRCNI
    //defend the east wall of the castle


//-------------------------------------------------------------//
//DECRYPTION OF SUBSTITUTION CIPHER

    else if (menu==4){
    
        printf("\nInput substitution cipher key (max 26 characters, no spaces):\n");
        scanf(" %[^\n]s", subs);       
        
        subsmax=countMax(subs);
    
        for (count=0; count<=max; count++){    
            if (subs[count]>=97 && subs[count]<=122)  //checks for lower case and converts to upper case
                subs[count] = subs[count]-32;
            }
   
        if (subsmax!=26){
            printf("Incorrect key format, please try again using exactly 26 characters.\n");
            return 0;
        }
    
        for (count=0; count<=max; count++){
            if (message[count]>=65 && message[count]<=90){            
                message[count] = undoSubs(message[count], subs, alpha);
            }
        }
        printf("\nYour message reads:\n%s\n", message); 
        return 0;
   
}
//-------------------------------------------------------------//
//IF NO VALID MENU OPTION IS CHOSEN
    else{
        
        printf("INVALID CHOICE OR NOT YET IMPLEMENTED.\n");
        return 0;
        }
   
}

