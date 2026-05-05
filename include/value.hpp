/**
 * File: value.hpp
 * Brief: Runtime data structures and value representations.
 *
 * This file defines the core data structures used to represent variables 
 * and their values in memory during script execution. It includes the 
 * DataType enumerations and the primary variant class used in the 
 * interpreter's environment map.
 */

#pragma once
#include "common.hpp"

enum DataType { TYPE_INT, TYPE_FLOAT, TYPE_STRING };

class varValue {
public:
  DataType type;
  int i_val;
  float f_val;
  string s_val;

  varValue() {
     type = TYPE_INT;
     i_val = 0;
     f_val = 0.0f;
     s_val = "";
  }
};
