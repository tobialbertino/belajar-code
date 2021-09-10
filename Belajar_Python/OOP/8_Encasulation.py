class Hero:
    def __init__(self, name, health, attackPower):
        self.__name = name
        self.__health = health
        self.__attPower = attackPower
    
    # getter 
    def getName(self):
        return self.__name
    def getHealth(self):
        return self.__health

    # setter 
    def diSerang(self, serangPower):
        self.__health -= serangPower
    def setAttPower(self, nilaiBaru):
        self.__attPower = nilaiBaru
        
# awal dari game 
earthhaker = Hero('EarthShaker', 50, 5)
# print(earthhaker.__dict__)
# game berjalan 
print(earthhaker.getName())
print(earthhaker.getHealth())
earthhaker.diSerang(5)
print(earthhaker.getHealth())