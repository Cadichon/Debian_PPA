/*
** get_ppa_key.c for add-apt-repository in /home/cadichon/Epitech/Debian_PPA
**
** Made by Cadichon
** Login   <leo.labruyere@epitech.eu>
**
** Started on  Tue Jun 13 16:55:05 2017 Cadichon
** Last update Tue Jun 13 16:55:06 2017 Cadichon
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LAST_CHAR(str) str[strlen(str) - 1]

int		main(int argc, char *argv[])
{
  char		**key;
  char		*str;
  char		*ptr;
  size_t	size;
  char		*cmd;
  FILE		*fd;
  int		i;

  if (argc != 2)
    {
      dprintf(2, "Utility for add-apt-repository\n");
      dprintf(2, "Please specify apt update error log\n");
      return (1);
    }
  if ((fd = fopen(argv[1], "r")) == NULL)
    {
      dprintf(2, "Can't open %s\n", argv[1]);
      return (1);
    }
  str = NULL;
  size = 0;
  i = 0;
  key = calloc(32, sizeof(char *));
  while (getline(&str, &size, fd) != -1)
    {
      if ((ptr = strstr(str, "NO_PUBKEY")) != NULL)
	{
	  key[i] = strdup(ptr + 10);
	  LAST_CHAR(key[i]) = '\0';
	  i++;
	}
    }
  free(str);
  key[i] = NULL;
  if (i == 0)
    {
      free(key);
      dprintf(2, "No public key found, exitting...\n");
      return (1);
    }
  i = 0 ;
  dprintf(1, "%s\n", "Public key to add :");
  while (key[i])
    {
      dprintf(1, "- %s\n", key[i]);
      i++;
    }
  i = 0;
  while (key[i])
    {
      asprintf(&cmd, "%s %s", "apt-key adv --keyserver keyserver.ubuntu.com --recv-keys", key[i]);
      free(key[i]);
      system(cmd);
      free(cmd);
      i++;
    }
  free(key);
  fclose(fd);
}
