   #include <stdio.h> 
   /* print Celsius-Fahrenheit table */

   int main() 
   { 
     float fahr, celsius; 
     float lower, upper, step; 
     lower = 1;      /* lower limit of temperatuire scale */ 
     upper = 300;    /* upper limit */ 
     step = 20;      /* step size */ 
     celsius = lower; 
     printf("Celsius  Fahrenheit \n");

     while (celsius <= upper) { 
         fahr = (celsius*9.0)/5.0 + 32; 
         printf("%10.0f %8.1f\n", celsius, fahr); 
         celsius = celsius + step; 
     } 
    return 0;
   } 
