//Practical No.: 1 
//Program Description: Implementation of Binary Search Tree.   
//Solution: 
#include<stdio.h> 
#include<stdlib.h> 
 
typedef struct treeNode 
{ 
        int data; 
        struct treeNode *left; 
        struct treeNode *right; 
 
}treeNode; 
 
treeNode* FindMin(treeNode *node) 
{ 
        if(node==NULL) 
        { 
                return NULL; 
        } 
        if(node->left)  
                return FindMin(node->left); 
        else  
                return node; 
} 
treeNode* FindMax(treeNode *node) 
{ 
        if(node==NULL) 
    { 
                 
        return NULL; 
    } 
    if(node->right)  
        FindMax(node->right); 
    else  
        return node;     
} 
 
treeNode * Insert(treeNode *node,int data) 
{ 
        if(node==NULL) 
        { 
                treeNode *temp; 
                temp = (treeNode *)malloc(sizeof(treeNode)); 
                temp -> data = data; 
                temp -> left = temp -> right = NULL; 
                return temp; 
        } 
 
        if(data >(node->data)) 
        { 
                node->right = Insert(node->right,data); 
        } 
        else if(data < (node->data)) 
        { 
                node->left = Insert(node->left,data); 
        } 
        /* Else there is nothing to do as the data is already in the 
tree. */ 
        printf("\nInsertion Successful....\n"); 
        return node; 
} 
 
treeNode * Delete(treeNode *node, int data) 
{ 
        treeNode *temp; 
        if(node==NULL) 
        { 
                printf("Element Not Found"); 
        } 
        else if(data < node->data) 
        { 
                node->left = Delete(node->left, data); 
        } 
        else if(data > node->data) 
        { 
                node->right = Delete(node->right, data); 
        } 
        else 
        { 
                /* Now We can delete this node and replace with 
either minimum element  
                   in the right sub tree or maximum element in the 
left subtree */ 
                if(node->right && node->left) 
                { 
                        /* Here we will replace with minimum element 
in the right sub tree */ 
                        temp = FindMin(node->right); 
                        node -> data = temp->data;  
                        /* As we replaced it with some other node, 
we have to delete that node */ 
 
                        node -> right = Delete(node->right,temp
>data); 
                } 
                else 
                { 
 
                        temp = node; 
                        if(node->left == NULL) 
                                node = node->right; 
                        else if(node->right == NULL) 
                                node = node->left; 
                        free(temp);  
                } 
        } 
        return node; 
 
} 
 
treeNode * Find(treeNode *node, int data) 
{ 
        if(node==NULL) 
        { 
                
                return NULL; 
        } 
        if(data > node->data) 
        { 
                return Find(node->right,data); 
        } 
        else if(data < node->data) 
        { 
    
                return Find(node->left,data); 
        } 
        else 
        { 
                return node; 
        } 
} 
 
 
int main() 
{ 
        treeNode *root = NULL; 
    treeNode * temp; 
    int choice,val; 
    while(1) 
    {
                printf("\nTree Menu"); 
                printf("\n1. Insert Node"); 
                printf("\n2. Delete Node"); 
                printf("\n3. Search an Element"); 
                printf("\n4. Find Minimum Element"); 
                printf("\n5. Find Maximum Element"); 
                printf("\n6. Exit"); 
                printf("\n\nEnter Your Choice (0-9) : "); 
                scanf("%d",&choice); 
                switch(choice) 
                { 
                        case 1: 
                                printf("\nInserting Node in Binary 
Search Tree\n"); 
                                printf("Enter value to insert in new 
node : "); 
                                scanf("%d",&val); 
                                root=Insert(root,val); 
                                break; 
                        case 2: 
                                printf("\nDeleting a Node in Binary 
Search Tree\n"); 
                                printf("Enter value of node to 
Delete : "); 
                                scanf("%d",&val); 
                                root=Delete(root,val); 
                                break; 
                        case 3: 
                                printf("\nSearch a Node"); 
                                printf("\nEnter value to search : 
"); 
                                scanf("%d",&val); 
                                temp = Find(root,val); 
                                if(temp==NULL) 
                                { 
                                        printf("Element %d not 
found\n",val); 
                                } 
                                else 
                                { 
                                        printf("Element %d Found 
\n",val); 
                                } 
                                break; 
                        case 4: 
                                temp = FindMin(root); 
                                printf("Minimum element is 
%d\n",temp->data);  
                                break; 
                        case 5: 
                                temp = FindMax(root); 
                                printf("Maximum element is 
%d\n",temp->data); 
                                break; 
                        case 6: 
                                printf("\nThanks for using Tree 
Program...\n"); 
                                exit(1); 
                                break; 
                        default: 
                                printf("\nInvalid Choice. Please Try 
Again....\n"); 
                                break; 
                } 
        } 
} 
 
 
 




//Practical No.: 2 
//Program Description: Conversion of BST PreOrder/PostOrder/InOrder. 
//Solution: 
#include<stdio.h> 
#include<stdlib.h> 
 
typedef struct treeNode 
{ 
        int data; 
        struct treeNode *left; 
        struct treeNode *right; 
 
}treeNode; 
 
treeNode* FindMin(treeNode *node) 
{ 
        if(node==NULL) 
        { 
                return NULL; 
        } 
        if(node->left)  
                return FindMin(node->left); 
        else  
                return node; 
} 
treeNode* FindMax(treeNode *node) 
{ 
        if(node==NULL) 
    { 
        return NULL; 
    } 
    if(node->right)  
        FindMax(node->right); 
    else  
        return node;     
} 
 
treeNode * Insert(treeNode *node,int data) 
{ 
        if(node==NULL) 
        { 
                treeNode *temp; 
                temp = (treeNode *)malloc(sizeof(treeNode)); 
                temp -> data = data; 
                temp -> left = temp -> right = NULL; 
                return temp; 
        } 
 
        if(data >(node->data)) 
        { 
                node->right = Insert(node->right,data); 
        } 
        else if(data < (node->data)) 
        { 
                node->left = Insert(node->left,data); 
        } 
         
        printf("\nInsertion Successful....\n"); 
        return node; 
} 
 
treeNode * Delete(treeNode *node, int data) 
{ 
        treeNode *temp; 
        if(node==NULL) 
        { 
                printf("Element Not Found"); 
        } 
        else if(data < node->data) 
        { 
                node->left = Delete(node->left, data); 
        } 
        else if(data > node->data) 
        { 
                node->right = Delete(node->right, data); 
        } 
        else 
        { 
 
                if(node->right && node->left) 
                { 
                  
                        temp = FindMin(node->right); 
                        node -> data = temp->data;  
                        node -> right = Delete(node->right,temp
>data); 
                } 
                else 
                { 
                        temp = node; 
                        if(node->left == NULL) 
                                node = node->right; 
                        else if(node->right == NULL) 
                                node = node->left; 
                        free(temp);  
        } 
        return node; 
 
} 
 
treeNode * Find(treeNode *node, int data) 
{ 
        if(node==NULL) 
        { 
                return NULL; 
        } 
        if(data > node->data) 
        { 
                return Find(node->right,data); 
        } 
        else if(data < node->data) 
        { 
                return Find(node->left,data); 
        } 
        else 
        { 
                return node; 
        } 
} 
 
void PrintInorder(treeNode *node) 
{ 
        if(node==NULL) 
        { 
                return; 
        } 
        PrintInorder(node->left); 
        printf("%d ",node->data); 
        PrintInorder(node->right); 
} 
 
void PrintPreorder(treeNode *node) 
{ 
        if(node==NULL) 
        { 
                return; 
        } 
        printf("%d ",node->data); 
        PrintPreorder(node->left); 
        PrintPreorder(node->right); 
} 
 
void PrintPostorder(treeNode *node) 
{ 
        if(node==NULL) 
        { 
                return; 
        } 
        PrintPostorder(node->left); 
        PrintPostorder(node->right); 
        printf("%d ",node->data); 
} 
 
int main() 
{ 
        treeNode *root = NULL; 
    treeNode * temp; 
    int choice,val; 
    while(1) 
    { 
                printf("\nTree Menu"); 
                printf("\n1. Insert Node"); 
                printf("\n2. Delete Node"); 
                printf("\n3. Pre Order Traversal"); 
                printf("\n4. Post Order Traversal"); 
                printf("\n5. In Order Traversal"); 
                printf("\n6. All Traversal"); 
                printf("\n7. Search an Element"); 
                printf("\n8. Find Minimum Element"); 
                printf("\n9. Find Maximum Element"); 
                printf("\n0. Exit"); 
                printf("\n\nEnter Your Choice (0-9) : "); 
                scanf("%d",&choice); 
                switch(choice) 
                { 
                        case 1: 
                                printf("\nInserting Node in Binary 
Search Tree\n"); 
                                printf("Enter value to insert in new 
node : "); 
                                scanf("%d",&val); 
                                root=Insert(root,val); 
                                break; 
                        case 2: 
                                printf("\nDeleting a Node in Binary 
Search Tree\n"); 
                                printf("Enter value of node to 
Delete : "); 
                                scanf("%d",&val); 
                                root=Delete(root,val); 
                                break; 
                        case 3: 
                                PrintPreorder(root); 
                                break; 
                        case 4: 
                                PrintPostorder(root); 
                                break; 
                        case 5: 
                                PrintInorder(root); 
                                break; 
                        case 6: 
                                printf("\nPre Order Traversal:"); 
                                PrintPreorder(root); 
                                printf("\nIn Order Traversal:"); 
                                PrintInorder(root); 
                                printf("\nPost Order Traversal:"); 
                                PrintPostorder(root); 
                                break; 
                        case 7: 
                                printf("\nSearch a Node"); 
                                printf("\nEnter value to search : 
"); 
                                scanf("%d",&val); 
                                temp = Find(root,val); 
                                if(temp==NULL) 
                                { 
                                        printf("Element %d not 
found\n",val); 
                                } 
                                else 
                                { 
                                        printf("Element %d Found 
\n",val); 
                                } 
                                break; 
                        case 8: 
                                temp = FindMin(root); 
                                printf("Minimum element is 
%d\n",temp->data); 
                                break; 
                        case 9: 
                                temp = FindMax(root); 
                                printf("Maximum element is 
%d\n",temp->data); 
                                break; 
                        case 0: 
                                printf("\nThanks for using Tree 
Program...\n"); 
                                exit(1); 
                                break; 
                        default: 
                                printf("\nInvalid Choice. Please Try 
Again....\n"); 
                                break; 
                } 
        } 
} 
 
 
 
 




//Practical No.: 3 
//Program Description:   Implementation of  Kruskal Algorithm 
//Solution: 
#include<bits/stdc++.h>  
using namespace std;  
 
// Creating shortcut for an integer pair  
typedef pair<int, int> iPair;  
 
// Structure to represent a graph  
struct Graph  
{  
    int V, E;  
    vector< pair<int, iPair> > edges;  
 
    // Constructor  
    Graph(int V, int E)  
    {  
        this->V = V;  
        this->E = E;  
    }  
 
    // Utility function to add an edge  
    void addEdge(int u, int v, int w)  
    {  
        edges.push_back({w, {u, v}});  
    }  
 
    // Function to find MST using Kruskal's  
    // MST algorithm  
    int kruskalMST();  
};  
 
// To represent Disjoint Sets  
struct DisjointSets  
{  
    int *parent, *rnk;  
    int n;  
 
    // Constructor.  
    DisjointSets(int n)  
    {  
        // Allocate memory  
        this->n = n;  
        parent = new int[n+1];  
        rnk = new int[n+1];  
 
        // Initially, all vertices are in  
        // different sets and have rank 0.  
        for (int i = 0; i <= n; i++)  
        {  
            rnk[i] = 0;  
 
            //every element is parent of itself  
            parent[i] = i;  
        }  
    }  
 
    // Find the parent of a node 'u'  
    // Path Compression  
    int find(int u)  
    {  
        /* Make the parent of the nodes in the path  
        from u--> parent[u] point to parent[u] */ 
        if (u != parent[u])  
            parent[u] = find(parent[u]);  
        return parent[u];  
    }  
 
    // Union by rank  
    void merge(int x, int y)  
    {  
        x = find(x), y = find(y);  
 
        /* Make tree with smaller height  
        a subtree of the other tree */ 
        if (rnk[x] > rnk[y])  
            parent[y] = x;  
        else // If rnk[x] <= rnk[y]  
            parent[x] = y;  
 
        if (rnk[x] == rnk[y])  
            rnk[y]++;  
    }  
};  
 
/* Functions returns weight of the MST*/ 
 
int Graph::kruskalMST()  
{  
    int mst_wt = 0; // Initialize result  
 
    // Sort edges in increasing order on basis of cost  
    sort(edges.begin(), edges.end());  
    // Create disjoint sets  
    DisjointSets ds(V);  
 
    // Iterate through all sorted edges  
    vector< pair<int, iPair> >::iterator it;  
    for (it=edges.begin(); it!=edges.end(); it++)  
    {  
        int u = it->second.first;  
        int v = it->second.second;  
 
        int set_u = ds.find(u);  
        int set_v = ds.find(v);  
 
        // Check if the selected edge is creating  
        // a cycle or not (Cycle is created if u  
        // and v belong to same set)  
        if (set_u != set_v)  
        {  
            // Current edge will be in the MST  
            // so print it  
            cout << u << " - " << v << endl;  
 
            // Update MST weight  
            mst_wt += it->first;  
 
            // Merge two sets  
            ds.merge(set_u, set_v);  
        }  
    }  
 
    return mst_wt;  
}  
 
// Driver program to test above functions  
int main()  
{  
    /* Let us create above shown weighted  
    and undirected graph */ 
    int V = 9, E = 14;  
    Graph g(V, E);  
 
    // making above shown graph  
    g.addEdge(0, 1, 4);  
    g.addEdge(0, 7, 8);  
    g.addEdge(1, 2, 8);  
    g.addEdge(1, 7, 11);  
    g.addEdge(2, 3, 7);  
    g.addEdge(2, 8, 2);  
    g.addEdge(2, 5, 4);  
    g.addEdge(3, 4, 9);  
    g.addEdge(3, 5, 14);  
    g.addEdge(4, 5, 10);  
    g.addEdge(5, 6, 2);  
    g.addEdge(6, 7, 1);  
    g.addEdge(6, 8, 6);  
    g.addEdge(7, 8, 7);  
 
    cout << "Edges of MST are \n";  
    int mst_wt = g.kruskalMST();  
 
    cout << "\nWeight of MST is " << mst_wt;  
 
    return 0;  
} 








//Practical No.: 4 
//Program Description: Implementation of Prim Algorithm 
//Solution: 
#include <bits/stdc++.h> 
using namespace std; 
 
// Function to construct and print the MST 
void primMST(vector<vector<int>> graph) { 
    int v = graph.size(); 
   
    // vector to store the parent of vertex 
    vector<int> parent(v); 
 
    // vector holds the weight/ cost of the MST 
    vector<int> key(v); 
 
    // vector to represent the set of 
    // vertices included in MST 
    vector<bool> vis(v); 
 
    priority_queue<pair<int, int>,  
    vector<pair<int, int>>,  
    greater<pair<int, int>>> pq; 
   
    // Initialize all key vector as INFINITE 
    // and vis vector as false 
    for (int i = 0; i < v; i++) { 
        key[i] = INT_MAX; 
        vis[i] = false; 
    } 
 
    // Always include the first vertex in MST. 
    // Make key 0 so that this vertex is 
    // picked as the first vertex. 
    key[0] = 0; 
 
    // First node is always the root of MST 
    parent[0] = -1; 
 
    // Push the source vertex to the min-heap 
    pq.push({0, 0}); 
 
    while (!pq.empty()) { 
        int node = pq.top().second; 
        pq.pop(); 
        vis[node] = true; 
        for (int i = 0; i < v; i++) { 
           
            // If the vertex is not visited 
            // and the edge weight of neighbouring 
            // vertex is less than key value of 
            // neighbouring vertex then update it. 
            if (!vis[i] && graph[node][i] != 0 
                && graph[node][i] < key[i]) { 
                pq.push({graph[node][i], i}); 
                key[i] = graph[node][i]; 
                parent[i] = node; 
            } 
        } 
    } 
 
    // Print the edges and their 
    // weights in the MST 
    cout << "Edge \tWeight\n"; 
    for (int i = 1; i < v; i++) { 
        cout << parent[i] << " - " << i  
          << " \t" << graph[i][parent[i]] << " \n"; 
    } 
} 
 
int main() { 
   
    // Define the adjacency matrix 
  vector<vector<int>> graph = {{0, 2, 0, 6, 0},  
                              {2, 0, 3, 8, 5},  
                              {0, 3, 0, 0, 7},  
                              {6, 8, 0, 0, 9},  
                              {0, 5, 7, 9, 0}}; 
 
    // Find and print the Minimum Spanning 
    // Tree using Prim's algorithm 
    primMST(graph); 
 
    return 0; 
} 






//Practical No.: 5 
//Program Description: Implementation of Dijkstra Algorithm 
//Solution: 
#include <iostream> 
#include <vector> 
#include <queue> 
#include <climits> 
 
using namespace std; 
 
typedef pair<int, int> pii; // Pair to store (distance, node) 
 
void dijkstra(int start, vector<vector<pii>>& graph, vector<int>& 
distances) { 
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap 
priority queue 
    pq.push({0, start}); 
    distances[start] = 0; 
 
    while (!pq.empty()) { 
        int currentDistance = pq.top().first; 
        int currentNode = pq.top().second; 
        pq.pop(); 
 
        // Skip if the distance is outdated 
        if (currentDistance > distances[currentNode]) continue; 
 
        // Explore neighbors 
        for (auto& neighbor : graph[currentNode]) { 
            int neighborNode = neighbor.first; 
            int edgeWeight = neighbor.second; 
 
            // Relaxation step 
            if (distances[currentNode] + edgeWeight < 
distances[neighborNode]) { 
                distances[neighborNode] = distances[currentNode] + 
edgeWeight; 
                pq.push({distances[neighborNode], neighborNode}); 
            } 
        } 
    } 
} 
 
int main() { 
    int n, m; // Number of nodes and edges 
    cout << "Enter the number of nodes and edges: "; 
    cin >> n >> m; 
 
    vector<vector<pii>> graph(n + 1); // Adjacency list (1-based 
indexing) 
 
    cout << "Enter the edges (u v w) where u and v are nodes and w is 
the weight:\n"; 
    for (int i = 0; i < m; ++i) { 
        int u, v, w; 
        cin >> u >> v >> w; 
        graph[u].push_back({v, w}); 
        graph[v].push_back({u, w}); // For undirected graph; omit this 
for directed 
    } 
 
    int start; 
    cout << "Enter the start node: "; 
    cin >> start; 
 
    vector<int> distances(n + 1, INT_MAX); // Initialize distances to 
infinity 
 
    dijkstra(start, graph, distances); 
 
    cout << "Shortest distances from node " << start << ":\n"; 
    for (int i = 1; i <= n; ++i) { 
        if (distances[i] == INT_MAX) { 
            cout << "Node " << i << ": INF\n"; 
        } else { 
            cout << "Node " << i << ": " << distances[i] << "\n"; 
        } 
    } 
 
    return 0; 
} 
 
