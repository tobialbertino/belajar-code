from logic import *

# Override class FolKB untuk menyesuaikan fungsi yg ada
class FolKB(KB):
    def __init__(self, initial_clauses=[]):
        self.clauses = [] # inefficient: no indexing
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

# deklerasi sesuai dengan silsilah keluarga
family_KB = FolKB(
    map(expr, ['Laki(James_I)', 'Laki(Charles_I)', 'Laki(Phillip)', 'Laki(Charles_II)', 'Laki(James_II)', 'Laki(Charles)',
                    'Laki(Mark)', 'Laki(Andrew)', 'Laki(Erdward)', 'Laki(William)', 'Laki(Hendry)', 'Laki(Peter)',
                'Wanita(Margareth)', 'Wanita(Sophia)', 'Wanita(Elizabeth)', 'Wanita(Catherine_I)', 'Wanita(Camila)', 'Wanita(Diana)',
                    'Wanita(Anne)', 'Wanita(Sarah)', 'Wanita(Sophie)', 'Wanita(Catherine_II)', 'Wanita(Zara)', 'Wanita(Beatrice)',
                    'Wanita(Eugenie)', 'Wanita(Lady)',

                '(Orangtua(m,x) & Wanita(m)) ==> Ibu(m, x)',
                '(Orangtua(f,x) & Laki(f)) ==> Ayah(f, x)',
                'Orangtua(James_I, Charles_I)', 'Orangtua(Margareth, Charles_I)', 'Orangtua(James_I, Elizabeth)', 'Orangtua(Margareth, Elizabeth)',
                    'Orangtua(Charles_I, Catherine_I)', 'Orangtua(Charles_I, Charles_II)', 'Orangtua(Charles_I, James_II)',
                    'Orangtua(Sophia, Catherine_I)', 'Orangtua(Sophia, Charles_II)', 'Orangtua(Sophia, James_II)',
                    'Orangtua(Elizabeth, Charles)', 'Orangtua(Elizabeth, Anne)', 'Orangtua(Elizabeth, Andrew)', 'Orangtua(Elizabeth, Edward)',
                    'Orangtua(Phillip, Charles)', 'Orangtua(Phillip, Anne)', 'Orangtua(Phillip, Andrew)', 'Orangtua(Phillip, Edward)',
                    'Orangtua(Charles, William)', 'Orangtua(Charles, Hendry)', 'Orangtua(Diana, William)', 'Orangtua(Diana, Hendry)',
                    'Orangtua(Anne, Peter)', 'Orangtua(Anne, Zara)', 'Orangtua(Mark, Peter)', 'Orangtua(Mark, Zara)',
                    'Orangtua(Andrew, Beatrice)', 'Orangtua(Andrew, Eugenie)', 'Orangtua(Sarah, Beatrice)', 'Orangtua(Sarah, Eugenie)',
                    'Orangtua(Edward, Lady)', 'Orangtua(Sophie, Lady)',

                'Menikah(James_I, Margareth)', 'Menikah(Charles_I, Sophia)', 'Menikah(Elizabeth, Phillip)',
                    'Menikah(Charles, Diana)', 'Menikah(Charles, Camila)', 'Menikah(Anne, Mark)', 'Menikah(Andrew, Sarah)', 'Menikah(Edward, Sophie)',
                    'Menikah(William, Catherine_II)',
                'IbuTiri(Camila, William)', 'IbuTiri(Camila, Hendry)',
                'Orangtua(p,x)& Orangtua(p,y) ==> SaudaraKandung(x,y)',

                '(SaudaraKandung(x,y)& Wanita(y)) ==> KakakPerempuan(y,x)',
                '(SaudaraKandung(x,y) & Laki(y)) ==> KakakLaki(y,x)',
                '(Orangtua(p,x) & SaudaraKandung(p,tk)) ==> TanteKandung(tk,x)',
                '(Orangtua(p,x) & SaudaraKandung(p,pm) & Menikah(pm,t) & Wanita(t)) ==> Tante(t,x)',
                '(Orangtua(pr,x) & SaudaraKandung(pr,pm) & Laki(pm)) ==> Paman(pm,x)',
                '(Kakek(k,x) & SaudaraKandung(k,ks) & Orangtua(ks,ts)& Wanita(ts)) ==> TanteSepupu(ts,x)',
                '(Orangtua(p,x) & Orangtua(p2,p) & Orangtua(kb,p2) & Laki(kb)) ==> KakekBuyut(kb,x)',
                '(Orangtua(p,x) & Orangtua(k,p) & Laki(k)) ==> Kakek(k,x)',
                '(Orangtua(p,x) & Orangtua(n,p) & Wanita(n))==> Nenek(n,x)',
                '(Orangtua(p,x) & SaudaraKandung(p,pm) & Orangtua(pm,u)) ==> Sepupu(u,x)',
                '(Orangtua(p,x) & Orangtua(p2,p) & Orangtua(nb,p2) & Wanita(nb)) ==> NenekBuyut(nb,x)',
                '(Orangtua(p,x) & Orangtua(p2,p) & Orangtua(p3,p2)) ==> Cicit(x,p3)',
                '(Orangtua(p,x) & Orangtua(p2,p) & Orangtua(p3,p2) & Wanita(x)) ==> CicitPerempuan(x,p3)' ]))

print("1. Apakah George I adalah ayah dari Charles I?")
print(repr(family_KB.ask_generator('Ayah(George_I,Charles_I)')))
#Output:[]

print("2. Siapakah nama ayah Charles I?")
print(repr(family_KB.ask_generator('Ayah(x,Charles_I)')))
#Output:[{x: James_I}]

print("3. Siapakah nama Ibu Hendry?")
print(repr(family_KB.ask_generator('Ibu(x,Hendry)')))
#Output:[{x: Diana}]

print("4. Siapakah anak dari Charles?")
print(repr(family_KB.ask_generator('Ayah(Charles,x)')))
#Output:[{x: Hendry}, {x: William}]

print("5. Apakah Andrew adalah paman William?")
print(repr(family_KB.ask_generator('Paman(Andrew,William)')))
#Output:[{}, {}]

print("6. Siapakah tante Peter?")
print(repr(family_KB.ask_generator('Tante(x,Peter)')))
#Output:[{x: Camila}, {x: Camila}, {x: Diana}, {x: Diana}, {x: Sarah}, {x: Sarah}, {x: Sophie}, {x: Sophie}]

print("7. Siapakah sepupu Zara?")
print(repr(family_KB.ask_generator('Sepupu(x,Zara)')))
#Output: [{x: Beatrice}, {x: Beatrice}, {x: Eugenie}, {x: Eugenie}, {x: Hendry}, {x: Hendry}, {x: Lady}, {x: Lady}, {x: Peter}, {x: Peter}, {x: William}, {x: William}, {x: Zara}, {x: Zara}]

print("8. Siapakah nenek dari William?")
print(repr(family_KB.ask_generator('Nenek(x,William)')))
#Output:[{x: Elizabeth}]

print("9. Apakah Elizabeth adalah nenek dari William dan Hendry?")
print(repr(family_KB.ask_generator('Nenek(Elizabeth,William)')))
#Output:[{}]

print("10. Siapakah kakek dari Peter?")
print(repr(family_KB.ask_generator('Kakek(x,Peter)')))
#Output:[{x: Phillip}]

print("11. Siapakah ibutiri William?")
print(repr(family_KB.ask_generator('IbuTiri(x,William)')))
#Output:[{x: Camila}]

print("12. Siapakah abang dari Diana?")
print(repr(family_KB.ask_generator('KakakLaki(x,Diana)')))
#Output:[]

print("13. Siapakah kakak dari Andrew?")
print(repr(family_KB.ask_generator('KakakPerempuan(x,Andrew)')))
#Output:[{x: Anne}, {x: Anne}]

print("14. Siapakah abang dari James II?")
#14
print(repr(family_KB.ask_generator('KakakLaki(x,James_II)')))
#Output:[{x: Charles_II}, {x: Charles_II}, {x: James_II}, {x: James_II}]

print("15. Apakah Sarah adalah tante dari Peter?")
print(repr(family_KB.ask_generator('Tante(Sarah,Peter)')))
#Output:[{}, {}]

print("16. Siapakah nenekbuyut dari Hendry?")
print(repr(family_KB.ask_generator('NenekBuyut(x,Hendry)')))
#Output:[{x: Margareth}]

print("17. Siapakah paman dari Charles?")
print(repr(family_KB.ask_generator('Paman(x,Charles)')))
#Output:[{x: Charles_I}, {x: Charles_I}]

print("18. Apakah Diana adalah ibukandung Hendry?")
print(repr(family_KB.ask_generator('Ibu(Diana,Hendry)')))
#Output:[{}]

print("19. Siapakah sepupu Hendry?")
print(repr(family_KB.ask_generator('Sepupu(x,Hendry)')))
#Output:[{x: Beatrice}, {x: Beatrice}, {x: Eugenie}, {x: Eugenie}, {x: Hendry}, {x: Hendry}, {x: Lady}, {x: Lady}, {x: Peter}, {x: Peter}, {x: William}, {x: William}, {x: Zara}, {x: Zara}]

print("20. Siapakah cicitperempuan dari Elizabeth?")
print(repr(family_KB.ask_generator('CicitPerempuan(x,Elizabeth)')))
#Output:[]