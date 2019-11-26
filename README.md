# push_swap

Push swap is implementing sorting algorithm by using two stack.
But this stack is different from ordinary stack data structure.
Basically, It works like stack, in terms of stacking data by LIFO(Last in First Out).
However, this use some other operations which original stack doesn't have.

## operations

`sa` swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
`sb` swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
`ss` sa and sb at the same time.
`pa` push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
`pb` push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
`ra` rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
`rb` rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
`rr` ra and rb at the same time.
`rra` reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.


[push_swap.en.pdf](/resources/push_swap.en.pdf) is the task file to see the detailed instruction.

## Project Structure

This project consists of five parts:

* push_swap
* checker
* Visualizer (Bonus)

Actual sorting program is `push_swap`, getting a unsorted numbers as argument
then return bunch of instructions to be sorted.

`checkher` is after getting the instruction from `push_swap`, adjust to unsorted number, then check if it is sorted or not.

`visualizer` is a bonus part to show how each stack is working in real time.

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## Usage

instead of using original `push_swap` and `checker`. there are test programs in `resources` directory.

> `rn` generate the random number
> `ps` generate random number and run `push_swap`, return count of instructions.
> `ch` using randomly generated numbers, run `push_swap` and `checker` with visualizer

```
Usage: ./resources/tester[ps | ch] <num>
    num          — range of the numbers
```
## Visualizer

Visualizer is made up of simple stdout by changing the color depending on the value.

![Visualizer](/resources/pushswap.gif)
