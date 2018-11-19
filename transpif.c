// Ankush Dave
// I pledge my honor that I have abided by the Stevens Honor System

// #2

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int main() {

    int idx,jdx,i,j,b,n,m;
    int block_size;

    // get input width,height and block size
    scanf("%d%d%d",&m,&n,&block_size);

    printf("size\tblock\tmicroseconds\n");

    printf("%d\t",n);
    printf("%d\t",block_size);

    // matrix using malloc
    int *src = (int *)malloc(n * m * sizeof(int)); 
    int *dest = (int *)malloc(n * m * sizeof(int)); 
    int val = 0;

    // initializing the matrix cells
    for(i=0; i< m*n;i++) {
        src[i] = i;
    }

    struct timeval start, end;

    // time before transposing is stored in start
    gettimeofday(&start, 0);

    for (i=0; i<m; i += block_size) {

        for(j = 0; j < n; j++) {

            //transposing a block of size block_size
            for(b = 0; (b < block_size) && ((i + b) < m); b++) {
                dest[j*m + i + b] = src[(i + b)*n + j];
            }

        }

    }

    // time after transposing is stored in end
    gettimeofday(&end, 0);

    long sec,ms;
    
    // time taken to calculate transpose in microseconds
    sec = end.tv_sec*1000000 - start.tv_sec*1000000 + end.tv_usec - start.tv_usec;
    printf("%ld\n",sec);

    return 0;
}
