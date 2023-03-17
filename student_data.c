#include<stdio.h>
#include<conio.h>
struct student                                                                  
{                                                                               
 char name[30];                                                                 
 int id, mark;                                                                  
};       

// adds student mark record
void addrecord()                                                                     
{                                                                               
  struct student stu;  
  FILE*fp;
  char ch;
  fp = fopen("student_mark_list.txt", "a+");
  printf("\nEnter student id: ");
  scanf("%d", &stu.id);

  printf("\nEnter student name: ");                                               
  scanf(" %s", stu.name);

  printf("\nEnter student mark: ");                                               
  scanf("%d", &stu.mark);

  fprintf(fp, "%d %s %d\n", stu.id, stu.name, stu.mark);
  fclose(fp);
  printf("\nStudent mark is written successfully!");
}

// searches student mark record
void showrecord()
{
  struct student stu;                                                           
  FILE *fp; 
  int id, status=0;                                                                    
  fp = fopen("student_mark_list.txt", "a+");                                   
  if(fp == NULL)                                                                
  {                                                                             
    printf("\nStudent mark list does not exists!");                                           
  }                                                                             
  else                                                                          
  {
     printf("\nEnter student id: ");
     scanf("%d", &id);
     printf("\nstudent id\tstudent name\t mark");                               
     while(fscanf(fp, "%d %s %d\n", &stu.id, stu.name, &stu.mark)!=EOF)                                    
     { 
       if(id == stu.id)
       {                                                                         
         printf("\n%d\t%s\t%d", stu.id,stu.name,stu.mark);                        
         status = 1;
       }
     }                                                                          
     fclose(fp);                                                                
  }                 
  if(status == 0)
  {
    printf("\nStudent mark does not exists!");
  }                                                            
}   

// deletes student mark record
void deleterecord()                                                               
{                                                                               
  struct student stu;                                                           
  FILE *fp, *fp_temp;                                                                     
  int id, status=0;                                                             
  fp = fopen("student_mark_list.txt", "r+");                                   
  fp_temp = fopen("student_mark_list_temp.txt", "a+");
  if(fp == NULL)                                                                
  {                                                                             
    printf("\nStudent mark list does not exists!");                             
  }                                                                             
  else                                                                          
  {                                                                             
     printf("\nEnter student id: ");                                            
     scanf("%d", &id);
     while(fscanf(fp, "%d %s %d\n", &stu.id, stu.name, &stu.mark)!=EOF)           
     {                                                           
       if(id != stu.id)                                                         
       { 
         fprintf(fp_temp, "%d %s %d\n", stu.id, stu.name, stu.mark);
       }        
       else
       {
         status =1;
       }                                                                
     }                                                               
     if(status == 1)                                                               
     {                                                                             
       printf("\nStudent mark detail is deleted for student id : %d", id);         
     }             
     fclose(fp);                                                                
     fclose(fp_temp);
     remove("student_mark_list.txt");
     rename("student_mark_list_temp.txt", "student_mark_list.txt");
  }                                                                             
}

// show all the student mark records
void showall()                                                              
{                                                                               
  struct student stu;                                                           
  FILE *fp;                                                                     
  fp = fopen("student_mark_list.txt", "a+");                                   
  if(fp == NULL)                                                                
  {                                                                             
    printf("\nStudent mark list does not exists!");                             
  }                                                                             
  else                                                                          
  {                                                                             
     printf("\nstudent id\tstudent name\t mark");                               
     while(fscanf(fp, "%d %s %d\n", &stu.id, stu.name, &stu.mark)!=EOF)           
     { 
       printf("\n%d\t%s\t%d", stu.id,stu.name,stu.mark);                        
     }                                                                          
     fclose(fp);                                                                
  }                                                                             
}  

void main()
{
  struct student stu;
  int option;
  printf("\nstudent mark details\n-------------------");
  do
  {
  printf("\n1 -> add record\n2 -> delete record\n3 -> show record\n4 -> show all\n5 -> exit");
  printf("\nEnter option: ");
  scanf("%d", &option);
  switch(option)
  {
    case 1:
      addrecord();
      break;
    case 2:
      deleterecord();
      break;
    case 3:
      showrecord();
      break;
      
      
    case 4:
      showall();
      break;
    case 5:
      return;
    default:
      printf("\nInvalid option!");
  }
  }while(1);;
}

