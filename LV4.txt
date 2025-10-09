ZADATAK 1.



#include<stdio.h>
#include <math.h>

float Trokut (float x, float y, float z) {
     if(x+y>z && y+z> x && z+x > y){
          float P, s;
     s= (x+y+z)/2;
     P= sqrt(s*(s-x)*(s-y)*(s-z));
     return P;
     }
   
     return 0;  
    
} 

int main(void) {
    float a,b,c,d;
    scanf("%f %f %f", &a, &b, &c);
    d = Trokut(a,b,c);
    printf("%f", d); 
}


