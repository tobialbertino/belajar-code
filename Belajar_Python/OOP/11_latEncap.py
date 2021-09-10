class Hero:

    # private class variabel
    __jumlah = 0

    def __init__(self, name, health, attPower, armor):
        self.__name = name
        self.__healthStandar = health
        self.__attPowerStandar = attPower
        self.__armorStandar = armor
        self.__level = 1
        self.__exp = 0

        self.__healthMax = self.__healthStandar * self.__level
        self.__attPower = self.__attPowerStandar * self.__level
        self.__armor = self.__armorStandar * self.__level

        self.__health = self.__healthMax

        Hero.__jumlah += 1

    @property
    def info(self):
        return '{} : \n\tlevel = {} \n\thealth = {}/{} \n\tattack = {} \n\tarmor = {}'.format(self.__name, self.__level, self.__health, self.__healthMax, self.__attPower, self.__armor)

    @property
    def gainEXP(self):
        pass

    @gainEXP.setter
    def gainEXP(self, addExp):
        self.__exp += addExp
        if (self.__exp >= 100):
            print(self.__name, ' level up')
            self.__level += 1
            self.__exp -= 100

            self.__healthMax = self.__healthStandar * self.__level
            self.__attPower = self.__attPowerStandar * self.__level
            self.__armor = self.__armorStandar * self.__level

    def attack(self, musuh):
        self.gainEXP = 50

slardar = Hero('Slardar', 100, 5, 10)
axe = Hero('Axe', 100, 5, 10)
print(slardar.info)

slardar.attack(axe)
slardar.attack(axe)
slardar.attack(axe)

print(slardar.info) 
print(slardar.gainEXP)
