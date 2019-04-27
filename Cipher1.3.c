/*
 * Program to process a message, adding or removing a cipher.
 * 
 * User input menu with stdin to choose option.
 * 
 * Message to be used to be written in text file. File name specified by user via stdin.
 * Encryption/decryption key input via stdin for rotation, or text file for substitution.
 * 
 * Message read from file, transferred to array. 
 * Checked for case sensitivity and converted as required.
 * 
 * Menu option chosen - appropriate cipher function applied, new message stored in seperate array
 * 
 * Processed message printed to screen via stdout and to text file 'output.txt'
 */


#include <stdio.h> 
#include "Functions.h"
#include <string.h>



int main() 
{ 
    char message[1000];              // -initilises an array to store message.
    char newmessage[1000];           // -array for processed message storage
    char wordtest[100];
    char subs[100];                  // -array to store substitution encryption key.
    char alpha[27];                  // -unmodified alphabet array
    char filename[50];
    char keyname[50];
    int key=-100;                    // -variable to store rotation key.
    int count=0, c=5, a=0;           // ---------
    int max=0, subsmax=0;            // -counters
    int menu=0;                      // ---------
  
    for (a=0; a<26; a++){
        alpha[a]=a+65;
    }
 
    //------------------------------------------------------------//
    //USER INPUT MENU
    printf("\nChoose from the following options;\n");
    printf("1) Encrypt a message using ROTATION cipher.\n");
    printf("2) Decrypt a message using ROTATION and known key value.\n");
    printf("3) Encrypt a message with SUBSTITUTION cipher.\n");;
    printf("4) DECRYPT a message with SUBSTITUTION cipher and known key.\n");
    printf("5) DECRYPT a rotation cipher with no key.\n");
    printf("Enter 1 - 5 followed by <enter>: ");
    scanf("%d", &menu);
   
   
    FILE *input;            //file pointers
    FILE *output;
    output=fopen("output.txt", "w");
    
    printf("Enter name of file where message is stored followed by <enter>: \n");
    scanf("%s", filename);              
    input=fopen(filename, "r");         //directs pointer to user specified filename
    
    if (input==NULL){
            printf("Unable to open file, or does not exist - please restart.\n");
            return 0;
        }
        
    fscanf(input, "%[^0]c", message);   //reads message from file in, assigns to array
   
    max=countMax(message);              //calculates total number of letters in the array
    
    for (count=0; count<=max; count++){    
        if (message[count]>=97 && message[count]<=122)  //checks for lower case and converts to upper case
            message[count] = message[count]-32;
    }


//-----------------------------------------------------------------//
//ROTATION ENCRYTION..
//Type message to be processed into 'Input.txt'
//Input key value via stdin
  
    if (menu==1 || menu==2){
                       
       key=keycheck(key, c);                //function to input key and check it's within valid range.
       
        if (menu==2){
            key=-key;                       //switches key for DECRYPTION
        }
        for (count=0; count<=max; count++){                         //for each char, checks if it's a letter.
            if (message[count]>=65 && message[count]<=90){          //if true, assigns new value and copys into
                newmessage[count]=applyKey(message[count], key);    //newmessage array
            }
            else
                newmessage[count]=message[count];               //if char is not a letter, copy without change
             
        }
     
        printf("\nYour message has been printed to file 'output.txt' and reads:\n\n%s\n", newmessage);
        fprintf(output, "%s", newmessage);
    
        return 0; 
    }
//-------------------------------------------------------------------------//
//ENCRYPTION WITH SUBSTITUTION..
//Type message to be processed into 'Input.txt'
//Input key value via stdin
   
    else if (menu==3){
        FILE *subskey;
        
        printf("Enter filename where cipher key is located, followed by <enter>:\n");
        scanf("%s", keyname);
        subskey=fopen(keyname, "r");
        
        if (subskey==NULL){
            printf("Unable to open file, or does not exist - please restart.\n");
            return 0;
        }
        
        fscanf(subskey, "%[^0]c", subs);
        
        subsmax=countMax(subs);     //counts number of chars in key, if incorrect exits.
    
        for (count=0; count<=max; count++){    
            if (subs[count]>=97 && subs[count]<=122)  //checks for lower case and converts to upper case
                subs[count] = subs[count]-32;
        }
   
        if (subsmax!=26){
            printf("Incorrect key format, please try again using exactly 26 characters.\n");
            return 0;
        }
    
        for (count=0; count<=max; count++){                 //processes each char in array 1 at a time
            if (message[count]>=65 && message[count]<=90){  //if char is a letter, apply encryption function.    
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
//DECRYPTION OF SUBSTITUTION CIPHER..
//Type message to be processed into 'Input.txt'
//Input key value via stdin

    else if (menu==4){
    
        FILE *subskey;
        
        printf("Enter filename where cipher key is located, followed by <enter>:\n");
        scanf("%s", keyname);
        subskey=fopen(keyname, "r");
        
        if (subskey==NULL){
            printf("Unable to open file, or does not exist - please restart.\n");
            return 0;
        }
        
        fscanf(subskey, "%[^0]c", subs);       
        
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

    else if (menu==5){
        FILE *words;
        words=fopen("words.txt", "r");
        
        int total=0, same=0;
        int m=0;
        
        for (key=1; key<26; key++){
                for (count=0; count<=max; count++){                      //for each digit, checks if it's a letter
                    if (message[count]>=65 && message[count]<=90){       //then assigns new value
                        newmessage[count]=applyKey(message[count], key);
                    }
                    else{
                        newmessage[count]=message[count];
                    }      
                }

                fgets(wordtest, sizeof wordtest, words); // read first line from test words and 
                total=0;
                while (feof(words)==0){
                    same=wordcheck(newmessage, wordtest);
                    total=total+same;
                    fgets(wordtest, sizeof wordtest, words);
                    
                }
                printf("%d words matched with key '%d'!\n", total, key); 
                    if (total>=3){
                        printf("\n%s\n\n", newmessage);
                        printf("High probability of successful decryption with key value %d.\n\nPress '1' to save file or any other key to continue testing.\n", key);
                        scanf("%d", &m);
                        if (m==1){
                            printf("\nYour message has been printed to file 'output.txt'\");
                            fprintf(output, "%s", newmessage);
                            return 0;
                        }
                        
                            
                    }
            rewind(words);                    
        }
        

        printf("All values tested, no valid solution found.\n");
        return 0;
    }
//-------------------------------------------------------------//
//IF NO VALID MENU OPTION IS CHOSEN
    else{
        
        printf("INVALID CHOICE OR NOT YET IMPLEMENTED.\n");
        return 0;
        }
   
}

