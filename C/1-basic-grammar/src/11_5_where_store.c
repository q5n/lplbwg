#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define StringLiteral "0 HELLO"

int file_outer_var=10;
static int file_inner_var=20;
const char * file_outer_ptr_str="1 hello";
const char file_outer_arr_str[]="2 hello";
static const char * file_inner_ptr_str="3 hello";
static const char file_inner_arr_str[]="4 hello";

int main(void){
    static int block_static_var=30;
    auto int block_auto_var=40;
    register int block_reg_var=50;

    static char *block_static_ptr_str="5 hello";
    static char block_static_arr_str[]="6 hello";
    char *block_auto_ptr_str="7 hello";
    char block_auto_arr_str[]="8 hello";
    
    int *block_dynamic_var_ptr=(int*) malloc(sizeof(int));
    *block_dynamic_var_ptr=60;

    char *block_dynamic_arr_str=(char*) malloc(block_reg_var*sizeof(char));
    strcpy(block_dynamic_arr_str,"9 hello");
    
    printf("1. StringLiteral:'%s', addr:%p, ptr_addr:%p\n",StringLiteral,StringLiteral,&StringLiteral);
    printf("2. file_outer_var:%d, addr:%p\n",file_outer_var,&file_outer_var);
    printf("3. file_inner_var:%d, addr:%p\n",file_inner_var,&file_inner_var);
    printf("4. file_outer_ptr_str:'%s', addr:%p, ptr_addr:%p\n",file_outer_ptr_str,file_outer_ptr_str,&file_outer_ptr_str);
    printf("5. file_outer_arr_str:'%s', addr:%p, addr+1:%p, ptr_addr:%p ptr_addr+1:%p\n",file_outer_arr_str,file_outer_arr_str,file_outer_arr_str+1,&file_outer_arr_str,&file_outer_arr_str+1);
    printf("6. file_inner_ptr_str:'%s', addr:%p, ptr_addr:%p\n",file_inner_ptr_str,file_inner_ptr_str,&file_inner_ptr_str);
    printf("7. file_inner_arr_str:'%s', addr:%p, ptr_addr:%p\n",file_inner_arr_str,file_inner_arr_str,&file_inner_arr_str);
    printf("8. block_static_var:%d, addr:%p\n",block_static_var,&block_static_var);
    printf("9. block_auto_var:%d, addr:%p\n",block_auto_var,&block_auto_var);
    //printf("10. block_reg_var:%d, addr:%p\n",block_reg_var,&block_reg_var); //&block_reg_var错误，不能对寄存器变量取址
    printf("10. block_reg_var:%d\n",block_reg_var);
    printf("11. block_static_ptr_str:'%s', addr:%p, ptr_addr:%p\n",block_static_ptr_str,block_static_ptr_str,&block_static_ptr_str);
    printf("12. block_static_arr_str:'%s', addr:%p, ptr_addr:%p\n",block_static_arr_str,block_static_arr_str,&block_static_arr_str);
    printf("13. block_auto_ptr_str:'%s', addr:%p, ptr_addr:%p\n",block_auto_ptr_str,block_auto_ptr_str,&block_auto_ptr_str);
    printf("14. block_auto_arr_str:'%s', addr:%p, ptr_addr:%p\n",block_auto_arr_str,block_auto_arr_str,&block_auto_arr_str);
    printf("15. block_dynamic_var_ptr:%d, addr:%p, ptr_addr:%p\n",*block_dynamic_var_ptr,block_dynamic_var_ptr,&block_dynamic_var_ptr);
    printf("16. block_dynamic_arr_str:'%s', addr:%p, ptr_addr:%p\n",block_dynamic_arr_str,block_dynamic_arr_str,&block_dynamic_arr_str);
    free(block_dynamic_var_ptr);
    free(block_dynamic_arr_str);
    //printf("17. block_dynamic_var_ptr:%d, addr:%p, ptr_addr:%p\n",*block_dynamic_var_ptr,block_dynamic_var_ptr,&block_dynamic_var_ptr);
    //printf("18. block_dynamic_arr_str:'%s', addr:%p, ptr_addr:%p\n",block_dynamic_arr_str,block_dynamic_arr_str,&block_dynamic_arr_str);
    return 0;
}
