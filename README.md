# SAM
Student Achievement Management 学生成绩管理系统<br/>
###目录
1. [课程设计的内容](#课程设计的内容)<br/>
2. [需求分析](#需求分析)<br/>
3. [概要设计](#概要设计)<br/>
  3.1[抽象数据类型定义](#抽象数据类型定义)<br/>
  3.2 [模块划分](#模块划分)<br/>
4. [详细设计](#详细设计)<br/>
  4.1 [数据类型的定义](#数据类型的定义)<br/>
  4.2 [主要模块的算法描述](#主要模块的算法描述)<br/>
  4.3 [函数之间的调用关系](#函数之间的调用关系)<br/>
5. [程序运行说明与测试](#程序运行说明与测试)<br/>
  5.1[用户手册](#用户手册)<br/>
  5.2[测试结果及分析](#测试结果及分析)<br/>
  <br/><br/>
  <hr/>
  
<a name="课程设计的内容"></a>
##1.课程设计的内容
####【问题描述】
    现有学生成绩信息文件1（1.txt）和文件2（2.txt），试编写一管理系统，完成如下功能：
    (1) 实现对两个文件数据进行合并,生成新文件3.txt；
    (2) 抽取出三科成绩中有补考的学生并保存在一个新文件4.txt；
    (3) 合并后的文件3.txt中的数据按总分降序排序
    (4) 输入一个学生姓名后，能查找到此学生的信息并输出结果；
    (5) 要求使用结构体，链或数组等实现上述要求。
####【设计要求】
    (1) 每条信息至少包含 ：姓名、学号、语文、数学、英语；
    (2) 作为一个完整的系统，应具有友好的界面和较强的容错能力；
    (3) 使用汉字显示。    
    
   
<a name="需求分析"></a>
##2.需求分析
   当前我们处于大数据时代，数据传输与数据管理越来越重要，无论前后端开发，还是数据库管理，json类型的数据是不错的选择。
   
  `JSON`(JavaScript Object Notation) 是一种轻量级的数据交换格式。JSON采用完全独立于语言的文本格式，但是也使用了类似于C语言家族的习惯（包括`C`、`C++`、`C#`、`Java`、`JavaScript`、`Perl`、`Pytho`n等）。这些特性使JSON成为理想的数据交换语言。 易于人阅读和编写，同时也易于机器解析和生成(一般用于提升网络传输速率)。
  
  因此，本次课程设计我们采用json作为数据解析与数据存储的类型，并使用cJSON插件辅助解析json类型数据。
  
  本次课程设计实现以下功能：
  (1).分别读取`gradeRecord`文件夹下的两个以json数据类型存储的学生成绩文件`1.txt`和`2.txt`，通过程序的解析处理，以成绩表格的形式展现在控制台屏幕上。若文件不存在，则在控制台提示用过户打开文件错误并返回空值，若学生成绩文件json结构存储不符合要求，则在控制台提示用户相应的错误信息并退出程序；
  (2).合并学生成绩文件1.txt和2.txt到新文件3.txt中，同样以json数据类型存储并实现以学生总分降序排列；
  (3).从学生成绩文件1.txt和2.txt中分析成绩是否及格，将不及格需要补考的学生数据写入新文件4.txt中，同样以json数据类型存储，并将分析结果展现在控制台屏幕上;
  (4).用户在控制台输入学生姓名进行查找，若学生成绩文件1.txt和2.txt中存在该学生，则在控制台屏幕上输出该学生的数据信息，若不存在则提示用户该学生不存在；
  
  以上程序功能通过菜单导航的形式在控制台屏幕上展示给用户，用户可以根据自己的需求，输入对应的菜单序号，范围为1-6内的所有正整数，选择对应的程序功能。程序可以跳步执行。

