#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GAMES 10000
#define MAX_ROLL_BUCKET 21

int rollDice(void)
 {

 int dice1= 1+ rand()%6;
 int dice2= 1+ rand()%6;
 return dice1+dice2;

 }

 void pattern()
 {
   printf("----------------------------------------\n");
 }

int main(void)
{

 srand(time(NULL));
 int wins[MAX_ROLL_BUCKET+1]={0};
 int loses[MAX_ROLL_BUCKET+1]={0};
 int frequency[13]={0};
 int total_rolls=0;
 int total_wins=0;
 int number[MAX_ROLL_BUCKET]={0};


 printf("=== CRAPS SIMULATION REPORT (FOR 10K GAME) ===\n\n");
 printf("Dice Rolls  |    Wins    |   Loses\n");
 pattern();

 for(int i=0 ; i<21; i++)
 {
    if(i==0)
    {
        continue;
    }

    else
    {
      number[i]=i;
    }
 }




for(int i=0; i<GAMES;i++)
 {

 
   int roll_bucket=0;

   int sum= rollDice();
   total_rolls++;
   frequency[sum]++;
   roll_bucket=1;

   if(sum ==7||sum==11)
   {
    wins[1]++;
    total_wins++;
   }

   else if(sum==2||sum==3||sum==12)
   {
    loses[1]++;
   }

   else
   {
    int point= sum;
    int didntwefindthepoint=1;

    while(didntwefindthepoint)
    {

        sum=rollDice();
        frequency[sum]++;
        roll_bucket++;
        total_rolls++;

       if(sum == 7)
       {

        if(roll_bucket<=MAX_ROLL_BUCKET-1)
        {
         loses[roll_bucket]++;
        }

        else
        {
          roll_bucket=MAX_ROLL_BUCKET;
          loses[roll_bucket]++;
        }

         break;

       }

       else
       {

         if(sum == point)
         {
            didntwefindthepoint=0;

            if(roll_bucket<=MAX_ROLL_BUCKET-1)
           {

            wins[roll_bucket]++;
            total_wins++;

           }

            else
            {
              roll_bucket=MAX_ROLL_BUCKET;
              wins[roll_bucket]++;
              total_wins++;

            }
           
          }
        
        }
       
    }
 
 }

 

}

for(int j=1;j<MAX_ROLL_BUCKET;j++)
 {

 printf("%6d      | %7d    | %7d\n", number[j], wins[j], loses[j]);
}

printf("    >20     | %7d    | %7d\n", wins[MAX_ROLL_BUCKET], loses[MAX_ROLL_BUCKET]);
pattern();

float total_winning_rate= (float)(total_wins*100)/GAMES;
float average_duration_of_game= (float)total_rolls/GAMES;

printf(" Total Winning Rate : %%%2.2f (Theoric Rate: %%49.29)\n", total_winning_rate);
printf(" Average Duration Time of Game :%.2f rolls\n", average_duration_of_game);


    return 0;
}