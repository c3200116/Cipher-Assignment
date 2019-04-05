
char function(char x, int y);



#include <stdio.h> 

int main() 
{ 
   char message[200];                //initilises an array of size 200
   int key=0;
   int count=0;
   
   printf("Input message to be encrypted\n");
   scanf("%[^\n]%*c", message);     //takes a string of input including spaces and assigns to array 'str'
   
   printf("Enter encryption key value\n");
   scanf("%d", &key);
   
   for (count=0; count<200; count++){
       if (message[count]
      message[count] = function(message[count], key);
  }

   
   printf("%s\n", message); 
  
   return 0; 
} 

char function (char x, int y){
    x=x+y;
    return x;
}
