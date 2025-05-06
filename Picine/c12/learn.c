//Whether or not malloc ( ) is used, the size must be specified before the array can be used. This leaves the problem of how to allocate space when you cannot know beforehand how many elements will need to be created.
// A linked list consists of a chain of elements called nodes. Each node contains the data item to be stored and a pointer pointing to the next node in the list. As each data item is read, a new node is created (using malloc) and tacked on to the end of the list. At the end of the input, the computer memory holds a list of nodes, each containing the data (such as the city's name and the temperature) and a pointer to the next node. The last node has a pointer whose value is NULL, the value defined in ANSI C as a pointer to nowhere.

//Each linked list starts with a simple pointer that points to the first item in the list. This pointer is called the head.
// struct Node { char *City;
// int Temp;
// struct Node *Next;
// };
// typedef struct Node * Link; Link Head;
// The typedef is created to make the code more readable. Predictably, a Link is a pointer to a Node. The first L in k we define is Head, which is NULL when the linked list is empty. Otherwise it points to the first node.
// Initializing a new linked list of this kind requires simply initializing the appropriate variables:
// Head = NULL; 
//NodeCount = O;

//The integer NodeCount will be useful in processing the linked list later on. As soon as the first node is added, Head points to it. Adding nodes can be easy or tedious. If you are adding nodes without being concerned about what place they occupy in the list (an unordered list), you simply add the node at the head. As each node is allocated, its link points to the current Head, and then Head is updated to point to the new Node