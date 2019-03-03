#include <iostream>
#include "List.h"

int main() {
    List l1, l2;
    std::string data1 = "data 1";
    std::string data2 = "data 2";
    std::string data3 = "data 3";
    std::string data4 = "data 4";
    l1.push_back(data1);
    l1.push_back(data2);
    l1.push_back(data3);
    l1.push_back(data4);
    //l1.print();
    /* serializetion... */
    FILE *f = fopen("srl.list", "wb");
    l1.serialize(f);
    fclose(f);

    /* deserializetion... */
    f = fopen("srl.list", "rb");
    l2.deserialize(f);
    l2.print();
    fclose(f);

    return 0;
}