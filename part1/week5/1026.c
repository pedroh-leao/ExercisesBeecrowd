#include <stdio.h>
#include <math.h>

int main(){
    unsigned int n1, n2, n3;
    int b1[32], b2[32];

    while(scanf("%u %u", &n1, &n2) != EOF){
        n3 = 0;

        for(int i=31; i>=0; i--){
            if(n1 == 0)
                b1[i] = 0;
            else{
                b1[i]= n1 % 2;
                n1 /= 2;
            }
        }
        for(int i=31; i>=0; i--){
            if(n2 == 0)
                b2[i] = 0;
            else{
                b2[i]= n2 % 2;
                n2 /= 2;
            }
        }

        for (int i = 0; i < 32; i++)
        {
            if(!((b1[i] == 1 && b2[i] == 1) || (b1[i] == 0 && b2[i] == 0))){
                //b3[i] = 1;
                //31-i
                n3 += pow(2, 31-i);
            }            
        }

        printf("%u\n", n3);
    }

    return 0;
}