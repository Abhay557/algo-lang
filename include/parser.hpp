/**
 * File: parser.hpp
 * Brief: Recursive descent parser for expressions and conditions.
 *
 * This module parses and evaluates inline mathematical and boolean 
 * expressions. It implements a recursive descent parsing strategy to 
 * correctly handle operator precedence (e.g., ensuring multiplication 
 * and division occur before addition and subtraction), and resolves 
 * conditional statements for control flow.
 */

#pragma once
#include "common.hpp"
#include "utils.hpp"
#include "value.hpp"

using namespace std;

//moves the pointer forward to ignore spaces and tabs
void skipWhitespace(const string& str, size_t& pos);

//reads a word, if digit, converts to float, if letters, pulls the value from variables map
//also handles negative sign and restarts if it sees ( ).
float parseFactor(const string& str, size_t& pos, map<string, varValue>* variables);
        
//handles multiplication, division, and modulus
//makes sure these happen before addition or subtraction.
float parseTerm(const string& str, size_t& pos, map<string, varValue>* variables);
        
//handles addition and subtraction.
//starting funciton of the parser
float parseExpression(const string& str, size_t& pos, map<string, varValue>* variables);


//helper function to evaluate boolean condition inside if statement
bool parseBooleanConditions(stringstream& nestedConditionalStatement, map<string, varValue>* variables);
//helper function to evaluate comparision condition inside if statement
bool parseComparisionConditions(const string& conditionalStatement, map<string, varValue>* variables);