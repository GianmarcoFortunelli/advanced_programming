#include <stdio.h>
#include "exam.h"


int main() {
    initPerson();    //init hash table that contains location and person
    initLocation();

    addTestingInfo("ID1", "Name1", "2022-10-20", "L1");   //add person info
    addTestingRes("ID1", "positive");                               //add test result
    addTestingInfo("ID2", "Name2", "2022-10-20", "L1");
    addTestingRes("ID2", "negative");
    addTestingInfo("ID3", "Name3", "2022-10-20", "L1");
    addTestingRes("ID3", "negative");
    addTestingInfo("ID4", "Name4", "2022-10-20", "L1");
    addTestingRes("ID4", "positive");
    addTestingInfo("ID5", "Name5", "2022-10-20", "L1");
    addTestingRes("ID5", "positive");
    addTestingInfo("ID6", "Name6", "2022-10-20", "L1");
    addTestingRes("ID6", "positive");
    addTestingInfo("ID7", "Name7", "2022-10-20", "L2");
    addTestingRes("ID7", "negative");
    addTestingInfo("ID8", "Name8", "2022-10-20", "L2");
    addTestingRes("ID8", "negative");
    addTestingInfo("ID9", "Name9", "2022-10-20", "L3");
    addTestingRes("ID9", "positive");
    addTestingInfo("ID10", "Name10", "2022-10-20", "L3");
    addTestingRes("ID10", "positive");

    searchTestingRes("ID1");    //search person by id

    searchRegionRisk("L1");    //search location by name

    searchRegionRisk("L2");

    searchRegionRisk("L3");
    return 0;
}
