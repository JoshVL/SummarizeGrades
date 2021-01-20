//////////////////////////////////////////////////////
//
// demo.cpp - Tests and demonstrates functionality of SummarizeGrades.cpp
//
//////////////////////////////////////////////////////

#include "SummarizeGrades.h"

/**
 * Tests functionality of SummarizeGrades.cpp and its functions
 */
int main() {
    // Test variables and file paths to use
    const string iFilePath = "/home/in.txt";
    const string oFilePath = "/home/out.txt";
    int *numStud;
    int *numAssign;
    *numStud = 3;
    *numAssign = 3;
    map<int, Name> studentNames;
    map<int, vector<int>> studentScores;

    // Testing and their results to cout
    cout << "Testing readGradeFile with " << iFilePath <<  ", " << *numStud << ", and " 
    << *numAssign << endl;
    readGradeFile(iFilePath, numStud, numAssign, studentNames, studentScores);

    cout << "Testing formatCaseOfNames from given names from previous step" << endl;
    formatCaseOfNames(studentNames);

    cout << "Testing computeTotalAndPercent with scores recieved from first step" << endl;
    map<int, int>  total;
    map<int,  float> percent;
    computeTotalAndPercent(studentScores, total, percent);

    cout << "Testing writeFormattedGrades with maps recieved from previous steps" << endl;
    writeFormattedGrades(oFilePath, studentNames, total, percent);
    cout << "Testing done. Check output files for results" << endl;
    return 0;
}
