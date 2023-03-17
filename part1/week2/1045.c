#include <stdio.h>
 
void ordemDecrescente(double *a, double *b, double *c){
   double aux;
   
   if(*a > *b && *a > *c){
       if(*c > *b){
           aux = *b;
           *b = *c;
           *c = aux;
       }
   }
   else if(*b > *c){
       if(*a > *c){
           //b > a > c
           aux = *b;
           *b = *a;
           *a = aux;
       }
       else{
           //b > c > a
           aux = *c;
           *c = *a;
           *a = *b;
           *b = aux;
       }
   }
   else{
       if(*a > *b){
           //c > a > b
           aux = *a;
           *a = *c;
           *c = *b;
           *b = aux;
       }
       else{
           //c > b > a
           aux = *a;
           *a = *c;
           *c = aux;
       }
   }
}
 
int main() {
    double a, b, c;
 
    scanf("%lf %lf %lf", &a, &b, &c);
    ordemDecrescente(&a, &b, &c);
    
    if(a >= b+c){
        printf("NAO FORMA TRIANGULO\n");
    }
    else{
        if(a*a == b*b + c*c){
            printf("TRIANGULO RETANGULO\n");    
        }
        else if(a*a > b*b + c*c){
            printf("TRIANGULO OBTUSANGULO\n");    
        }
        else{
            printf("TRIANGULO ACUTANGULO\n");    
        }
        
        if(a == b && a == c){
            printf("TRIANGULO EQUILATERO\n");
        }
        else if(a == b || a == c || b == c){
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    
    return 0;
}