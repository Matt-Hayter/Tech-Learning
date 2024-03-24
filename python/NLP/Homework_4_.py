# -*- coding: utf-8 -*-
"""
HW 4

POS Tagging

Stemming with nltk

Using POS tagged corpora


Notes:
    - Always best to use library stemmers (rather than building my own), as they can handle irregular cases. Best to use Porter for supporting search using alt. forms of words
    - Most Corpora come pre-tagged
"""

from nltk.corpus import brown
import nltk


"""
Find the different POS tags for the word "Promised" using Brown
"""
#Returns an array of pairs containing a word and the tag of every word in the corpus
#Universal uses the universal tagset, as some corpuses use different tagsets
tagged_words = brown.tagged_words(tagset = "universal")
promised_tags = []
for i in tagged_words:
    if i[0] == "promised":
        promised_tags.append(i[1])
set_of_promised_tags = set(promised_tags)
print(set_of_promised_tags)

"""
Stem a list of tokens using Porter. Some stems are not valid words (completely fine)
"""
Porter = nltk.PorterStemmer()
fifty_stemmed_words = [Porter.stem(token) for token in list(brown.words())[:50]]
print("\n")
print(fifty_stemmed_words)

"""
If stemmed, lemmatized words that are actual lemmas (real words), WordNet could be used. Not quite as good as Porter but still good,
"""
wnl = nltk.WordNetLemmatizer()
fifty_stemmed_words = [wnl.lemmatize(t) for t in list(brown.words())[:50]]
print("\n")
print(fifty_stemmed_words)

"""
POS tagging a new piece of text
"""
text = nltk.word_tokenize("And now for something completely different")
tagged_text = nltk.pos_tag(text)

"""
.similar() finds similar words in a text, based on the POS context of the word (POS tag before and after)
"""
text = nltk.Text(word.lower() for word in nltk.corpus.brown.words())
similar_words = text.similar('woman')

"""
Creates list of pairs containing words and thei POS tags, from the string below
"""
sent = '''
The/AT grand/JJ jury/NN commented/VBD on/IN a/AT number/NN of/IN
other/AP topics/NNS ,/, AMONG/IN them/PPO the/AT Atlanta/NP and/CC
Fulton/NP-tl County/NN-tl purchasing/VBG departments/NNS which/WDT it/PPS
said/VBD ``/`` ARE/BER well/QL operated/VBN and/CC follow/VB generally/RB
accepted/VBN practices/NNS which/WDT inure/VB to/IN the/AT best/JJT
interest/NN of/IN both/ABX governments/NNS ''/'' ./.
'''
tagged_words = [nltk.tag.str2tuple(t) for t in sent.split()]

"""
Produces a list of tagged sentences, not just words
"""
tagged_sentences = nltk.coprus.brown.tagged_sents()

"""
Creates a frequency distribution of each tag within the tagged brown corpus
"""
brown_news_tagged = brown.tagged_words(categories='news', tagset='universal')
tag_fd = nltk.FreqDist(tag for (word, tag) in brown_news_tagged)

"""
Create list of bigrams in the tagged brown corpus and find most frequent word tags before a noun
"""
word_tag_pairs = nltk.bigrams(brown_news_tagged)
noun_preceders = [a[1] for (a, b) in word_tag_pairs if b[1] == 'NOUN']
fdist = nltk.FreqDist(noun_preceders)
tags = [tag for (tag, _) in fdist.most_common()]

"""
Counting POS tags for a given word
"""
wsj = nltk.corpus.treebank.tagged_words(tagset='universal')
cfd1 = nltk.ConditionalFreqDist(wsj)
pos_taggs = cfd1['yield'].most_common()

"""
Reversing the above pair for most common words for a given POS tag
"""
wsj = nltk.corpus.treebank.tagged_words()
cfd2 = nltk.ConditionalFreqDist((tag, word) for (word, tag) in wsj)
common_words = list(cfd2['VBN'])

"""
For each tag that starts with "NN" (all variations of Nouns), counting word frequencies and printing 
"""
def findtags(tag_prefix, tagged_text):
    cfd = nltk.ConditionalFreqDist((tag, word) for (word, tag) in tagged_text
                                  if tag.startswith(tag_prefix))
    return dict((tag, cfd[tag].most_common(5)) for tag in cfd.conditions())
tagdict = findtags('NN', nltk.corpus.brown.tagged_words(categories='news'))
for tag in sorted(tagdict):
   print(tag, tagdict[tag])







