#include <bits/stdc++.h>
using namespace std;

/*
This can be implemented using a Doubly Linked List and a Hashmap<int, node*>
On initialisation of a new LRU cache, we take two nodes front and back and connect them, we dont carry any value in them they are just like guard nodes

Then for inserting we insert a new (key,value) pair in the next position of front node and store the node as a value for the given key in the hashmap
Then for getting a node, we check that its present in the hashmap or not, if not then we simply return -1
Now incase the capacity is full while inserting we simply remove the node present previous to back

Now, to get that node we first get the pointer of that node from hashmap then we remove it from its position and insert it next to front node and then return its value
*/

struct Node
{
    int key, val;
    Node *next;
    Node *prev;

    Node(int _key, int _val)
    {
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
    unordered_map<int, Node *> map;
    int cap;
    Node *front;
    Node *back;

    void addNode(Node *node)
    {
        Node *temp = front->next;

        front->next = node;
        temp->prev = node;

        node->prev = front;
        node->next = temp;

        map[node->key] = node;
    }

    void removeNode(Node *delNode)
    {
        Node *delLeft = delNode->prev;
        Node *delRight = delNode->next;

        delLeft->next = delRight;
        delRight->prev = delLeft;

        map.erase(delNode->key);
    }

public:
    LRUCache(int capacity)
    {
        front = new Node(0, 0);
        back = new Node(0, 0);
        cap = capacity;
        map.clear();

        front->next = back;
        back->prev = front;
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
            return -1;

        Node *node = map[key];

        removeNode(node);
        addNode(node);

        return node->val;
    }

    void put(int key, int val)
    {
        if (map.find(key) != map.end())
        {
            Node *duplicateNode = map[key];
            removeNode(duplicateNode);
        }

        if (map.size() == cap)
        {
            removeNode(back->prev);
        }

        Node *newNode = new Node(key, val);
        addNode(newNode);
    }
};

int main()
{

    return 0;
}