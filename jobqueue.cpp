#include <iostream>
#include <queue>
#include <string>

using namespace std;

class JobQueue {
private:
    queue<string> jobs; // Queue to store job names

public:
    // Function to add a job to the queue
    void addJob(const string& job) {
        jobs.push(job);
        cout << "Job added: " << job << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (jobs.empty()) {
            cout << "No jobs to delete." << endl;
            return;
        }
        cout << "Job deleted: " << jobs.front() << endl;
        jobs.pop();
    }

    // Function to display the current jobs in the queue
    void displayJobs() const {
        if (jobs.empty()) {
            cout << "The job queue is empty." << endl;
            return;
        }

        cout << "Current jobs in the queue: ";
        queue<string> tempQueue = jobs; // Create a copy to display
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main() {
    JobQueue jobQueue;
    int choice;
    string job;

    do {
        cout << "\nJob Queue Menu:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin >> job;
                jobQueue.addJob(job);
                break;

            case 2:
                jobQueue.deleteJob();
                break;

            case 3:
                jobQueue.displayJobs();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
