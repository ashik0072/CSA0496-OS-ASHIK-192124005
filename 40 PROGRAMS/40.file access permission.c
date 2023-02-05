#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char *filename;
    struct stat fs;
    int r;

    if( argc<2 )
    {
        puts("Filename required");
        exit(1);
    }

    filename = argv[1];
    printf("Obtaining permission mode for '%s':\n",filename);
    r = stat(filename,&fs);
    if( r==-1 )
    {
        fprintf(stderr,"File error\n");
        exit(1);
    }

    printf("Permission bits: %X\n",fs.st_mode);

    return(0);
}
