#include <iostream>

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int _value) : value(_value), right(nullptr), left(nullptr){};
    ~Node()
    {
        delete left;
        delete right;
        left = right = nullptr;
    }
};

class BST
{
private:


    int size;
public:
    Node* root;
    BST() : root(nullptr), size(0){};
    ~BST()
    {
        delete root;
    }

    void insert(int value)
    {
        if (size == 0)
        {
            root = new Node(value);
            ++size;
            return;
        }

        Node* current = root;

        while (true)
        {
            if (value == current->value)
            {
                return;
            }
            else if (value > current->value)
            {
                if (current->right != nullptr)
                    current = current->right;
                else
                {
                    current->right = new Node(value);
                    return;
                }
            }
            else
            {
                if (current->left != nullptr)
                    current = current->left;
                else
                {
                    current->left = new Node(value);
                    return;
                }
            }
        }
    }

    Node* search(int value)
    {
        if (size == 0)
        {
            return nullptr;
        }

        Node* current = root;

        while (true)
        {
            if (value == current->value)
            {
                return current;
            }
            else if (value > current->value)
            {
                if (current->right != nullptr)
                    current = current->right;
                else
                    return nullptr;
            }
            else
            {
                if (current->left != nullptr)
                    current = current->left;
                else
                    return nullptr;
            }
        }
    }


    void printTree( const Node* current, int indent = 0 )
    {
        if ( current == nullptr )
            return;
        printTree( current->right, indent + 2 );
        std::cout
                << std::string( indent * 3, ' ' )
                << current->value << std::endl;
        printTree( current->left, indent + 2 );
    }

};
/*
    iterator begin()
    {
        if (!root)
        {
            return iterator(nullptr);
        }

        auto current = root;
        while (current->left)
            current = current->left;

        return iterator(current);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    iterator find(const T &value)
    {
        auto current = root;
        while (current)
        {
            if (value < current->value)
            {
                current = current->left;
            }
            else if (value >= current->value && current->value >= value)
            {
                return iterator(current);
            }
            else
            {
                current = current->right;
            }
        }
        return end();
    }

*/

/*
   void erase(iterator pos)
    {
        auto toBeErased = pos.current;
        if (toBeErased == nullptr)
            return;

        if (toBeErased->left == nullptr && toBeErased->right == nullptr)
        {
            if (toBeErased->parent != nullptr)
            {
                if (toBeErased->parent->left == toBeErased)
                {
                    toBeErased->parent->left = nullptr;
                }
                else
                {
                    toBeErased->parent->right = nullptr;
                }
            }
            else
            {
                root = nullptr;
            }
            delete toBeErased;
            --size_;
            return;
        }

        if (toBeErased->left == nullptr || toBeErased->right == nullptr)
        {
            auto child = (toBeErased->left != nullptr) ? toBeErased->left : toBeErased->right;
            if (toBeErased->parent != nullptr)
            {
                if (toBeErased == toBeErased->parent->left)
                {
                    toBeErased->parent->left = child;
                }
                else
                {
                    toBeErased->parent->right = child;
                }
                child->parent = toBeErased->parent;
            }
            else
            {
                root = child;
                child->parent = nullptr;
            }
            delete toBeErased;
            --size_;
            return;
        }

        Node *successor = pos.findSuccessor(toBeErased);
        toBeErased->value = successor->value;
        erase(iterator(successor));

        updateHeight(toBeErased);
        updateBalanceFactor(toBeErased);
    }

    ~Set()
    {
        while (root != nullptr)
        {
            erase(iterator(root));
        }
    }
};

*/

int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(-10);
    tree.insert(20);
    tree.insert(10);
    tree.insert(0);

    tree.printTree(tree.root);

    return 0;
}

