#include<stdio.h>
#include<string.h>
void addStudent();
void editStudent();
void deleteStudent();
void searchStudent();
void displayListOfStudents();
int rollNumber[100];
char name[100][21];
int numberOfRecordsAdded;
int main()
{
int ch;
numberOfRecordsAdded=0;
while(1)
{
printf("1. Add\n");
printf("2. Edit\n");
printf("3. Delete\n");
printf("4. Search\n");
printf("5. List\n");
printf("6. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch<1 || ch>6)
{
printf("Invalid choice \n");
continue;
}
if(ch==1)
{
if(numberOfRecordsAdded==100)
{
printf("You cannot add more than 100 students\n");
continue;
}
addStudent();
}
if(ch>=2 && ch<=5)
{
if(numberOfRecordsAdded==0)
{
printf("You have not added any students\n");
continue;
}
if(ch==2) editStudent();
if(ch==3) deleteStudent();
if(ch==4) searchStudent();
if(ch==5) displayListOfStudents();
}
if(ch==6) break;
}
return 0;
}
void addStudent()
{
int k,e;
char m;
char nm[22];
printf("Student (Add Module)\n");
printf("Enter roll number : ");
scanf("%d",&k);
fflush(stdin);
if(k<=0)
{
printf("Invalid roll number\n");
return;
}
e=0;
while(e<numberOfRecordsAdded)
{
if(rollNumber[e]==k)
{
printf("That roll number alloted to %s\n",name[e]);
return;
}
e++;
}
printf("Enter name : ");
fgets(nm,22,stdin);
fflush(stdin);
printf("Save (Y/N) : ");
scanf("%c",&m);
fflush(stdin);
nm[strlen(nm)-1]='\0';
if(m!='y' && m!='Y')
{
printf("Student not added\n");
return;
}
rollNumber[numberOfRecordsAdded]=k;
strcpy(name[numberOfRecordsAdded],nm);
numberOfRecordsAdded++;
printf("Student added\n");
printf("Press enter key to continue.......");
getchar();
fflush(stdin);
}
void editStudent()
{
int k,e,found;
char nm[22];
char m;
printf("Student (Edit Module)\n");
printf("Enter roll number : ");
scanf("%d",&k);
fflush(stdin);
if(k<=0)
{
printf("Invalid roll number\n");
return;
}
found=0;
for(e=0;e<numberOfRecordsAdded;e++)
{
if(k==rollNumber[e])
{
found=1;break;
}
}
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name : %s\n",name[e]);
printf("Edit (Y/N) : ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not updated\n");
return;
}
printf("Enter new name : ");
fgets(nm,22,stdin);
fflush(stdin);
nm[strlen(nm)-1]='\0';
printf("Update (Y/N) : ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not updated\n");
return;
}
strcpy(name[e],nm);
printf("Student updated\n");
}
void deleteStudent()
{
int k,e,found,i;
char m;
printf("Student (Delete Module)\n");
printf("Enter roll number : ");
scanf("%d",&k);
fflush(stdin);
if(k<=0)
{
printf("Invalid roll number\n");
return;
}
found=0;
for(e=0;e<numberOfRecordsAdded;e++)
{
if(k==rollNumber[e])
{
found=1;
break;
}
}
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name : %s\n",name[e]);
printf("Delete (Y/N) : ");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Student not deleted\n");
return;
}
i=numberOfRecordsAdded-2;
while(e<=i)
{
rollNumber[e]=rollNumber[e+1];
strcpy(name[e],name[e+1]);
e++;
}
numberOfRecordsAdded--;
printf("Student deleted\n");
printf("Press enter key to continue.......");
getchar();
fflush(stdin);
}
void searchStudent()
{
int k,e,found;
printf("Student (Search Module)\n");
printf("Enter roll number : ");
scanf("%d",&k);
fflush(stdin);
if(k<=0)
{
printf("Invalid roll number\n");
return;
}
found=0;
for(e=0;e<numberOfRecordsAdded;e++)
{
if(k==rollNumber[e])
{
found=1;
break;
}
}
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name : %s\n",name[e]);
printf("Press enter key to continue...........\n");
getchar();
fflush(stdin);
}
void displayListOfStudents()
{
int f;
printf("Student (Dipslay Module\n");
for(f=0;f<numberOfRecordsAdded;f++)
{
printf("Roll number %d, Name %s\n",rollNumber[f],name[f]);
}
printf("Press enter key to continue...........\n");
getchar();
fflush(stdin);
}