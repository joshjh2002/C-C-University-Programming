#include <stdio.h>

int main()
{
int num=13;
int ctr=0;
for(int i=2;i<=num/2;i++){
  if(num % i==0){
      ctr++;
      break;
   }
 }
if(ctr==0 || num== 1) //select if statement from below
     printf("%d is a prime number.\n",num);
else
     printf("%d is not a prime number",num);
     
return 0;
}
