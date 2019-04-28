#include <stdio.h>
#include "Functions.h"
#include <string.h>


//-------------------------------------------//
//Function to apply subsitution cipher. 
//Calculates input letter 'x' position in the alphabet 
//and swaps it with character in same position within 'subs' array (cipher key).
//Takes input of single char from message array and outputs new char to newmessage.

char applySubs (char x, char subs[], char alpha[]){
    int y=0;
    for (y=0; x!=alpha[y]; y++);{
        if (x==alpha[y]);
            x=subs[y];
            return x;
        }
    return 0;  
}

//-------------------------------------------//
//Function to apply subsitution cipher for DECRYPTION.
//As above but alpha and subs are reversed.

char undoSubs (char x, char subs[], char alpha[]){
    int y=0;
    for (y=0; x!=subs[y]; y++);{
        if (x==subs[y]);
            x=alpha[y];
            return x;
        }
    return 0;
}

//------------------------------------------//
//Function counts the number of digits in a given string/array by incrementing a  
// counter until it reaches a NULL value.
//Function input any string, outputs final counter value for use elsewhere

int countMax(char message[]){
    int x=0, max=0;
    for(x=0; message[x]!='\0'; x++){                                                              
        if(message[x]>=0 || message[x]<=127)              
         max++;
        }
    return max;
}

//-----------------------------------------//
//ROTATION CIPHER FUNCTION
//Takes single char input from message array and key value.
//Outputs new char.
//Adds key value to char ascii value, checks if it still falls within alphabet range.
//If outside range,adds or subtracts 26 to 'wrap around' to start of alphabetical values.

char applyKey (char x, int y){
    x=x+y;
        if (x>90)
            x=x-26;
        else if (x<65)
            x=x+26;
    return x;
}


//------------------------------------------------------------------------//
//Takes a rotation key value and checks if it is within a valid range (-25 to 25)
//if not, asks for repeat input or exits.
//Function inputs are initial key value and pre-set counter. Outputs a usuable key.

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
//WORD ANALYSIS..
//takes an input message string and single test word then checks each character sequentially against message text
//if at any point the values do not match, breaks and restarts test word sequence from first value
//while continuing through message text. 
//If all test values successfully match sequentially a word has been found, count is increased and returned.

int wordcheck(char * newmessage, char * wordtest){
    int i=1, j=0, found=0, count=0;
    int messageLen=0, testLen=0;

    messageLen = strlen(newmessage);      // length of string
    testLen = strlen(wordtest)-2;           // length of word to be searched
    
    
    for(i=0; i <= messageLen-testLen; i++){
        found = 1;                              //checks first char of test word and first char of message 
        for(j=0; j<testLen; j++){               //if they are == then test next value until all values of test word
            if(newmessage[i + j] != wordtest[j]){  //have been checked. If all are == then entire word matches and count++
                found = 0;
                break;                          //if any if the test values are != then break and start from test value 1 again
            }
        }
        if(found == 1)
            count++;                            //final count value shows total number of times all testvalues were successfully matched sequentially
    }
    return count;
}
