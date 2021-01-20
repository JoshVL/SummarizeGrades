//////////////////////////////////////////////////////
//
// SummarizeGrades.h - Program reads a file with student information and
// their homework scores. Program then manipulates the data to compute the
// total score and percentage for each student and writes a summary file with
// the computed scores for each students.
//
//////////////////////////////////////////////////////

#ifndef SUMMARIZEGRADES_H
#define SUMMARIZEGRADES_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/** 
*  Structure for Name including strings for firstName and lastName
*/
struct Name {
    string firstName;
    string lastName;
};

/**
* Takes the path of the input file and references to some data structures
* that will hold the student names and scores for other functions to process
*
* @param inputFilepath - Filepath to the input file
* @param *numberOfStudents - Pointer to number of students
* @param *numberOfAssignments - Pointer to number of assignments
* @param &studentNames - Map<int, Name> of student names
* @param &studentScores - map<int, vector<int>> of student scores
*/
void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments, map<int, Name> &studentNames, map<int, vector<int>> &studentScores);

/**
* Takes the student names map and changes the first and last name strings in the struct(values in map)
* so that the first letter of each string is a capital letter and all other letters are lower case. 
*
* @param &names - map<int, Name> of the names to format
*/
void formatCaseOfNames(map<int, Name> &names);

/**
* Takes the scores map and computes the total score as well as
* the final percentages a float and stores these computed results in total and percent maps respectively
*
* @param &scores - map<int, vector<int>> of scores
* @param &total - map<int,int> for the total scores
* @param &percent - map<int, float> for the percentages
*/
void computeTotalAndPercent(map<int, vector<int>> &scores, map<int, int>  &total, map<int,  float> &percent);

/**
* Writes the results of the formated grades to a specified file
*
* @param outputFilepath - Filepath of the output file
* @param &names - Map<int, Name> of names
* @param &total - Map<int, int> of total scores
* @param &percent Map<int,float> of percentages
*/
void writeFormattedGrades(const string outputFilepath, map<int, Name> &names, map<int, int> &total, map<int, float> &percent);

#endif /* SUMMARIZEGRADES_H */
