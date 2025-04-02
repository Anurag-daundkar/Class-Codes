#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BuildTree(Node* root)
{
    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    root = new Node(data);
    cout << "Enter data for left of " << data << endl;
    root->left = BuildTree(root->left);

    cout << "Enter data for right of " << data <<endl;
    root->right  =BuildTree(root->right);

    return root;
}

bool search_in_root2(Node* root2, int remain)
{
    if(root2 == NULL)
        return false;
    
    if(root2->data == remain)
        return true;
    
    else if(root2->data > remain)
        return search_in_root2(root2->left, remain);    

    else
        return search_in_root2(root2->right, remain);

}

void SUM(Node* root1, Node* root2, int sum)
{
    queue<Node*> q;
    q.push(root1);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int remaning = sum - temp->data;
        if(search_in_root2(root2, remaning))
            cout << "(" << temp->data << " , " << remaning << ")";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

int main()
{
    Node* root1 = NULL;
    cout << "Enter root 1 data ";
    root1 = BuildTree(root1);

    Node* root2 = NULL;
    cout << "Enter root 2 data ";
    root2 = BuildTree(root2);

    cout << "Enter Sum : ";
    int sum;
    cin >> sum;

    SUM(root1, root2, sum);
}

