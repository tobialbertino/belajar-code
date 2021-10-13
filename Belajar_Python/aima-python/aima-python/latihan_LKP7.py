# import semua fungsi dari modul
from logic import *

class FolKB(KB):
    """A knowledge base consisting of first-order definite clauses.
    >>> kb0 = FolKB([expr('Farmer(Mac)'), expr('Rabbit(Pete)'),
    ...              expr('(Rabbit(r) & Farmer(f)) ==> Hates(f, r)')])
    >>> kb0.tell(expr('Rabbit(Flopsie)'))
    >>> kb0.retract(expr('Rabbit(Pete)'))
    >>> kb0.ask(expr('Hates(Mac, x)'))[x]
    Flopsie
    >>> kb0.ask(expr('Wife(Pete, x)'))
    False
    """
    def __init__(self, clauses=None):
        super().__init__()
        self.clauses = []  # inefficient: no indexing
        if clauses:
            for clause in clauses:
                self.tell(clause)
    def tell(self, sentence):
        if is_definite_clause(sentence):
            self.clauses.append(sentence)
        else:
            raise Exception('Not a definite clause: {}'.format(sentence))
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

royal_family_kb = FolKB(
    map(expr, ['Man(JamesI)', 'Man(CharlesI)', 'Man(CharlesII)', 'Man(Phillip)',
                'Man(Charles)', 'Man(William)', 'Man(Hendry)', 'Man(Mark)', 
                'Man(Peter)', 'Man(Andrew)', 'Man(Edward)', 'Man(JamesII)',
                'Woman(Margareth)','Woman(Sophia)','Woman(CatherineI)', 'Woman(Elizabeth)', 'Woman(Camila)', 'Woman(Diana)', 'Woman(CatherineII)', 'Woman(Anne)', 'Woman(Zara)', 'Woman(Sarah)', 'Woman(Beatrice)', 'Woman(Eugenie)','Woman(Sophie)', 'Woman(Lady)',
                'Menikah(JamesI, Margareth)', 'Menikah(CharlesI, Sophia)',
                'Menikah(Charles, Diana)', 'Menikah(Phillip, Elizabeth)',
                'Menikah(Charles, Camila)', 'Menikah(William, CatherineII)',
                'Menikah(Andrew, Sarah)', 'Menikah(Mark, Anne)',
                'Menikah(Edward, Sophie)', 
                'Orangtua(JamesI, CharlesI)', 'Orangtua(Margareth, CharlesI)',
                'Orangtua(JamesI, Elizabeth)', 'Orangtua(Margareth, Elizabeth)',
                'Orangtua(CharlesI, CatherineI)', 'Orangtua(Sophia, CatherineI)',
                'Orangtua(CharlesI, CharlesII)', 'Orangtua(Sophia, CharlesII)',
                'Orangtua(CharlesI, JamesII)', 'Orangtua(Sophia, JamesII)',
                'Orangtua(Elizabeth, Charles)', 'Orangtua(Phillip, Charles)',
                'Orangtua(Elizabeth, Anne)', 'Orangtua(Phillip, Anne)',
                'Orangtua(Elizabeth, Andrew)', 'Orangtua(Phillip, Andrew)',
                'Orangtua(Elizabeth, Edward)', 'Orangtua(Phillip, Edward)',
                'Orangtua(Charles, William)', 'Orangtua(Diana, William)',
                'Orangtua(Charles, Hendry)', 'Orangtua(Diana, Hendry)',
                'Orangtua(Anne, Peter)', 'Orangtua(Mark, Peter)',
                'Orangtua(Anne, Zara)', 'Orangtua(Mark, Zara)',
                'Orangtua(Andrew, Beatrice)', 'Orangtua(Sarah, Beatrice)',
                'Orangtua(Andrew, Eugenie)', 'Orangtua(Sarah, Eugenie)',
                'Orangtua(Edward, Lady)', 'Orangtua(Sophie, Lady)',
                # 'Menikah(x,y) ==> (Man(x) & Woman(y))',
                'Orangtua(z,x) ==> Anak(x,z)',
                'Orangtua(x,y) & Woman(x) ==> Ibu(x, y)', 'Orangtua(x,y) & Man(x) ==> Ayah(x, y)',
                'Orangtua(z,x) & Orangtua(z,y) ==> SaudaraKandung(x,y)',
                # 'Anak(x,y) & Anak(z,y) ==> SaudaraKandung(x,z)',
                'SaudaraKandung(x,y) & Woman(x) ==> KakakPerempuan(x,y)',
                'SaudaraKandung(x,y) & Man(x) ==> KakakLakiLaki(x,y)',
                # 'Ayah(x,y) & Menikah(x,z) & (~Ibu(z,y)) ==> IbuTiri(z, y)',
                'Orangtua(x,y) & KakakPerempuan(z,x) ==> TanteKandung(z,y)',
                'Orangtua(x,y) & SaudaraKandung(x,z) & Menikah(z,w) ==> Tante(w,y)',
                'Orangtua(z,y) & SaudaraKandung(x,z) & Man(x) ==> Paman(x,y)',
                # 'Orangtua(x,y) & SaudaraKandung(z,x) & Menikah(w,z) & Man(w) ==> Paman(w,y)',
                'Orangtua(x,y) & SaudaraKandung(x,z) & Orangtua(z,w) ==> Sepupu(y,w)', 
                'Orangtua(x,y) & Sepupu(x,z) & Woman(z) ==> TanteSepupu(z,y)',
                'Orangtua(x,y) & Ayah(z,x) ==> Kakek(z,y)',
                'Orangtua(x,y) & Ibu(z,x) ==> Nenek(z,y)',
                'Ayah(x,y) & Kakek(y,z) ==> KakekBuyut(x,z)',
                'Ibu(x,y) & Nenek(y,z) ==> NenekBuyut(x,z)',
                'KakekBuyut(x,y) & Man(y) ==> Cicit(y,x)', 
                'NenekBuyut(x,y) & Man(y) ==> Cicit(y,x)', 
                'KakekBuyut(x,y) & Woman(y) ==> CicitPerempuan(y,x)', 
                'NenekBuyut(x,y) & Woman(y) ==> CicitPerempuan(y,x)',
                'IbuTiri(Camila, William)', 'IbuTiri(Camila,Hendry)',
                ]))

print("1. Apakah George I adalah ayah dari Charles I?")
print(repr(royal_family_kb.ask_generator('Ayah(GeorgeI, CharlesI)')))

print("2. Siapakah nama ayah Charles I?")
print(repr(royal_family_kb.ask_generator('Ayah(x, CharlesI)')))

print("3. Siapakah nama Ibu Hendry?")
print(repr(royal_family_kb.ask_generator('Ibu(x, Hendry)')))

print("4. Siapakah anak dari Charles?")
print(repr(royal_family_kb.ask_generator('Orangtua(Charles, x)')))

print("5. Apakah Andrew adalah paman William?")
print(repr(royal_family_kb.ask_generator('Paman(Andrew, William)')))

print("6. Siapakah tante Peter?")
print(repr(royal_family_kb.ask_generator('Tante(x, Peter)')))

print("7. Siapakah sepupu Zara?")
print(repr(royal_family_kb.ask_generator('Sepupu(x, Zara)')))

print("8. Siapakah nenek dari William?")
print(repr(royal_family_kb.ask_generator('Nenek(x, William)')))

print("9. Apakah Elizabeth adalah nenek dari William dan Hendry?")
print(repr(royal_family_kb.ask_generator('Nenek(Elizabeth, William)')))
print(repr(royal_family_kb.ask_generator('Nenek(Elizabeth, Hendry)')))

print("10. Siapakah kakek dari Peter?")
print(repr(royal_family_kb.ask_generator('Kakek(x, Peter)')))

print("11. Siapakah ibutiri William?")
print(repr(royal_family_kb.ask_generator('IbuTiri(x, William)')))

print("12. Siapakah abang dari Diana?")
print(repr(royal_family_kb.ask_generator('KakakLakiLaki(x, Diana)')))

print("13. Siapakah kakak dari Andrew?")
print(repr(royal_family_kb.ask_generator('KakakPerempuan(x, Andrew)')))

print("14. Siapakah abang dari James II?")
print(repr(royal_family_kb.ask_generator('KakakLakiLaki(x, JamesII)')))

print("15. Apakah Sarah adalah tante dari Peter?")
print(repr(royal_family_kb.ask_generator('Tante(Sarah, Peter)')))

print("16. Siapakah nenekbuyut dari Hendry?")
print(repr(royal_family_kb.ask_generator('NenekBuyut(x, Hendry)')))

print("17. Siapakah paman dari Charles?")
print(repr(royal_family_kb.ask_generator('Paman(x, Charles)')))

print("18. Apakah Diana adalah ibukandung Hendry?")
print(repr(royal_family_kb.ask_generator('Ibu(Diana, Hendry)')))

print("19. Siapakah sepupu Hendry?")
print(repr(royal_family_kb.ask_generator('Sepupu(x, Hendry)')))

print("20. Siapakah cicitperempuan dari Elizabeth?")
print(repr(royal_family_kb.ask_generator('CicitPerempuan(x, Elizabeth)')))