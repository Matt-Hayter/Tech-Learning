# -*- coding: utf-8 -*-
"""
HW 7

Performing latent semantic indexing on a Vector Space Model (doc|freq) example (condensing the VSM)

Finding vector embeddings using the word2vec algorithm

Performing operations using word embeddings generated using the word2vec algorithm from the gensim library

notes: 
    -Loads more info on the Word2Vec Gensim library can be found at https://radimrehurek.com/gensim/models/word2vec.html and https://www.geeksforgeeks.org/python-word-embedding-using-word2vec/
    -Within Gensim's Word2Vec, Can either use pre-trained word-embeddings or your own.
"""

import numpy as np


"""
Applying latent semantic indexing
"""
#Start with VSM for a given corpus
vsm_matrix = np.array([[1, 1, 0, 0],
               [1, 1, 0, 0],
               [0, 0, 1, 1],
               [0, 0, 1, 1],
               [1, 1, 0, 1]])
k = np.linalg.matrix_rank(vsm_matrix)
print("\n", "k Value obtained from numpy.linalg = {}".format(k))
#Perform singular value decomposition on matrix
u, d, v = np.linalg.svd(vsm_matrix)
#Choose left k columns of u and v
U = u[:, :k]
V = v[:, :k]
#Need to convert d array to the diagonals of a matrix of 0s. Then chose top left k rows and columns
D = np.diag(d)[:k, :k]
#Document feature vectors. Matmul multiplies matrices
doc_vectors = np.matmul(U, D)
#Term feature vectors
term_vectors = np.matmul(V, D)

"""
Calculate term similarity with condensed term vectors calculated from a doc-term matrix just derived
Taken from lecturers example
"""
def cos_sim(a, b):
    """
    Calculates the cosine similarity between two vectors
    """
    return np.dot(a, b)/(np.linalg.norm(a)*np.linalg.norm(b))
#Now using condensed term-document matrix
#The order of terms in original doc-freq matrix remain, but now for rows
similarity_i = cos_sim(term_vectors[0], term_vectors[1]) 
similarity_ii = cos_sim(term_vectors[0], term_vectors[3])
print("Similarity i =", similarity_i, "Similarity ii =", similarity_ii)

"""
Using genism's word2vec
Note: word2vec takes sentences as an argument and will calclate word embeddings.
Word embeddings are vector representations of words that can be used for a variety of processing tasks eg. predicting a word given context, finding similarities etc.
These processing algorithms can be accessed through the gensim.models.word2vec library.
"""
from gensim.models import Word2Vec
from nltk.corpus import brown


print("\n")
#Sentences taken as an argument here. Returns a Word2vec model object
brown_model = Word2Vec(brown.sents())
#Returns the top 5 most similar words to "money" within the brown corpus
#wv needed to access "word-vectors" property of the model
print(brown_model.wv.most_similar("money", topn=5))
#Find the cosine similarity between two terms
print(brown_model.wv.similarity("money", "sugar"))

