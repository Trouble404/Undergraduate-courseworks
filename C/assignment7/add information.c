#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
main()
{
int i;
char a[50];
char b[20];
char c[11];
FILE*fp;
srand((unsigned)time(NULL));
fp=fopen("librarybooks.txt","a");
for(i=0;i<9999;i++){
a[i]=(rand()%(1000000)+(0));
b[i]=(rand()%(10000)+(0));
c[i]=(rand()%(1000000)+(0));
fprintf(fp,"%d ",a[i]);
fprintf(fp,"%d ",b[i]);
fprintf(fp,"%d ",c[i]);
fprintf(fp,"\n");
}
fclose(fp);
}

