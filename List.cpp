//
// Created by Роман on 2019-03-03.
//

#include "List.h"

List::List() {
    head = NULL;
    tail = NULL;
    int count = 0;
}

List::~List() {
    ListNode *need_delete = head;
    ListNode *deleted;
    while(need_delete != NULL) {
        deleted = need_delete;
        need_delete = need_delete->next;
        delete deleted;
    }
}

void List::push_back(std::string &data) {
    ListNode *node = new ListNode();
    node->data = data;
    node->next = NULL;
    node->rand = NULL;
    if(head == NULL) {
        node->prev = NULL;
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    count++;
}

void List::erase(std::string &data) {
    ListNode *node = head;
    while(node->data != data) node = node->next;

    if(node == tail) {
        tail = tail->prev;
        tail->next = NULL;
        delete node;
        return;
    }

    if(node == head) {
        head = head->next;
        head->prev = NULL;
        delete node;
        return;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

void List::print() {
    ListNode *printable = head;
    while(printable != NULL) {
        printf("%s\n", printable->data.c_str());
        printable = printable->next;
    }
}

void List::serialize(FILE *file) {
    fwrite(&count, sizeof(int), 1, file);
    ListNode *node = head;
    unsigned long len;
    while(node != NULL) {
        len = node->data.length();
        fwrite(&len, sizeof(unsigned long), 1, file);
        fwrite(node->data.c_str(), sizeof(char), len, file);
        node = node->next;
    }
}

void List::deserialize(FILE *file) {
    int LOF;
    std::string str_data;
    unsigned long str_len;
    fread(&LOF, sizeof(int), 1, file);
    for(int i = 0; i < LOF; i++) {
        fread(&str_len, sizeof(unsigned long), 1, file);
        str_data.resize(str_len);
        fread(&str_data[0], sizeof(char), str_len, file);
        this->push_back(str_data);
    }
}

int List::getLenght() {
    return count;
}