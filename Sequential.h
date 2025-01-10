#pragma once
#include <vector>
#include <iostream>

class Sequential {
public:
    static void findMaxPerColumn(const std::vector<std::vector<int>>& matrix, std::vector<int>& maxElements);
    static void printMaxPerColumn(const std::vector<int>& maxElements) ;
    static void updateMatrixDiagonalElements(std::vector<std::vector<int>>& matrix, const std::vector<int>& maxElements);
};
