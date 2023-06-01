#include <bits/stdc++.h>

using namespace std;

void permute(string str)
{
    sort(str.begin(), str.end()); // sorting the string in lexicographically smallest order
    
    do {
        cout << str << endl; // printing the current permutation
    } while (next_permutation(str.begin(), str.end())); // generating the next permutation
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "All possible permutations of " << str << " are: " << endl;
    permute(str);
    return 0;
}