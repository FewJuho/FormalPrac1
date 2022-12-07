#include "formal.h"
#include "gtest/gtest.h"

TEST(Solution, test1) {
  EXPECT_EQ(5, Solution("ab+*", "acabacaaabaccaaba"));
}

TEST(Solution, test2) {
  EXPECT_EQ(1, Solution("ab+", "acab"));
}

TEST(Solution, test3) {
  EXPECT_EQ(2, Solution("ab*+", "aacbacbb"));
}

TEST(Solution, test4) {
  EXPECT_EQ(1, Solution("1c*+a.", "ac"));
}

TEST(Solution, test5) {
  EXPECT_EQ(0, Solution("acb..", "abcabcbaa"));
}

TEST(Solution, test6) {
  EXPECT_EQ(2, Solution("acb..ba*.+", "abac"));
}

TEST(Solution, test7) {
  EXPECT_EQ(3, Solution("acb..ba*.+", "acacacbb"));
}

TEST(Solution, test8) {
  EXPECT_EQ(7, Solution("ac.ca.+b*.", "accabbbbbacca"));
}

TEST(Solution, test9) {
  EXPECT_EQ(13, Solution("ac.ca.+b*.*", "accabbbbbacca"));}

TEST(Solution, test10) {
  EXPECT_EQ(1, Solution("1a+b*.*", "a"));
}

TEST(Solution, test11) {
  EXPECT_EQ(2, Solution("1a+b*.*ab.*.b+", "acaacb"));
}

TEST(Solution, test12) {
  EXPECT_EQ(0, Solution("ab+*1a+b*.*ab.*.b++", ""));
}

TEST(Solution, test13) {
  EXPECT_EQ(4, Solution("ab+*1a+b*.*ab.*.b++c.b*+", "cbabcb"));
}

TEST(Solution, test14) {
  EXPECT_EQ(0, Solution("ab+1+", ""));
}

TEST(Solution, test15) {
  EXPECT_EQ(3, Solution("c*a*+b*+", "aacabcbbbccba"));
}

TEST(Solution, test16) {
  EXPECT_EQ(10, Solution("c*a*+b*+*", "aacabcbbbc"));
}

TEST(Solution, test17) {
  EXPECT_EQ(5, Solution("ab.bc.a+*.", "cbcababccabbc"));
}

TEST(Solution, test18) {
  EXPECT_EQ(2, Solution("ab+bc+a.*+", "bbcaacabbcaabab"));
}

TEST(Solution, test19) {
  EXPECT_EQ(6, Solution("bc.a.ac.b.+*", "abcabcacb"));
}

TEST(Solution, test20) {
  EXPECT_EQ(1, Solution("ab+1+*", "cacaccaccbccbcb"));
}