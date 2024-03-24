# -*- coding: utf-8 -*-
"""
HW2

Accessing Text from the Web and from Disk (parsing)

Regular Expressions for Tokenizing text

Formatting: Lists and strings

Printing formats

Reading/writing to files

Cond. freq. distriibutions with ngrams

General notes:
-Regular experssion symbols in 3.7 at https://www.nltk.org/book/ch03.html
-It's better to use NLTK's regular experssion tokenizer as oppose to the "re" library
-Compare Tokenization results with those of a gold standard (eg. nltk.corpus.treebank_raw.raw() -> nltk.corpus.treebank.words())
 then optimise your tokenisation (through reg. expressions) accordingly
-Cond.freq. functions etc. found in 2.4 at https://www.nltk.org/book/ch02.html
-Functions differ for freq. dist and cond. freq. dist.,even when you're trying to do the same thing, so check if unsure.
-Complete list of corpora within nltk.corpora found at https://www.nltk.org/nltk_data/
"""
#For extracting text from HTML files
import bs4
#For extracting text from a url
from urllib import request
import nltk
#For ngrams function
from nltk.util import ngrams
#For accessing the contents of blogs
import feedparser
#For regular expressions
import re
#For constants etc.
import math
#To handle formatting of text in output 
import textwrap


"""
Import text file from the web as a string
"""
#Example url
#url = "http://www.gutenberg.org/files/2554/2554-0.txt"
#response = request.urlopen(url)
#.decode('utf8') transfers text from unicode format to regular format
#Produces a string
#raw = response.read().decode('utf8')
#print(raw)

"""
Create a list of word tokens from "raw" string
"""
#tokens = nltk.word_tokenize(raw)

"""
Create an NLTK text from these tokens, so it can be processed further
"""
#text = nltk.Text(tokens)

"""
Finding the locatiion of phrases in a string and trim the strim to start and finish accordingly
"""
#First instance of substring "Part I", returning number of chars from beginning
#raw.find("PART I")
#Last instance of substring "End of Project Gutenberg's Crime", returning number of chars from beginning
#raw.rfind("End of Project Gutenberg's Crime")
#raw = raw[raw.find("PART I"):raw.rfind("End of Project Gutenberg's Crime")]

"""
Extracting word tokens from a html file
Most text online is as HTML documents
"""
url = "http://news.bbc.co.uk/2/hi/health/2284783.stm"
html = request.urlopen(url).read().decode('utf8')
#Using the bs4 html parser
raw = bs4.BeautifulSoup(html, 'html.parser').get_text()
tokens = nltk.word_tokenize(raw)

"""
Creating a corpus from an online blog using feedparser anf then bs4
"""
#Parsing the contents of a blog
llog = feedparser.parse("http://languagelog.ldc.upenn.edu/nll/?feed=atom")
#Find the numebr of entries in blog
number_of_entries = len(llog.entries)
#Title of a given post
post_title = llog.entries[2].title
#Creates html document of the ontent of a given post
post_content = llog.entries[2].content[0].value
#Convert from html to list
raw = bs4.BeautifulSoup(post_content, 'html.parser').get_text()
#tokenise as words
tokens = nltk.word_tokenize(raw)

"""
Reading local files
"""
#file = open(...)
#Creates a string with the contents of the file
#Contains \n for new line
#raw = file.read()

"""
Can read local files by line
"""
#file = open(...)
#for line in file:
    #.strip() Removes new line character 
#    print(line.strip())

"""
Can also read nltk's corpora in this way
"""
path = nltk.data.find('corpora/gutenberg/melville-moby_dick.txt')
raw = open(path).read()
#As this method is used, need to tokenise this string
tokens = nltk.word_tokenize(raw)

"""
Create input stream and save a users input to a variable
"""
#usr_input = input("Please input:")

"""
Alternative tokenisiation, this time with apostrophes etc. seperate from words
"""
alt_tokens = nltk.wordpunct_tokenize(raw)

"""
Tokenizing text using regular expressions (specifying delimeters)
Require r prefix (for raw) tells compiler to process text literally (ignore backslash-character special substrings)
"""
#\t means tab, \n means new line
re.split(r'[ \t\n]+', raw) 

"""
re.findall() creates a list of all substrings within raw separated by the regular expression given
"""
#If no instances of any word character, try any non-whitespace character followed by any word character
re.findall(r'\w+|\S\w*', raw)
#More complex example
re.findall(r"\w+(?:[-']\w+)*|'|[-.(]+|\S\w*", raw)

"""
Better to use NLTK's regular expression tokenizer
Use comments for readability.
Special "verbose flag" (?x) indicates that whitespaces and comments should be ignored
Have to use "\s" rather than " " when using the verbose flag
"""
text = text = 'That U.S.A. poster-print costs $12.40...'
#Example of reg. expression pattern
pattern = r'''(?x)             # set flag to allow verbose regexps
          (?:[A-Z]\.)+         # abbreviations, e.g. U.S.A.
          | \w+(?:-\w+)*       # words with optional internal hyphens
          | \$?\d+(?:\.\d+)?%? # currency and percentages, e.g. $12.40, 82%
          | \.\.\.             # ellipsis
          | [][.,;"'?():-_`]   # these are separate tokens; includes ], [
          '''
reg_expression_tokens = nltk.regexp_tokenize(text, pattern)

"""
Converting List to string
In "...".join(), ... can be anything
"""
silly = ["a", "b", "c", "d"]
#Joins list to form one string, separated by a space
string = " ".join(silly)

"""
Displaying a string
"""
word = "word"
print(word)
#Use """ if you want string to be on new line
sentence_on_two_lines = """a 
scentence"""
#Print a new line character
print("\n")
print(sentence_on_two_lines)

"""
Alternative way of printing variables
Can specify what argument of .format() required by {1} etc. if not in order
"""
fdist = nltk.FreqDist(['dog', 'cat', 'dog', 'cat', 'dog', 'snake', 'dog', 'cat'])
for word in sorted(fdist):
    #{} Is replaced by arguments of .format() function
    print('{}->{};'.format(word, fdist[word]), end=' ')
    
"""
Lining up outputs
"""
#Adding padding to outputs 
#Left padding
print('{:6}'.format(41))
#Right padding
print('{:<6}'.format(41))

"""
Formatting a float
"""
#4 digits should be displayed after the decimal point
print('{:.4f}'.format(math.pi))
count, total = 3205, 9375
#Display count/total fraction as a percentage with 4 digits after the decimal point
print("accuracy for {} words: {:.4%}".format(total, count / total))

"""
Writing to a file named ...
Must put all variables in a string format with str(...)
"""
# output_file = open(...)
# words = set(nltk.corpus.genesis.words('english-kjv.txt'))
# for word in sorted(words):
#     #Output each word to output_file
#     print(word, file=output_file)

"""
Avoid output overflowing line
"""
saying = ['After', 'all', 'is', 'said', 'and', 'done', ',',
          'more', 'is', 'said', 'than', 'done', '.']
pieces = ["{} ({})".format(word, len(word)) for word in saying]
output = ' '.join(pieces)
#Formats output so it fits
wrapped = textwrap.fill(output)
print(wrapped)
#Same as above but ensuring the length of the word is on the sam line as the word
pieces = ["{}_({})".format(word, len(word)) for word in saying]
output = " ".join(pieces)
wrapped = textwrap.fill(output)
#Replace _ with a space and print
print(wrapped.replace("_", " "))
print("\n")

"""
Genereating bigrams and trigrams from a corpus, exculding punctuation.
As punctuation was not wanted, a new list was created excluding it
"""
#This includes punctuation, and we don't want this.
words_of_brown = list(nltk.corpus.brown.words())
print(words_of_brown[:60], "\n")
#Declare empty list
word_only_tokens = []
#Removes all entries that are purely punctuation
for token in words_of_brown:
    if re.search("\w+", token):
        word_only_tokens.append(token)
print(word_only_tokens[:60], "\n")
#use below for ngrams
#Second argument is for "n"
bigrams = list(ngrams(word_only_tokens, 2))
trigrams = list(ngrams(word_only_tokens, 3))

"""
Generating text from frequent bigrams
"""
text = list(nltk.corpus.genesis.words('english-kjv.txt'))
#Make text lower case
lower_case_text = []
for i in range(len(text)):
    lower_case_text.append(text[i].lower())
bigrams = nltk.bigrams(text)
#Creates cond.freq.dist for bigrams, hence enabling us to find most frequent bigrams
cfd = nltk.ConditionalFreqDist(bigrams)
#Creates random text from most frequent bigrams in the above corpus
def generate_text(cond_freq_dist, word):
    for i in  range(15):
        print(word, " ")
        #Set next word as the second element of the most frequent word pair from within text
        #The condition is set as word, of which there will be multiple tallies. We want the largest tally
        #This returns the second element of pair
        word = cfd[word].max()      
generate_text(cfd, "living")

"""
Comparing the likeihood of two sentences appearing, based on ngram frequencies in a given text.
These are based off the unigram and n-gram model formulae for probabilities
Sentence 1 = "I saw a girl running yesterday"
Sentence 2 = "I saw a rabbit flying yesterday"
Using unigrams:
"""
sentence_one = "I saw a girl running yesterday"
sentence_two = "I saw a rabbit flying yesterday"
text = list(nltk.corpus.genesis.words("english-kjv.txt"))
unigrams = ngrams(text, 1)
freq_dist =  nltk.FreqDist(unigrams)
denominator = 0
#Calculating the denominator as per the formula
for word in freq_dist:
    denominator += freq_dist[word] + 1
#Now for the numerator
word_lists = [nltk.word_tokenize(sentence_one), nltk.word_tokenize(sentence_two)]
#Starting value for prob'
probability_of_sentence = 1
sentence_probabilities = []
print("\n")
print("Using unigram model:")
for word_list in word_lists:
    for word in word_list:
        numerator = freq_dist.freq(word) + 1
        probability_of_sentence = probability_of_sentence * (numerator/denominator)
    sentence_probabilities.append(probability_of_sentence)
    print("prob of sentence =","{:.90f}".format(probability_of_sentence))

"""
Same as above for Bigrams:
(Not sure how to handle the first word in the sentence so didn't calc prob for it directly)
"""
sentence_one = "I saw a girl running yesterday"
sentence_two = "I saw a rabbit flying yesterday"
text = list(nltk.corpus.brown.words())
bigrams = ngrams(text, 2)
#Create conditional freq. dist using bigram pairs
cond_freq_dist = nltk.ConditionalFreqDist(bigrams)
word_lists = [nltk.word_tokenize(sentence_one), nltk.word_tokenize(sentence_two)]
#starting value for prob.
prob_of_sentence = 1
denominator = 0
print("\n")
print("Using bigram model:")
#Loop for two sentences
for word_list in word_lists:
    word_counter = 0
    #Loop through each word in each sentence
    for word in word_list:
        #Don't perform calculation for first word in sentence
        if word_counter != 0:
            #Counts for specific bigram in sentence
            numerator_counts = cond_freq_dist[word_list[word_counter -1]][word]
            #Sum up all counts for bigrams that have a first item of the pair that is the same as this one here
            for second_value_of_pair in cond_freq_dist[word_list[word_counter -1]]:
                #Value to the right of denominator gives the frequency count for a given pair
                #Note that .freq() is not required with conditional freq. dists
                denominator = denominator + cond_freq_dist[word_list[word_counter -1]][second_value_of_pair]
            prob_of_word = numerator/denominator
            prob_of_sentence = prob_of_sentence * prob_of_word
        #reset denominator for next word
        denominator = 0
        word_counter = word_counter + 1
    print("prob of sentence =","{:.90f}".format(prob_of_sentence))
            






        
    
    
    


