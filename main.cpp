#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "Sequential.h"
#include <chrono>
#include <vector>
#include <fstream>

int main() {
    std::fstream myFile;
    myFile.open(R"(C:\KSE\Parallel and Client-Server Programming\parallel-assignment-1-olesia-mykhailyshyn\resultsSequential.txt)", std::ios::out);

    std::cout << "SEQUENTIAL VARIANT:" << std::endl;
    std::vector<int> matrixesSises = {5, 50, 100, 500, 1000, 10000};

    if (myFile.is_open()) {
        for (int i = 0; i < matrixesSises.size(); i++) {
            std::cout << "\nTesting matrix of size: " << matrixesSises[i] << std::endl;
            myFile << matrixesSises[i] << " ";

            double total_time = 0.0;
            for (int j = 0; j < 5; j++) {
                Matrix matrix(matrixesSises[i]);
                matrix.matrixCreation();

                std::vector<int> maxElements;

                auto start = std::chrono::high_resolution_clock::now();

                Sequential::findMaxPerColumn(matrix.getMatrix(), maxElements);
                Sequential::updateMatrixDiagonalElements(matrix.getMatrix(), maxElements);

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed_seconds = end - start;

                total_time += elapsed_seconds.count();

                std::cout << "Elapsed time: " << std::fixed << std::setprecision(6) << elapsed_seconds.count() << " seconds\n";
            }

            double average_time = total_time / 5;
            std::cout << "Average time: " << std::fixed << std::setprecision(6) << average_time << " seconds\n";
            myFile << std::fixed << std::setprecision(6) << average_time << "\n";
        }
    }

    myFile.close();

    return 0;
}