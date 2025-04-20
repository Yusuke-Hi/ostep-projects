#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    exit(0);
  }

  char *filepath[argc];
  for (int i = 1; i < argc; i++)
  {
    filepath[i] = argv[i];
  }

  for (int i = 1; i < argc; i++)
  {
    printf("filepath[%d]: %s\n", i, filepath[i]);
    FILE *fp = fopen(filepath[i], "r");
    if (fp == NULL)
    {
      perror("wcat: cannot open file\n");
      exit(1);
    }

    char buffer[1024];
    char *result;
    while ((result = fgets(buffer, 1024, fp)) != NULL)
    {
      printf("%s", result);
    }

    fclose(fp);
    printf("\n");
  }
}