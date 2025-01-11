import matplotlib.pyplot as plt

def plot_from_file(filename):
    thread_counts = []
    execution_times = []

    with open(filename, 'r') as file:
        for line in file:
            _, thread_count, execution_time = map(float, line.split())
            thread_counts.append(int(thread_count))
            execution_times.append(execution_time)

    plt.figure(figsize=(12, 8))
    plt.plot(thread_counts, execution_times, marker='o', linestyle='-', label="Matrix Size = 1000")

    plt.xlim(0, max(thread_counts) + 10)
    plt.ylim(max(execution_times) + 0.01, 0)
    plt.title("Execution Time vs Thread Count (Top-Left Start)", fontsize=18)
    plt.xlabel("Thread Count", fontsize=14)
    plt.ylabel("Execution Time (seconds)", fontsize=14)
    plt.xticks(thread_counts, fontsize=12)
    plt.yticks(fontsize=12)
    plt.grid(True)
    plt.legend(fontsize=12)

    plt.show()

data_file = r'C:\KSE\Parallel and Client-Server Programming\parallel-assignment-1-olesia-mykhailyshyn\resultsParallel.txt'
plot_from_file(data_file)