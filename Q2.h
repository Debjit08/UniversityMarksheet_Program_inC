#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct _Student {
char name[30]; int rollNumber; int marks[5]; int subjectIndexes[5]; // index into UniversitySubjectList 
} Student;

typedef enum _Semester { EVEN, ODD } Semester;

extern char *UniversitySubjectList[]; // Available array of Subject names

typedef struct _UniversityMarksheet { int academicYear; // 2019, 2020, etc.
 Semester semester; 
 int totalStudents; // For indicated year and semester
Student *arrayStudents; // Details of every student
} UniversityMarksheet;

void PrintUniversityMarksheet(int totalMarksheets, UniversityMarksheet *marksheets);

//Compare function to compare between marksheet's year and semester.
int comp1(const void *a,const void *b){
	
	UniversityMarksheet *UMA = (UniversityMarksheet *)a;
	UniversityMarksheet *UMB = (UniversityMarksheet *)b;
	
	if(UMA->academicYear == UMB->academicYear)
		return( UMA->semester - UMB->semester);
	else
		return(UMA->academicYear -UMA->academicYear);
}

//
int comp2(const void *a,const void *b){
	int i;
	Student *Sa = (Student *)a;
	Student *Sb = (Student *)b;
	int tA=0, tB=0;
	for(i=0;i<5;i++){
		tA+=Sa->marks[i];
		tB+=Sb->marks[i];
	}
	if(tA==tB)
		return (strcmp(Sa->name,Sb->name));
	else
		return(tA - tB);
		
}

void PrintUniversityMarksheet(int totalMarksheets, UniversityMarksheet *marksheets) {
	int i,j,l;
	char Sem[2][5] = {"EVEN","ODD"};
	qsort(marksheets,totalMarksheets,sizeof(UniversityMarksheet),comp1);
	for(i=0;i<totalMarksheets;i++){
		printf("Year: %d, Semester: %s\n",marksheets[i].academicYear,Sem[marksheets[i].semester]);
		qsort(marksheets[i].arrayStudents, marksheets[i].totalStudents,sizeof(Student),comp2);
		
		for(j=0;j<marksheets[i].totalStudents;j++){
			int t=0;
			for(l=0; l<5; l++)
				t+=marksheets[i].arrayStudents[j].marks[l];
			printf("Total Marks: %d\tName of Student: %s\t",t,marksheets[i].arrayStudents[j].name);
			printf("Subject and Marks\t");
			for(l=0;l<5;l++)
				printf("%s:%d", UniversitySubjectList[marksheets[i].arrayStudents[j].subjectIndexes[l]], marksheets[i].arrayStudents[j].marks[l]);
			printf("\n");
		}
		for(l=0;l<80;l++)
			printf("-");
		printf("\n");
		}
	}


