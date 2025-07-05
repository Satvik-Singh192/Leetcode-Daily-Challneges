#!/bin/bash

# Get current date in YYYY-MM-DD format
TODAY=$(date +"%d-%m-%Y")

# Prompt for problem name
read -p "Enter today's LeetCode problem name: " PROBLEM_NAME

# Clean the problem name
CLEAN_NAME=$(echo "$PROBLEM_NAME" | tr ' ' '_' | tr -cd '[:alnum:]_')

# Create today's directory
mkdir -p "$TODAY"

# Create solution file
cat > "$TODAY/$CLEAN_NAME.cpp" <<EOF
/*
 * $PROBLEM_NAME
 * Date: $TODAY
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Your solution here
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
EOF

# Create README
cat > "$TODAY/README.md" <<EOF
# $PROBLEM_NAME - $TODAY

## Problem Description
[Add description here]

## Approach
[Explain your approach]

## Solution Code
\`\`\`cpp
$(cat "$TODAY/$CLEAN_NAME.cpp")
\`\`\`

## Complexity Analysis
- Time: 
- Space: 
EOF

echo "Created:"
echo "- $TODAY/$CLEAN_NAME.cpp"
echo "- $TODAY/README.md"