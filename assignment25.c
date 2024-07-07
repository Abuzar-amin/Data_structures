#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int element;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void create() 
{
    int n, i;
    struct node *temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: \n");

    for (i = 0; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &temp->element);
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
}

void view() 
{
    struct node *x = head;
    while (x != NULL) {
        printf("%d ", x->element);
        x = x->next;
    }
    printf("\n");
}

int getSum()
{
    int sum = 0;
    struct node *y = head;
    while (y != NULL) {
        sum += y->element;
        y = y->next;
    }
    return sum;
}

float getAverage(int n) 
{
    int sum = getSum();
    return sum / n;
}

int getMax() 
{
    int max = head->element;
    struct node *x = head;
    while (x != NULL) {
        if (x->element > max) {
            max = x->element;
        }
        x = x->next;
    }
    return max;
}

int getMin()
{
    int min = head->element;
    struct node *x = head;
    while (x != NULL) {
        if (x->element < min) {
            min = x->element;
        }
        x = x->next;
    }
    return min;
}

float getVariance(int n) 
{
    float mean = getAverage(n);
    float variance = 0;
    struct node *x = head;
    while (x != NULL) {
        variance += pow(x->element - mean, 2);
        x = x->next;
    }
    return variance / n;
}

float getStandardDeviation(int n) 
{
    return sqrt(getVariance(n));
}

int main() {
    create();
    view();

    struct node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Sum: %d\n", getSum());
    printf("Average: %f\n", getAverage(count));
    printf("Max: %d\n", getMax());
    printf("Min: %d\n", getMin());
    printf("Variance: %f\n", getVariance(count));
    printf("Standard Deviation: %f\n", getStandardDeviation(count));

    return 0;
}
