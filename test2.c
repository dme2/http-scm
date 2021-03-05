#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getDirList(char* directory) {
               DIR *d;
               char* res = calloc(1024,sizeof(char));
               struct dirent *dir;
               d = opendir(directory);
               if (d) {
                       while((dir = readdir(d)) != NULL){
                         char temp[50];
                         strcpy(temp,dir->d_name);
                              strcat(temp,"\n");
                         strcat(res,temp);
                        }
                       closedir(d);
               }
               return res;
}

int main(){
  char *res = getDirList("/home/dave/projects");
  printf("running\n");
  printf(res);
  return 0;
}
