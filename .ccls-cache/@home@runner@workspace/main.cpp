#include <iostream>
#include <iomanip>


double getScore();
bool isLower(double val1, double val2);
bool isHigher(double val1, double val2);
double calcAverage(double total, double min, double max);
int main() {
    double minScore = 11.0; 
    double maxScore = -1.0;
    double totalScore = 0.0;
    double score = 0.0;
    const int NUM_JUDGES = 5;
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Star Search Performer Score Calculator\n";
    std::cout << "======================================\n";
    for (int i = 0; i < NUM_JUDGES; ++i) {
        std::cout << "Enter score for judge " << i + 1 << ": ";
        score = getScore();
        totalScore += score;
        if (i == 0) {
            minScore = score;
            maxScore = score;
        } else {
            if (isLower(score, minScore)) {
                minScore = score;
            }
            if (isHigher(score, maxScore)) {
                maxScore = score;
            }
        }
    }
    
    double averageScore = calcAverage(totalScore, minScore, maxScore);
    std::cout << "\nScores entered:\n";
    std::cout << "  Highest score: " << maxScore << "\n";
    std::cout << "  Lowest score:  " << minScore << "\n";
    std::cout << "  Sum of all scores: " << totalScore << "\n";
    std::cout << "The final average score (with highest and lowest dropped) is: " << averageScore << "\n";

    return 0;
}

double getScore() {
    double score;
    do {
        std::cin >> score;
        if (score < 0.0 || score > 10.0) {
            std::cout << "Invalid score. Please enter a score between 0.0 and 10.0: ";
        }
    } while (score < 0.0 || score > 10.0);
    return score;
}

bool isLower(double val1, double val2) {
    return val1 <= val2;
}

bool isHigher(double val1, double val2) {
    return val1 >= val2;
}

double calcAverage(double total, double min, double max) {
    double sumOfMiddleScores = total - min - max;
    return sumOfMiddleScores / 3.0;
}