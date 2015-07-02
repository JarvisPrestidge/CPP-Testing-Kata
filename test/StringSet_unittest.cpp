// StringSet.h:   Jarvis Prestidge
// Description:   My first TDD kata developing a class that 
// represents a string set, supporting set operations.

#include "StringSet.h"
#include "gtest/gtest.h"

#include <iostream>
#include <stdexcept>
#include <string>

using std::string;

const string empty = "";
const string str = "Hello World!";

// Creating StringSet object.
StringSet set;

TEST(StringSetTest, AddEmptyString) {
  // Tests the addition of the empty string.
  set.Add(empty);
  EXPECT_EQ(empty, set.GetString(0));
}

TEST(StringSetTest, AddString) {
  // Tests the addition of a simple string.
  set.Add(str);
  EXPECT_EQ(str, set.GetString(1));
}

TEST(StringSetTest, CheckSetContainsString) {
  // Tests if the set contains a given string.
  EXPECT_TRUE(set.Contains(str));
}

TEST(StringSetTest, CheckSetContainsString2) {
  // Tests if the set contains a second given string.
  EXPECT_FALSE(set.Contains("Something, Something"));
}

TEST(StringSetTest, RemoveString) {
  // Removes a given string from the set.
  set.Remove(str);
  EXPECT_FALSE(set.Contains(str));
}

TEST(StringSetTest, Count1String) {
  // Tests the count function.
  EXPECT_EQ(1, set.Count());
}

TEST(StringSetTest, Count3Strings) {
  // Tests the count function.
  set.Add("String number 2.");
  set.Add("String number 3.");
  EXPECT_EQ(3, set.Count());
}

TEST(StringSetTest, UnionOfTwoStringSets) {
  // Tests the Unions of two sets, including all strings.
  StringSet first, second;
  first.Add("First string.");
  first.Add("Second string.");
  first.Add("Third string.");
  second.Add("First string.");
  second.Add("Second string.");
  StringSet third = first.Union(second);
  EXPECT_TRUE(third.Contains("First string."));
  EXPECT_TRUE(third.Contains("Second string."));
  EXPECT_TRUE(third.Contains("Third string."));
  EXPECT_EQ(3, third.Count());
}

TEST(StringSetTest, IntersectionOfTwoStrings) {
  // Tests the intersection of two set, including only strings occuring
  // in both sets.
  StringSet first, second;
  first.Add("First string.");
  first.Add("Second string.");
  first.Add("Third string.");
  second.Add("First string.");
  second.Add("Second string.");
  StringSet intersection = first.Intersection(second);
  EXPECT_TRUE(intersection.Contains("First string."));
  EXPECT_TRUE(intersection.Contains("Second string."));
  EXPECT_FALSE(intersection.Contains("Third string."));
  EXPECT_EQ(2, intersection.Count());
}

TEST(StringSetTest, ClearTheSet) {
  // Tests that the set in cleared.
  set.Clear();
  EXPECT_EQ(0, set.Count());
  EXPECT_NE(3, set.Count());
  
}