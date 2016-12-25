


/*************************引用标准头文件*********************************
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






/*************************引用cJSON插件处理json数据**********************
* 
*
*/
#include "cJSON.h"
#include "cJSON.c"  
/*
*
*
*************************************************************************/





/*************************定义学生结构体*******************************
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



/************************定义cJSON解析对象和数组的方法********************
*
*
*/
stu Expjson(char *s,int ifprint=1){
	stu student;
	cJSON *root = cJSON_Parse(s);
	if(!root) {
		printf("获取对象失败 !\n");
		exit(0);
	}

/****************获取节点id************/
	cJSON *id = cJSON_GetObjectItem(root, "id");
	if(!id) {
		printf("No id !\n");
		exit(0);
	}
	
/**************************************/


/****************获取节点Infor**********/
	cJSON *Infor = cJSON_GetObjectItem(root, "Infor");
	if(!Infor) {
		printf("No Infor !\n");
		exit(0);
	}
/**************************************/



/****************获取节点Xh***********/
	cJSON *Xh = cJSON_GetObjectItem(Infor, "Xh");
	if(!Xh) {
		printf("No Xh !\n");
		exit(0);
	}
/**************************************/

/****************获取节点name***********/
	cJSON *name = cJSON_GetObjectItem(Infor, "name");
	if(!name) {
		printf("No name !\n");
		exit(0);
	}	
/**************************************/

/****************获取节点Sex***********/
	cJSON *Sex = cJSON_GetObjectItem(Infor, "Sex");
	if(!Sex) {
		printf("No Sex !\n");
		exit(0);
	}
/**************************************/



/****************获取节点Grade**********/
	cJSON *Grade = cJSON_GetObjectItem(root, "Grade");
	if(!Grade) {
		printf("No Grade !\n");
		exit(0);
	}
/**************************************/

/****************获取节点Chinese***********/
	cJSON *Chinese = cJSON_GetObjectItem(Grade, "Chinese");
	if(!Chinese) {
		printf("No Chinese !\n");
		exit(0);
	}
/**************************************/

/****************获取节点Chinese***********/
	cJSON *Math = cJSON_GetObjectItem(Grade, "Math");
	if(!Math) {
		printf("No Math !\n");
		exit(0);
	}
/**************************************/

/****************获取节点Chinese***********/
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
	printf("|   %d   |",Chinese->valueint+Math->valueint+English->valueint);//总成绩
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







/************************定义cJSON创建对象的方法********************
*
*
*/

char *create_jsObject(int ID,const char *const XH,const char *const NAME,const char *const SEX,int CHINESE,int MATH,int ENGLISH)
{
    cJSON *root;
    root = cJSON_CreateObject();
    if(!root) {
        printf("创建对象失败!\n");
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
			//printf("创建对象成功!\n"); 
            //printf("您创建的对象是 %s\n",s);
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



/************************学生结构体转换为json字符串********************
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




/***************************降序排列**************************************
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









/**********************************优化界面****************************
*
*
*/
//欢迎界面
void welcome(){	
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t--------------------------------------------------------------------\n\n\n");
	printf("\t\t\t\t\t\t欢迎来到学生成绩管理系统\n\n");
	printf("\t\t\t\t\t\t Power BY Wang Xuefeng\n\n\n");	
	printf("\t\t\t--------------------------------------------------------------------\n\n\n");
}


void nav(){	
	printf("\n\t导航菜单，请选择下面的一项并按回车，\n");	
	printf("--------------------------------------------------------------------\n");
	printf("\t\t1.查看学生成绩文件1.txt\n");
	printf("\t\t2.查看学生成绩文件2.txt\n");
	printf("\t\t3.合并学生成绩文件1.txt和2.txt到3.txt，并按总分降序排列\n");
	printf("\t\t4.筛选需要补考的学生成绩到文件4.txt，并查看\n");
	printf("\t\t5.搜索学生姓名查看成绩信息\n");
	printf("\t\t6.退出程序\n");
	printf("\n\n");
}






//初始化表头
void initlistHead(){
	printf("---------------------------------------------------------------------------\n");
	printf("|  ID\t|    学号    |\t 姓名\t| 性别 |  语文\t|  数学\t|  英语\t|  总 分  |\n");
}



/*
*
*
*************************************************************************/







/************************************文件操作*****************************
*
*
*/
//合并后的数据写入文件3.txt
void writenew(char *s){

 FILE *fp=fopen("gradeRecord/3.txt","a");
 fprintf(fp,s,120);
 fprintf(fp,"\n",1);
 fclose(fp); 

}

//不及格的学生信息写入文件4.txt
void writeEA(char *s){

 FILE *fp=fopen("gradeRecord/4.txt","a");
 fprintf(fp,s,120);
 fprintf(fp,"\n",1);
 fclose(fp); 

}

//筛选不及格学生并写入文件4.txt，并返回补考情况
char *needexamagain(stu p){	
	char name[20];
	char str1[100];		
	char str2[100];		
	char str3[100];


		strcpy(str1,strcat(strcpy(name,p.name),"\t语文通过"));
		strcpy(str2,"\t数学通过");
		strcpy(str3,"\t英语通过");

		if (p.Chinese<60||p.Math<60||p.English<60){
						writeEA(stuTOjson(p));						
			}
	   if (p.Chinese<60) {		  
		  strcpy(str1,strcat(strcpy(name,p.name),"\t需要补考语文"));		  
	   }
	   if (p.Math<60) {
		  strcpy(str2,"\t需要补考数学");		 
	   }
	   if (p.English<60) {
		  strcpy(str3,"\t需要补考英语");		 
	   }	   
	
  return strcat(str1,strcat(str2,str3)); 
}

//获取文件P中的第n行信息
char *getfileline(char *p,int n, char *str){
	FILE *fp;
	int i;
	if ((fp=fopen(p,"r"))==NULL){
		printf("打开文件错误\n");
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


//获取一个学生信息并返回
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
	case 1:		printf("学生成绩文件1.txt的内容如下：\n");		
				initlistHead();
				for(i=1;i<(fileline[0]+1);i++){
					students[i-1]=getfullfile("1.txt",i);
				}
				printf("---------------------------------------------------------------------------\n");
				break;
	case 2:		printf("学生成绩文件2.txt的内容如下：\n");	
				initlistHead();			
				for(i=(fileline[0]+1),j=1;i<(fileline[0]+fileline[1]+1);i++){
					students[i-1]=getfullfile("2.txt",j);
					j++;
				}
				printf("---------------------------------------------------------------------------\n");
				break;
	case 3:		printf("合并学生成绩文件1.txt与2.txt的内容如下：\n");	
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
				printf("降序排列合并后的数据并写入文件3.txt，文件3.txt内容如下：\n");	
				initlistHead();
				for(i=0;i<20;i++){
					writenew(stuTOjson(students[i]));
					Expjson(stuTOjson(students[i]));
				}
			    printf("---------------------------------------------------------------------------\n");
				break;
	case 4:		char str[20][100];
				printf("将从以下内容中筛选需要补考的学生信息：\n");		
				initlistHead();
				for(i=1;i<(fileline[0]+1);i++){
					students[i-1]=getfullfile("1.txt",i);
				}
				for(i=11,j=1;i<(fileline[0]+fileline[1]+1);i++){
					students[i-1]=getfullfile("2.txt",j);
				j++;
				}
				printf("---------------------------------------------------------------------------\n");
				printf("筛选后的补考信息如下，并将需要补考的学生信息已写入4.txt\n\n");
				for(i=0;i<(fileline[0]+fileline[1]);i++){					
					strcpy(str[i],needexamagain(students[i]));
					puts(needexamagain(students[i]));
				};
				break;
	case 5:		char name[5];int u;
				printf("请输入您要搜索的姓名:");
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
						printf("\t姓名：%s\n",students[i].name);
						printf("\t学号：%s\n",students[i].xh);
						printf("\t性别：%s\n",students[i].sex);
						printf("\t语文：%d\n",students[i].Chinese);
						printf("\t数学：%d\n",students[i].Math);
						printf("\t英语：%d\n",students[i].English);
						printf("\t总分：%d\n",students[i].total);
						u=1;
					}else{
					continue;
					}				
				}
				if(u==0){
				printf("您输入的姓名不存在！\n");
				};break;
	case 6:exit(0);
	default :printf("您输入有误，请重新输入！\n");break;	
	}
}



void main()
{   
	welcome();
	printf("\n\n\t按回车开始程序...");
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


