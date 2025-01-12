#pragma once
#include <vector>

class Parallel {
public:
    static void findMaxPerColumn(const std::vector<std::vector<int>>& matrix, std::vector<int>& maxElements, int maxThreads);
    static void printMaxPerColumn(const std::vector<int>& maxElements);
    static void updateMatrixDiagonalElements(std::vector<std::vector<int>>& matrix, const std::vector<int>& maxElements, int maxThreads);
    static void findMaxInColumn(const std::vector<std::vector<int>>& matrix, int column, std::vector<int>& maxElements);
    //static void updateMatrixDiagonalElement(std::vector<std::vector<int>>& matrix, int column, const std::vector<int>& maxElements);
};