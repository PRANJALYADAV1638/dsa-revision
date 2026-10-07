
/*
# Expression Conversion — Interview Quick Revision

## 1. Basic Terms

### Infix

Operator is **between operands**.

```text
a + b
a + b * c
```

Normal mathematical expression.

### Prefix

Operator comes **before operands**.

```text
+ab
*+abc
```

### Postfix

Operator comes **after operands**.

```text
ab+
abc*+
```

---

# 2. Most Important Conversion Table

| Conversion       | Traversal    | Stack stores     |
| ---------------- | ------------ | ---------------- |
| Infix → Postfix  | Left → Right | `char` operators |
| Infix → Prefix   | Right → Left | `char` operators |
| Postfix → Infix  | Left → Right | `string`         |
| Prefix → Infix   | Right → Left | `string`         |
| Postfix → Prefix | Left → Right | `string`         |
| Prefix → Postfix | Right → Left | `string`         |

### Golden Rule

**Infix conversions → operator stack + precedence**

**Prefix/Postfix conversions → operand stack, usually `stack<string>`**

---

# 3. Operator Precedence

```text
^       → 3
* /     → 2
+ -     → 1
```

Higher number = higher precedence.

Example:

```text
a + b * c
```

First:

```text
b * c
```

Then:

```text
a + (b*c)
```

Postfix:

```text
abc*+
```

---

# 4. Infix → Postfix

### Direction

```text
LEFT → RIGHT
```

### Logic

```text
Operand → directly answer

Operator →
    pop higher/equal precedence operators
    push current operator

End →
    pop remaining operators
```

### Basic code pattern

```cpp
stack<char> st;
string ans;

for(char ch : s){

    if(operand)
        ans += ch;

    else{
        while(!st.empty() && precedence(st.top()) >= precedence(ch)){
            ans += st.top();
            st.pop();
        }

        st.push(ch);
    }
}

while(!st.empty()){
    ans += st.top();
    st.pop();
}
```

### Example

```text
Infix:   a+b*c
Postfix: abc*+
```

---

# 5. Infix → Prefix

### Direction

```text
RIGHT → LEFT
```

Basic idea:

1. Scan from right.
2. Operand → answer.
3. `)` → push.
4. `(` → pop until `)`.
5. Operator → handle precedence.
6. Reverse final answer.

### Remember

```text
Infix → Prefix
RIGHT → LEFT
then REVERSE
```

Example:

```text
Infix:  (a+b)*c
Prefix: *+abc
```

---

# 6. Postfix → Infix

### Direction

```text
LEFT → RIGHT
```

### Stack

```cpp
stack<string> st;
```

### Logic

Operand:

```text
push
```

Operator:

```text
op2 = pop
op1 = pop

ans = "(" + op1 + operator + op2 + ")"

push(ans)
```

### Formula

```text
Postfix:
op1 op2 operator

Infix:
(op1 operator op2)
```

### Example

```text
Postfix: ab+
Infix:   (a+b)
```

---

# 7. Prefix → Infix

### Direction

```text
RIGHT → LEFT
```

### Logic

Operand:

```text
push
```

Operator:

```text
op1 = pop
op2 = pop

ans = "(" + op1 + operator + op2 + ")"

push(ans)
```

### Important

Because we scan from **right to left**, the first popped value becomes `op1`.

### Example

```text
Prefix: *+abc

Infix:
((a+b)*c)
```

---

# 8. Postfix → Prefix

### Direction

```text
LEFT → RIGHT
```

### Stack

```cpp
stack<string> st;
```

### Logic

Operand:

```text
push
```

Operator:

```text
op2 = pop
op1 = pop

ans = operator + op1 + op2

push(ans)
```

### Formula

```text
Postfix:
op1 op2 operator

Prefix:
operator op1 op2
```

### Example

```text
Postfix: ab+c*

Prefix:  *+abc
```

Another:

```text
Postfix: abc*+d-

Prefix: -+a*bcd
```

---

# 9. Prefix → Postfix

### Direction

```text
RIGHT → LEFT
```

### Stack

```cpp
stack<string> st;
```

### Logic

Operand:

```text
push
```

Operator:

```text
op1 = pop
op2 = pop

ans = op1 + op2 + operator

push(ans)
```

### Formula

```text
Prefix:
operator op1 op2

Postfix:
op1 op2 operator
```

### Example

```text
Prefix: *+abc

Postfix: ab+c*
```

---

# 10. The Most Important Pop Order

This is where interview mistakes commonly happen.

## Postfix → Infix / Prefix

Scan:

```text
LEFT → RIGHT
```

When operator comes:

```cpp
op2 = st.top();
st.pop();

op1 = st.top();
st.pop();
```

Then:

```text
Infix  = op1 operator op2
Prefix = operator op1 op2
```

---

## Prefix → Infix / Postfix

Scan:

```text
RIGHT → LEFT
```

When operator comes:

```cpp
op1 = st.top();
st.pop();

op2 = st.top();
st.pop();
```

Then:

```text
Infix  = op1 operator op2
Postfix = op1 op2 operator
```

---

# 11. Parentheses

For Infix → Postfix:

```text
( → push
) → pop until '('
```

Example:

```text
(a+b)*c
```

Postfix:

```text
ab+c*
```

For Infix → Prefix, remember:

```text
Scan from RIGHT
')' → push
'(' → pop until ')'
```

---

# 12. One-Page Memory Trick

### Infix → Postfix

```text
L → R
Operator stack
Precedence
```

### Infix → Prefix

```text
R → L
Operator stack
Precedence
Reverse
```

### Postfix → Infix

```text
L → R
String stack
op1 + op + op2
```

### Prefix → Infix

```text
R → L
String stack
op1 + op + op2
```

### Postfix → Prefix

```text
L → R
String stack
op + op1 + op2
```

### Prefix → Postfix

```text
R → L
String stack
op1 + op2 + op
```

---

# 13. Complexity

For all standard conversions:

```text
Time  → O(n)
Space → O(n)
```

Why?

Every character is processed a constant number of times and stack operations are `O(1)`.

---

# 14. Interview Questions You Should Be Ready For

### Q1. Why do we use stack?

Because expression conversion requires **LIFO ordering**, especially for operators and operands.

### Q2. Why `stack<string>` in Postfix/Prefix conversions?

Because intermediate expressions can contain multiple characters.

Example:

```text
a
*bc
+a*bc
```

So `string` is convenient.

### Q3. Why `stack<char>` in Infix → Postfix?

Because we mainly store individual operators:

```text
+
-
*
/
^
```

### Q4. Why precedence is needed in Infix conversion?

Because operators have different priorities.

```text
a+b*c
```

must become:

```text
abc*+
```

not:

```text
ab+c*
```

### Q5. What is the biggest difference?

```text
Infix → needs precedence
Prefix/Postfix → mostly direct stack manipulation
```

---

# 15. Final Interview Cheat Sheet

```text
                 DIRECTION       STACK

INFIX → POSTFIX  L → R           char
INFIX → PREFIX   R → L           char + precedence

POSTFIX → INFIX  L → R           string
PREFIX → INFIX   R → L           string

POSTFIX → PREFIX L → R           string
PREFIX → POSTFIX R → L           string
```

### Remember these four formulas:

```text
POSTFIX → INFIX
op1 op2 op
→
(op1 op op2)

POSTFIX → PREFIX
op1 op2 op
→
op op1 op2

PREFIX → INFIX
op op1 op2
→
(op1 op op2)

PREFIX → POSTFIX
op op1 op2
→
op1 op2 op
```

**If you remember only one thing before the interview:**

```text
IN ORDER:
Infix = Operator between operands

PRE:
Operator first

POST:
Operator last
```

And for stack conversions:

```text
POSTFIX → scan LEFT → RIGHT
PREFIX  → scan RIGHT → LEFT
```
*/


/*
Absolutely. For interviews, paragraph-style explanations are better because you can **speak them directly to the interviewer**. Here is an easy-English version for all six conversions.

# Expression Conversion — Easy English Interview Notes

## 1. Infix to Postfix

Infix to Postfix conversion is used to convert a normal mathematical expression into postfix form. In infix notation, the operator is written between operands, like `A+B`. In postfix notation, the operator is written after the operands, like `AB+`. We scan the expression from **left to right**. If we find an operand, we directly add it to the answer. If we find an operator, we use a stack and compare its precedence with the operator present at the top of the stack. Higher or equal precedence operators are removed from the stack and added to the answer. Finally, all remaining operators are popped from the stack.

**Example:**

```text
Infix:   A+B*C
Postfix: ABC*+
```

**Remember:**
`Left to Right + Operator Stack + Precedence`

---

## 2. Infix to Prefix

Infix to Prefix conversion converts a normal infix expression into prefix form. In prefix notation, the operator comes before its operands. For example, `A+B` becomes `+AB`. We process the expression from **right to left** and use a stack to store operators. Operands are directly added to the result, while operators are handled according to their precedence. Parentheses are also handled using the stack. After processing the complete expression, the result is reversed to obtain the final prefix expression.

**Example:**

```text
Infix:  (A+B)*C
Prefix: *+ABC
```

**Remember:**
`Right to Left + Operator Stack + Precedence + Reverse`

---

## 3. Postfix to Infix

Postfix to Infix conversion converts an expression where operators come after operands into a normal mathematical expression. We scan the postfix expression from **left to right** and use a stack of strings. When we find an operand, we push it into the stack. When we find an operator, we pop the top two operands from the stack. The second popped value is the first operand, and the first popped value is the second operand. We combine them as `(operand1 operator operand2)` and push the resulting expression back into the stack. At the end, the stack contains the complete infix expression.

**Example:**

```text
Postfix: AB+
Infix:   (A+B)
```

**Remember:**
`Left to Right + String Stack + op1 operator op2`

---

## 4. Prefix to Infix

Prefix to Infix conversion converts an expression where the operator comes before its operands into a normal infix expression. We scan the prefix expression from **right to left** because the operands required by an operator are found from the right side. We use a stack of strings. When we find an operand, we push it into the stack. When we find an operator, we pop the top two expressions, combine them in the form `(operand1 operator operand2)`, and push the new expression back into the stack. The final element in the stack is the infix expression.

**Example:**

```text
Prefix: *+ABC
Infix:  ((A+B)*C)
```

**Remember:**
`Right to Left + String Stack + op1 operator op2`

---

## 5. Postfix to Prefix

Postfix to Prefix conversion changes a postfix expression into prefix form. We scan the expression from **left to right** and use a stack of strings. When we find an operand, we push it into the stack. When we find an operator, we pop two expressions from the stack. We then place the operator before those two operands and push the resulting prefix expression back into the stack. After processing all characters, the remaining element in the stack is the final prefix expression.

**Example:**

```text
Postfix: AB+C*
Prefix:  *+ABC
```

For example:

```text
B C *
→ *BC
```

Then:

```text
A *BC +
→ +A*BC
```

**Remember:**
`Left to Right + String Stack + operator before operands`

---

## 6. Prefix to Postfix

Prefix to Postfix conversion changes a prefix expression into postfix form. We scan the prefix expression from **right to left** and use a stack of strings. When we find an operand, we push it into the stack. When we find an operator, we pop the top two expressions from the stack and place the operator after them. The resulting postfix expression is pushed back into the stack. After processing the complete expression, the remaining element is the final postfix expression.

**Example:**

```text
Prefix:  *+ABC
Postfix: AB+C*
```

For example:

```text
+B A
→ AB+
```

Then:

```text
* (+AB) C
→ AB+C*
```

**Remember:**
`Right to Left + String Stack + operator after operands`

---

# Very Easy Way to Explain in an Interview

### Infix → Postfix

> "I scan the expression from left to right. Operands are directly added to the answer, while operators are stored in a stack according to their precedence. At the end, I pop all remaining operators from the stack."

### Infix → Prefix

> "I scan the expression from right to left. I use a stack for operators and handle them according to precedence. After processing the expression, I reverse the result to get the prefix expression."

### Postfix → Infix

> "I scan from left to right and use a stack of strings. For an operand I push it. For an operator I pop two expressions, combine them as operand1-operator-operand2, and push the result back."

### Prefix → Infix

> "I scan from right to left and use a stack of strings. For an operand I push it. For an operator I pop two expressions, combine them in infix form, and push the result back."

### Postfix → Prefix

> "I scan from left to right. I push operands into a stack. When I find an operator, I pop two operands and put the operator before them. The resulting expression is pushed back into the stack."

### Prefix → Postfix

> "I scan from right to left. I push operands into a stack. When I find an operator, I pop two operands and put the operator after them. The resulting expression is pushed back into the stack."

---

# Final Memory Trick

```text
INFIX
Operator is BETWEEN operands

PREFIX
Operator is BEFORE operands

POSTFIX
Operator is AFTER operands
```

### Direction

```text
POSTFIX → anything
LEFT → RIGHT

PREFIX → anything
RIGHT → LEFT
```

### Infix conversions

```text
Need:
Stack
Precedence
Parentheses
```

### Prefix/Postfix conversions

```text
Need:
Stack of strings
No precedence required
```

### The 4 formulas to memorize

```text
POSTFIX → INFIX

A B +
↓
(A+B)
```

```text
POSTFIX → PREFIX

A B +
↓
+AB
```

```text
PREFIX → INFIX

+ A B
↓
(A+B)
```

```text
PREFIX → POSTFIX

+ A B
↓
AB+
```

These four formulas + the scanning directions are enough to reconstruct the logic during an interview.
*/