#include "myhead.h"



char *readingInput_myshell(void)
{
  char *myshell_readline = NULL;
  size_t linesize = 0;

  if (getline(&myshell_readline, &linesize, stdin) == -1)
  {
    if (feof(stdin))
    {
      exit(EXIT_SUCCESS);
    }
    else
    {
      perror("readline");
      exit(EXIT_FAILURE);
    }     
  }
  return myshell_readline;
}

char **tokenLine_myshell(char *myshell_readline)
{
    int linesize = 256, line_splitter = 0;
    char **strings = malloc(linesize * sizeof(char*));
    char *input_word;
    if (!strings)
    {
      fprintf(stderr, "sh: Error in aloocating.\n");
      exit(EXIT_FAILURE);
    }
    input_word = strtok(myshell_readline, " \t\r\n\a");
    while (input_word != NULL)
    {
        strings[line_splitter] = input_word;
        line_splitter++;

        if (line_splitter >= linesize)
        {
          linesize += 256;
          strings = realloc(strings, linesize * sizeof(char*));
          if (!strings)
          {
            fprintf(stderr, "sh: Error in aloocating.\n");
            exit(EXIT_FAILURE);
          }
            
        }
        input_word = strtok(NULL, " \t\r\n\a");
    }
    strings[line_splitter] = NULL;
    return strings;
    
}

int execvpCall_myshell(char **inputs_myshell)
{
  pid_t p_id;
  int cmd_execute;

  p_id = fork();
  if(p_id == 0)
  {
    if (execvp(inputs_myshell[0], inputs_myshell) == -1)
    {
      perror("sh");
    }
    exit(EXIT_FAILURE);
  }
  else if(p_id < 0)
  {
    perror("sh");
  }
  else
  {
    do
    {
      waitpid(p_id, &cmd_execute, WUNTRACED);
    } 
    while (!WIFEXITED(cmd_execute) && !WIFSIGNALED(cmd_execute));
      
  }

  return 1;
    
}

int run_myshell(char **inputs_myshell)
{
  int i;

  if (inputs_myshell[0] == NULL) 
  {
    return 1;
  }

  for (i = 0; i < autocalcnum_myshell(); i++) 
  {
    if (strcmp(inputs_myshell[0], cmdarray_myshell[i]) == 0) 
    {
      return (*functions_myshell[i])(inputs_myshell);
    }
  }

  return execvpCall_myshell(inputs_myshell);
}

int main(int argc, char **argv)
{  

  char *myshell_readline;
  char **inputs_myshell;
  int cmd_execute;

  do
  { 
    printf("uab_sh > ");
    myshell_readline = readingInput_myshell();
    file_Discriptor = open("uab_sh.log",O_CREAT | O_RDONLY | O_APPEND, 0755);
    size_t size = strlen(myshell_readline);
    if(file_Discriptor==-1)
    {
      printf("Error in creating the file \n");
    }
    close(file_Discriptor);
    input_fd = open("uab_sh.log", O_WRONLY | O_APPEND);
    write(input_fd,myshell_readline,size);
    close(input_fd);
   
    inputs_myshell = tokenLine_myshell(myshell_readline);
    
    
    cmd_execute = run_myshell(inputs_myshell);
    
    free(myshell_readline);
    free(inputs_myshell);
  } while (cmd_execute);

  return EXIT_SUCCESS;
}