// StringSet.cpp: Jarvis Prestidge
// Description:   My first TDD kata developing a class that 
// represents a string set, supporting set operations.

#include "StringSet.h"

#include <stdexcept>
#include <iostream>

// Default constructor.
StringSet::StringSet() {
}

// Default destructor.
StringSet::~StringSet() {
}

// Adds a string to set.
void StringSet::Add (std::string in_string) {
  strings.push_back(in_string);
}

// Gets the value of a string at a given postion.
std::string StringSet::GetString (int index) {
  return strings[index];
}

// Determines whether a string is contained within the set.
bool StringSet::Contains(std::string in_string) {
  for (int i = 0; (unsigned)i < strings.size(); ++i)
    if (strings[i] == in_string)
      return true;
  return false;
}

// Removes a string from the set.
void StringSet::Remove(std::string in_string) {
  for (int i = 0; (unsigned)i < strings.size(); ++i)
    if (strings[i] == in_string)
      strings.erase(strings.begin() + i);
}

// Returns the number of strings in the set.
int StringSet::Count() {
  return strings.size();
}

// Takes two string sets and returns the union set.
StringSet StringSet::Union(StringSet in_set) {
  StringSet result;
  for (int i = 0; i < this->Count(); ++i)
    result.Add(this->GetString(i));
  for (int i = 0; i < in_set.Count(); ++i)
    if (!result.Contains(in_set.GetString(i)))
      result.Add(in_set.GetString(i));
  return result;
}

// Takes two string sets and returns the intersection set.
StringSet StringSet::Intersection(StringSet in_set) {
  StringSet result;
  for (int i = 0; i < this->Count(); ++i)
    if (in_set.Contains(this->GetString(i)))
      result.Add(this->GetString(i));
  return result;
}

void StringSet::Clear() {
  strings.clear();
}
// Foot Note: It is always recommended to declare or cast variables to "unsigned"
// is they are intended to be compared to sizes to avoid compiler warnings.