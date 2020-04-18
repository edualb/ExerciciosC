// rubro-negra lib

/*  
typedef struct node {
    int value;
    char color; // r-> red, b-> black
    Node* right;
    Node* left;
    Node* father;
} Node;
*/
typedef struct node Node;

// Responsable to create a new node.
Node* create(int value);

// Responsable to insert a new node in the tree.
void insert(Node* node);

// Responsable to print the tree.
void printTree();