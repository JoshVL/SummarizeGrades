//////////////////////////////////////////////////////
//
// SummarizeGrades.cpp - Implementation of SummarizeGrades.h and its functions
//
//////////////////////////////////////////////////////

#include "SummarizeGrades.h"
#include <fstream>
#include <iomanip> 

void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments, map<int, Name> &studentNames, map<int, vector<int>> &studentScores) {
    // Creates the stream
    ifstream inputFile;
    inputFile.open(inputFilepath);

    // Gets information from the file
    int numFromFile;
    string strFromFile;

    // Obtains number of students
    inputFile >> strFromFile >> numFromFile;
    *numberOfStudents = numFromFile;

    // Obtains number of assignments
    inputFile >> strFromFile >> numFromFile;
    *numberOfAssignments = numFromFile;

    // Obtains assignment information
    inputFile >> strFromFile >> strFromFile >> strFromFile;
    for(int i = 0; i < *numberOfAssignments; i++) {
        inputFile >> numFromFile;
    }

    // Obtains ID and name info
    string name1;
    string name2;
    int studentID;
    while(inputFile >> studentID >> name1 >> name2) {
        // Creates the Name struct
        Name newStudent = {name1, name2};
        // Adds to the studentName map
        studentNames[studentID] = newStudent;
        vector<int> studentGrades;
        for(int i = 0; i < *numberOfAssignments; i++) {
            inputFile >> numFromFile;
            studentGrades.push_back(numFromFile);
        }
         // Adds to the studentScore map
        studentScores[studentID] = studentGrades;
    }
    // Closes the input file
    inputFile.close();
}

/**
 * Helper method to adjust the name's cases
 * 
 * @param name - name to adjust
 * @return Adjusted case of the name
*/
string nameHelper(string name) {
    int nameLength = name.length();
    for(int i = 0; i < nameLength; i++) {
        if(i == 0) {
            // Sets first letter to upper case
            name[i] = (toupper(name[i]));
        } else {
            // All other letters to lower case
            name[i] = (tolower(name[i]));
        }
    }
    return name;
}

void formatCaseOfNames(map<int, Name> &names){
    // Loops through the map to format the names properly
    for (auto &p : names) {
        p.second.firstName = nameHelper(p.second.firstName);
        p.second.lastName = nameHelper(p.second.lastName);
    }
}

void computeTotalAndPercent(map<int, vector<int>> &scores, map<int, int>  &total, map<int,  float> &percent) {
    // Iterates through students to calculate each one's total and percent
    for(auto &p : scores) {
        // Counter variables
        int totalSum = 0;
        int assignmentCount = 0;

        // Calculates current student's total
        for(auto &i : p.second) {
            totalSum += i;
            assignmentCount += 1;
        }
        total[p.first] = totalSum;

        // Calculates the percentage
        float finalPercent = static_cast<float>(totalSum) / (static_cast<float>(10) * static_cast<float>(assignmentCount));
        finalPercent = finalPercent * 100;
        percent[p.first] = finalPercent;
    }
}

void writeFormattedGrades(const string outputFilepath, map<int, Name> &names, map<int, int> &total, map<int, float> &percent) {
    // Opens the file
    ofstream outputFile;
    outputFile.open(outputFilepath);

    // Outputs names and grade information
    for(auto &p : names) {
        int studentID = p.first;
        string formattedName = p.second.lastName + ", " + p.second.firstName;
        outputFile << formattedName;
        outputFile << setw(22 - formattedName.length());
        outputFile << total[studentID];
        outputFile << setw(7);
        outputFile << setprecision(1) << fixed << percent[studentID] << endl;
    }

    // Closes the file
    outputFile.close();
}