struct node
{
    double value;
    struct node *next;
};

typedef struct node node;

double getNextValue(node **p);
void addNext(node **p, double value);
void allocate(node **p);
void setValue(node *p, double v);
void setNext(node *p, node *next);
int hasNext(node *p);
double getValue(node *p);