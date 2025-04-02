#include<iostream>
#include<queue>
#include<vector>
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


Node* createBST(Node* root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(root->data > data)
        root->left = createBST(root->left, data);
    else
        root->right = createBST(root->right, data);
    
    return root;
}


Node* Convert_To_Bst(Node* root)
{
    vector<int> v;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        v.push_back(temp->data);
        
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    Node* BST = NULL;
    for(int i = 0 ; i < v.size() ; i++)
    {
        BST = createBST(BST, v[i]);
    }
    return BST;
}

void LevelOrderTraversalPrinting(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp != NULL)
        {
            cout << temp->data << " ";
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }

        else
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

    }
}


int main()
{
    Node* root = NULL;
    cout << "Enter root data ";

    root = BuildTree(root);

    Node* BST = Convert_To_Bst(root);


    LevelOrderTraversalPrinting(BST);
}

