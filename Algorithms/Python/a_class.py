class Animal:
    def __init__(self, name, sciName, classi, kingdom):
        self.__name = name
        self.__sciName = sciName
        self.__classi = classi
        self.__kingdom = kingdom

    #setter for name
    def set_name(self, name):
        self.__name = name

    #setter for scientific name
    def set_sciName(self, sciName):
        self.__sciName = sciName

    #setter for classification
    def set_classi(self, classi):
        self.__classi = classi

    #setter for kingdom
    def set_kingdom(self, kingdom):
        self.__kingdom = kingdom

    #getter for name
    def get_name(self, name):
        return self.__name

    #getter for scientific name
    def get_sciName(self, sciName):
        return self.__sciName

    #getter for classification
    def get_classi(self, classi):
        return self.__classi
        
    #getter for kingdom
    def get_kingdom(self, kingdom):
        return self.__kingdom


    def printData(self):
        print("\nName = " + self.__name)
        print("\nScientific name = " + self.__sciName)
        print("\nClass = " + self.__classi)
        print("\nKingdom = " + self.__kingdom)
        

def main():
    name = "Fly" 
    sciName = "Diptera" 
    classi = "Insecta" 
    kingdom = "Animalia"
    fly = Animal(name, sciName, classi, kingdom)

    

    name = "Lion" 
    sciName = "Panthera leo" 
    classi = "Felidae" 
    kingdom = "Animalia"
    lion = Animal(name, sciName, classi, kingdom)

    fly.printData()
    print("\n\n")
    lion.printData()

main()