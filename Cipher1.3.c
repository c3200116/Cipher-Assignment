
//char applyKey(char x, int y);
//int keycheck (int x, int y);



#include <stdio.h> 
#include "Functions.h"



int main() 
{ 
   char message[200];                //initilises an array of size 200
   int key=-100;
   int count=0, c=5;
   int max=0, x=0;
   int menu=0;
   
   printf("Choose from the following options;\n1) Encrypt a message using rotation.\n2) Decrypt a message using rotation and known key value.\n");
   printf("Enter 1 or 2: ");
   scanf("%d", &menu);
   
   if (menu==1){
       printf("\nInput message to be encrypted (max 200 characters):\n");
       scanf(" %[^\n]s", message);                           //takes a string of input including spaces and assigns to array 'str'
       
       key=keycheck(key, c);                                  //function which checks the input key is valid
       
        if (key<-25 || key>25){                               //if no correct key input, kill program            
            printf("INVALID INPUT, PLEASE RESTART.\n");
            return 0;
        }
       
        for(x=0; message[x]!='\0'; x++){                      //calculates the total number of digits                                         
            if(message[x]>=0 || message[x]<=127)              //in the string and assigns it to 'max'
            max++;
        }
       //printf("number of digits in string = %d\n", max);   //prints number of digits in string
                                                                //used for testing only
       
       for (count=0; count<=max; count++){                      //for each digit, checks if it's a letter
           if (message[count]>=65 && message[count]<=90){       //then assigns new value
            message[count] = applyKey(message[count], key);}    //
            
          else if (message[count]>=97 && message[count]<=122){  //checks for lower case and converts to upper case
            message[count] = message[count]-32;                 //
            message[count] = applyKey(message[count], key);     //
             }
    
      }
     
       printf("\nYour encrytped message reads:\n%s\n", message); 
      
       return 0; 
   }

   else if (menu==2){
       printf("\nInput message to be DEcrypted (max 200 characters):\n");
       scanf(" %[^\n]s", message);                           //takes a string of input including spaces and assigns to array 'str'
       
       key=keycheck(key, c);                                  //function which checks the input key is valid
       
        if (key<-25 || key>25){                               //if no correct key input, kill program            
            printf("INVALID INPUT, PLEASE RESTART.\n");
            return 0;
        }
       
        for(x=0; message[x]!='\0'; x++){                      //calculates the total number of digits                                         
            if(message[x]>=0 || message[x]<=127)              //in the string and assigns it to 'max'
            max++;
        }
       //printf("number of digits in string = %d\n", max);   //prints number of digits in string
                                                                //used for testing only
       
       for (count=0; count<=max; count++){                      //for each digit, checks if it's a letter
           if (message[count]>=65 && message[count]<=90){       //then assigns new value
            message[count] = applyKey(message[count], -key);}    //
            
          else if (message[count]>=97 && message[count]<=122){  //checks for lower case and converts to upper case
            message[count] = message[count]-32;                 //
            message[count] = applyKey(message[count], -key);     //
             }
    
      }
     
       printf("\nYour encrytped message reads:\n%s\n", message); 
      
       return 0; 
   }

    else{
    printf("INVALID CHOICE OR NOT YET IMPLEMENTED.\n");
    return 0;
    }

    
}

/*
char applyKey (char x, int y){
    x=x+y;
        if (x>90)
            x=x-26;
        else if (x<65)
            x=x+26;
    return x;
}

int keycheck(int key, int c){
   
       while ((key<-25 || key>25) && (c>0)){
        printf("\nEnter encryption key value between -25 to 25:\n");      //takes the encryption key value
        scanf("%d", &key);
             if (key<-25 || key>25){
                  c--;
                  printf("Invalid encryption value, you have %d attempts remaining.\n", c);
             }
             else {
             return key;
             }
        }

}
*/