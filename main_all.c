#include<stdio.h>

void displayMenu();
int addGuest();
void displayGuest(int menu);


int main(){
    int a;
displayMenu();
a = addGuest();
displayGuest(a);

return 0;

}

void displayMenu(){
printf("*************");
printf("1.pizza :20000\n");
printf("2.spaghetti :12000\n");
printf("********************\n");
}

int addGuest(){
int menu;
printf("원하는 메뉴는?");
scanf("%d",&menu);
return menu;
}

void displayGuest(int menu){
if(menu==1){
    printf("피자 선택");
}
else printf("스파게티 선택");
printf("\n");
}