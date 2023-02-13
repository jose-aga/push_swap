# push_swap
Push Swap project | *42 School*

------------
## The Project

### **push_swap** is a simple and very effective algorithmic project: you have to sort data.
You have at your disposal a set of int values, two stacks and a set of instructions to manipulate both.

What is the objective? Simple: You will write a **C program** that you will call *push_swap*.

The program will calculate and display on standard output a list of written instructions.
in push_swap language. You must look for the minimum number of instructions to order
the set of integers received as an argument.the set of integers received as an argument.

## Mandatory part
### The rules of the game

• The game is made up of two stacks, called a and b.
• For a start:

◦ In a you will have positive and/or negative numbers, never duplicates.
◦ In b there will be nothing.
• The goal is to sort the numbers in stack a in ascending order.
• To do so you have the following operations at your disposal:

sa : **swap a** - swaps the first two elements on top of stack a. Does not make
nothing if there are one or fewer elements.
sb : **swap b** - swaps the first two elements on top of stack b. Does not make
nothing if there are one or fewer elements.
ss : **swap a** and swap b at the same time.
pa : **push a** - takes the first item from stack b and puts it on top of stack a.
Does nothing if b is empty.
pb : **push b** - takes the first element of stack a and puts it on top of stack b.
Does nothing if a is empty.
ra : **rotate a** - shifts all stack items up by one position, so that the first element becomes the last.
rb : **rotate b** - shifts all elements of stack b up one position, so that the first element becomes the last.
rr : **rotate a and rotate b** - scroll all the elements of the stack at the same time
a and from stack b one position up, so that the first element is becomes the last
rra : **reverse rotate a** - scrolls down all items in the stack by a position, so that the last element becomes the first.
rrb : **reverse rotate b** - scroll down all elements of stack b one
position, so that the last element becomes the first.
rrr : **reverse rotate a and reverse rotate b**- scrolls at the same time all
the elements of stack a and stack b one position down, so that
the last element becomes the first.

### The program: “push_swap"

You must write a program called push_swap that will receive as an argument the
stack a in the format of a list of integers. The first argument must be the one
be on top of the stack (be careful with the order).

• The program must show the list of instructions (shortest possible) to order
the stack a, from lowest to highest where the lowest is at the top of the stack.

• Instructions must be separated using a “\n” and nothing else.

• The objective is to order the stack with the minimum number of operations possible. During the evaluation we will compare the number of instructions obtained by your program with a maximum instruction range.

• Your program will not receive points as much if your program lists too much
long as if the result is not correct.

• If no parameters are specified, the program should not display anything and should
return control to the user.

• In case of error, you should show **Error** followed by a “\n” on the standard error output. Some of the possible errors are: arguments that are not integers, arguments greater than an int, and/or find duplicate numbers.

## Do you want to check it ? Download

```shell
make
```

## If you run the program under Mac

```shell
make mtest2
make mtest3
make mtest5
make mtest100
make mtest500
make mtest1000
```

You can sort 2, 3, 5, 100, 500 or 1000 integers with the commands provided.

***Example***

  jose-aga@c3r5s2 push_swap % **make mtest100**
    ./push_swap -41 -5 49 6 8 -35 10 24 -49 -8 -11 -36 -2 20 22 -21 -17 -4 46 -44 -22 -50 -40 17 -47 -1 -46 0 21 -7 -33 12 -39 -42 23 18 4 44 34 -9 9 -15 -25 -48 30 31 5 26 47 -6 27 40 13 -24 -18 28 -19 -38 -16 35 -34 29 32 -12 -28 -30 -20 14 -3 -37 -14 41 -43 7 37 -31 2 45 -45 42 -32 -29 43 -27 -10 11 25 38 -26 1 48 36 -13 33 -23 39 15 3 19 16 | ./checker_Mac -41 -5 49 6 8 -35 10 24 -49 -8 -11 -36 -2 20 22 -21 -17 -4 46 -44 -22 -50 -40 17 -47 -1 -46 0 21 -7 -33 12 -39 -42 23 18 4 44 34 -9 9 -15 -25 -48 30 31 5 26 47 -6 27 40 13 -24 -18 28 -19 -38 -16 35 -34 29 32 -12 -28 -30 -20 14 -3 -37 -14 41 -43 7 37 -31 2 45 -45 42 -32 -29 43 -27 -10 11 25 38 -26 1 48 36 -13 33 -23 39 15 3 19 16
    OK
    -n Instructions: 
         592
    jose-aga@c3r5s2 push_swap %

**OK** Indicates that the process is carried out correctly and the number of Instructions is the necessary number of movements to sort the supplied list.

## If you run the program under Linux

First of all you have to write in the terminal
```shell
make
```
Then try the test 

```shell
make test2
make test3
make test5
make test100
make test500
make test1000
```


