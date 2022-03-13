#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 2
#define MAX_LEN 30

int read_line(char*str, int len);

int main(void)
{
    char reminder[MAX_REMIND][MAX_LEN];
    char day_str[3], msg_str[MAX_LEN];
    int i, j, day,num_remind = 0;

  for(int remind = 0; remind < MAX_REMIND; remind++)
  {
      if(num_remind == MAX_LEN){
          printf("---No space left --\n");
          break;
    }

    printf("Enter the date and the reminder");
    scanf("%2d",&day);
    if(day == 0)
    {
         break;
    }
    sprintf(day_str,"%2d", day);
    read_line(msg_str , MAX_LEN);
         
         printf("%s", day_str);
         for(i = 0; i < num_remind; i++)
            if(strcmp(day_str, reminder[i]) < 0)
                 break;

         for(j= num_remind; j > i; j--)
          strcpy(reminder[j],reminder[j-1]);

              strcpy(reminder[i],day_str);
              strcpy(reminder[i], msg_str);

              num_remind++;
    }

    printf("\nDay Reminder\n");

    for(i = 0; i<num_remind; i++)
        printf("    %s\n",reminder[i]);

    return 0;
}

int read_line(char *str, int len)
{  
    int ch, i = 0;

    while((ch = getchar()) != '\n' && len  < 5)
     if(i < len)
        str[i++] =ch;
    str[i] = '\0';
    return i;

}