#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "Sequential.h"
#include "Parallel.h"
#include <chrono>
#include <vector>
#include <fstream>

int main() {
    std::cout << "SEQUENTIAL VARIANT:" << std::endl;

    std::fstream myFileSequential;
    myFileSequential.open(R"(C:\KSE\Parallel and Client-Server Programming\parallel-assignment-1-olesia-mykhailyshyn\resultsSequential.txt)", std::ios::out);

    std::vector<int> matrixSizes = {5, 50, 100, 500, 1000};

    if (myFileSequential.is_open()) {
        for (int size : matrixSizes) {
            std::cout << "\nTesting matrix of size: " << size << std::endl;
            myFileSequential << size << " ";

            double total_time = 0.0;
            for (int j = 0; j < 5; j++) {
                Matrix matrix(size);
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
            myFileSequential << std::fixed << std::setprecision(6) << average_time << "\n";
        }
    }

    myFileSequential.close();

    std::cout << "-----------------------------" << std::endl;
    std::cout << "PARALLEL VARIANT (VARYING THREAD COUNTS):" << std::endl;

    std::fstream myFileParallelThreads;
    myFileParallelThreads.open(R"(C:\KSE\Parallel and Client-Server Programming\parallel-assignment-1-olesia-mykhailyshyn\resultsParallelThreads.txt)", std::ios::out);

    std::vector<int> threadCounts = {6, 12, 24, 48, 96, 192, 384};
    int matrixSize = 1000;

    if (myFileParallelThreads.is_open()) {
        for (int maxThreads : threadCounts) {
            std::cout << "\nTesting with " << maxThreads << " threads for matrix size: " << matrixSize << std::endl;
            myFileParallelThreads << matrixSize << " " << maxThreads << " ";

            double total_time = 0.0;
            for (int j = 0; j < 5; j++) {
                Matrix matrix(matrixSize);
                matrix.matrixCreation();

                std::vector<int> maxElements;

                auto start = std::chrono::high_resolution_clock::now();

                Parallel::findMaxPerColumn(matrix.getMatrix(), maxElements, maxThreads);
                Parallel::updateMatrixDiagonalElements(matrix.getMatrix(), maxElements, maxThreads);

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed_seconds = end - start;

                total_time += elapsed_seconds.count();

                std::cout << "Elapsed time: " << std::fixed << std::setprecision(6) << elapsed_seconds.count() << " seconds\n";
            }

            double average_time = total_time / 5;
            std::cout << "Average time with " << maxThreads << " threads: " << std::fixed << std::setprecision(6) << average_time << " seconds\n";
            myFileParallelThreads << std::fixed << std::setprecision(6) << average_time << "\n"; // Log average time
        }
    }

    myFileParallelThreads.close();

    return 0;
}