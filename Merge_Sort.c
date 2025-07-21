#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to hold student details
typedef struct {
    int id;
    char name[100];
    char reg_date[11]; // Format: YYYY-MM-DD
    int age;
    char Branch[10];
} Student;

// Function to compare dates (YYYY-MM-DD format)
int compare_dates(const char *date1, const char *date2) {
    int y1, m1, d1;
    int y2, m2, d2;

    sscanf(date1, "%d-%d-%d", &y1, &m1, &d1);
    sscanf(date2, "%d-%d-%d", &y2, &m2, &d2);

    if (y1 != y2) return y1 - y2;
    if (m1 != m2) return m1 - m2;
    return d1 - d2;
}

// Function pointer type for comparison
typedef int (CompareFunc)(const char*, const char*);

// Merge function
void merge(Student arr[], int left, int mid, int right, CompareFunc cmp) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Student L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (cmp(L[i].reg_date, R[j].reg_date) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(Student arr[], int left, int right, CompareFunc cmp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, cmp);
        mergeSort(arr, mid + 1, right, cmp);
        merge(arr, left, mid, right, cmp);
    }
}

// Print function
void printStudents(Student arr[], int size) {
    printf("\nID\tName\t\tRegistration Date \tAge\tBranch\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%-15s%-20s%d\t%-10s\n", arr[i].id, arr[i].name, arr[i].reg_date, arr[i].age, arr[i].Branch);
    }
}

// Reverse comparison function for descending order
int compare_dates_desc(const char *date1, const char *date2) {
    return compare_dates(date2, date1);
}

// Main function
int main() {
    Student students[] = {
        {101, "Aarav", "2024-03-15", 22, "B.Tech"},  
        {102, "Sai Priya", "2024-04-10", 24, "MBA"},  
        {103, "Vikram", "2024-01-25", 23, "M.Sc"}, 
        {104, "Ananya", "2024-05-05", 21, "BBA"},  
        {105, "Rohan", "2024-06-12", 25, "M.Tech"},  
        {106, "Neha", "2024-07-19", 22, "B.Com"},  
        {107, "Karan", "2024-08-22", 24, "MCA"},  
        {108, "Hemachandra", "2024-02-28", 23, "MCA"}, 
        {109, "Divya", "1998-09-30", 22, "B.Sc"},  
        {110, "Arjun", "2023-10-10", 26, "MBA"},
        {111, "Amrutha", "2023-05-15", 21, "MCA"},
        {112, "Bhavana", "2023-08-10", 22, "MCA"},
        {113, "Hema", "2024-01-20", 20, "MBA"},
        {114, "Lathesh", "2022-01-05", 21, "MBA"},
        {115, "Santhosh", "2024-02-02", 21, "MCA"},
        {116, "Mohit", "2024-01-01", 20, "CA"},
        {117, "Likith", "2023-02-01", 21, "MCA"},
        {118, "Hemachandra", "2024-02-08", 23, "MCA"},
        {119, "Sandeep", "2025-02-28", 23, "CA"},
        {120, "Koushik", "2025-09-28", 23, "MCA"},
        {121, "Nischitha", "2025-02-02", 23, "MCA"},
        {122, "Nishanth", "1998-02-08", 23, "MCA"},
        {123, "Lathesha", "2022-12-06", 21, "MBA"}
    };

    int n = sizeof(students) / sizeof(students[0]);
    int choice;

    printf("Choose sorting order:\n");
    printf("1. Ascending Order\n");
    printf("2. Descending Order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        mergeSort(students, 0, n - 1, compare_dates);
    } else if (choice == 2) {
        mergeSort(students, 0, n - 1, compare_dates_desc);
    } else {
        printf("Invalid choice. Sorting in ascending order by default.\n");
        mergeSort(students, 0, n - 1, compare_dates);
    }

    printStudents(students, n);
    return 0;
}

















