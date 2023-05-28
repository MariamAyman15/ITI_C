#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//include standard typedef and struct
#include "STD_TYPES.h"
#include "school.h"

//this function displays the welcome screen and targeted activates.
void main_menu(Student *S,u8 ID) //take student data as an object of struct 
{
    u8 choice;
    do
	{
        printf("Welcome to the School Management System!\n");
        printf("1. New student\n");
        printf("2. Delete student\n");
        printf("3. Student list\n");
        printf("4. Edit student\n");
        printf("5. Rank students\n");
        printf("6. Update student scores\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) //the choice number call the wanted function
		{
            case 1:
                new_student(S);
                break;
            case 2:
                delete_student(S);
                break;
            case 3:
                student_list(S);
                break;
            case 4:
                student_edit(S);
                break;
            case 5:
                rank_student(S);
                break;
            case 6:
                student_score(S);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0); //if choice = 0 exit
}

/*this function creates a new student account. it asks about details of the
student such as name, date of birth, ID, address and phone number. */
void new_student(Student *S)
{
    Student *new_student = (Student *) malloc(sizeof(Student)); //create new node of same size of struct
    if (new_student == NULL)
	{
        printf("Error: could not allocate memory!\n");
    }
    printf("Enter student name: "); //get student data
	_flushall();
     gets(new_student->name);

    printf("Enter student date of birth (DD/MM/YYYY): ");
    scanf("%s", new_student->DateOfBirth);

    printf("Enter student address: ");
	_flushall();
     gets(new_student->address);

    printf("Enter student phone number: ");
    scanf("%s", new_student->phone);

	printf("Enter student ID number: ");
    scanf("%s", new_student->id);

    new_student->cs_score = 0;
    new_student->next = NULL; //next of the new node point to null
    if (head == NULL)
	 {
        head = new_student;
     }
	 else
	 {
        Student *current = head;
        while (current->next != NULL)  //make the last node points to null
		{
            current = current->next;
        }
        current->next = new_student;
     }
    printf("New student added successfully!\n"); 
}

/*this function is for deleting a student account.*/
void delete_student(Student *S)
{
    u8 id[MAX_ID_LENGTH];
    printf("Enter student ID to delete: ");
    scanf("%s", id);
    if (head == NULL) //the linked list is empty
	{
        printf("No students found!\n");
    }
    if (strcmp(head->id, id) == 0) 
	{
        Student *temp = head;
        head = head->next; //point to the next node
        free(temp); //free the allocated node for the deleted student
        printf("Student deleted successfully!\n");
    }
    Student *prev = head;
    Student *current = head->next;
    while (current != NULL)
	{
        if (strcmp(current->id, id) == 0)
		{
            prev->next = current->next;
            free(current);
            printf("Student deleted successfully!\n");
        }
        prev = current;
        current = current->next;
    }
    printf("Student not found!\n");
}

/*this function, you can view the students information such as name, date of
birth, ID, address and phone number in table form (alphabetically ascending).*/
void student_list(Student *S)
{
	u8 j,i=0,k, min_index, count=0;
    if (head == NULL) //the linked list is empty
	{
        printf("No students found!\n");
    }
    // Create an array of pointers to student nodes
    Student *current = head;
    while (current != NULL) //count the number of students
	{
        count++;
        current = current->next;
    }
    Student *students[count];
    current = head;
    while (current != NULL)
	{
        students[i] = current;
        i++;
        current = current->next;
    }
    // Sort the array of pointers using selection sort
    for ( j = 0; j < count - 1; j++)
	{
        min_index = j;
        for ( k = j + 1; k < count; k++)
		{
            if (strcmp(students[k]->name, students[min_index]->name) < 0)
			{
                min_index = k;
            }
        }
        if (min_index != j)
		{
            Student *temp = students[j];
            students[j] = students[min_index];
            students[min_index] = temp;
        }
    }
    // Print out the student information in order
    printf("Student List:\n");
    printf("Name\t\tDOB\t\tID\t\tAddress\t\t\tPhone\t\tCS Score\n");
    printf("------------------------------------------------------------------------\n");
    for (j = 0; j < count; j++)
	{
        printf("%-15s%-15s%-15s%-30s%-15s%-5d \n", students[j]->name, "", students[j]->id, students[j]->address, students[j]->phone, students[j]->cs_score);
    }
}

/*this function has been used for updating a particular student account.*/
void student_edit(Student *S)
{
    u8 id[MAX_ID_LENGTH];
    printf("Enter student ID to edit: ");
    scanf("%s", id);
    if (head == NULL) //the linked list is empty
	{
        printf("No students found!\n");
    }
    Student *current = head;
    while (current != NULL) //search to find the wanted id
	{
        if (strcmp(current->id, id) == 0) //edit the student data
		{
            printf("Enter new name: ");
            scanf("%s", current->name);

            printf("Enter new date of birth: ");
            scanf("%s", current->DateOfBirth);

            printf("Enter new address: ");
            scanf("%s", current->address);

            printf("Enter new phone number: ");
            scanf("%s", current->phone);

            printf("Student information updated successfully!\n");
        }
        current = current->next;
    }
    printf("Student not found!\n");
}

/*this function can sort all students according to computer science score.*/
void rank_student(Student *s)
{
	u8 k,j,i=0,count=0;
    if (head == NULL)
	{
        printf("No students found!\n");
    }
    Student *current = head;
    while (current != NULL) //count the number of students
	{
        count++;
        current = current->next;
    }
    Student *students[count];
    current = head;
    while (current != NULL)
	{
        students[i] = current;
        i++;
        current = current->next;
    }
    for ( j = 0; j < count - 1; j++) //sorting
	{
        for ( k = j + 1; k < count; k++)
		{
            if ((students[j]->cs_score) < (students[k]->cs_score)) //swapping
			{
                Student *temp = students[j];
                students[j] = students[k];
                students[k] = temp;
            }
        }
    }
    printf("Ranking List:\n");
    printf("Rank\tName\t\tCS Score\n");
    printf("--------------------------------\n");
    for ( j = 0; j < count; j++) //print the students name and score
	{
        printf("%d.\t%-15s%d\n", j + 1, students[j]->name, students[j]->cs_score);
    }
}

/*this function has been used for updating score of all students.*/
void student_score(Student *S)
{
    if (head == NULL) //empty linked list
	{
        printf("No students found!\n");
    }
    u8 name[MAX_NAME_LENGTH];
    u32 new_score;
    printf("Enter student name and new computer science score (separated by a space), or enter 'done' to finish:\n");
    while (scanf("%s", name) == 1 && strcmp(name, "done") != 0) 
	{
        scanf("%d", &new_score); //get the new score
        Student *current = head;
        while (current != NULL)
		{
            if (strcmp(current->name, name) == 0) 
			{
                current->cs_score = new_score; //updete the score
                break;
            }
            current = current->next;
        }
        if (current == NULL)
		{
            printf("Student not found: %s\n", name);
        }
		else
		{
            printf("Computer science score updated for student: %s\n", name);
        }
        printf("Enter student name and new computer science score (separated by a space), or enter 'done' to finish:\n");
    }
    printf("Computer science scores updated successfully!\n");
}

