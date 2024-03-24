"""
HW 5

Word Sense Disambiguation

Using Lesk algorithm (for knowledge based WSD)

Supervised Machine learning for WSD (https://scikit-learn.org/stable/index.html)

notes:
    - numpy arrays generally take up significantly less space, are faster than lists and have more functionality. Prob best to use these from now on.
    - For slight chance of an improved lesk result when using nltk, give a pos tag hint
    - nltk's lesk uses wordnet corpus. It returns the synset for a given word in a context.would take a while. Would use a method outlined at https://scikit-learn.org/stable/index.html
    - Task to design my own Supervised machine learning classifier. Too long, but would use https://scikit-learn.org/stable/index.htm
    - Classifiers use training data to put previously unseen objects into set groups. In clustering, all obbjects are new.
"""

import nltk
import numpy as np



"""
Use of the lesk algoirthm within nltk
In NLTK, a "Synset" is a grouping of synonyms. Some words have multiple synsets (for words with different senses - these are what we're interested in here)
Give ambiguous word and it's context (a list of tokens) and return a Synset with the highest number of overlapping words between context and different definitions within each Synset.
Uses wordnet
"""
context = ["I'm", "sat", "here", "doing", "homework", "in", "the", "library", "on", "a", "chair"]
#Perform the lesk algorithm to find most common synset
synset_with_most_matches = nltk.wsd.lesk(context, "sat")
#Fidn the definition of the synset/sense
most_likely_sense = synset_with_most_matches.definition() #Seems to actually set this wrong -> not perfect
print(synset_with_most_matches, most_likely_sense, "\n")


"""
Find all synsets/sents for a given word
"""
#Returns all the synsets for a given word within wordnet
synsets = nltk.corpus.wordnet.synsets("sat")
for synset in synsets:
    print(synset, synset.definition())
print("\n")
    
"""
Using nltk's lesk with POS tags within wordnet
"""
#Synset and accompanying pos tag pairs, for more info on nltk sents
synsets_pos_pairs = [(synset, synset.pos()) for synset in nltk.corpus.wordnet.synsets("sat")]
for synset in synsets_pos_pairs:
    print(synset[0], synset[0].definition(), ', "{}"'.format(synset[1]))
print("\n")
#Find synset and definition/sent found using nltk's lesk algorithm
print(nltk.wsd.lesk(context, "sat"), nltk.wsd.lesk(context, "sat").definition())
#Find synset and definition/sent found using nltk's lesk algorithm, with a hint of the pos tag
print(nltk.wsd.lesk(context, "sat", pos="v"), nltk.wsd.lesk(context, "sat", pos="v").definition()) # Can see that hint still doesn't give the correct sense!
print("\n")

"""
Test behaviour if there are no matching senses
"""
#Kind of weird matches here...Not perfect but does the job.
print(nltk.wsd.lesk('John loves Mary'.split(), 'loves'), nltk.wsd.lesk('John loves Mary'.split(), 'loves').definition())

"""
Using lesk on another example
"""
Context = "Although X-ray is heavily researched in Japan, it is very difficult to use to draw lines on a chip because\
the X-ray particles are hard to control."
synset = nltk.wsd.lesk(Context.split(), "hard")
sense = synset.definition()
print("\n")
print(sense)









