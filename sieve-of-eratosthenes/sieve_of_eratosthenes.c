#include <stdio.h>

#define LIMIT 1000

int main(void)
{

 int prime[LIMIT]={0};
 int counter=0;

  for(int i = 0; i< LIMIT ; i++)
  {
    prime[i]=1;
  }

  prime[0]=0;
  prime[1]=0;

  for(int j= 2; j * j< LIMIT ; j++ )
  {

    if (prime[j]==1)
    {

       for( int k= j* j; k < LIMIT ; k= k+j)
        {
       
        prime[k]= 0;
       
        }
   
  }

}

  printf("=== SIEVE OF ERATOSTHENES ( BETWEEN 2 - 999 PRIME NUMBERS) ===\n");


  for(int l=0; l < LIMIT; l++)
  {
    
    if(prime[l] == 1)
    {
        prime[l]=l;
        counter++;

        printf(" %4d ",prime[l]);

      if(counter % 10== 0)

      {

      printf("\n");

      }

    }
   

    
  }
    printf("\n");
 
    printf("Total number of prime numbers is: %d \n",counter);

    return 0;
}