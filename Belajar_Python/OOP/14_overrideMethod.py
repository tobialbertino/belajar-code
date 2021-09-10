class Hero:
    def __init__(self, name, health):
        self.name = name
        self.health = health
    
    def showInfo(self):
        print('show info Class Hero')
        print("{} \n\tHealth: {}".format(self.name, self.health))

class Hero_intelligent(Hero):
    def __init__(self, name):
        super().__init__(name, 100)

    # override
    def showInfo(self):
        print('show info subClass')
        print('{} \n\tTipe: intelligent, \n\tHealth: {}'.format(
            self.name, self.health))

class Hero_strength(Hero):
    def __init__(self, name):
        super().__init__(name, 200)


lina = Hero_intelligent('Lina')
axe = Hero_strength('Axe')

axe.showInfo()
