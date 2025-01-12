import matplotlib.pyplot as plt

def plot_matrix_execution_time(filename):
    matrix_sizes = []
    execution_times = []

    with open(filename, 'r') as file:
        for line in file:
            matrix_size, execution_time = map(float, line.split())
            matrix_sizes.append(int(matrix_size))
            execution_times.append(execution_time)

    plt.figure(figsize=(12, 8))
    plt.plot(matrix_sizes, execution_times, marker='o', linestyle='-', label="Execution Time")

    plt.title("Execution Time vs Matrix Size", fontsize=18)
    plt.xlabel("Matrix Size", fontsize=14)
    plt.ylabel("Execution Time (seconds)", fontsize=14)
    plt.xticks(range(0, max(matrix_sizes) + 1, 100), fontsize=12)
    plt.yticks(fontsize=12)
    plt.grid(True)
    plt.legend(fontsize=12)

    plt.gca().invert_yaxis()

    plt.show()

data_file = r'C:\KSE\Parallel and Client-Server Programming\parallel-assignment-1-olesia-mykhailyshyn\resultsSequential.txt'
plot_matrix_execution_time(data_file)