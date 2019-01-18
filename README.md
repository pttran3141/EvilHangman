# Evil Hangman

To compile the game, type "make". To run the game, type "./hangman".

Computing II Final Project. 

## The assignment

In case you aren't familiar with the game of Hangman, the rules are as follows: 

1. One player chooses a secret word, and then writes out a number of dashes equal to the word length. 
2. The other player begins guessing letters. Whenever she guesses a letter contained in the hidden word, the first player reveals every instance of that letter in the word. Otherwise, the guess is wrong. 
3. The game ends either when all the letters in the word have been revealed or when the guesser has run out of guesses.

Fundamental to the game is the fact the first player accurately represents the word she has chosen. That way, when the other players guess letters, she can reveal whether that letter is in the word. But what happens if the player doesn't do this? This gives the player who chooses the hidden word an enormous advantage. For example, suppose that you're the player trying to guess the word, and at some point you end up revealing letters until you arrive at this point with only one guess remaining: 

D O – B L E 

There are only two words in the English language that match this pattern: “doable” and “double.” If the player who chose the hidden word is playing fairly, then you have a fifty-fifty chance of winning this game on your next guess if you guess 'A' or 'U' as the missing letter. However, if your opponent is cheating and hasn't actually committed to either word, then there is no possible way you can win this game on that first guess. No matter what letter you guess, your opponent can claim that she had picked the other word. 

That is, if you guess that the word is “doable,” she can pretend that she committed to “double” the whole time, and vice-versa. Let's illustrate this technique with an example. Suppose that you are playing Hangman and it's your turn to choose a word, which we'll assume is of length four. Rather than committing to a secret word, you instead compile a list of every four-letter word in the English language. For simplicity, let's assume that English only has a few four-letter words, all of which are reprinted here: 

ALLY BETA COOL DEAL ELSE FLEW GOOD HOPE IBEX 

Now, suppose that your opponent guesses the letter 'E.' You now need to tell your opponent which letters in the word you've “picked” are E's. Of course, you haven't picked a word, and so you have multiple options about where you reveal the E's. Here's the above word list, with E's highlighted in each word: 

ALLY BETA COOL DEAL ELSE FLEW GOOD HOPE IBEX 

If you'll notice, every word in your word list falls into one of five “word families:” 

- ---- , which contains the words ALLY, COOL, and GOOD. 

- -E-- , containing BETA and DEAL. 

- --E- , containing FLEW and IBEX. 

- E--E , containing ELSE. 

- ---E , containing HOPE. 

Since the letters you reveal have to correspond to some word in your word list, you can choose to reveal any one of the above five families. There are many ways to pick which family to reveal – perhaps you want to steer your opponent toward a smaller family with more obscure words, or toward a larger family in the hopes of keeping your options open. In this assignment, in the interests of simplicity, we'll adopt the latter approach and always choose the largest of the remaining word families. In this case, it means that you should pick the family ---- . This reduces your word list down to 

ALLY COOL GOOD 

and since you didn't reveal any letters, you would tell your opponent that his guess was wrong. 

## Prerequisites

- A string-handling module. (MyString)

- A generic vector module that holds MyString objects.

- An array of generic vectors of MyStrings containing the entire dictionary read from the “dictionary.txt” file. The dictionary file contains an unabridged dictionary with over 120,000 words. The array should hold 30 Vectors of words separated by word lengths 1 to 29, each of which holds MyString objects which each hold a word.

- An AssociativeArray module which allows using MyString data as the “key” or “index” to locate a particular Vector of Mystrings. The AssociativeArray must be implemented using an AVL Tree. There will be no duplicate keys. When a new MyString data item is added to the AssociativeArray, a “key” value (MyString object) will be given. That “key” is located in the AVL tree (or added to the AVL tree), and the data MyString is added to the Vector associated with that “key”. Look-up by “key” yields a Vector of all of the MyString that have been added to the Vector associated with that key.

## Requirements

1. Prompt the user for a word length, re-prompting as necessary until she enters a number such that there's at least one word that's exactly that long. That is, if the user wants to play with words of length -42 or 137, since no English words are that long, you should reprompt her.

2. Prompt the user for a number of guesses, which must be an integer greater than zero. Don't worry about unusually large numbers of guesses – after all, having more than 26 guesses isclearly not going to help your opponent!

3. Prompt the user for whether she wants to have a running total of the number of words remaining in the word list. This completely ruins the illusion of a fair game that you'll be cultivating, but it's quite useful for testing (and grading!)

4. Play a game of Hangman using the Evil Hangman algorithm, as described below:

    a. Select the Vector of all words in the English language whose length matches the input length.

    b. Print out how many guesses the user has remaining, along with any letters the player has guessed and the current blanked-out version of the word. If the user chose earlier to see the number of words remaining, print that out too.

    c. Prompt the user for a single letter guess, re-prompting until the user enters a letter that she hasn't guessed yet. Make sure that the input is exactly one character long and that it's a letter of the alphabet.

    d. Partition the words in the dictionary into groups by word family. The word family is the “key” in the AssociativeArray, and the words (already contained in MyStrings from having been read into the Vector of Vectors of MyStrings initially), are added to the Vector in the AssociativeArray which is associated with the given “key” word family.

    e. Find the most common “word family” in the remaining words, remove all words from the word list that aren't in that family, and report the position of the letters (if any) to the user. If the word family doesn't contain any copies of the letter, subtract a remaining guess from the user.

    f. If the player has run out of guesses, pick a word from the word list and display it as the word that the computer initially “chose.”

    g. If the player correctly guesses the word, congratulate her.

5. Ask if the user wants to play again and loop accordingly.
