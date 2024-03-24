# -*- coding: utf-8 -*-
"""
HW 3

Relevance of documents using tf*idf
"""


"""
Finding the most relavent k documents in a corpus, using the highest values of tf*idf
Trying to be as efficient as possible
"""
import nltk
#Corpus being used in first algorithm
from nltk.corpus import gutenberg
from math import log10


class relevant_documents:
    """
    Find relevant documents
    """
    def __init__(self):
        """
        Initialise object
        """
        #Default values
        self.term = "init"
        self.requested_number_of_files = 0
        #Initialise map of file name to tfidf values
        self.document_tfidfs = []
        #This valu's used a few time, so set as member data here
        self.number_of_documents = 0
        
    def user_enter_values(self) -> None:
        #self.term = str(input("Enter the term you would like to search for: "))
        #self.number_of_files = int(input("Enter the number of relevant documents would you like to see: "))
        self.term = "jesus"
        self.requested_number_of_files = 3
                
    def calculate_tf(self, document: str) -> float:
        """
        Calculate term frequency
        """
        #Make all words lower case in the words of a given document
        words = [w.lower() for w in list(gutenberg.words(document))]
        freq_dist = nltk.FreqDist(words)
        tf = freq_dist[self.term]
        return tf
    
    def calculate_tfidfs(self) -> None:
        """
        Calculate term frequency for each file in corpus
        """
        document_tfs = []
        document_count = 0
        self.number_of_documents = len(gutenberg.fileids())
        #More efficient to calculate tf and df in the same loop
        for document in gutenberg.fileids():
            tf = self.calculate_tf(document)
            if tf != 0:
                document_count += 1
            document_tfs.append(tf)
        #Filter out these now so this check does not have to be made on every loop of the next for loop
        if document_count == 0:
            print("This term does not appear in any document")
            return
        counter = 0
        #Fpr tf.idf calculations
        for i in gutenberg.fileids():
            if document_tfs[counter] == 0:
                self.document_tfidfs.append((i, 0))
                counter += 1
                continue
            #Calculate tfidfs and fill array with file name, value pairs
            self.document_tfidfs.append((i, (1 + log10(document_tfs[counter])) * log10(len(gutenberg.fileids())/document_count)))
            counter += 1
        return
    
    def print_most_relevant_documents(self) -> None:
        """
        Rank documents by relevance (depending on tfidfs) and return correct results
        """
        #Sorts in Descending order based on second values of pairs
        self.document_tfidfs.sort(reverse = True, key = lambda x:x[1])
        print("\n")
        print("Most relevant documents in Gutenberg corpus, ranked from most relevant to least: \n")
        #Ensures there are no segmentation faults when accessing files
        if self.requested_number_of_files > self.number_of_documents:
            self.requested_number_of_files = self.number_of_documents
        for i in range(0, self.requested_number_of_files):
            #Print data
            print("Document:", self.document_tfidfs[i][0], ", tf.idf value:", self.document_tfidfs[i][1])

def main():
    """
    Main call function
    """
    #Initialises document object
    documents = relevant_documents()
    documents.user_enter_values()
    documents.calculate_tfidfs()
    documents.print_most_relevant_documents()
    
    
documents = main()