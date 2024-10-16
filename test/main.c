#include<stdio.h>
#include<string.h>

int main(void)
{
  char s[30];
  int len;
  
  scanf("%s", s);
  len=strlen(s);
  
  if(s[len-3]=='s' && s[len-2]=='a' && s[len-1]=='n')
    {
      printf("Yes\n");
    }
  else
    {
      printf("No\n");
    }
  return 0;
}
