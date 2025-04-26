#include <stdio.h>

int main() {
    int choice, n, i;
    double num, result;

    do {
        // Display menu
        printf("\n===== Simple Calculator (N Inputs) =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division (2 numbers only)\n");
        printf("5. Modulus (N integers)\n");
        printf("6. Exit\n");
        printf("Choose an operation (1-6): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Enter how many numbers: ");
            scanf("%d", &n);

            result = (choice == 1 || choice == 3) ? 1 : 0; // Initialize properly

            for (i = 0; i < n; i++) {
                printf("Enter number %d: ", i + 1);
                scanf("%lf", &num);
                if (choice == 1)
                    result += num;
                else if (choice == 2 && i == 0)
                    result = num;
                else if (choice == 2)
                    result -= num;
                else if (choice == 3)
                    result *= num;
            }

            printf("Result = %.2lf\n", result);

        } else if (choice == 4) {
            double a, b;
            printf("Enter first number: ");
            scanf("%lf", &a);
            printf("Enter second number: ");
            scanf("%lf", &b);
            if (b != 0)
                printf("Result = %.2lf\n", a / b);
            else
                printf("Error: Division by zero is not allowed.\n");

        } else if (choice == 5) {
            int mod, temp;
            printf("Enter how many integers: ");
            scanf("%d", &n);
            printf("Enter number 1: ");
            scanf("%d", &mod);
            for (i = 1; i < n; i++) {
                printf("Enter number %d: ", i + 1);
                scanf("%d", &temp);
                if (temp == 0) {
                    printf("Error: Modulus by zero is not allowed.\n");
                    mod = 0;
                    break;
                }
                mod %= temp;
            }
            if (mod != 0 || n == 1)
                printf("Result = %d\n", mod);

        } else if (choice == 6) {
            printf("Exiting calculator. Goodbye!\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 6);

    return 0;
}
