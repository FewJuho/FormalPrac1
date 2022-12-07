#ifndef FORMAL
#define FORMAL
#include <bits/stdc++.h>

void OperationPlus(std::stack<int>& stack, std::vector<std::vector<std::vector<bool>>>& Vector3D, int pos);
void OperationStar(std::stack<int>& stack, std::vector<std::vector<std::vector<bool>>>& Vector3D, int pos);
void OperationConcatination(std::stack<int>& stack, std::vector<std::vector<std::vector<bool>>>& Vector3D, int pos);
int Solution(std::string regex, std::string word);

#endif // FORMAL