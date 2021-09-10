import json
# list amino acid one letter code
translateNameProtein= {
    'A': 'Alanine', 'C': 'Cysteine', 'D': 'Aspartic_acid',
    'E': 'Glutamic_acid', 'F': 'Phenylalanine', 'G': 'Glycine',
    'H': 'Histidine', 'I': 'Isoleucine', 'K': 'Lysine',
    'L': 'Leucine', 'M': 'Methionine', 'N': 'Asparagine',
    'O': 'Stop', 'P': 'Proline', 'Q': 'Glutamine',
    'R': 'Arginine', 'S': 'Serine', 'T': 'Threonine',
    'V': 'Valine', 'W': 'Tryptophan', 'Y': 'Tyrosine'
}

def main(fileName):
    fh = open(fileName)             # Membuka file

    baris_pertama = fh.readline()   # membaca baris pertama
    name = baris_pertama[1: -1]     # menghilangkan tanda awal dan akhir
    name = name.replace('|', ' | ') # memberi jarak pemisah |
    sequence = ''
    while True:                     # loop untuk mengambil sequence
        baris = fh.readline()       # baca perbaris
        if (baris == ''):           # akhiri jika null
            break
        else :                      # tambahkan, hilangkan \n
            sequence += baris.replace('\n', '')

    print('the name is: %s' %name)
    print('the sequence is: %s' %sequence)

    seqAsam = list(sorted(set(sequence)))   # Urutkan list sequence, dan hilangkan duplikasi dgn set()

    jumlahAsam = []
    distribusiAsam = []
    objectJumlahAsam = {}
    objectDistribusiAsam = {}
    total = 0
    for i in range(len(seqAsam)):           # loop menghitung jumlah
        jumlah = sequence.count(seqAsam[i]) # hitung jumlah asam
        total += jumlah                     # tambahkan total
        jumlahAsam.append(str(translateNameProtein[seqAsam[i]])+ ': '+ str(jumlah)) # tamba list
        objectJumlahAsam[translateNameProtein[seqAsam[i]]] = jumlah  # untuk menambah object 
    
    for i in range(len(seqAsam)):           # loop presentase asam
        jumlah = sequence.count(seqAsam[i]) # ambil jumlah
        distribusiAsam.append(str(translateNameProtein[seqAsam[i]]) + ': ' + str(format((jumlah/total) * 100, '.2f')) + '%') # tambah list
        objectDistribusiAsam[translateNameProtein[seqAsam[i]]] = str(format((jumlah/total) * 100, '.2f')) + '%'

    print('\njumlah asam amino')
    for i in range(len(seqAsam)):
        print (jumlahAsam[i])

    print('\njumlah presentase asam amino')
    for i in range(len(seqAsam)):
        print (distribusiAsam[i])
    
    # print(objectJumlahAsam)
    # print(objectDistribusiAsam)
    
    ans = open('sequence pada ' + fileName, 'w+')
    ans.write(name + '\n')
    ans.write('sequence: \n')
    ans.write(sequence + '\n')
    ans.write('jumlah tiap Asam amino pada ' + fileName + ': \n')
    ans.write(json.dumps(objectJumlahAsam) + '\n')
    ans.write('distribusi tiap Asam amino pada ' + fileName + ': \n')
    ans.write(json.dumps(objectDistribusiAsam) + '\n')
    ans.close()

    fh.close()

print('\n=>')
main('seqA.fasta')
print('\n=>')
main('rcsb_pdb_2MK2.fasta')
print('\n=>')
main('rcsb_pdb_3W6A.fasta')