# -*- coding: utf-8 -*-
"""
Created on Fri Jul 22 07:28:22 2022

@author: auorr
"""
#libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd



#import data
data = pd.read_csv("Data.csv")

#Split data independent and dependent datasets
x = data.iloc[:, :-1].values
y = data.iloc[:, -1].values

print(x)
print(y)

#Missing data handeler
from sklearn.impute import SimpleImputer
imputer = SimpleImputer(missing_values = np.nan, strategy = 'mean')
imputer.fit(x[:, 1:3])
x[:, 1:3] = imputer.transform(x[:, 1:3])

print(x)


#Encode Independent variable
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder
ct = ColumnTransformer(transformers= [('encoder', OneHotEncoder(), [0])], remainder='passthrough')
x = np.array(ct.fit_transform(x))

print(x)


#Encode Dependent vaiable
from sklearn.preprocessing import LabelEncoder
le = LabelEncoder()
y = le.fit_transform(y)

print(y)


#Split data in Testing and test dataset
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.2, random_state = 1)

print(x_train)
print(x_test)
print(y_train)
print(y_test)


#Feature scaling
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
x_train[:, 3:] = sc.fit_transform(x_train[:,3:])
x_test[:,3:] = sc.transform(x_test[:,3:])

print(x_train)
print(x_test)

