#ifndef SCHOOL_H
#define SCHOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "STD_TYPES.h"

//define the length of each string
#define MAX_NAME_LENGTH 50
#define MAX_DateOfBirth_LENGTH 10
#define MAX_ADDRESS_LENGTH 500
#define MAX_PHONE_LENGTH 20
#define MAX_ID_LENGTH 10

//structure to take student data
typedef struct student
{
    u8 name[MAX_NAME_LENGTH];
	u8 DateOfBirth[MAX_DateOfBirth_LENGTH];
    u8 address[MAX_ADDRESS_LENGTH];
    u8 phone[MAX_PHONE_LENGTH];
    u8 id[MAX_ID_LENGTH];
    u32 cs_score;  //computer scince score
    struct student *next;
} Student;

Student *head = NULL;  //initialize

//fuctions proto type
void main_menu(Student *S,u8 ID);
void new_student(Student *S);
void delete_student(Student *S);
void student_list(Student *S);
void student_edit(Student *S);
void rank_student(Student *S);
void student_score(Student *S);

#endif // SCHOOL_H_INCLUDED
