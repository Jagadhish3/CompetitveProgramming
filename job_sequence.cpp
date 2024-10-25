#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    char ch;
    int deadline;
    int profit;
};

// Class to handle job scheduling
class A {
    public:
    // Vector to store jobs
    vector<Job> vec;

    // Method to add jobs to the vector
    void push(char ch, int deadline, int profit) {
        vec.push_back({ch, deadline, profit});
    }

    // Static comparison function for sorting jobs by profit in descending order
    static bool comp(Job a, Job b) {
        return a.profit > b.profit;
    }

    // Method to display jobs
    void displayJobs() {
        for(auto &job : vec) {
            cout << "Job: " << job.ch << ", Deadline: " << job.deadline << ", Profit: " << job.profit << endl;
        }
    }
};

int main() {
    A obj;
    
    // Adding jobs (job name, deadline, profit)
    obj.push('a', 2, 100);
    obj.push('b', 1, 50);
    obj.push('c', 2, 200);
    obj.push('d', 1, 150);
    obj.push('e', 3, 120);
    
    // Sorting jobs by profit in descending order
    sort(obj.vec.begin(), obj.vec.end(), A::comp);
    
    // Display the sorted jobs
    obj.displayJobs();

    return 0;
}
