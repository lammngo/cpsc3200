//
// Created by lolita kim on 5/12/22.
//

#include <iostream>
#include <memory>
#include "inFest.h"
#include "gridFlea.h"
#include "vector"

using namespace std;

const int NUM_INFESTS = 10;

vector<unique_ptr<inFest>> createInfests() {
    vector<unique_ptr<inFest>> infests(NUM_INFESTS);
    for (int i = 0; i < NUM_INFESTS; i++) {
        int num_gen = rand() % 10 + 1;
        int len = rand() % 20 + 1;
        infests[i] = make_unique<inFest>(num_gen, len);
    }
    return infests;
}

void createSharedInfests() {
    int num_gen = rand() % 10 + 1;
    int len = rand() % 20 + 1;
    shared_ptr<inFest>shared_ptr_infest = make_shared<inFest>(num_gen, len);
    cout << endl << "=== TESTS ON SHARED POINTERS ===" << endl
         << "/ this test will create an array of shared pointers points to the same object address /" << endl
         << "- Original object address: " << shared_ptr_infest.get() << endl
         << "- Original reference count: " << shared_ptr_infest.use_count() << endl
         << "================================================" << endl;

    vector<shared_ptr<inFest>> shared_infests(6);
    for(int i = 0; i < shared_infests.size(); i++){
        shared_infests[i] = shared_ptr_infest;
        cout << "Shared infest #" << (i + 1) << endl
             << "- Object address: " << shared_infests[i].get() << endl
             << "- Reference count: " << shared_infests[i].use_count() << endl
             << "=============================================" << endl;
    }
    cout << "<<< RESULTS AFTER USING SHARED POINTERS >>>" << endl
         << "- Final object address: " << shared_ptr_infest.get() << endl
         << "- Final reference count: " << shared_ptr_infest.use_count() << endl;
}
void testSharedInfest(){
    int num_gen = rand() % 10 + 1;
    int len = rand() % 20 + 1;
    shared_ptr<inFest>shared_ptr_infest = make_shared<inFest>(num_gen, len);
    cout << endl << "=== OUT OF SCOPE TESTS ON SHARED POINTERS ===" << endl
         << "/ this test will reduce the reference count by how many shared infests went out of scope /" << endl
         << "- Original object address: " << shared_ptr_infest.get() << endl
         << "- Original reference count: " << shared_ptr_infest.use_count() << endl
         << "================================================" << endl;

    vector<shared_ptr<inFest>> shared_infests(6);
    for(int i = 0; i < shared_infests.size(); i++){
        shared_infests[i] = shared_ptr_infest;
        cout << "Shared infest #" << (i + 1) << endl
             << "- Object address: " << shared_infests[i].get() << endl
             << "- Reference count: " << shared_infests[i].use_count() << endl
             << "=============================================" << endl;
    }
    cout << "...MAKING THE OG OBJECT OUT OF SCOPE..." << endl;
    shared_ptr_infest.reset();
    cout << "Updated the new state for the original object!" << endl
         << "=============================================" << endl;

    for(int i = 0; i < shared_infests.size(); i++){
        shared_infests[i] = shared_ptr_infest;
        cout << "Shared infest #" << (i + 1) << endl
             << "- Object address: " << shared_infests[i].get() << endl
             << "- Reference count: " << shared_infests[i].use_count() << endl;
        shared_infests[i].reset();
        cout << "=============================================" << endl;
    }

    cout << "<<< RESULTS AFTER MAKING SHARED POINTERS OUT OF SCOPE >>>" << endl
         << "- Final object address: " << shared_ptr_infest.get() << endl
         << "- Final reference count: " << shared_ptr_infest.use_count() << endl;

}
//using unique pointers
void testInfestRelation(vector<unique_ptr<inFest>> &infest){
    cout << endl << " === RELATIONS TESTS ON 2 INITIAL OBJECTS ===" << endl
         << "infest #1: " << infest[0]->getValue() << endl
         << "infest #2: " << infest[1]->getValue() << endl
         << ">>> RESULTS CHART <<< " << endl
         << "infest1 == infest2: " << (infest[0]->getValue() == infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 != infest2: " << (infest[0]->getValue() != infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 > infest2: " << (infest[0]->getValue() > infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 < infest2: " << (infest[0]->getValue() < infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 >= infest2: " << (infest[0]->getValue() >= infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 <= infest2: " << (infest[0]->getValue() <= infest[1]->getValue() ? "true" : "false") << endl;

    infest[0]->move(2);
    infest[1]->move(3);

    cout << endl << " === RELATIONS TESTS ON 2 MOVING OBJECTS === " << endl
         << "infest #1 moving 2 squares..." << endl
         << "infest #2 moving 3 squares..." << endl
         << "/// Updated new values for 2 objects /// " << endl
         << "infest #1: " << infest[0]->getValue() << endl
         << "infest #2: " << infest[1]->getValue() << endl
         << ">>> RESULTS CHART <<<" << endl
         << "infest1 == infest2: " << (infest[0]->getValue() == infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 != infest2: " << (infest[0]->getValue() != infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 > infest2: " << (infest[0]->getValue() > infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 < infest2: " << (infest[0]->getValue() < infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 >= infest2: " << (infest[0]->getValue() >= infest[1]->getValue() ? "true" : "false") << endl
         << "infest1 <= infest2: " << (infest[0]->getValue() <= infest[1]->getValue() ? "true" : "false") << endl;
}

void testAddInfests(vector<unique_ptr<inFest>> &infest, inFest newInfest){
    cout << endl << "=== ADDITION INFEST ON INFEST ARRAY === " << endl
         << "/ this test will append new infest (multiple gridFleas) on each infest / " << endl
         << "- Original infest size is " << infest.size() << endl
         << "- Adding the infest size of " << newInfest.getSize() << endl
         << ">>> Adding the infest value of " << newInfest.getValue() << " <<<" << endl
         << endl << "*** RESULTS CHART ***" << endl;

    int i = 0;
    for (unique_ptr<inFest>& infestptr : infest)
    {
        cout << "Old infest #" << (i) << " size: " << infestptr->getSize() << endl;
        cout << "Old infest #" << (i) << " value: " << infestptr->getValue() << endl;

        (*infestptr) += newInfest;

        cout << "New infest #" << (i) << " size: " << infestptr->getSize() << endl;
        cout << "New infest #" << (i) << " value: " << infestptr->getValue() << endl;
        i++;
        cout << "==============================" << endl;
    }
}

void testAddGridFlea(vector<unique_ptr<inFest>> &infest, gridFlea gf){
    cout << endl << "=== ADDITION GRID FLEA ON INFEST ARRAY === " << endl
         << "/ this test will append a single new gridFlea on each infest / " << endl
         << "- Original infest size is " << infest.size() << endl
         << "- Adding the grid value of " << gf.value() << endl
         << endl << "*** RESULTS CHART ***" << endl;

    int i = 0;
    for (unique_ptr<inFest>& infestptr : infest)
    {
        cout << "Old infest #" << (i) << " size: " << infestptr->getSize() << endl;
        cout << "Old infest #" << (i) << " value: " << infestptr->getValue() << endl;

        (*infestptr) += gf;

        cout << "New infest #" << (i) << " size: " << infestptr->getSize() << endl;
        cout << "New infest #" << (i) << " value: " << infestptr->getValue() << endl;
        i++;
        cout << "==============================" << endl;
    }
}

void testGridRelations(gridFlea gf1, gridFlea gf2){
    cout << endl << " === RELATIONS TESTS ON 2 INITIAL GRIDFLEAS ===" << endl
         << "gridFlea #1: " << gf1.value() << endl
         << "gridFlea #2: " << gf2.value() << endl
         << ">>> RESULTS CHART <<< " << endl
         << "gridFlea1 == gridFlea2: " << (gf1 == gf2 ? "true" : "false") << endl
         << "gridFlea1 != gridFlea2: " << (gf1 != gf2 ? "true" : "false") << endl
         << "gridFlea1 > gridFlea2: " << (gf1 > gf2 ? "true" : "false") << endl
         << "gridFlea1 < gridFlea2: " << (gf1 < gf2 ? "true" : "false") << endl
         << "gridFlea1 >= gridFlea2: " << (gf1 >= gf2 ? "true" : "false") << endl
         << "gridFlea1 <= gridFlea2: " << (gf1 <= gf2 ? "true" : "false") << endl;

    gf1.move(3);
    gf2.move(5);

    cout << endl << " === RELATIONS TESTS ON 2 MOVING GRIDFLEAS ===" << endl
         << "gridFlea #1 moving 3 squares..." << endl
         << "gridFlea #2 moving 5 squares..." << endl
         << "/// Updated new values for 2 gridFleas /// " << endl
         << "gridFlea #1: " << gf1.value() << endl
         << "gridFlea #2: " << gf2.value() << endl
         << ">>> RESULTS CHART <<< " << endl
         << "gridFlea1 == gridFlea2: " << (gf1 == gf2 ? "true" : "false") << endl
         << "gridFlea1 != gridFlea2: " << (gf1 != gf2 ? "true" : "false") << endl
         << "gridFlea1 > gridFlea2: " << (gf1 > gf2 ? "true" : "false") << endl
         << "gridFlea1 < gridFlea2: " << (gf1 < gf2 ? "true" : "false") << endl
         << "gridFlea1 >= gridFlea2: " << (gf1 >= gf2 ? "true" : "false") << endl
         << "gridFlea1 <= gridFlea2: " << (gf1 <= gf2 ? "true" : "false") << endl;
}

void testAddGridFlea(gridFlea gf, int steps){
    cout << endl << "=== ADDITION TESTS ON GRID FLEA === " << endl
         << "/ this test will move gridFlea up by injected value / " << endl
         << "- Original gridFlea value is " << gf.value() << endl
         << "- Adding to gridFlea a value of " << steps << " aka make gridFlea move up by " << steps << "" << endl;

    gf += steps;
    cout << ">>> New gridFlea value after moving up by " << steps << " is " << gf.value() << endl;
}

void testSubtractGridFlea(gridFlea gf, int steps){
    cout << endl << "=== SUBTRACTION TESTS ON GRID FLEA === " << endl
         << "/ this test will move gridFlea down by injected value / " << endl
         << "- Original gridFlea value is " << gf.value() << endl
         << "- Subtracting gridFlea a value of " << steps << " aka make gridFlea move down by " << steps << "" << endl;

    gf -= steps;
    cout << ">>> New gridFlea value after moving down by " << steps << " is -" << gf.value() << endl;
}

void testPrePostGridFlea(gridFlea gf){
    cout << endl << "=== PRE-INCREMENT TEST ON GRID FLEA === " << endl
         << "/ this test will move gridFlea up by 1 and return the updated the value / " << endl
         << "- Original gridFlea value is " << gf.value() << endl;
    ++gf;
    cout << ">>> New gridFlea value after using pre-increment is " << gf.value() << endl;

    cout << endl << "=== POST-INCREMENT TEST ON GRID FLEA === " << endl
         << "/ this test will move gridFlea up by 1 and return the original the value / " << endl
         << "- Original gridFlea value is " << gf.value() << endl;
    gf++;
    cout << ">>> New gridFlea value after using pre-increment is " << gf.value() << endl;
}

void testAddTwoGridFleas(gridFlea gf1, gridFlea gf2){
    cout << endl << "=== ADDITION TESTS ON TWO MOVING GRID FLEAS === " << endl
         << "/ this test will add 2 moving grid fleas together / " << endl;

    gf1.move(2);
    gf2.move(3);

    cout << "Original gridFlea #1 value is " << gf1.value() << endl
         << ">>> Adding on gridFlea #1 a value of " << gf2.value() << endl;
    gf1 += gf2;
    cout << "New gridFlea #1 value is " << gf1.value() << endl;
}

void testSubtractTwoGridFleas(gridFlea gf1, gridFlea gf2){
    cout << endl << "=== SUBTRACTION TESTS ON TWO MOVING GRID FLEAS === " << endl
         << "/ this test will subtract 2 moving grid fleas together / " << endl;

    gf1.move(2);
    gf2.move(3);

    cout << "Original gridFlea #1 value is " << gf1.value() << endl
         << ">>> Subtracting gridFlea #1 with a value of " << gf2.value() << endl;
    gf1 -= gf2;
    cout << "New gridFlea #1 value is -" << gf1.value() << endl;
}

int main(int argc, char *argv[]){
    vector<unique_ptr<inFest>> infests = createInfests();
    gridFlea gf1 (3, 5, 10);
    gridFlea gf2 (4,6,10);
    cout << "                          <<< START HERE >>>" << endl;
    cout << "Welcome! " << infests.size() << " infest objects has been created. You can run the tests now!" << endl;
    testInfestRelation(infests);
    testAddInfests(infests, *infests[0]);
    testAddGridFlea(infests, gf1);
    testGridRelations(gf1, gf2);
    testAddGridFlea(gf2, 3);
    testSubtractGridFlea(gf1, 4);
    testPrePostGridFlea(gf1);
    testAddTwoGridFleas(gf1, gf2);
    testSubtractTwoGridFleas(gf1, gf2);
    createSharedInfests();
    testSharedInfest();
}
