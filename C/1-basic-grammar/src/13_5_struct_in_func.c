/* 结构体在函数中的使用 */
#include <stdio.h>
#include <string.h>

#define NAME_LEN 50

static long baseId=10000;

struct Other{
    char* data;
};
struct User{
    long id;
    char nick_name[NAME_LEN];
    char *email;
    int age;
    char gender; //M-male/F-female
    struct Other other;
    //struct User* link_man;
};

long nextId(void);
struct User getInputUser(void);
void showUser(struct User *user);
void showUserByStruct(struct User user);


int main(void){
    struct User user=getInputUser();
    puts("----------------------------------");
    printf("main user@%p:\n",&user);
    puts("----------------------------------");
    showUser(&user);
    puts("----------------------------------");
    showUserByStruct(user);
    puts("----------------------------------");
    puts("\n");

    struct User user2=user;
    puts("----------------------------------");
    printf("main user2@%p:\n",&user2);
    puts("----------------------------------");
    showUser(&user2);
    puts("----------------------------------");
    
    puts("\n==>over!");
    return 0;
}


long nextId(void){
    baseId++;
    return baseId;
}
 

struct User getInputUser(void){
    struct User user={nextId(),"","",-1,'\0'};
    strcpy(user.nick_name,"Steve Jobs");
    user.email="steve-jobs@gmail.com";//字符常量
    user.age=40;
    user.gender='M';
    user.other=(struct Other){"test"};

    printf("getInputUser@%p:\n",&user);
    printf("\t.id==>[%ld]@%p\n",user.id,&user.id);
    printf("\t.nick_name==>[\"%s\"]@%p\n",user.nick_name,user.nick_name);
    printf("\t.email==>[\"%s\"]@%p\n",user.email,user.email);
    printf("\t.age==>[%d]@%p\n",user.age,&user.age);
    printf("\t.gender==>[%c]@%p\n",user.gender,&user.gender);
    printf("\t.other==>[data=\"%s\"@%p]@%p\n",user.other.data,user.other.data,&user.other);
    return user;
}

void showUser(struct User *user){
    printf("showUser@%p:\n",user);
    printf("\t.id==>[%ld]@%p\n",user->id,&user->id);
    printf("\t.nick_name==>[\"%s\"]@%p\n",user->nick_name,user->nick_name);
    printf("\t.email==>[\"%s\"]@%p\n",user->email,user->email);
    printf("\t.age==>[%d]@%p\n",user->age,&user->age);
    printf("\t.gender==>[%c]@%p\n",user->gender,&user->gender);
    printf("\t.other==>[data=\"%s\"@%p]@%p\n",user->other.data,user->other.data,&user->other);
}

void showUserByStruct(struct User user){
    printf("showUserByStruct@%p:\n",&user);
    printf("\t.id==>[%ld]@%p\n",user.id,&user.id);
    printf("\t.nick_name==>[\"%s\"]@%p\n",user.nick_name,user.nick_name);
    printf("\t.email==>[\"%s\"]@%p\n",user.email,user.email);
    printf("\t.age==>[%d]@%p\n",user.age,&user.age);
    printf("\t.gender==>[%c]@%p\n",user.gender,&user.gender);
    printf("\t.other==>[data=\"%s\"@%p]@%p\n",user.other.data,user.other.data,&user.other);
}



