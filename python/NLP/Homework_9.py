# -*- coding: utf-8 -*-
"""
HW9

Automatic Speech Recognition (ASR)

notes:
    - For python_speech_features and generating a speech recognition system: https://python-speech-features.readthedocs.io/en/latest/
    - Or could use the below method
"""

"""
Building an automatic letter recognition system for "a", "b" and "c"
This is coppied and pasted from lecturers example and uses librosa and skllearn instead of 
python_speech_features and scipy as per the above link.

"""
#Where audio files is a list of audio file paths

# # there are 3 letters (label)
# selected_letters = ['a','b','c']
# # construct a dataset for training and testing
# filenames = []
# labels = []
# for audio in audios:
#   for letter in selected_letters:
#     if letter == audio[:1]:
#       filenames.append(audio)
#       labels.append(letter)

# from librosa.feature import mfcc
# import librosa
# import numpy as np
# # extract mfccs from audio file
# def get_mfcc(audio_file):
#   y, sr = librosa.load(audio_file)
#   feat = mfcc(y=y, sr=sr, n_mfcc=40)
#   return feat

# # we can use the mean of mfccs to train a simple classifier
# features = [np.mean(get_mfcc(a).T,axis=0) for a in filenames]

# from sklearn.model_selection import train_test_split
# from sklearn.metrics import accuracy_score
# # we make 80% for train and 20% for test
# X_train, X_test, y_train, y_test = train_test_split(np.array(features), labels, test_size=0.2, random_state=42,stratify = labels)

# from sklearn.ensemble import RandomForestClassifier
# from sklearn.linear_model import SGDClassifier 
# from sklearn.tree import DecisionTreeClassifier
# from sklearn.pipeline import make_pipeline

# from sklearn.preprocessing import StandardScaler

# # let's try three different classifiers to see how they differ
# rf = RandomForestClassifier(random_state=42)
# svm = make_pipeline(StandardScaler(), SGDClassifier(max_iter=1000, tol=1e-3))
# dt = DecisionTreeClassifier(random_state=42)

# # Random Forest
# rf.fit(X_train,y_train)
# rf.score(X_test,y_test)

# # SVM
# svm.fit(X_train,y_train)
# svm.score(X_test,y_test)

# # Decision Tree
# dt.fit(X_train,y_train)
# dt.score(X_test,y_test)