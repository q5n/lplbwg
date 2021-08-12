/* qsort()示例 */
#include <stdio.h>
#include <stdlib.h>

#define NUM 50

void fill_array(double arr[],int n);
void show_array(const double arr[],int n);
int my_compare(const void *p1,const void *p2);


int main(void){
    double vals[NUM];

    puts("Random list:");
    fill_array(vals,NUM);
    show_array(vals,NUM);
    
    qsort(vals,NUM,sizeof(double),my_compare);
    
    puts("\nAfter qsort:");
    show_array(vals,NUM);

    puts("\n==>over!");
    return 0;
}

void fill_array(double arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=(double)rand()/((double)rand()-rand());
    }
}
void show_array(const double arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%9.4f ",arr[i]);
        if(i%10==9){
            putchar('\n');
        }
    }
    if(i%10!=0){
        putchar('\n');
    }
}
int my_compare(const void *p1,const void *p2){
    const double *a1=(const double *)p1;
    const double *a2=(const double *)p2;
    if(*a1<*a2){
        return -1;
    }else if (*a1==*a2){
        return 0;
    }else {
        return 1;
    }
}

