#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char** argv)
{
    int src = open(argv[1], O_RDONLY);
    int dst = open(argv[2], O_WRONLY | O_CREAT, 0644);

    off_t tamanho = lseek(src, 0, SEEK_END);
    char* memory = (char*)malloc(tamanho);
    lseek(src, 0, SEEK_SET);

    ssize_t bytes = read(src, memory, tamanho);

    while(bytes > 0)
    {
        write(dst, memory, bytes);
        bytes = read(src, memory, tamanho);
    }

    close(src);
    close(dst);
    free(memory);
    
    return 0;
}
