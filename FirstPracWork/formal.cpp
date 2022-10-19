#include "formal.h"
#include <bits/stdc++.h>

void OperationPlus(std::stack<int>& stack_of_positions, std::vector<std::vector<std::vector<bool>>>& Vector3D, int pos) {
  auto first = stack_of_positions.top();
  stack_of_positions.pop();
  auto second = stack_of_positions.top();
  stack_of_positions.pop();
  for (auto i = 0; i < Vector3D[pos].size(); ++i) {
    for (auto j = i; j < Vector3D[pos][i].size(); ++j) {
      if (Vector3D[first][i][j] || Vector3D[second][i][j]) {
        Vector3D[pos][i][j] = true;
      }
    }
  }
}

void OperationStar(std::stack<int>& stack_of_positions, std::vector<std::vector<std::vector<bool>>>& Vector3D, int pos) {
  for (auto i = 0; i < Vector3D[pos].size(); ++i) {
    Vector3D[pos][i][i] = true;
  }
  auto first = stack_of_positions.top();
  stack_of_positions.pop();
  for (auto i = 0; i < Vector3D[pos].size(); ++i) {
    for (auto j = i + 1; j < Vector3D[pos][i].size(); ++j) {
      for (auto mid = i; mid <= j; ++mid) {
        // word[i...j) = word[i...mid1) + word[mid1...mid2) + ... + word[mid_last...j)
        if (Vector3D[first][mid][j] && Vector3D[pos][i][mid]) {
          Vector3D[pos][i][j] = true;
        }
      }
    }
  }
}

void OperationConcatination(std::stack<int>& stack_of_positions, std::vector<std::vector<std::vector<bool>>>& Vector3D, int pos) {
  auto first = stack_of_positions.top();
  stack_of_positions.pop();
  auto second = stack_of_positions.top();
  stack_of_positions.pop();
  for (auto i = 0; i < Vector3D[pos].size(); ++i) {
    for (auto j = i; j < Vector3D[pos][i].size(); ++j) {
      for (auto mid = i; mid <= j; ++mid) {
        //  word[i...j) = word[i...mid) + word[mid...j)
        if (Vector3D[second][i][mid] && Vector3D[first][mid][j]) {
          Vector3D[pos][i][j] = true;
        }
      }
    }
  }
}

int Solution(std::string regular_expression, std::string word) {
  std::stack<int> stack_of_positions;
  std::vector<std::vector<std::vector<bool>>> Vector3D(regular_expression.size());
  for (auto i = 0; i < regular_expression.size(); ++i) {
    Vector3D[i] = std::vector<std::vector<bool>> (word.size() + 1);
    for (auto j = 0; j < word.size() + 1; ++j) {
      Vector3D[i][j] = std::vector<bool> (word.size() + 1);
      for (auto k = 0; k < word.size() + 1; ++k) {
        Vector3D[i][j][k] = false;
      }
    }
  }

  for (auto pos_in_regular = 0; pos_in_regular < regular_expression.size(); ++pos_in_regular) {
    char symbol = regular_expression[pos_in_regular];
    if (symbol == '+') {
      OperationPlus(stack_of_positions, Vector3D, pos_in_regular);
    } else if (symbol == '*') {
      OperationStar(stack_of_positions, Vector3D, pos_in_regular);
    } else if (symbol == '.') {
      OperationConcatination(stack_of_positions, Vector3D, pos_in_regular);
    } else if (symbol == '1') {
      for (auto l = 0; l <= word.size(); ++l) {
        Vector3D[pos_in_regular][l][l] = true;
      }
    } else {
      for (auto l = 0; l < word.size(); ++l) {
        if (word[l] == regular_expression[pos_in_regular]) {
          Vector3D[pos_in_regular][l][l + 1] = true;
        }
      }
    }
    stack_of_positions.push(pos_in_regular);
  }

  int max = 0;
  for (auto i = 0; i <= word.size(); ++i) {
    for (auto j = word.size(); j > i; j--) {
      if (Vector3D[regular_expression.size() - 1][i][j]) {
        if (max < (j - i)) {
          max = j - i;
        }
      }
    }
  }
  return max;
}