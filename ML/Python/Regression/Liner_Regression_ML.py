# -*- coding: utf-8 -*-
"""
Created on Wed Jul 27 13:31:49 2022

@author: auorr
"""

#libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Import data
data = pd.read_csv('Salary_Data.csv')
x = data.iloc[:, :-1].values
y = data.iloc[:,-1].values

#Split up data Training and test datasets
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.2, random_state=0)

#Train Linear regression model 
from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(x_train, y_train)

#Predict Test dataset
y_pred = regressor.predict(x_test)

#Training dataset visualization
plt.scatter(x_train, y_train, color = 'red')
plt.plot(x_train, regressor.predict(x_train), color = 'blue')
plt.title('Salary vs Experience (Training Set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()

#Test dataset visualization
plt.scatter(x_test, y_test, color = 'red')
plt.plot(x_train, regressor.predict(x_train), color = 'blue')
plt.title('Salary vs Experience (Test Set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()

#Evaluate Model Preformance
from sklearn.metrics import r2_score
print(r2_score(y_test, y_pred))