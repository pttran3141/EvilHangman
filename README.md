# Evil Hangman

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

Let's see a few more examples of this strategy. Given this three-word word list, if your opponent guesses the letter O, then you would break your word list down into two families: 

- -OO- , containing COOL and GOOD. 

- ---- , containing ALLY. 

The first of these families is larger than the second, and so you choose it, revealing two O's in the word and reducing your list down to 

COOL GOOD 

But what happens if your opponent guesses a letter that doesn't appear anywhere in your words list? For example, what happens if your opponent now guesses 'T'? This isn't a problem. If you try splitting these words apart into word families, you'll find that there's only one family – the family - OO - in which T appears nowhere and which contains both COOL and GOOD. Since there is only one word family here, it's trivially the largest family, and by picking it you'd maintain the word list you already had. 

There are two possible outcomes of this game. First, your opponent might be smart enough to pare the word list down to one word and then guess what that word is. In this case, you should congratulate him – that's an impressive feat considering the scheming you were up to! Second, and by far the most common case, your opponent will be completely stumped and will run out of guesses. When this happens, you can pick any word you'd like from your list and say it's the word that you had chosen all along. The beauty of this setup is that your opponent will have no way of knowing that you were dodging guesses the whole time – it looks like you simply picked an unusual word and stuck with it the whole way.
