#include "myhead.h"

int file_Discriptor,input_fd,output_fd;


int hello_myshell(char **inputs_myshell);
int fibonacci_myshell(char **inputs_myshell);
int list_myshell(char **inputs_myshell);
int cd_myshell(char **inputs_myshell);
int help_myshell(char **inputs_myshell);
int quit_myshell(char **inputs_myshell);
int history_myshell(char **inputs_myshell);

char *cmdarray_myshell[] = {
  "hello",
  "fibonacci",
  "list",
  "cd",
  "help",
  "quit",
  "history"
};

int (*functions_myshell[]) (char **) = {
  &hello_myshell,
  &fibonacci_myshell,
  &list_myshell,
  &cd_myshell,
  &help_myshell,
  &quit_myshell,
  &history_myshell
};

int autocalcnum_myshell() {
  return sizeof(cmdarray_myshell) / sizeof(char *);
}

// Functions of the builtin commands.
int hello_myshell(char **inputs_myshell)
{
  printf("Hello World!.....\n");
  return 1;
}

int fibonacci_myshell(char **inputs_myshell)
{
  char *tempchar;
  int numValus;
  size_t tempsize = 32;
  if (inputs_myshell[1]==NULL)
  {
    printf("How many elements you want to display: ");
    tempchar = (char *)malloc(tempsize * sizeof(char));
    getline(&tempchar, &tempsize, stdin);
    if (tempchar == NULL)
    {
      perror("Buffer Error in aloocating.");
      exit(1);
    }
    numValus = atoi(tempchar);
    
    int fib[numValus + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < numValus; i++)
    {
      fib[i] = fib[i -1] + fib[i - 2];
    }
    printf("The first %d values: ",numValus);
    for (int i = 0; i < numValus; i++)
    {
    printf("%d ",fib[i]); 
    }
    printf("\n");
  }
  else
  {
    numValus = atoi(inputs_myshell[1]);
    int fib[numValus + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < numValus; i++)
    {
      fib[i] = fib[i -1] + fib[i - 2];
    }
    printf("The first %d values: ",numValus);
    for (int i = 0; i < numValus; i++)
    {
    printf("%d ",fib[i]); 
    }
    printf("\n");
  }
  return 1;
}

int list_myshell(char **inputs_myshell)
{
    system("ls");
    return 1;
}

int cd_myshell(char **inputs_myshell)
{
  if (inputs_myshell[1] == NULL) 
  {
    fprintf(stderr, "sh: argument expected after the \"cd\"\n");
  } 
  else 
  {
    if (chdir(inputs_myshell[1]) != 0) 
    {
      perror("sh");
    }
  }
  return 1;
}

int help_myshell(char **inputs_myshell)
{
  printf("\n");
  int i;
  for (i = 0; i < autocalcnum_myshell(); i++) 
  {
    printf("  %s\n", cmdarray_myshell[i]);
  }
  printf("\n\nThese are the available commands and\ndisplaying how the available functions are expected to work in the shell created.\n\n");
  printf(">hello: This command will print the 'Hello World.'\n\n");
  printf(">fibonacci: This command will take or ask for the integer argument as input\nand display number of fibonacci series given as input.\n\n");
  printf(">list: This command will display the files in the current folder.\n\n");
  printf(">cd: This command will help you change your current directory location.\n\n");
  printf(">help: This command will display the information about the commands\nand how they are expected to work.\n\n");
  printf(">quit: This command will terminate the uab_sh shell.\n\n");
  return 1;
}

int quit_myshell(char **inputs_myshell)
{
  return 0;
}

int history_myshell(char **myshell_input)
{
  printf("\n");
  int h;
  char hisarr[1000];
  output_fd = open("uab_sh.log", O_RDONLY);
  while((h = read(output_fd,hisarr,1000))>0){
    printf("%s",hisarr);
  }
  printf("\n");
  return 1;
}