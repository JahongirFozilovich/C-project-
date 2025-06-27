// Online C compiler to run C program online
#include <stdio.h>

#define SIZE 10

//  structure for product
struct Product {
    int id;
    char name[20];
    float price;
    int stock;
};

// Global array of products
struct Product products[SIZE];

// Global variable for user role
int role = 0;



//  declarations of functions
void initializeProducts();
void selectRole();
void customerMenu();
void shopkeeperMenu();
void displayProducts();
void purchaseProduct();
void restockProduct();

int main() {
    initializeProducts();
    selectRole();

    if (role == 1) {
        customerMenu();
    } else if (role == 2) {
        shopkeeperMenu();
    } else {
        printf("Invalid role selected. Program exiting.\n");
    }

    return 0;
}

// Initialize 10 sample products
void initializeProducts() {
    products[0] = (struct Product){1, "Apple", 1.00, 50};
    products[1] = (struct Product){2, "Bread", 2.50, 30};
    products[2] = (struct Product){3, "Milk", 1.75, 25};
    products[3] = (struct Product){4, "Eggs", 3.00, 40};
    products[4] = (struct Product){5, "Rice", 4.00, 20};
    products[5] = (struct Product){6, "Pasta", 2.00, 35};
    products[6] = (struct Product){7, "Sugar", 2.25, 45};
    products[7] = (struct Product){8, "Salt", 0.80, 60};
    products[8] = (struct Product){9, "Oil", 5.00, 15};
    products[9] = (struct Product){10, "Butter", 3.50, 10};
}

// Role selection
void selectRole() {
    printf("Select Role:\n");
    printf("1. Customer\n");
    printf("2. Shopkeeper\n");
    printf("Enter choice: ");
    scanf("%d", &role);
}

// Customer menu
void customerMenu() {
     int choice;
    while (1) {
        printf("\n--- Customer Menu ---\n");
        printf("Press 1 to View Products\n");
        printf("Press 2 to Purchase Product\n");
        printf("Press 3 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice) {
            case 1:
                displayProducts();
                break;
            case 2:
                purchaseProduct();
                break;
            case 3:
                printf("Thank you for shopping with TOPSIDE\n");
                return;
            default:
                printf("Invalid choice. Try again\n");
        }
    }
}

// Shopkeeper menu
void shopkeeperMenu() {
    int choice;
    do {
        printf("\n--- Shopkeeper Menu ---\n");
        printf("1. View Products\n");
        printf("2. Restock Product\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayProducts();
        } else if (choice == 2) {
            restockProduct();
        } else if (choice == 3) {
            printf("Goodbye, Shopkeeper!\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
}

// Display all products
void displayProducts() {
    int i;
    printf("\nID\tName\t\tPrice\tStock\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d\t%-10s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

//  customer purchase
void purchaseProduct() {
        printf("Buy products by writing its ID and Quantity!!!\n\n");
    int p = 1, choice, i = 0;
    int id1[10], quant1[10];
    while (p == 1) {
        printf("Write ID and Quantity!");
        scanf("%d %d", &id1[i], &quant1[i]);
        while (quant1[i] > products[i].stock || quant1[i] < 0) {
            printf("Invalid quantity\nMaximum value for this product is %d\n", products[id1[i] - 1].stock);
            printf("Please write again: ");
            scanf("%d", &quant1[i]);
        }
        i++;
        printf("Do you want to buy something else?\n");
        printf("Press 1, if Yes\n");
        printf("Press 2, if No\n\n\n");
        scanf("%d", &choice);
        if (choice == 1){
            continue;
        }
        else {
            break;
        }
    }
    int dm; 
    float sum=0;
    for (int j = 0; j < i; j++) {
        printf("%d %d\n", id1[j], quant1[j]);
        sum += (products[id1[j]-1].price * quant1[j]);
    }
    printf("Total amount:$%.2f\n", sum);
    printf("Purchase successful!\n");

    for (int j = 0; j < i; j++) {
        products[id1[j]-1].stock -= quant1[j];
    }

    
}

//  restocking
void restockProduct() {
    int id, quantity, i, found = 0;
    printf("Enter Product ID to restock: ");
    scanf("%d", &id);

    for (i = 0; i < SIZE; i++) {
        if (products[i].id == id) {
            found = 1;
            printf("Enter quantity to add: ");
            scanf("%d", &quantity);

            if (quantity > 0) {
                products[i].stock += quantity;
                printf("Restock done successfully. New stock: %d\n", products[i].stock);
            } else {
                printf("Invalid quantity.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}
