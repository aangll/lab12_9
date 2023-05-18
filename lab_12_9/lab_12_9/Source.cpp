#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* CreateTree(int nodeCount)
{
    if (nodeCount == 0)
        return NULL;
    else
    {
        Node* newNode = new Node;

        std::cout << " Enter node value: ";
        std::cin >> newNode->data;

        int leftCount = nodeCount / 2;
        int rightCount = nodeCount - leftCount - 1;
        newNode->left = CreateTree(leftCount);
        newNode->right = CreateTree(rightCount);
        return newNode;
    }
}

Node* BinarySearchInsert(Node*& root, int value, bool& found)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        found = false;
        return root;
    }
    else
        if (value == root->data)
        {
            found = true;
            return root;
        }
        else
            if (value < root->data)
                return BinarySearchInsert(root->left, value, found);
            else
                return BinarySearchInsert(root->right, value, found);
}

int findMin(Node* root)
{
    //code
    if (root == NULL)
    {
        return INT_MAX;
    }
    int res = root->data;
    int left = findMin(root->left);
    int right = findMin(root->right);
    if (left < res)
    {
        res = left;
    }
    if (right < res)
    {
        res = right;
    }
    return res;
}

void PrintTree(Node* root, int level)
{
    if (root != NULL)
    {
        PrintTree(root->right, level + 1);
        for (int i = 1; i <= level; i++)
            std::cout << " ";
        std::cout << root->data << std::endl;
        PrintTree(root->left, level + 1);
    }
}

void PrefixOrder(Node* root, int min, int S)
{
    
    if (root != NULL)
    {
        if (root->data == min && S != 0)
        {
            std::cout << "[" << root->data << "]" << " ";
            S = NULL;
        }
        else
            std::cout << root->data << " ";
        PrefixOrder(root->left, min, S);
        PrefixOrder(root->right, min, S);
       
    }
}

int Count(Node* root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + Count(root->left) + Count(root->right);
}

void RightRotation(Node*& root)
{
    Node* tmp1 = root->left;
    Node* tmp2 = tmp1->right;
    tmp1->right = root; //1
    root->left = tmp2; //2
    root = tmp1; //3
}
void LeftRotation(Node*& root)
{
    Node* tmp1 = root->right;
    Node* tmp2 = tmp1->left;
    tmp1->left = root; //1
    root->right = tmp2; //2
    root = tmp1; //3
}
int Height(Node* root)
{
    if (root == NULL)
        return 0;
    int hL = Height(root->left);
    int hR = Height(root->right);
    return (hL > hR ? hL : hR) + 1;
}
int BFactor(Node* root)
{
    return Height(root->right) - Height(root->left);
}

void BalanceHeight(Node * &root)
{
    if (root != NULL)
    {
        while (BFactor(root) >= 2)
        {
            if (BFactor(root->right) < 0)
                RightRotation(root->right);
            LeftRotation(root);
        }
        while (BFactor(root) <= -2)
        {
            if (BFactor(root->left) > 0)
                LeftRotation(root->left);
            RightRotation(root);
        }
        BalanceHeight(root->left);
        BalanceHeight(root->right);
    }
}


Node* Insert(Node* p, int value)
{
    if (!p)
    {
        p = new Node;
        p->data = value;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    if (value < p->data)
        p->left
        = Insert(p->left, value);
    else
        p->right
        = Insert(p->right, value);
    return p;
}

Node* Find(Node* root, int value)
{
    if (root == NULL || value == root->data)
        return root;
    if (value < root->data)
        return Find(root->left, value);
    else
        return Find(root->right, value);
}


Node* FindMax(Node* root) {
    if (root
        ->right != NULL
        )
        return FindMax(root
            ->right);
    else
        return root;
}

Node* BinarySearchDelete(Node* root, int value)
{
    if (NULL == root) return NULL;
    if (root->data == value)
    {
        if (NULL == root->left && NULL == root->right)
        {
            delete root;
            return NULL;
        }
        if (NULL == root->right && root->left != NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if (NULL == root->left && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        root->data = FindMax(root->left)->data;
        root->left = BinarySearchDelete(root->left, root->data);
        return root;
    }
    if (value < root->data)
    {
        root->left = BinarySearchDelete(root->left, value);
        return root;
    }
    if (value > root->data)
    {
        root->right = BinarySearchDelete(root->right, value);
        return root;
    }
    return root;
}

void DeleteTree(Node*& root, Node* node)
{
    if (node != NULL)
    {
        DeleteTree(root, node->left);
        DeleteTree(root, node->right);
        root = BinarySearchDelete(root, node->data);
    }
}

void printMenu() {
    std::cout << "\nChoose an action:\n";
    std::cout << "1. Create a binary tree\n";
    std::cout << "2. Create a binary search tree\n";
    std::cout << "3. Display the binary tree\n";
    std::cout << "4. Add a new element maintaining order\n";
    std::cout << "5. Balance the binary search tree\n";
    std::cout << "6. Remove a tree element with no child nodes\n";
    std::cout << "7. Remove a tree element with one child node\n";
    std::cout << "8. Remove a tree element with two child nodes\n";
    std::cout << "9. Remove a tree element with all its child nodes\n";
    std::cout << "10. Determine min tree value \n";
}

int main() {
    
    Node* root = NULL;
    int choice;
    
    while (true)
    {
        printMenu();
        std::cin >> choice;
        

        switch (choice) {
            case 1: 
            {
                int N;
                std::cout << "Enter nodes count: "; std::cin >> N;
                root = CreateTree(N);
                break;
            }
            
            case 2:
            {
                int N;
                std::cout << "Nodes count: "; std::cin >> N;
                int value;
                bool found = false;
                for (int i = 0; i < N; i++)
                {
                    std::cout << "value: "; std::cin >> value;
                    BinarySearchInsert(root, value, found);
                }
                break;
            }
            case 3:
            {
                PrintTree(root, 0);
                std::cout << std::endl;
                break;
            }
            case 4:
            {
                int value;
                std::cout << "value: ";
                std::cin >> value;
                Insert(root, value);
                break;
            }
            case 5:
            {
                BalanceHeight(root);
                break;
            }
            case 6:
            {
                int value;
                std::cout << "value:";
                std::cin >> value;
                BinarySearchDelete(root, value);
                break;
            }
            case 7:
            {
                int value;
                std::cout << "value:";
                std::cin >> value;
                BinarySearchDelete(root, value);
                break;
            }
            case 8:
            {
                int value;
                std::cout << "value:";
                std::cin >> value;
                BinarySearchDelete(root, value);
                break;
            }
            case 9:
            {
                int value;
                std::cout << "delete tree value: "; std::cin >> value;
                DeleteTree(root, Find(root, value));
                break;

            }
            case 10:
            {
                int min = findMin(root);
                PrefixOrder(root, min, 1);
                break;

            }
            default:
                std::cout << "Incorrect choice, try again.\n";
        }

    }
    return 0;
}
