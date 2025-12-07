#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUDENT_FILE "students.txt"
#define Credential_File "credentials.txt"
struct Student {
    char name[50];
    int roll;
    float marks;
};
char currentRole[10];
char currentUser[50];


void mainMenu();
void adminMenu();
void guestMenu();
void staffMenu();

int loginSystem();
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();
void updateStudent();

/*---------------------------------------Main Function---------------------------------------*/
int main() {
    printf("\n========================================\n");
    printf("  STUDENT RECORD MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    
    if (loginSystem()) {
        mainMenu();
    } else {
        printf("\nLogin Failed. Exiting...\n");
    }
    return 0;
}


/*---------------------------------------Login System---------------------------------------*/
int loginSystem() {
    char username[50], password[50];
    char fileUsername[50], filePassword[50], fileRole[10];
    
    printf("\n----- Login -----\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    
    FILE *file = fopen(Credential_File, "r");
    if (file == NULL) {
        printf("Error: Credentials file not found!\n");
        printf("Creating default credentials file...\n");
        
        file = fopen(Credential_File, "w");
        fprintf(file, "admin admin123 admin\n");
        fprintf(file, "staff staff123 staff\n");
        fprintf(file, "guest guest123 guest\n");
        fclose(file);
        
        printf("\nDefault users created:\n");
        printf("  admin/admin123 (Admin)\n");
        printf("  staff/staff123 (Staff)\n");
        printf("  guest/guest123 (Guest)\n");
        printf("\nPlease restart the program and login.\n");
        return 0;
    }
    
    while (fscanf(file, "%s %s %s", fileUsername, filePassword, fileRole) != EOF) {
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            strcpy(currentRole, fileRole);
            strcpy(currentUser, username);
            fclose(file);
            printf("\n✓ Login Successful! Welcome %s (%s)\n", currentUser, currentRole);
            return 1;
        }
    }
    fclose(file);
    printf("\n✗ Invalid Username or Password!\n");
    return 0;
}

/*---------------------------------------Main Menu---------------------------------------*/
void mainMenu() {
    if(strcmp(currentRole, "admin") == 0) {
        adminMenu();
    }else if(strcmp(currentRole, "staff") == 0) {
        staffMenu();
    }
    else{
        guestMenu();
    }
}

/*---------------------------------------Staff Menu---------------------------------------*/
void staffMenu() {
    int choice;
    printf("\n========================================\n");
    printf("         STAFF MENU\n");
    printf("========================================\n");
    printf("1. View All Students\n");
    printf("2. Search Student\n");
    printf("3. Logout\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            viewStudents();
            break;
        case 2:
            searchStudent();
            break;
        case 3:
            printf("\nLogging out...\n");
            return;
        default:
            printf("\n✗ Invalid choice!\n");
    }
}

/*---------------------------------------Guest Menu---------------------------------------*/
void guestMenu() {
    printf("\n========================================\n");
    printf("         GUEST MENU\n");
    printf("========================================\n");
    printf("Guest users can only view student list.\n\n");
    viewStudents();
}

/*---------------------------------------Admin Menu---------------------------------------*/
void adminMenu() {
    int choice;
    do {
        printf("\n========================================\n");
        printf("         ADMIN MENU\n");
        printf("========================================\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Logout\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("\nLogging out...\n");
                return;
            default:
                printf("\n✗ Invalid choice!\n");
        }
    } while (choice != 6);
}
/*-------------------------------------add student---------------------------------------*/
void addStudent() {
    struct Student student;
    FILE *file = fopen(STUDENT_FILE, "a");
    
    if (file == NULL) {
        printf("Error opening student file.\n");
        return;
    }
    
    printf("\n----- Add New Student -----\n");
    printf("Enter student name: ");
    scanf("%s", student.name);
    printf("Enter roll number: ");
    scanf("%d", &student.roll);
    printf("Enter marks: ");
    scanf("%f", &student.marks);
    
    fprintf(file, "%s %d %.2f\n", student.name, student.roll, student.marks);
    fclose(file);
    
    printf("\n✓ Student added successfully!\n");
}

/*-------------------------------------view students---------------------------------------*/
void viewStudents() {
    struct Student student;
    FILE *file = fopen(STUDENT_FILE, "r");
    
    if (file == NULL) {
        printf("\nNo student records found.\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("         STUDENT RECORDS\n");
    printf("========================================\n");
    printf("%-20s %-10s %-10s\n", "Name", "Roll No", "Marks");
    printf("----------------------------------------\n");
    
    int count = 0;
    while (fscanf(file, "%s %d %f", student.name, &student.roll, &student.marks) != EOF) {
        printf("%-20s %-10d %-10.2f\n", student.name, student.roll, student.marks);
        count++;
    }
    
    printf("----------------------------------------\n");
    printf("Total Students: %d\n", count);
    fclose(file);
}


/*-------------------------------------search student---------------------------------------*/
void searchStudent() {
    struct Student student;
    int roll, found = 0;
    
    printf("\n----- Search Student -----\n");
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    
    FILE *file = fopen(STUDENT_FILE, "r");
    if (file == NULL) {
        printf("Error opening student file.\n");
        return;
    }
    
    while (fscanf(file, "%s %d %f", student.name, &student.roll, &student.marks) != EOF) {
        if (student.roll == roll) {
            printf("\n✓ Student Found:\n");
            printf("  Name: %s\n", student.name);
            printf("  Roll: %d\n", student.roll);
            printf("  Marks: %.2f\n", student.marks);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\n✗ Student with roll number %d not found.\n", roll);
    }
    fclose(file);
}


/*-------------------------------------update student---------------------------------------*/
void updateStudent() {
    struct Student student;
    int roll, found = 0;
    
    printf("\n----- Update Student -----\n");
    printf("Enter roll number to update: ");
    scanf("%d", &roll);
    
    FILE *file = fopen(STUDENT_FILE, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    
    if (file == NULL || tempFile == NULL) {
        printf("Error opening student file.\n");
        return;
    }
    
    while (fscanf(file, "%s %d %f", student.name, &student.roll, &student.marks) != EOF) {
        if (student.roll == roll) {
            printf("Current Record - Name: %s, Marks: %.2f\n", student.name, student.marks);
            printf("Enter new name: ");
            scanf("%s", student.name);
            printf("Enter new marks: ");
            scanf("%f", &student.marks);
            found = 1;
        }
        fprintf(tempFile, "%s %d %.2f\n", student.name, student.roll, student.marks);
    }
    
    fclose(file);
    fclose(tempFile);
    remove(STUDENT_FILE);
    rename("temp.txt", STUDENT_FILE);
    
    if (found) {
        printf("\n✓ Student record updated successfully.\n");
    } else {
        printf("\n✗ Student with roll number %d not found.\n", roll);
    }
}

/*-------------------------------------delete student---------------------------------------*/
void deleteStudent() {
    struct Student student;
    int roll, found = 0;
    
    printf("\n----- Delete Student -----\n");
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    
    FILE *file = fopen(STUDENT_FILE, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    
    if (file == NULL || tempFile == NULL) {
        printf("Error opening student file.\n");
        return;
    }
    
    while (fscanf(file, "%s %d %f", student.name, &student.roll, &student.marks) != EOF) {
        if (student.roll == roll) {
            printf("Deleting: %s (Roll: %d)\n", student.name, student.roll);
            found = 1;
            continue;
        }
        fprintf(tempFile, "%s %d %.2f\n", student.name, student.roll, student.marks);
    }
    
    fclose(file);
    fclose(tempFile);
    remove(STUDENT_FILE);
    rename("temp.txt", STUDENT_FILE);
    
    if (found) {
        printf("\n✓ Student record deleted successfully.\n");
    } else {
        printf("\n✗ Student with roll number %d not found.\n", roll);
    }
}
