from utils import *
from logic import *

# Inisiasi wold wumpus 
kb_wumpus = PropKB()
P = {}
B = {}
S = {}
G = {}
W = {}

P[1, 1] = Symbol("P[1,1]")
P[1, 2] = Symbol("P[1,2]")
P[1, 3] = Symbol("P[1,3]")
P[1, 4] = Symbol("P[1,4]")
P[2, 1] = Symbol("P[2,1]")
P[2, 2] = Symbol("P[2,2]")
P[2, 3] = Symbol("P[2,3]")
P[2, 4] = Symbol("P[2,4]")
P[3, 1] = Symbol("P[3,1]")
P[3, 2] = Symbol("P[3,2]")
P[3, 3] = Symbol("P[3,3]")
P[3, 4] = Symbol("P[3,4]")
P[4, 1] = Symbol("P[4,1]")
P[4, 2] = Symbol("P[4,2]")
P[4, 3] = Symbol("P[4,3]")
P[4, 4] = Symbol("P[4,4]")
B[1, 1] = Symbol("B[1,1]")
B[1, 2] = Symbol("B[1,2]")
B[1, 3] = Symbol("B[1,3]")
B[1, 4] = Symbol("B[1,4]")
B[2, 1] = Symbol("B[2,1]")
B[2, 2] = Symbol("B[2,2]")
B[2, 3] = Symbol("B[2,3]")
B[2, 4] = Symbol("B[2,4]")
B[3, 1] = Symbol("B[3,1]")
B[3, 2] = Symbol("B[3,2]")
B[3, 3] = Symbol("B[3,3]")
B[3, 4] = Symbol("B[3,4]")
B[4, 1] = Symbol("B[4,1]")
B[4, 2] = Symbol("B[4,2]")
B[4, 3] = Symbol("B[4,3]")
B[4, 4] = Symbol("B[4,4]")
G[1, 1] = Symbol("G[1,1]")
G[1, 2] = Symbol("G[1,2]")
G[2, 1] = Symbol("G[2,1]")
G[2, 2] = Symbol("G[2,2]")
G[2, 3] = Symbol("G[2,3]")
G[3, 2] = Symbol("G[3,2]")
G[3, 3] = Symbol("G[3,3]")
G[4, 2] = Symbol("G[4,2]")
G[4, 1] = Symbol("G[4,1]")
G[4, 3] = Symbol("G[4,3]")
W[1, 1] = Symbol("W[1,1]")
W[1, 2] = Symbol("W[1,2]")
W[1, 3] = Symbol("W[1,3]")
W[1, 4] = Symbol("W[1,4]")
W[2, 1] = Symbol("W[2,1]")
W[2, 3] = Symbol("W[2,3]")
W[2, 2] = Symbol("W[2,2]")
W[2, 4] = Symbol("W[2,4]")
W[3, 3] = Symbol("W[3,3]")
W[3, 2] = Symbol("W[3,2]")
S[1, 1] = Symbol("S[1,1]")
S[1, 2] = Symbol("S[1,2]")
S[1, 4] = Symbol("S[1,4]")
S[2, 1] = Symbol("S[2,1]")
S[2, 2] = Symbol("S[2,2]")
S[2, 3] = Symbol("S[2,3]")
S[3, 2] = Symbol("S[3,2]")
S[4, 2] = Symbol("S[4,2]")
S[4, 1] = Symbol("S[4,1]")

# memberi informasi letak PIT
kb_wumpus.tell(P[3,1])
kb_wumpus.tell(P[3,3])
kb_wumpus.tell(P[4,4])
# memberi informasi GOLD
kb_wumpus.tell(G[2,3])
# memberi informasi lokasi Wumpus
kb_wumpus.tell(W[1,3])
# memberi informasi Breeze
kb_wumpus.tell(B[2,1] |'<=>'| ((P[1,1]|P[3,1]|P[2,2])))
kb_wumpus.tell(B[3,2] |'<=>'| ((P[4,2]|P[2,2]|P[3,3]|P[3,1])))
kb_wumpus.tell(B[4,1] |'<=>'| ((P[3,1]|P[4,2])))
kb_wumpus.tell(B[2,3] |'<=>'| ((P[3,3]|P[1,3]|P[2,2]|P[2,4])))
kb_wumpus.tell(B[4,3] |'<=>'| ((P[3,3]|P[4,2]|P[4,4])))
kb_wumpus.tell(B[3,4] |'<=>'| ((P[3,3]|P[2,4]|P[4,4])))
# memberi informasi Stench
kb_wumpus.tell(S[1,2] |'<=>'| ((W[1,3]|W[2,2]|W[1,1])))
kb_wumpus.tell(S[1,4] |'<=>'| ((W[1,3]|W[2,4])))
kb_wumpus.tell(S[2,3] |'<=>'| ((W[1,3]|W[2,4]|W[2,2]|W[3,3])))

# memulai dari lokasi [1,1]
print('Posisi sekarang di [1,1]')
print('Pit :' + str(kb_wumpus.ask_if_true(P[1,1])))
print('Breeze :' + str(kb_wumpus.ask_if_true(B[1,1])))
print('Wumpus :' + str(kb_wumpus.ask_if_true(W[1,1])))
print('Glitter :' + str(kb_wumpus.ask_if_true(G[1,1])))
print('Stench :' + str(kb_wumpus.ask_if_true(S[1,1])))
if(kb_wumpus.ask_if_true(B[1,1])):
    print('Awas ada lubang di sekitar sini!')
if(kb_wumpus.ask_if_true(S[1,1])):
    print('Awas ada monster di sekitar sini!')

# Pergi ke lokasi [2,1]
print('Posisi sekarang di [2,1]')
print('Pit :' + str(kb_wumpus.ask_if_true(P[2,1])))
print('Breeze :' + str(kb_wumpus.ask_if_true(B[2,1])))
print('Wumpus :' + str(kb_wumpus.ask_if_true(W[2,1])))
print('Glitter :' + str(kb_wumpus.ask_if_true(G[2,1])))
print('Stench :' + str(kb_wumpus.ask_if_true(S[2,1])))
if(kb_wumpus.ask_if_true(B[2,1])):
    print('Awas ada lubang di sekitar sini!')
if(kb_wumpus.ask_if_true(S[2,1])):
    print('Awas ada monster di sekitar sini!')
if(kb_wumpus.ask_if_true(G[2,1])):
    print('Selamat anda menemukan emas!')

# Main aman, maka kembali ke [1, 1] dan coba cari info yg lain
print('Lokasi sekarang di [1,1]')

# Pergi ke lokasi [1,2]
print('Posisi sekarang di [1,2]')
print('Pit :' + str(kb_wumpus.ask_if_true(P[1,2])))
print('Breeze :' + str(kb_wumpus.ask_if_true(B[1,2])))
print('Wumpus :' + str(kb_wumpus.ask_if_true(W[1,2])))
print('Glitter :' + str(kb_wumpus.ask_if_true(G[1,2])))
print('Stench :' + str(kb_wumpus.ask_if_true(S[1,2])))
if(kb_wumpus.ask_if_true(B[1,2])):
    print('Awas ada lubang di sekitar sini!')
if(kb_wumpus.ask_if_true(S[1,2])):
    print('Awas ada monster di sekitar sini!')
if(kb_wumpus.ask_if_true(G[1,2])):
    print('Selamat anda menemukan emas!')

# Pergi ke lokasi [2,2]
print('Posisi sekarang di [2,2]')
print('Pit :' + str(kb_wumpus.ask_if_true(P[2,2])))
print('Breeze :' + str(kb_wumpus.ask_if_true(B[2,2])))
print('Wumpus :' + str(kb_wumpus.ask_if_true(W[2,2])))
print('Glitter :' + str(kb_wumpus.ask_if_true(G[2,2])))
print('Stench :' + str(kb_wumpus.ask_if_true(S[2,2])))
if(kb_wumpus.ask_if_true(B[2,2])):
    print('Awas ada lubang di sekitar sini!')
if(kb_wumpus.ask_if_true(S[2,2])):
    print('Awas ada monster di sekitar sini!')
if(kb_wumpus.ask_if_true(G[2,2])):
    print('Selamat anda menemukan emas!')

# Pergi ke lokasi [3,2]
print('Posisi sekarang di [3,2]')
print('Pit :' + str(kb_wumpus.ask_if_true(P[3,2])))
print('Breeze :' + str(kb_wumpus.ask_if_true(B[3,2])))
print('Wumpus :' + str(kb_wumpus.ask_if_true(W[3,2])))
print('Glitter :' + str(kb_wumpus.ask_if_true(G[3,2])))
print('Stench :' + str(kb_wumpus.ask_if_true(S[3,2])))
if(kb_wumpus.ask_if_true(B[3,2])):
    print('Awas ada lubang di sekitar sini!')
if(kb_wumpus.ask_if_true(S[3,2])):
    print('Awas ada monster di sekitar sini!')
if(kb_wumpus.ask_if_true(G[3,2])):
    print('Selamat anda menemukan emas!')

# Bermain Aman, kembali ke posisi [2, 2], cari info di posisi lain
print('Lokasi sekarang di [2,2]')

# Pergi ke lokasi [2,3]
print('Posisi sekarang di [2,3]')
print('Pit :' + str(kb_wumpus.ask_if_true(P[2,3])))
print('Breeze :' + str(kb_wumpus.ask_if_true(B[2,3])))
print('Wumpus :' + str(kb_wumpus.ask_if_true(W[2,3])))
print('Glitter :' + str(kb_wumpus.ask_if_true(G[2,3])))
print('Stench :' + str(kb_wumpus.ask_if_true(S[2,3])))
if(kb_wumpus.ask_if_true(B[2,3])):
    print('Awas ada lubang di sekitar sini!')
if(kb_wumpus.ask_if_true(S[2,3])):
    print('Awas ada monster di sekitar sini!')
if(kb_wumpus.ask_if_true(G[2,3])):
    print('Selamat anda menemukan emas!')