/*
2 POINTER + SLIDING WINDOW — QUICK REVISION ⚡
1. Two Pointer

Idea: Use 2 indices to avoid repeated scanning.

Types

Opposite direction

L →       ← R
[1 2 3 4 5]

Used for:

Sorted array + pair sum
Palindrome
2/3 Sum
Compare from both ends

Same direction

slow → fast →

Used for:

Remove duplicates
Move zeroes
In-place modification
Fast/slow linked list
Key Rule

Move a pointer only when you can prove that movement cannot miss the answer.

Complexity

Time: O(n)
Space: O(1) usually

2. Sliding Window

Sliding Window = Two Pointers + a contiguous range + maintained information.

L → [ elements ] ← R

Used mainly for:

Subarray
Substring
Longest/shortest range
Maximum/minimum sum
Frequency problems
Window Size
right - left + 1
3. Fixed Window

Window size = K

Example:

Maximum sum of subarray of size K

sum += arr[right];

if(right-left+1 > k){
    sum -= arr[left];
    left++;
}

Time: O(n)

4. Variable Window

General pattern:

for(right = 0; right < n; right++){

    // add right

    while(invalid){
        // remove left
        left++;
    }

    // update answer
}
Longest
Make valid → MAX
Shortest
While valid → MIN → shrink
5. Most Important Concept 🔥
Expand → Check → Shrink
R moves → window grows
       ↓
condition violated?
       ↓
L moves → window shrinks

Both pointers generally move only forward:

L ≤ n
R ≤ n

Therefore:

O(n + n) = O(n)

6. At Most vs Exactly

Very important:

Exactly K
= AtMost(K) - AtMost(K-1)

Used frequently with distinct elements.

7. When to Think Sliding Window?

If problem says:

Longest / Shortest / Count + Subarray/Substring + condition

Immediately think:

SLIDING WINDOW

Examples:

Longest substring without repeating characters
Longest subarray with at most K distinct
Minimum window substring
Maximum sum of size K
8. ⚠️ Important Limitation

Sliding Window does not work blindly.

For many sum problems, it works naturally when values/condition have monotonic behavior (e.g. positive numbers).

With negative numbers, normal sum-based shrinking may fail.

🧠 10-SECOND REVISION
TWO POINTER
→ 2 indices
→ sorted/pairs/in-place
→ usually O(n)

SLIDING WINDOW
→ 2 pointers + contiguous range
→ subarray/substring
→ Fixed K OR Variable
→ Expand R
→ Shrink L
→ update answer
→ usually O(n)

Window size = R-L+1

Exactly K = AtMost(K) - AtMost(K-1)

Golden rule:

Don't memorize pointer movement. Understand WHY moving that pointer is safe
*/