
"""
Example was provided by: Polycode
URL: https://www.youtube.com/watch?v=kft1AJ9WVDk

My 1st attempt in Machine Learning
This demonstrates how a neuro-network learns.
No hidden layers are included for the simplicity

     |        Inputs         |     Outputs
-----|-------|-------|-------|-------------------
Ex 1 |   0   |   0   |   1   |        0
Ex 2 |   1   |   1   |   1   |        1
Ex 3 |   1   |   0   |   1   |        1
Ex 4 |   0   |   1   |   1   |        0

Do the following:

Ex 5 |   1   |   0   |   0   |        1 

Explanation of Ex5:

Upon looking at Examples 1 to 4 I realized that the output sole depends on the first collumn of any of the examples.
When looking at "Ex 1 |   0   |   0   |   1   |        0" and  "Ex 4 |   0   |   1   |   1   |        0" you'll notice
that the middle input has no influence on the output. 
Moving on to "Ex 2 |   1   |   1   |   1   |        1" and "Ex 3 |   1   |   0   |   1   |        1", notice how the outputs
are both now 1 when the first input is "1". 
Within this example the third input has always been "1" so it is known if results are dependent on it when combined with
the first input. For example, both gates must be on for an output of one (like an AND gate).

A neuronetwork consists of:

Inputs | Synapses |          Neuron            |   Output
_______________________________________________________________
           w.1
x.1 ------------->              ------------->      
           w.2
x.2 ------------->    NEURON    ------------->        y
           w.3          ^
x.3 ------------->      |       ------------->   
                        |
            Use math to figure out what's    
               happening in the NEURON 

                    Let n = # of inputs

                    n SUMM i = 1 (x.i*w.i) = x.1*w.1 + x.2*w.2 + x.3*w.3

                      where PHI = normalization of the function

                   
                    Sigmoid Normalization Function:
                        Tries to NORMALIZATIZE the data from the input, so that it can be represented in
                        an easier format (through averaging, kind of like normal-bell curve).

                        Sigmoid Normalization ensure you have an intersection when x = 0 you'd have a 0.5 amplitude
                        and the graph always caps at -1 and 1.
                    
                        PHI(z) = 1/(1+e^-z) -------> PHI(z = { n SUMM i = 1 (x.i*w.i) }) 
                                                        = 1/(1+e^-{n SUM i = 1 [x.i*w.i]})
"""

#Coding Part 1

import numpy as np

#our normalization function
def sigmoid(z):
    return 1/(1 + np.exp(-z)) # Sigmoid Normalization function = PHI(z) = 1/(1+e^-z)

def sigmoid_derivative(x):
    return x * (1-x)

#inputs for training our machine
#our inputs will just be like the table above with Ex. 1-4
training_inputs = np.array([
                            [0,0,1],
                            [1,1,1],
                            [1,0,1],
                            [0,1,1]
                                   ])

#we're letting the machine know the outcome of our output
#so the results are already known
#meaning this is a supervised machine-learning
training_outputs = np.array([[0,1,1,0]]).T  #.T means to transpose

#seeding random values for our weights
np.random.seed(1)

synaptic_weights = 2 * np.random.random((3,1))-1

print('\nRandom starting synaptic weights: ')
print(synaptic_weights)

#our for loop starting at 1
for iteration in range(1):
    input_layer = training_inputs
    
    outputs = sigmoid(np.dot(input_layer, synaptic_weights))

    #calculates errors here
    error = training_outputs - outputs

    #calculates for adjustments (midigates the error)
    adjustments = error * sigmoid_derivative(outputs)

    synaptic_weights += np.dot(input_layer.T, adjustments)

#prints results from input
print('\nSynaptic weights after training: ')
print(synaptic_weights)
print('\nOutputs after trainning: ')
print(outputs)