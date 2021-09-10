class Hero:

    # private class variabel
    __jumlah = 0

    def __init__(self, name):
        self.__name = name
        Hero.__jumlah += 1

    # method ini hanya berlaku pada object
    def getJumlah(self):
        return Hero.__jumlah
    
    # method ini tidak berlaku untuk object, tapi bisa untuk CLASS
    def getJumlah1(self):
        return Hero.__jumlah
    
    # method static (decorator), nempel ke objek dan class
    @staticmethod # tanpa argumen
    def getJumlah2():
        return Hero.__jumlah
    
    @classmethod # menerima argumen
    def getJumlah3(cls):
        return cls.__jumlah
    

sniper = Hero('Sniper')
print(sniper.getJumlah2())
rikimaru = Hero('Rikimaru')
print(sniper.getJumlah2())
drowranger = Hero('Drowranger')
print(Hero.getJumlah3())