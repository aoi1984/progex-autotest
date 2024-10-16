#include<stdio.h>

void gen_build_target(const char *target)
{
  printf("main: %s\n", target);
  printf("\tgcc %s -o main\n", target);
}

void gen_test_target(const int testnum, const char **inputs, const char **expects)
{
  printf("test: main");
  for(int i=0; i<testnum; i++)
    {
      printf(" %s", inputs[i]);
    }
  for(int i=0; i<testnum; i++)
    {
      printf(" %s", expects[i]);
    }

  printf("\n");
  
  for(int i=0; i<testnum; i++)
    {
      printf("\t./main < %s > %s.out\n", inputs[i], inputs[i]);
      printf("\tdiff %s %s.out; \n", expects[i], inputs[i]);
    }
}

void gen_clean_target(const int testnum, const char **inputs)
{
  printf("clean: \n");
  printf("\trm main");
  for(int i=0; i<testnum; i++)
    {
      printf(" %s.out",inputs[i]);
    }
  printf(" *~\n");
}

int main(const int argc, const char *argv[])
{
  //printf("target filename: %s\n", argv[1]);

  int testnum;
  sscanf(argv[2], "%d", &testnum);

  //printf("number of test cases: %d\n",testnum);

  //printf("input files:");
  //for(int i=0; i<testnum; i++)
  //{
  //printf(" %s",argv[3+i]);
  //}

  //printf("\n");

  //printf("excepted files:");
  //for(int i=0; i<testnum; i++)
  //{
  //  printf(" %s",argv[3+testnum+i]);
  //}

  //printf("\n");

  const char *target = argv[1];
  const char **inputs = argv + 3 ;
  const char **expects = argv + 3+testnum	;

  gen_build_target(argv[1]);
  gen_test_target(testnum, inputs, expects);
  gen_clean_target(testnum, inputs);
}
