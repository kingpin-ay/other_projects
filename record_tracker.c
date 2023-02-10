#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100
#define MAX_STUDENTS 100

struct student
{
    char name[MAX_LEN];
    char id[MAX_LEN];
    char office[MAX_LEN];
    float marks;
};

int main()
{
    FILE *fp;
    char line[MAX_LEN];
    struct student students[MAX_STUDENTS];
    int student_count = 0;
    float max_marks = 0;
    int max_marks_student_index = 0;

    // Open the file for reading --> "r"
    fp = fopen("students.csv", "r");

    // Check if file was opened successfully
    if (fp == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }

    // Read the header line and ignore it
    fgets(line, MAX_LEN, fp);

    // Read the rest of the lines
    while (fgets(line, MAX_LEN, fp) != NULL)
    {
        char *token;
        token = strtok(line, ",");
        strcpy(students[student_count].name, token);
        token = strtok(NULL, ",");
        strcpy(students[student_count].id, token);
        token = strtok(NULL, ",");
        strcpy(students[student_count].office, token);
        token = strtok(NULL, ",");
        students[student_count].marks = atof(token);

        // Update the max marks and the corresponding student index
        if (students[student_count].marks > max_marks)
        {
            max_marks = students[student_count].marks;
            max_marks_student_index = student_count;
        }

        student_count++;
    }

    // Close the file
    fclose(fp);

    // Print the student with the highest marks
    printf("Student with highest marks: \n");
    printf("Name: %s\n", students[max_marks_student_index].name);
    printf("ID: %s\n", students[max_marks_student_index].id);
    printf("Office: %s\n", students[max_marks_student_index].office);
    printf("Marks: %.2f\n", students[max_marks_student_index].marks);

    return 0;
}