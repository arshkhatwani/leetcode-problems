#include <bits/stdc++.h>
using namespace std;

/*
This is like LRU cache with some differences

Here we take another hashmap which stores frequency as key and DLL as its value

When we put an element we add it next to front of the frequency 1 list

When we get an element we first remove it from its freq list and we increase its frequency by 1 and add it in list of new incremented frequency

Watch video to understand more: https://youtu.be/0PSB9y8ehbk
*/

struct Node
{
    int key, val, cnt;
    Node *next;
    Node *prev;

    Node(int _key, int _val)
    {
        key = _key;
        val = _val;
        cnt = 1;

        next = NULL;
        prev = NULL;
    }
};

struct List
{
    Node *front;
    Node *back;
    int size;

    List()
    {
        front = new Node(0, 0);
        back = new Node(0, 0);

        front->next = back;
        back->prev = front;

        size = 0;
    }

    void addNode(Node *node)
    {
        node->next = front->next;
        node->prev = front;
        front->next->prev = node;
        front->next = node;

        size++;
    }

    void removeNode(Node *node)
    {
        Node *leftNode = node->prev;
        Node *rightNode = node->next;

        leftNode->next = rightNode;
        rightNode->prev = leftNode;

        size--;
    }
};

class LFUCache
{
    unordered_map<int, Node *> map;
    unordered_map<int, List *> freqMap;
    int maxSize, curSize, minFreq;

    void updateFreqList(Node *node)
    {
        map.erase(node->key);
        freqMap[node->cnt]->removeNode(node);

        if (freqMap[node->cnt]->size == 0 and node->cnt == minFreq)
        {
            minFreq++;
        }

        node->cnt += 1;

        List *newList = new List();
        if (freqMap.find(node->cnt) != freqMap.end())
            newList = freqMap[node->cnt];

        newList->addNode(node);
        freqMap[node->cnt] = newList;
        map[node->key] = node;
    }

public:
    LFUCache(int capacity)
    {
        maxSize = capacity;
        curSize = minFreq = 0;
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
            return -1;

        Node *node = map[key];

        updateFreqList(node);

        return node->val;
    }

    void put(int key, int value)
    {
        if (maxSize == 0)
            return;

        if (map.find(key) != map.end())
        {
            Node *node = map[key];
            node->val = value;
            updateFreqList(node);
            return;
        }

        if (maxSize == curSize)
        {
            List *freqList = freqMap[minFreq];
            map.erase(freqList->back->prev->key);
            freqList->removeNode(freqList->back->prev);
            curSize--;
        }

        curSize++;
        minFreq = 1;
        Node *node = new Node(key, value);

        List *list = new List();
        if (freqMap.find(1) != freqMap.end())
            list = freqMap[1];

        list->addNode(node);
        freqMap[1] = list;
        map[key] = node;
    }
};

int main()
{

    return 0;
}