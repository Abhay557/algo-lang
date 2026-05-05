/**
 * File: control_flow.hpp
 * Brief: Control flow boundary resolution for the interpreter.
 *
 * This module provides scanning utilities to calculate jump targets and 
 * scope boundaries within the source buffer. It contains functions to linearly 
 * scan the token/string sequence to match the beginning and end of 
 * control structures like IF/ELIF/ELSE conditionals and WHILE loops.
 */


#pragma once
#include "common.hpp"
#include "utils.hpp"

using namespace std;

//generic block finder for IF, ELIF, and ELSE
int findBlockEnd(int startIndex, const vector<string>& Buffer, string startCmd, string endCmd);
int findEndWhile(int startIndex, const vector<string>& Buffer);
int findWhile(int startIndex, const vector<string>& Buffer);
