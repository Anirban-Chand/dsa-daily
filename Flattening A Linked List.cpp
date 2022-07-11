/* 
  Node structure  used in the program
*/


struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


/*  
  Function which returns the  root of the flattened linked list. 
*/
Node *flatten(Node *root)
{
   // Your code here
    if(!root) return nullptr;
    vector<int> v;
    while(root){
        v.push_back(root->data);
        while(root->bottom){
            v.push_back(root->bottom->data);
            root->bottom = root->bottom->bottom;
        }
        root = root->next;
    }
   
    sort(v.begin(), v.end());
   
    Node* head = new Node(v[0]);
    Node *it = head;
    for(int i=1; i<v.size(); i++){
        it->bottom = new Node(v[i]);
        it = it->bottom;
    }
    it->bottom = nullptr;
   
    return head;
}
