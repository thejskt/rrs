#include<stdio.h>
#include<stdlib.h>
int c,i,pnr; 
char name[30]; 
FILE *fp; 
int n; 
long curr_pos; 
int search(FILE *fp,int pnr); 
void display(FILE *fp); 
typedef struct details 
{ 
 int pnr; 
 char name[30]; 
}details; 
details d; 
int main() 
{ 
 printf("\nWelcome to Railway Reservation System "); 
 printf("\n"); 
 printf("\nHow many Tickets you would like to insert ? : "); 
fflush(stdout); 
 scanf("%d",&n); 
 fp=fopen("rail.txt","a"); 
 for(i=0;i<n;i++) 
 { 
 printf("\nEnter pnr number and name(With spaces): "); fflush(stdout); 
 scanf("%d%s",&d.pnr,d.name); 
 fwrite(&d,sizeof(d),1,fp); 
 } 
 fclose(fp); 
 while(1) 
 { 
 printf("\nWhat would you like to do now ? : \n"); 
 printf("\n1.Display \t2.Search \t3.Modify \t4.Exit \n"); 
 fflush(stdout); 
 scanf("%d",&c); 
 switch(c) 
 { 
 case 1: 
 fp=fopen("rail.txt","r+"); 
 display(fp); 
 printf("\nThe tickets booked are as followed:"); 
 fclose(fp); 
 break; 
 case 2: 
 fp=fopen("rail.txt","r+"); 
 printf("\nEnter pnr number to search : "); fflush(stdout); 
 scanf("%d",&pnr); 
 if(search(fp,pnr)) 
 { 
 printf("\nThe ticket is as follows : "); 
 printf("\n%d\t%s",d.pnr,d.name); fflush(stdout); 
 } 
 else
 printf("\nTicket not found"); 
 fclose(fp); 
 break; 
 case 3: 
 fp=fopen("rail.txt","r+"); 
 printf("\nEnter pnr number to modify the record : "); 
fflush(stdout); 
 scanf("%d",&pnr); 
 if(search(fp,pnr)) 
 { 
 printf("\nEnter new name : "); fflush(stdout); 
 scanf("%s",d.name); 
 printf("\nTicket modified"); 
 fseek(fp, curr_pos, 0); 
 fwrite(&d,sizeof(d),1,fp); 
 } 
 else
 printf("\nSpecified ticket not found "); 
 fclose(fp); 
 break; 
 case 4: 
 printf("Thankyou for using our system,please visit again!!"); 
 return 0; 
 } 
 } 
} 
int search(FILE *fp,int pnr) 
{ 
 rewind(fp); 
 curr_pos = ftell(fp); 
 while(fread(&d,sizeof(d),1,fp)) 
 { 
 if(pnr==d.pnr) {return 1;} 
 curr_pos = ftell(fp); 
 } 
 return 0; 
} 
void display(FILE *fp) 
{ 
 rewind(fp); 
 while(fread(&d,sizeof(d),1,fp)) 
 { 
 printf("\n%d\t%s",d.pnr,d.name); 
 } 
} 
