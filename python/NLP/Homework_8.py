# -*- coding: utf-8 -*-
"""
HW8

The librosa library for handling input audio signals

Fourier transforms to produce spectrograms using the STFT (Short-time fourier transform)

Producing waveforms from an audio file

Finding google drives and finding paths on Linux

Notes:
    - Info on the librosa.stft library: https://librosa.org/doc/0.8.0/generated/librosa.stft.html
    - For a given amplitude a function in time will have a given value of time, and the fourier transform of this function in f
      requency will have a given frequency value. These values are plotted in a contour plot, with freq vs time for each amplitude
"""

import librosa
#For specshow
import librosa.display
import numpy as np
import matplotlib.pyplot as plt
import os
#For displaying playable sound files in terminal
import IPython.display as ipd

"""
STFT represents a signal in the time frequency domain and returns a complex-valued matrix, which can be used
to calculate various values (eg. frequency at t)
The STFT can then be used to plot a spectrogram
"""
#y is a real-valued n-dimensional array representation of the input signal
#.load(.ex()) acceses the librosa database of voice vocal samples
y, sr = librosa.load(librosa.ex('trumpet'))
#Finds the magnitude of frequencies f at times t (positive values of all freqs that match the same amp at t)
S = np.abs(librosa.stft(y))
print(S)
#display spectrogram
fig, axes = plt.subplots(figsize = (9, 6))
#specshow() creates plot of spectrogram and adds is to ax
spectrogram = librosa.display.specshow(librosa.amplitude_to_db(S, ref=np.max),y_axis='log', x_axis='time', ax=axes)
axes.set_title('Power spectrogram')
fig.colorbar(spectrogram, ax=axes, format="%+2.0f dB")

"""
Example using STFT with my own sample + more librosa functionality
"""
#Below is for if I want to use a hardrive located on google drive
# mount my google drive for loading files directly from google drive
# from google.colab import drive
# drive.mount('/content/drive/')

#This is for I was on Linux, to correctly adjust path names to find Unix-style
# import glob
# # find the all wav files in th dir
#** Means any (more than one if necessary) paths
# wav_audios = glob.glob('**/*.wav',recursive = True)
# mp3_audios = glob.glob('**/*.mp3',recursive = True)

sample_path = "C:/Users/Student/OneDrive - The University of Manchester/CODE/Python/NLP/Spectrogram_samples/clicks.wav"
#Loads the first 2 seconds of the sample
y, sr = librosa.load(sample_path, duration = 2)
#Loads audio into ipython and should output to terminal? Can't get it working
print("\n",  ipd.Audio(y, rate=sr))
fig, axes1 = plt.subplots(figsize = (8, 6))
#Generates sound wave amp against time from a sound file
librosa.display.waveplot(y, sr=sr)
fig, axes2 = plt.subplots(figsize = (8, 6))
f = np.abs(librosa.stft(y))
spectrogram = librosa.display.specshow(librosa.amplitude_to_db(f, ref=np.max), y_axis='log', x_axis='time', ax=axes2)
fig.colorbar(spectrogram, ax=axes2, format="%+2.0f dB")





