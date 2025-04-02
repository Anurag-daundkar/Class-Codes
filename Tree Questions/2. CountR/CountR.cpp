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

int countR(Node* root, int low, int high)
{
    if(root == NULL)
        return 0;
    
    int left = countR(root->left, low, high);
    int right = countR(root->right, low, high);

    if(root->data > low && root->data < high)
        return (1 + left + right);

    else
        return (left + right);
}

int main()
{
    Node* root = NULL;
    cout << "Enter root data ";
    root = BuildTree(root);

    cout << "Enter Low and High ";
    int low, high;
    cin >> low >> high;
    int ans = countR(root, low, high);
    cout << "Count = " << ans << endl;
}

