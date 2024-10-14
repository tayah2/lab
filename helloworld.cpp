#include <stdio.h>
#include <string.h>

// Define month names for convenience
const char* months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Function prototypes
void monthly_sales_report(float sales[]);
void sales_summary_report(float sales[]);
void six_month_moving_average(float sales[]);
void sales_report_high_to_low(float sales[]);

int main() {
    // Sales data (input hardcoded for simplicity)
    float sales[12] = {
        23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,
        72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22
    };

    // Generate reports
    printf("Monthly Sales Report for 2024\n");
    monthly_sales_report(sales);

    printf("\nSales Summary Report:\n");
    sales_summary_report(sales);

    printf("\nSix-Month Moving Average Report:\n");
    six_month_moving_average(sales);

    printf("\nSales Report (Highest to Lowest):\n");
    sales_report_high_to_low(sales);

    return 0;
}

// Function to display the monthly sales report
void monthly_sales_report(float sales[]) {
    printf("%-10s %10s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
}

// Function to display the sales summary (minimum, maximum, and average)
void sales_summary_report(float sales[]) {
    float min = sales[0], max = sales[0], sum = 0.0;
    int minIndex = 0, maxIndex = 0;

    for (int i = 0; i < 12; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }
        sum += sales[i];
    }

    float average = sum / 12.0;
    printf("Minimum sales: $%.2f (%s)\n", min, months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxIndex]);
    printf("Average sales: $%.2f\n", average);
}

// Function to calculate and display the six-month moving average
void six_month_moving_average(float sales[]) {
    for (int i = 0; i <= 6; i++) {
        float sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float average = sum / 6.0;
        printf("%s-%s $%.2f\n", months[i], months[i+5], average);
    }
}

// Function to display the sales report from highest to lowest
void sales_report_high_to_low(float sales[]) {
    // Create a copy of sales array and index array to keep track of the months
    float sorted_sales[12];
    int month_indices[12];

    for (int i = 0; i < 12; i++) {
        sorted_sales[i] = sales[i];
        month_indices[i] = i; // stores the index for sorting months later
    }

    // Sort the sales using a simple selection sort, also sorting the months
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sorted_sales[i] < sorted_sales[j]) {
                // Swap sales
                float temp_sales = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp_sales;

                // Swap corresponding month indices
                int temp_index = month_indices[i];
                month_indices[i] = month_indices[j];
                month_indices[j] = temp_index;
            }
        }
    }

    // Display sorted sales and corresponding months
    printf("%-10s %10s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2f\n", months[month_indices[i]], sorted_sales[i]);
    }
}
