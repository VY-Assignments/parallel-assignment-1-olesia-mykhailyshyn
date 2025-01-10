#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "Sequential.h"
#include <chrono>
#include <vector>

int main() {
    std::cout << "SEQUENTIAL VARIANT:" << std::endl;
    std::vector<int> matrixesSises = {5, 50, 100, 500, 1000, 10000};

    for (int i = 0; i < matrixesSises.size(); i++) {
        std::cout << "\nTesting matrix of size: " << matrixesSises[i] << std::endl;
        for (int j = 0; j < 5; j++) {
            Matrix matrix(matrixesSises[i]);
            matrix.matrixCreation();
            // matrix.printMatrix();
            // matrix.printDiagonalElements();

            std::vector<int> maxElements;

            std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
            start = std::chrono::high_resolution_clock::now();

            Sequential::findMaxPerColumn(matrix.getMatrix(), maxElements);
            // Sequential::printMaxPerColumn(maxElements);

            Sequential::updateMatrixDiagonalElements(matrix.getMatrix(), maxElements);
            // matrix.printMatrix();

            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;

            std::cout << "Elapsed time: " << std::fixed << std::setprecision(6) << elapsed_seconds.count() << " seconds\n";
        }
    }

    return 0;
}