#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>      /* flags for read and write */ 
#include <sys/types.h>  /* typedefs */ 
#include <sys/stat.h>   /* structure returned by stat */ 
#include <sys/dir.h>   /* local directory structure */ 
#include <time.h>

#define MAX_PATH 1024 

typedef struct {       /* portable directory entry */ 
    long ino;                  /* inode number */ 
    char name[NAME_MAX+1];     /* name + '\0' terminator */ 
} Dirent; 

struct tm *tm;

void fsize(char *);
void dirwalk(char *, void (*fcn)(char *)); 

main(int argc, char **argv) 
{ 
    if (argc == 1)  /* default: current directory */ 
        fsize("."); 
    else 
        while (--argc > 0) 
            fsize(*++argv); 
    return 0; 
} 

/* fsize:  print the name of file "name" */ 
void fsize(char *name) 
{ 
    struct stat stbuf; 
    if (stat(name, &stbuf) == -1) { 
        fprintf(stderr, "fsize: can't access %s\n", name); 
        return; 
    } 
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) 
        dirwalk(name, fsize); 

    char buff[100];

    printf("File: %s\n", name);     
    printf("Size: %8ld \n", stbuf.st_size); 
    printf("Number of links to file: %8ld \n", stbuf.st_nlink); 
    printf("Mode bits: %8ld \n", stbuf.st_mode); 
    printf("Access: Uid: %d Gid: %d\n", stbuf.st_uid, stbuf.st_gid); 

    tm = localtime(&stbuf.st_atime);
    strftime( buff, 100,"%x - %I:%M%p", tm);
    printf("Access : |%s|\n", buff );

    tm = localtime(&stbuf.st_mtime);
    strftime( buff, 100,"%x - %I:%M%p", tm);
    printf("Modify : |%s|\n", buff );

    tm = localtime(&stbuf.st_ctime);
    strftime( buff, 100,"%x - %I:%M%p", tm);
    printf("Created : |%s|\n", buff);
} 

/* dirwalk:  apply fcn to all files in dir */ 
void dirwalk(char *dir, void (*fcn)(char *)) 
{ 
    char name[MAX_PATH]; 
    Dirent *dp; 
    DIR *dfd; 
    if ((dfd = opendir(dir)) == NULL) { 
        fprintf(stderr, "dirwalk: can't open %s\n", dir); 
        return; 
    } 
    while ((dp = readdir(dfd)) != NULL) { 
        if (strcmp(dp->name, ".") == 0 
            || strcmp(dp->name, "..")) 
            continue;    /* skip self and parent */ 
        if (strlen(dir)+strlen(dp->name)+2 > sizeof(name)) 
            fprintf(stderr, "dirwalk: name %s %s too long\n", 
                dir, dp->name); 
        else { 
            sprintf(name, "%s/%s", dir, dp->name); 
            (*fcn)(name); 
        } 
    } 
    closedir(dfd); 
} 
