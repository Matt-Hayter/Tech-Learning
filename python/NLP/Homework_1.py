"""
HW1

Get failiar with NLTK

Regular expressions

Frequency distributions

Conditional frequency distributions


General notes:
- All functions in FreqDist library found in https://www.nltk.org/book/ch01.html under 3.4
- Library functions for nltk.corpus are listed in section 1.8 in https://www.nltk.org/book/ch02.html
- The structures of the corpora contained in the nltk.corpora library are listed in section 1 in https://www.nltk.org/book/ch02.html
  Corpora can have different structures
- Info on loading new corpus libraries  found in section 1.9 at https://www.nltk.org/book/ch02.html
- Regular experssions are found at https://www.nltk.org/book/ch03.html#sec-regular-expressions-word-patterns
"""


import nltk
import nltk.corpus
import nltk.book
from nltk.corpus import PlaintextCorpusReader
#For regular expressions
#import re

text = nltk.corpus.reuters.words()

"""
prints texts within book library
"""
book_texts = nltk.book.texts()

"""
create frequency distribusion of words
"""
freq_dist = nltk.FreqDist(text)
for i in freq_dist:
    print(freq_dist[i])

"""
50 most frequent tokens
"""
fifty_most_freq = freq_dist.most_common(50)

"""
plot cumulative distribution for 50 most frequent tokens
"""
freq_dist.plot(50, cumulative =True)

"""
Find happaxes
hapaxes are words that occur only once. Lots of them!
"""
hapaxes = freq_dist.hapaxes()

"""
Can select words
long words example here
Finding all words within text that have a length greater than 15 and print list
"""
long_words = [w for w in set(text) if len(w) > 15]
print(long_words)

"""
More complicated version of above plus a freq. dist of word to be larger than 5
can acces element of a list with [value] or [indentation]
Sorted in order
"""
long_words = sorted(w for w in set(text) if len(w) > 15 and freq_dist[w] > 5)
print(long_words)

"""
Create a list of bigrams from the given words and print
Bigrams are **consecutive word pairs
.bigrams() takes a list and makes **consecutive word pairs
"""
bigrams = list(nltk.bigrams(['more', 'is', 'said', 'than', 'done', "."]))
print(bigrams)

"""
Find and print collocations in text
For some reason this isn't working with text (part of the NLTK corpa)'
Collocations are words that appear together unusally often
"""
nltk.book.text5.collocations()

"""
Find the frequency of the most common word length
Square brackets required to create list of lengths
"""
list_of_lengths = [len(w) for w in text]
freq_dist_of_word_lengths = nltk.FreqDist(list_of_lengths)
most_frequent_length = freq_dist_of_word_lengths.max()
frequency_of_most_frequent_length = freq_dist_of_word_lengths.freq(most_frequent_length)
print(frequency_of_most_frequent_length)

"""
Top creates and prints the length of set of lower case words in text5
Bottom creates a list of a set of words in text5, then making each element lower case and printing the length
Hence the bottom will have some duplicates in the list
"""
print(len(set(w.lower() for w in nltk.book.text5)))
print(len([w.lower() for w in set(nltk.book.text5)]))

"""
Print built in functionalities for corpus processing
"""
help(nltk.corpus.reader)

"""
Conditional frequency distribution - collection of freq.dists each one for a different condition eg.
category of text
Each condition needs to be paired with a given event (word) to find the freq dist eg.
("news", "a"), ("news", "yes"). Each will have a different frequency 
Form is: ("condition", "counted_data")

Counting words by genre
ConditionalFreqDist() takes a list of pairs as an input from which it will count the frequencies of each
pair for each category
"""
cond_freq_dist = nltk.ConditionalFreqDist((genre, word)
                                          for genre in nltk.corpus.brown.categories()
                                              for word in nltk.corpus.brown.words())

"""
Creates a list of conditions belonging to eacg frequency distribution
"""
cond_freq_dist.conditions()

"""
Another example of cond. distributions
For each file in each inaugural corpus, counting the number of times "america" or "citizen" is said.
Taking the first four digits of the file name (or file_id), being the file date
"""
cond_freq_dist = nltk.ConditionalFreqDist((condition, file_id[:4])
                                          for file_id in nltk.corpus.inaugural.fileids()
                                              for w in nltk.corpus.inaugural.words(file_id)
                                                  for condition in ["america", "citizen"]
                                                      #If this is True, count file date for given above condition
                                                      if w.lower().startswith(condition))

#Plots these freq. dists on the same graph
cond_freq_dist.plot(conditions = ["america", "citizen"])

"""
Tabulate function prints a table as oppose to a  graph
"""
cond_freq_dist.tabulate(conditions = ["america", "citizen"], cumulative = True)

"""
Regular expressions and detecting word patterns
.endswith("...") and .startswith("...") can be used when searching for words
.search function is a member of the "re" library
"ed$" means "ed" at the end of the word
"^" catches the start of the string
"." wildcard means any character
"?" means previous character is optional
"[abc]" means any of these characters
"[g-o]" means any letter from g to o in the alphabet
"+" means one or more instances of the preceeding item
"*" means 0 or more instances of the preceeding item
"[^abc]" means any characters other than a,b or c
"\" means that the following character is deprived of it's special function and must be exactly matched
? means 0 or more of the prev. item
?: specifies a non-capturing parenthesis (?:...) 
...: means the same as above for any special repeat-count character?
\t meas tab and \n means new line
\w can be used for [a-zA-Z0-9_]
\W used for the opposite of the above (anything other than word characters or underscore)
\s means whitespace character (or " "). Can't use " " if your using the verbose flag'
\S means non-whitespace character
| means "or"
(?x) is the verbose flag (see HW2).
The rest are found at https://www.nltk.org/book/ch03.html#sec-regular-expressions-word-patterns
"""
#Two .words here as the corpus in named "words"
wordlist = [w for w in nltk.corpus.words.words("en") if w.islower()]
Prints all words ending with "ed". re .search looks for the left in the right. re.search returns boolean 
print([w for w in wordlist if re.search("ed$", w)])
Prints all words starting with "a", with any characters for the next two until "t"
print([w for w in wordlist if re.search("^a..t", w)])

"""
Add a tonne of new corpora to NLTK's corpora library
"""
#folder containing loads of corpus
corpus_root = "\\Users\\Student\\OneDrive - The University of Manchester\\CODE\\Python\\NLP\\NLTK Corpora"
#searching the above directory plus ANY files/folders (see regular experssion above)
new_corpora = PlaintextCorpusReader(corpus_root, ".+")

"""
The "words" corpus is just a list of words. It could be used as a comparison cprous eg.
spellcheck, or in this case to find unusual words that are in a text:
"""
def unusual_words(text):
    #.isalpha() returns true if all characters are in the alphabet
    text_vocab = set(w.lower() for w in text if w.isalpha())
    english_vocab = set(w.lower() for w in nltk.corpus.words.words())
    unusual = text_vocab - english_vocab
    return sorted(unusual)
#Print unusualy words, not within the "words" corpus
print(len(unusual_words(nltk.book.text5)))
#Compared with all words in the text (obvs more)
print(len(set(w.lower() for w in nltk.book.text5 if w.isalpha())))

"""
To filter out common words, want to compare against the stop words corpus. These can often make it through
with solely the method above
"""
#Only one category we're searching here, so no need for "categories = [...,...]"
print(nltk.corpus.stopwords.words("english"))









