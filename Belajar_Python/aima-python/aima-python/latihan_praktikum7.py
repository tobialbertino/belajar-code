from logic import *

class FolKB(KB):
    def __init__(self, initial_clauses=[]):
        self.clauses = []  # inefficient: no indexing
        for clause in initial_clauses:
            self.tell(clause)
    def tell(self, sentence):
        if is_definite_clause(sentence):
            self.clauses.append(sentence)
        else:
            raise Exception("Not a definite clause: {}".format(sentence))
    def ask_generator(self, query):
        q = expr(query)
        test_variables = variables(q)
        answers = fol_bc_ask(self, q)
        return sorted([dict((x, v) for x, v in list(a.items())
                            if x in test_variables)
                            for a in answers], key=repr)
    def retract(self, sentence):
        self.clauses.remove(sentence)
    def fetch_rules_for_goal(self, goal):
        return self.clauses


test_kb = FolKB(
    map(expr, ['Farmer(Mac)',
                'Rabbit(Pete)',
                'Mother(MrsMac, Mac)',
                'Mother(MrsRabbit, Pete)',
                '(Rabbit(r) & Farmer(f)) ==> Hates(f, r)',
                '(Mother(m, c)) ==> Loves(m, c)',
                '(Mother(m, r) & Rabbit(r)) ==> Rabbit(m)',
                '(Farmer(f)) ==> Human(f)',
                '(Mother(m, h) & Human(h)) ==> Human(m)']
        ))

# Pertanyaan-pertanyaan tersebut dapat kita tuliskan sebagai berikut :
print(repr(test_kb.ask_generator('Human(x)')))
#Output:[{x: Mac}, {x: MrsMac}]
print(repr(test_kb.ask_generator('Farmer(y)')))
#Output:[{y: Mac}]
print(repr(test_kb.ask_generator('Rabbit(z)')))
#Output: [{z: MrsRabbit}, {z: Pete}]
print(repr(test_kb.ask_generator('Loves(x,y)'))) 
#Output: [{x: MrsMac, y: Mac}, {x: MrsRabbit, y: Pete}]
print(repr(test_kb.ask_generator('Rabbit(MrsMac)')))
# [] # false
print(repr(test_kb.ask_generator('Rabbit(MrsRabbit)')))
# [{}] # true

crime_kb = FolKB(
    map(expr, ['(American(x) & Weapon(y) & Sells(x, y, z) & Hostile(z)) ==> Criminal(x)',
                'Owns(Nono, M1)',
                'Missile(M1)', '(Missile(x) & Owns(Nono, x)) ==> Sells(West, x, Nono)',
                'Missile(x) ==> Weapon(x)',
                'Enemy(x, America) ==> Hostile(x)',
                'American(West)',
                'Enemy(Nono, America)']))
print(repr(crime_kb.ask_generator('Criminal(x)')))
#Output: [{x: West}]
print(repr(crime_kb.ask_generator('Weapon(x)')))
#Output: [{x: M1}]
