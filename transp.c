// Ankush Dave
// I pledge my honor that I have abided by the Stevens Honor System

// #1

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

/*
* code to calculate pow(x,n)
*/
int pows(int x, int n) {

    if(n==0) {
        return 1;
    }

    int val = pows(x,n/2);

    val = val*val;

    if(n%2!=0)
        val = val*x;

    return val;
}

int main() {
    //different sizes of matrix
    int sizes[] = {2048,4096,8192};
    int idx,jdx,i,j,b;

    printf("size\tblock\tmicroseconds\n");
    //looping over all the sizes
    for(idx =0; idx<3;idx++) {

        int n = sizes[idx],m=sizes[idx];
        int block_val = 2;

        //looping over all the possible block size
        for(jdx=2; block_val<=n; jdx++) {

            int block_size = block_val;
            printf("%d\t",n);
            printf("%d\t",block_size);

            int *src = (int *)malloc(n * m * sizeof(int)); 
            int *dest = (int *)malloc(n * m * sizeof(int)); 
            int val = 0;

            for(i=0; i< m*n;i++) {
                src[i] = i;
            }


            struct timeval start, end;

            //time before transposing is stored in start
            gettimeofday(&start, 0);

            for (i=0; i<m; i += block_size) {

                for(j = 0; j < n; j++) {

                    //transposing a block of size block_size
                    for(b = 0; (b < block_size) && ((i + b) < m); b++) {
                        dest[j*m + i + b] = src[(i + b)*n + j];
                    }
                    
                }
            }

            //time after transposing is stored in end
            gettimeofday(&end, 0);

            long sec,ms;
            //time taken to calculate transpose in microseconds
            sec = end.tv_sec*1000000 - start.tv_sec*1000000 + end.tv_usec - start.tv_usec;
            printf("%ld\n",sec);

            block_val = pows(2,jdx);
        }
    }

    return 0;
}
