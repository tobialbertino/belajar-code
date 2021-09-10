'''
program.py
'''
# class mobil otonom
class Mobilotonom(Agent):
    def __init__(self):
        location = 1
# mendefinisikan fungsi accelerate, brake, reverse
    def accelerate(self):
        self.location += 1
    def brake(self):
        self.location += 0
    def reverse(self):
        self.location -= 1
# program sederhana sesuai dengan kondisi
def program(Percept):
    for p in Percept:
        if see_people:
            return brake
        elif see_nothing:
            return accelerate
        elif see_blind_alley:
            return reverse