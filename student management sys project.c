#include <stdio.h>
#include <stdlib.h>
struct student{
int id;
char name[50];
float marks;
};

int main(){
FILE *fp, *temp;
int choice;

struct student s;

while(1){
printf("\n--student management system--\n");
printf("1. Add student\n");
printf("2. Display student\n");
printf("3. remove student\n");
printf("4. Exit\n");

printf("enter choice:");
scanf("%d", &choice);

switch(choice){

case 1:
fp= fopen("student.txt", "a");
printf("Enter id:");
scanf("%d", &s.id);
printf("Enter name:");
scanf("%s", s.name);
printf("Enter marks:");
scanf("%f",&s.marks);
fprintf(fp,"%d %s %.2f\n",s.id,s.name,s.marks);
fclose(fp);
printf("student added successfully!\n");
break;

case 2:
fp = fopen("student.txt", "r");
printf("\n--student list--\n");

while(fscanf(fp, "%d %s %f", &s.id,s.name,&s.marks)!=EOF){
    printf("id:%d | name:%s | marks:%.2f\n",s.id,s.name,s.marks);
}
fclose(fp);
break;

case 3:
{
    int id, found = 0;

    fp = fopen("student.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL){
        printf("File error!\n");
        break;
    }

    printf("Enter ID to delete:");
    scanf("%d", &id);

    while(fscanf(fp, "%d %s %f", &s.id, s.name, &s.marks) == 3){
        if(s.id != id){
            fprintf(temp, "%d %s %.2f\n", s.id, s.name, s.marks);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    if(remove("student.txt") != 0 || rename("temp.txt", "student.txt") != 0){
        printf("Error updating file!\n");
    }

    if(found)
        printf("Student deleted successfully!\n");
    else
        printf("Student not found!\n");

    break;
}


case 4:
  exit(0);

default:
    printf("invalid choice!\n");
}}
return 0;
}
