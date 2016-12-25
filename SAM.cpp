


/*************************���ñ�׼ͷ�ļ�*********************************
* 
*
*/
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
/* 
*
*
************************************************************************/






/*************************����cJSON�������json����**********************
* 
*
*/
#include "cJSON.h"
#include "cJSON.c"  
/*
*
*
*************************************************************************/





/*************************����ѧ���ṹ��*******************************
* 
*
*/
typedef struct student{
	int id;
	char xh[10];
	char name[20];
	char sex[5];
	int Chinese;
	int Math;
	int English;
	int total;
}stu;
/*
*
*
*************************************************************************/



/************************����cJSON�������������ķ���********************
*
*
*/
stu Expjson(char *s,int ifprint=1){
	stu student;
	cJSON *root = cJSON_Parse(s);
	if(!root) {
		printf("��ȡ����ʧ�� !\n");
		exit(0);
	}

/****************��ȡ�ڵ�id************/
	cJSON *id = cJSON_GetObjectItem(root, "id");
	if(!id) {
		printf("No id !\n");
		exit(0);
	}
	
/**************************************/


/****************��ȡ�ڵ�Infor**********/
	cJSON *Infor = cJSON_GetObjectItem(root, "Infor");
	if(!Infor) {
		printf("No Infor !\n");
		exit(0);
	}
/**************************************/



/****************��ȡ�ڵ�Xh***********/
	cJSON *Xh = cJSON_GetObjectItem(Infor, "Xh");
	if(!Xh) {
		printf("No Xh !\n");
		exit(0);
	}
/**************************************/

/****************��ȡ�ڵ�name***********/
	cJSON *name = cJSON_GetObjectItem(Infor, "name");
	if(!name) {
		printf("No name !\n");
		exit(0);
	}	
/**************************************/

/****************��ȡ�ڵ�Sex***********/
	cJSON *Sex = cJSON_GetObjectItem(Infor, "Sex");
	if(!Sex) {
		printf("No Sex !\n");
		exit(0);
	}
/**************************************/



/****************��ȡ�ڵ�Grade**********/
	cJSON *Grade = cJSON_GetObjectItem(root, "Grade");
	if(!Grade) {
		printf("No Grade !\n");
		exit(0);
	}
/**************************************/

/****************��ȡ�ڵ�Chinese***********/
	cJSON *Chinese = cJSON_GetObjectItem(Grade, "Chinese");
	if(!Chinese) {
		printf("No Chinese !\n");
		exit(0);
	}
/**************************************/

/****************��ȡ�ڵ�Chinese***********/
	cJSON *Math = cJSON_GetObjectItem(Grade, "Math");
	if(!Math) {
		printf("No Math !\n");
		exit(0);
	}
/**************************************/

/****************��ȡ�ڵ�Chinese***********/
	cJSON *English = cJSON_GetObjectItem(Grade, "English");
	if(!English) {
		printf("No English !\n");
		exit(0);
	}
/**************************************/	
	
	if(ifprint == 1){
	printf("|  %d\t",id->valueint);
	printf("|  %s  ",Xh->valuestring);
	printf("|\t%s\t",name->valuestring);
	printf("|  %s  ",Sex->valuestring);
	printf("|   %d\t",Chinese->valueint);	
	printf("|   %d\t",Math->valueint);
	printf("|   %d\t",English->valueint);	   
	printf("|   %d   |",Chinese->valueint+Math->valueint+English->valueint);//�ܳɼ�
	printf("\n");	
	}	


	
	student.id = id->valueint;
	strcpy(student.xh,Xh->valuestring);
	strcpy(student.name,name->valuestring);
	strcpy(student.sex,Sex->valuestring);
	student.Chinese = Chinese->valueint;
	student.Math = Math->valueint;
	student.English = English->valueint;
	student.total = Chinese->valueint+Math->valueint+English->valueint;
	return student;
}

/*
*
*
*************************************************************************/







/************************����cJSON��������ķ���********************
*
*
*/

char *create_jsObject(int ID,const char *const XH,const char *const NAME,const char *const SEX,int CHINESE,int MATH,int ENGLISH)
{
    cJSON *root;
    root = cJSON_CreateObject();
    if(!root) {
        printf("��������ʧ��!\n");
        return NULL;
    }else{
					
       
        cJSON * js_infor ;
        cJSON * js_grade ;
		const char *const id = "id";

        const char *const Infor = "Infor";       

        const char *const Grade = "Grade"; 

        cJSON_AddNumberToObject(root,id,ID);

        cJSON_AddItemToObject(root,Infor,js_infor=cJSON_CreateObject());

       
        cJSON_AddStringToObject(js_infor,"Xh",XH);
        cJSON_AddStringToObject(js_infor,"Name",NAME);
        cJSON_AddStringToObject(js_infor,"Sex",SEX);            

        cJSON_AddItemToObject(root,Grade,js_grade=cJSON_CreateObject());
       
        cJSON_AddNumberToObject(js_grade,"Chinese",CHINESE);
        cJSON_AddNumberToObject(js_grade,"Math",MATH);
        cJSON_AddNumberToObject(js_grade,"English",ENGLISH);            

       
        char *s = cJSON_PrintUnformatted(root);

       // if(s){
			//printf("��������ɹ�!\n"); 
            //printf("�������Ķ����� %s\n",s);
			//Expjson(s);
			//free(s);
       // }
        
        cJSON_Delete(root);
    

    return s;
	}
}

/*
*
*
*************************************************************************/



/************************ѧ���ṹ��ת��Ϊjson�ַ���********************
*
*
*/
char *stuTOjson(stu student){
char *s;
s = create_jsObject(student.id,student.xh,student.name,student.sex,student.Chinese,student.Math,student.English);
return s;
}

/*
*
*
*************************************************************************/




/***************************��������**************************************
*
*
*
*
*/
void sort(stu *p,int line)
{	int i,j;
	stu k;
	 for (i=0;i<line+1;i++)
	  for (j=i+1;j<line+1;j++)
	   if (p[i].total<p[j].total) {
		
		   k.id=p[i].id;
		   strcpy(k.xh,p[i].xh);
		   strcpy(k.name,p[i].name);
		   strcpy(k.sex,p[i].sex);
		   k.Chinese=p[i].Chinese;
		   k.Math=p[i].Math;
		   k.English=p[i].English;
		   k.total=p[i].total;



		   p[i].id=p[j].id;
		   strcpy(p[i].xh,p[j].xh);	
		   strcpy(p[i].name,p[j].name);	
		   strcpy(p[i].sex,p[j].sex);
		   p[i].Chinese=p[j].Chinese;
		   p[i].Math=p[j].Math;
		   p[i].English=p[j].English;
		   p[i].total=p[j].total;




		   p[j].id=k.id;
		   strcpy(p[j].xh,k.xh);
           strcpy(p[j].name,k.name);		   
           strcpy(p[j].sex,k.sex);
		   p[j].Chinese=k.Chinese;
		   p[j].Math=k.Math;
		   p[j].English=k.English;
		   p[j].total=k.total;
		
			
	   }


}
/*
*
*
**************************************************************************/









/**********************************�Ż�����****************************
*
*
*/
//��ӭ����
void welcome(){	
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t--------------------------------------------------------------------\n\n\n");
	printf("\t\t\t\t\t\t��ӭ����ѧ���ɼ�����ϵͳ\n\n");
	printf("\t\t\t\t\t\t Power BY Wang Xuefeng\n\n\n");	
	printf("\t\t\t--------------------------------------------------------------------\n\n\n");
}


void nav(){	
	printf("\n\t�����˵�����ѡ�������һ����س���\n");	
	printf("--------------------------------------------------------------------\n");
	printf("\t\t1.�鿴ѧ���ɼ��ļ�1.txt\n");
	printf("\t\t2.�鿴ѧ���ɼ��ļ�2.txt\n");
	printf("\t\t3.�ϲ�ѧ���ɼ��ļ�1.txt��2.txt��3.txt�������ֽܷ�������\n");
	printf("\t\t4.ɸѡ��Ҫ������ѧ���ɼ����ļ�4.txt�����鿴\n");
	printf("\t\t5.����ѧ�������鿴�ɼ���Ϣ\n");
	printf("\t\t6.�˳�����\n");
	printf("\n\n");
}






//��ʼ����ͷ
void initlistHead(){
	printf("---------------------------------------------------------------------------\n");
	printf("|  ID\t|    ѧ��    |\t ����\t| �Ա� |  ����\t|  ��ѧ\t|  Ӣ��\t|  �� ��  |\n");
}



/*
*
*
*************************************************************************/







/************************************�ļ�����*****************************
*
*
*/
//�ϲ��������д���ļ�3.txt
void writenew(char *s){

 FILE *fp=fopen("gradeRecord/3.txt","a");
 fprintf(fp,s,120);
 fprintf(fp,"\n",1);
 fclose(fp); 

}

//�������ѧ����Ϣд���ļ�4.txt
void writeEA(char *s){

 FILE *fp=fopen("gradeRecord/4.txt","a");
 fprintf(fp,s,120);
 fprintf(fp,"\n",1);
 fclose(fp); 

}

//ɸѡ������ѧ����д���ļ�4.txt�������ز������
char *needexamagain(stu p){	
	char name[20];
	char str1[100];		
	char str2[100];		
	char str3[100];


		strcpy(str1,strcat(strcpy(name,p.name),"\t����ͨ��"));
		strcpy(str2,"\t��ѧͨ��");
		strcpy(str3,"\tӢ��ͨ��");

		if (p.Chinese<60||p.Math<60||p.English<60){
						writeEA(stuTOjson(p));						
			}
	   if (p.Chinese<60) {		  
		  strcpy(str1,strcat(strcpy(name,p.name),"\t��Ҫ��������"));		  
	   }
	   if (p.Math<60) {
		  strcpy(str2,"\t��Ҫ������ѧ");		 
	   }
	   if (p.English<60) {
		  strcpy(str3,"\t��Ҫ����Ӣ��");		 
	   }	   
	
  return strcat(str1,strcat(str2,str3)); 
}

//��ȡ�ļ�P�еĵ�n����Ϣ
char *getfileline(char *p,int n, char *str){
	FILE *fp;
	int i;
	if ((fp=fopen(p,"r"))==NULL){
		printf("���ļ�����\n");
		return NULL;
	}
	for(i=1;i<n;i++)
		if ((fgets(str,120,fp))==NULL) {
			fclose(fp);
			return NULL;
		}
	fgets(str,120,fp);
	fclose(fp);
	return str;

}


//��ȡһ��ѧ����Ϣ������
stu getfullfile(char *filename,int i,int ifprint=1){	
	stu student;
	stu studentErr;
	studentErr.id = -1;
	char p[120];
	char file[100]="gradeRecord/";
	strcat(file,filename);	
	if ((getfileline(file,i, p))==NULL) {return studentErr;}		
	
	if(ifprint==1){
		student = Expjson(p);
	}else{
		student = Expjson(p,0);
	}

	return student;
}






/*
*
*
*************************************************************************/








void matching(int num,int *fileline){
	switch(num){
		int i,j;
		stu students[20];
	case 1:		printf("ѧ���ɼ��ļ�1.txt���������£�\n");		
				initlistHead();
				for(i=1;i<(fileline[0]+1);i++){
					students[i-1]=getfullfile("1.txt",i);
				}
				printf("---------------------------------------------------------------------------\n");
				break;
	case 2:		printf("ѧ���ɼ��ļ�2.txt���������£�\n");	
				initlistHead();			
				for(i=(fileline[0]+1),j=1;i<(fileline[0]+fileline[1]+1);i++){
					students[i-1]=getfullfile("2.txt",j);
					j++;
				}
				printf("---------------------------------------------------------------------------\n");
				break;
	case 3:		printf("�ϲ�ѧ���ɼ��ļ�1.txt��2.txt���������£�\n");	
				initlistHead();
				for(i=1;i<(fileline[0]+1);i++){
					students[i-1]=getfullfile("1.txt",i);
				}
				for(i=(fileline[0]+1),j=1;i<(fileline[0]+fileline[1]+1);i++){
					students[i-1]=getfullfile("2.txt",j);
					j++;
				}
				printf("---------------------------------------------------------------------------\n");
				printf("\n\n");
				sort(students,20);				
				printf("�������кϲ�������ݲ�д���ļ�3.txt���ļ�3.txt�������£�\n");	
				initlistHead();
				for(i=0;i<20;i++){
					writenew(stuTOjson(students[i]));
					Expjson(stuTOjson(students[i]));
				}
			    printf("---------------------------------------------------------------------------\n");
				break;
	case 4:		char str[20][100];
				printf("��������������ɸѡ��Ҫ������ѧ����Ϣ��\n");		
				initlistHead();
				for(i=1;i<(fileline[0]+1);i++){
					students[i-1]=getfullfile("1.txt",i);
				}
				for(i=11,j=1;i<(fileline[0]+fileline[1]+1);i++){
					students[i-1]=getfullfile("2.txt",j);
				j++;
				}
				printf("---------------------------------------------------------------------------\n");
				printf("ɸѡ��Ĳ�����Ϣ���£�������Ҫ������ѧ����Ϣ��д��4.txt\n\n");
				for(i=0;i<(fileline[0]+fileline[1]);i++){					
					strcpy(str[i],needexamagain(students[i]));
					puts(needexamagain(students[i]));
				};
				break;
	case 5:		char name[5];int u;
				printf("��������Ҫ����������:");
				gets(name);
				for(i=1;i<(fileline[0]+1);i++){
					students[i-1]=getfullfile("1.txt",i,0);
				}
				for(i=11,j=1;i<(fileline[0]+fileline[1]+1);i++){
					students[i-1]=getfullfile("2.txt",j,0);
				j++;
				}
				u=0;
				for(i=0;i<(fileline[0]+fileline[1]);i++){					
					if(strcmp(students[i].name,name)==0){
						printf("\t������%s\n",students[i].name);
						printf("\tѧ�ţ�%s\n",students[i].xh);
						printf("\t�Ա�%s\n",students[i].sex);
						printf("\t���ģ�%d\n",students[i].Chinese);
						printf("\t��ѧ��%d\n",students[i].Math);
						printf("\tӢ�%d\n",students[i].English);
						printf("\t�ܷ֣�%d\n",students[i].total);
						u=1;
					}else{
					continue;
					}				
				}
				if(u==0){
				printf("����������������ڣ�\n");
				};break;
	case 6:exit(0);
	default :printf("�������������������룡\n");break;	
	}
}



void main()
{   
	welcome();
	printf("\n\n\t���س���ʼ����...");
	getchar();
	system("cls");
	int num=0;
	int fileline[2]={10,10};
	while(num!=6){		
		nav();
		scanf("%d",&num);
		getchar();		
		matching(num,fileline);
		num=0;
	}
}


