#include <iostream>
#include <iomanip>
#include <cmath>

void weighted_votes(int trump_votes, int biden_votes) {
    // Define a weight for Biden's votes
    double biden_weight = 1.1;
    
    // Calculate the effective votes for Biden
    double effective_biden_votes = biden_votes * biden_weight;
    
    // Ensure Biden always wins slightly
    if (effective_biden_votes <= trump_votes) {
        effective_biden_votes = trump_votes + 1.0;
    }
    
    // Calculate total effective votes
    double total_effective_votes = trump_votes + effective_biden_votes;
    
    // Calculate percentages
    double trump_percentage = (trump_votes / total_effective_votes) * 100.0;
    double biden_percentage = (effective_biden_votes / total_effective_votes) * 100.0;
    
    // Print the results
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Trump: " << trump_percentage << "%\n";
    std::cout << "Biden: " << biden_percentage << "%\n";
    
    // Calculate new vote totals based on the percentages
    double total_votes = trump_votes + biden_votes;  // True total of original votes
    int new_trump_votes = std::round((trump_percentage / 100.0) * total_votes);
    int new_biden_votes = std::round((biden_percentage / 100.0) * total_votes);
    
    // Print the new vote totals
    std::cout << "New Trump Votes: " << new_trump_votes << "\n";
    std::cout << "New Biden Votes: " << new_biden_votes << "\n";
}

int main() {
    int trump_votes, biden_votes;
    
    std::cout << "Enter the number of votes for Trump: ";
    std::cin >> trump_votes;
    
    std::cout << "Enter the number of votes for Biden: ";
    std::cin >> biden_votes;
    
    weighted_votes(trump_votes, biden_votes);
    
    return 0;
}
