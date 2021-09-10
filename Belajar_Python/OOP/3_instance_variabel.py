class Hero: # template
    # class variabel
    jumlah = 0
    def __init__(self, inputName, inputHealth, inputPower, inputArmor):
        # instance variabel
        self.name = inputName
        self.health = inputHealth
        self.power = inputPower
        self.armor = inputArmor
        Hero.jumlah += 1
        print('membuat hero dengan nama ', inputName)


hero1 = Hero('sniper', 100, 10, 4)
hero2 = Hero('mirane', 100, 15, 1)
hero3 = Hero('ucup', 1000, 100, 0)

print(hero1.__dict__)
print(hero2.__dict__)
print(hero3.__dict__)
print(Hero.__dict__)
print(Hero.jumlah)