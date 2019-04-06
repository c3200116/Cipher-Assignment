#ifndef VARIABLE
#define VARIABLE
char applyKey (char x, int y);
int keycheck(int key, int c);


//-------------------------------------------------------------------------//


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
             }
             else {
             return key;
             }
        }
}
#endif