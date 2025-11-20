#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
typedef struct Node {
    int coeff;       // coefficient
    int px, py;      // powers of x and y
    struct Node* next;
} Node;

// Function to create new node
Node* createNode(int coeff, int px, int py) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->px = px;
    newNode->py = py;
    newNode->next = NULL;
    return newNode;
}

// Insert at end of linked list
void insertTerm(Node** poly, int coeff, int px, int py) {
    Node* newNode = createNode(coeff, px, py);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        Node* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display polynomial
void displayPoly(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%d*x^%d*y^%d", poly->coeff, poly->px, poly->py);
        if (poly->next != NULL && poly->next->coeff >= 0)
            printf(" + ");
        else if (poly->next != NULL)
            printf(" ");
        poly = poly->next;
    }
    printf("\n");
}

// Function to create polynomial from user input
Node* createPolynomial() {
    Node* poly = NULL;
    int n, coeff, px, py;

    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient, power of x, power of y (e.g., 3 2 1 for 3x^2y^1): ");
        scanf("%d %d %d", &coeff, &px, &py);
        insertTerm(&poly, coeff, px, py);
    }

    return poly;
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL;

    printf("Create first polynomial:\n");
    poly1 = createPolynomial();

    printf("\nCreate second polynomial:\n");
    poly2 = createPolynomial();

    printf("\nFirst Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    return 0;
}