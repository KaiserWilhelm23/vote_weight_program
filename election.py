from decimal import Decimal, getcontext

# Set precision high enough for large numbers
getcontext().prec = 28

def weighted_votes(trump_votes, biden_votes):
    # Define a weight for Biden's votes
    biden_weight = Decimal('1.1')
    
    # Convert votes to Decimal
    trump_votes = Decimal(trump_votes)
    biden_votes = Decimal(biden_votes)
    
    # Calculate the effective votes
    effective_biden_votes = biden_votes * biden_weight
    
    # Ensure Biden always wins slightly
    if effective_biden_votes <= trump_votes:
        effective_biden_votes = trump_votes + Decimal('1')
    
    # Calculate total effective votes
    total_effective_votes = trump_votes + effective_biden_votes
    
    # Calculate percentages
    trump_percentage = (trump_votes / total_effective_votes) * 100
    biden_percentage = (effective_biden_votes / total_effective_votes) * 100
    
    # Print the results
    print(f"Trump: {trump_percentage:.2f}%")
    print(f"Biden: {biden_percentage:.2f}%")
    
    # Calculate new vote totals based on the percentages
    total_votes = trump_votes + biden_votes  # True total of original votes
    new_trump_votes = (trump_percentage / 100) * total_votes
    new_biden_votes = (biden_percentage / 100) * total_votes
    
    # Print the new vote totals
    print(f"New Trump Votes: {round(new_trump_votes)}")
    print(f"New Biden Votes: {round(new_biden_votes)}")

# Example usage
trump_votes = int(input("Enter the number of votes for Trump: "))
biden_votes = int(input("Enter the number of votes for Biden: "))

weighted_votes(trump_votes, biden_votes)
