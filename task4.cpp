#include <iostream>
#include <vector>
#include <string>

// Structure to represent a Task
struct Task {
    std::string description;
    bool isCompleted;

    // Constructor to initialize a new task
    Task(const std::string& desc) : description(desc), isCompleted(false) {}
};

// Function prototypes
void displayMenu();
void addTask(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);
void markTaskAsCompleted(std::vector<Task>& tasks);

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                markTaskAsCompleted(tasks);
                break;
            case 5:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu() {
    std::cout << "\n--- To-Do List Manager ---" << std::endl;
    std::cout << "1. Add a task" << std::endl;
    std::cout << "2. View tasks" << std::endl;
    std::cout << "3. Delete a task" << std::endl;
    std::cout << "4. Mark task as completed" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

// Function to add a task to the list
void addTask(std::vector<Task>& tasks) {
    std::cin.ignore();  // Clear input buffer
    std::string taskDescription;
    std::cout << "Enter the task: ";
    std::getline(std::cin, taskDescription);
    tasks.push_back(Task(taskDescription));
    std::cout << "Task added successfully!" << std::endl;
}

// Function to view all tasks in the list
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to show." << std::endl;
    } else {
        std::cout << "\n--- To-Do List ---" << std::endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].isCompleted) {
                std::cout << " [Done]";
            }
            std::cout << std::endl;
        }
    }
}

// Function to delete a task from the list
void deleteTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete." << std::endl;
        return;
    }

    viewTasks(tasks);
    int taskIndex;
    std::cout << "Enter the task number to delete: ";
    std::cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        std::cout << "Invalid task number." << std::endl;
    } else {
        tasks.erase(tasks.begin() + taskIndex - 1);
        std::cout << "Task deleted successfully!" << std::endl;
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to mark as completed." << std::endl;
        return;
    }

    viewTasks(tasks);
    int taskIndex;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        std::cout << "Invalid task number." << std::endl;
    } else {
        tasks[taskIndex - 1].isCompleted = true;
        std::cout << "Task marked as completed!" << std::endl;
    }
}
