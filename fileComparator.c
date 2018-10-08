#include<stdio.h>
#include<stdlib.h>

char * getFile(char * filename, long long * length) {
    char * buffer = 0;
    FILE * f = fopen (filename, "rb");

    if (f)
    {
      fseek (f, 0, SEEK_END);
      fseek (f, 0, SEEK_SET);
      buffer = malloc (*length);
      if (buffer)
      {
        fread (buffer, 1, *length, f);
      }
      fclose (f);
    }
    return buffer;
}

int main (int argc, char **argv) {
  long long length = atoll(argv[3]);

  char * f1 = getFile(argv[1], &length);
  char * f2 = getFile(argv[2], &length);

  for (int i = 0; i < length; i++) {
    if (!(*(f1+i) == *(f2+i))) {
      printf("error at : %d", i);
      return 1;
    }
  }
  printf("no errors");

  return 0;

}
