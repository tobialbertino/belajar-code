from csp import *

neighbors = {
    'FAPERTA'   : ['FMIPA', 'FAHUTAN', 'FEMA'],
    'FMIPA'     : ['FAPERTA', 'FAHUTAN'],
    'FEMA'      : ['FAPERTA', 'FAHUTAN', 'FATETA', 'FEM'],
    'FAHUTAN'   : ['FMIPA', 'FAPERTA', 'FEMA', 'FATETA'],
    'FEM'       : ['FEMA', 'LSI'],
    'LSI'       : ['FEM', 'REKTORAT', 'FATETA'],
    'FATETA'    : ['FAHUTAN', 'FEMA', 'LSI'],
    'REKTORAT'  : ['LSI']
}
# MapColoringCSP(colors, neighbors)
# membuat CSP untuk masalah coloring untuk beda dengan warna berbeda
coloring_problem = MapColoringCSP('12345', neighbors) 
result = backtracking_search(coloring_problem)  # menggunakan algoritme backtracking

print(result)