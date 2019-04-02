

#include <stdio.h>

int main(){
   
       char alpha[26];
       int n, count = 0;
       

        printf("Enter the no of characters present in an array \n ");
        scanf("%d", &n);

        printf(" Enter the string of %d characters \n" , n);
        scanf("%s", alpha);

        while (count < n)
        {
            printf(" %c=%d\n", alpha[count], alpha[count] );
            alpha[0]=alpha[0]+1;
            printf(" %c=%d\n", alpha[count], alpha[count] );
            ++ count ;
        }
        
}
