#include <stdio.h>
#include <stdlib.h>


// PROJECT 1: Addition of Unbounded Integers Using Linked Lists

// Node structure for storing digits
typedef struct DigitNode {
    int digit;
    struct DigitNode* next;
} DigitNode;

// Create new digit node
DigitNode* createDigitNode(int digit) {
    DigitNode* newNode = (DigitNode*)malloc(sizeof(DigitNode));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

// insert digit at the end 
void insertDigit(DigitNode** head, int digit) {
    DigitNode* newNode = createDigitNode(digit);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    DigitNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// create number from string
DigitNode* createNumberFromString(char* numStr) {
    DigitNode* head = NULL;
    int i = 0;
    
    // Skip leading zeros
    while (numStr[i] == '0' && numStr[i+1] != '\0') {
        i++;
    }
    
    // insert digits in reverse order
    int len = 0;
    while (numStr[i + len] != '\0') len++;
    
    for (int j = len - 1; j >= 0; j--) {
        insertDigit(&head, numStr[i + j] - '0');
    }
    
    return head;
}

// add two numbers represented as linked lists
DigitNode* addNumbers(DigitNode* num1, DigitNode* num2) {
    DigitNode* result = NULL;
    DigitNode* tail = NULL;
    int carry = 0;
    
    DigitNode* p1 = num1;
    DigitNode* p2 = num2;
    
    // add digits until both lists are exhausted and no carry remains
    while (p1 != NULL || p2 != NULL || carry != 0) {
        int digit1 = (p1 != NULL) ? p1->digit : 0;
        int digit2 = (p2 != NULL) ? p2->digit : 0;
        
        int sum = digit1 + digit2 + carry;
        
        // If sum is greater than or equal to 10, subtract 10 and set carry to 1
        if (sum >= 10) {
            sum = sum - 10;
            carry = 1;
        } else {
            carry = 0;
        }
        
        // Create new node for result
        DigitNode* newNode = createDigitNode(sum);
        
        if (result == NULL) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        
        // Move to next digits
        if (p1 != NULL) p1 = p1->next;
        if (p2 != NULL) p2 = p2->next;
    }
    
    return result;
}

// display number
void displayNumber(DigitNode* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    
    // Count nodes
    int count = 0;
    DigitNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    // Store digits in array and print in reverse
    int* digits = (int*)malloc(count * sizeof(int));
    temp = head;
    for (int i = 0; i < count; i++) {
        digits[i] = temp->digit;
        temp = temp->next;
    }
    
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", digits[i]);
    }
    free(digits);
}

// Function to free the linked list
void freeNumberList(DigitNode* head) {
    while (head != NULL) {
        DigitNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// ============================================
// PROJECT 2: Circular Linked List
// ============================================

// Node structure for circular linked list
typedef struct CircularNode {
    int data;
    struct CircularNode* next;
} CircularNode;

// Function to create a circular linked list
CircularNode* createCircularList(int n) {
    if (n <= 0) return NULL;
    
    CircularNode* head = NULL;
    CircularNode* tail = NULL;
    
    for (int i = 1; i <= n; i++) {
        int data;
        printf("Input data for node %d : ", i);
        scanf("%d", &data);
        
        CircularNode* newNode = (CircularNode*)malloc(sizeof(CircularNode));
        newNode->data = data;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Make it circular
    if (tail != NULL) {
        tail->next = head;
    }
    
    return head;
}

// Function to display circular linked list
void displayCircularList(CircularNode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    CircularNode* temp = head;
    int count = 1;
    
    printf("\nData entered in the list are :\n");
    do {
        printf("Data %d = %d\n", count, temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);
}

// Function to free circular linked list
void freeCircularList(CircularNode* head) {
    if (head == NULL) return;
    
    CircularNode* current = head;
    CircularNode* next;
    
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);
}

// ============================================
// MAIN MENU
// ============================================

void project1() {
    char num1Str[1000], num2Str[1000];
    
    printf("\n=== PROJECT 1: Unbounded Integer Addition ===\n");
    printf("Enter first large integer: ");
    scanf("%s", num1Str);
    
    printf("Enter second large integer: ");
    scanf("%s", num2Str);
    
    // Create linked lists for both numbers
    DigitNode* num1 = createNumberFromString(num1Str);
    DigitNode* num2 = createNumberFromString(num2Str);
    
    printf("\nFirst number:  ");
    displayNumber(num1);
    printf("\nSecond number: ");
    displayNumber(num2);
    
    // Add the numbers
    DigitNode* result = addNumbers(num1, num2);
    
    printf("\nSum:           ");
    displayNumber(result);
    printf("\n");
    
    // Free memory
    freeNumberList(num1);
    freeNumberList(num2);
    freeNumberList(result);
}

void project2() {
    int n;
    
    printf("\n=== PROJECT 2: Circular Linked List ===\n");
    printf("Input the number of nodes : ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }
    
    printf("\n");
    CircularNode* head = createCircularList(n);
    displayCircularList(head);
    
    // Free memory
    freeCircularList(head);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n========================================\n");
        printf("      LINKED LIST PROGRAMMING PROJECTS\n");
        printf("========================================\n");
        printf("1. Unbounded Integer Addition\n");
        printf("2. Circular Linked List\n");
        printf("3. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                project1();
                break;
            case 2:
                project2();
                break;
            case 3:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
