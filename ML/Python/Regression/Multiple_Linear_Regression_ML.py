# -*- coding: utf-8 -*-
"""
Created on Thu Jul 28 05:50:26 2022

@author: auorr
"""

#Libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#import data
data = pd.read_csv('50_Startups.csv')
x = data.iloc[:,:-1].values
y = data.iloc[:,-1].values

#Encode Independent variable
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder
ct = ColumnTransformer(transformers= [('encoder', OneHotEncoder(), [3])], remainder='passthrough')
x = np.array(ct.fit_transform(x))

#Split Data Train and Test datasets
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=0)

#Train Model
from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(x_train, y_train)

#Test Model
y_pred = regressor.predict(x_test)
np.set_printoptions(precision=2)
print(np.concatenate((y_pred.reshape(len(y_pred), 1), y_test.reshape(len(y_test), 1)), 1))

#Evaluate Model Preformance
from sklearn.metrics import r2_score
print(r2_score(y_test, y_pred))

