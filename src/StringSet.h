// StringSet.h:   Jarvis Prestidge
// Description:   My first TDD kata developing a class that 
// represents a string set, supporting set operations.

#ifndef _STRING_SET_H_
#define _STRING_SET_H_ 

// Necessary to allow tests to access private members. 
#include "gtest/gtest_prod.h"

#include <string>
#include <vector>

class StringSet
{
  // Private by default.
  std::vector<std::string> strings;  

public:
  // Constructor.
  StringSet();

  // Destructor.
  ~StringSet();

  // Adds a string to the set.
  void Add(std::string in_string);

  // Getter method for vector.
  std::string GetString(int index);

  // Checks if the string exists within set.
  bool Contains(std::string in_string);

  // Removes the string passed from the set.
  void Remove(std::string in_string);

  // Count the number of strings in the set.
  int Count();

  // Take two string sets and return the unions set.
  StringSet Union(StringSet in_set);

  // Take two string sets and return the intersection set.
  StringSet Intersection(StringSet in_set);

  // Clears the set of all strings.
  void Clear();
};

#endif
