#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Calculate the total # of votes that candidate has
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(candidates[k].name, name) == 0)
        {
            candidates[k].votes = candidates[k].votes + 1;

            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int k = 1;

    candidate winner[MAX] = {{"", 0}};

    //Compare with the MAX
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winner[0].votes)
        {
            winner[0].votes = candidates[i].votes;

            winner[0].name = candidates[i].name;
        }
    }

    // Compare with the MAX
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winner[0].votes)
        {
            winner[k].votes = candidates[i].votes;

            winner[k].name = candidates[i].name;

            k = k + 1;
        }
    }
    // No need to compare
    for (int i = 1; i < k; i++)
    {
        printf("%s\n", winner[i].name);
    }

    // change line
    printf("\n");

}