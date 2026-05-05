/**
 * File: evaluator.hpp
 * Brief: Core execution engine and statement evaluator.
 *
 * The evaluator is responsible for the runtime execution of the program. 
 * It processes individual statements line-by-line, triggers mathematical 
 * evaluations, manages control flow state (like branch execution tracking), 
 * and updates the global variable environment.
 */

#pragma once
#include "common.hpp"
#include "utils.hpp"
#include "parser.hpp"
#include "control_flow.hpp"
#include "value.hpp"

using namespace std;

float doMaths(const string& expression, map<string, varValue>* variables);

//engine that processes a single line, moved here so IF can call it recursively
void executeLine(string line, int& i, const vector<string>& Buffer, map<string, varValue>* variables, bool* previousIfBranchExecuted, bool* isRunning);
