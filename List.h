//
// Created by Роман on 2019-03-03.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <string>

struct ListNode {
    ListNode *      prev;
    ListNode *      next;
    ListNode *      rand; // указатель на произвольный элемент данного списка либо NULL
    std::string     data;
};


class List {
private:
    ListNode *head;
    ListNode *tail;
    int count;

public:
    List();
    ~List();

    void serialize(FILE * file);
    void deserialize(FILE * file);

    void push_back(std::string &data);
    void erase(std::string &data); // deletes the first found element by data
    void print();
    int getLenght();
};


#endif //LIST_LIST_H
