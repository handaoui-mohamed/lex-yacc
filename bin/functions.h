/* Chained List */
typedef struct node
{
    double value;
    struct node *next;
} node;

double getNextValue(node **p);
void addNext(node **p, double value);
void allocate(node **p);
void setValue(node *p, double value);
void setNext(node *p, node *next);
int hasNext(node *p);

/* Functions */
double average(node *list);
double sum(node *list);
double product(node *list);
double variance(node *list);
double standardDeviation(node *list);
double min(node *list);
double max(node *list);