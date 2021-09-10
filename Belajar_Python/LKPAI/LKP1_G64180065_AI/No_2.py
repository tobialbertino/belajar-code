"""
NO 2
"""
# membuat list output untuk mempermudah proses
golongan_1 = 'Anda mendapatkan golongan UKT 1'
golongan_2 = 'Anda mendapatkan golongan UKT 2'
golongan_3 = 'Anda mendapatkan golongan UKT 3'
golongan_4 = 'Anda mendapatkan golongan UKT 4'
golongan_5 = 'Anda mendapatkan golongan UKT 5'

tipe = input()              # Ambil tipe = input() "Input() = selalu mengambil nilai string"
if (tipe == 'BIDIKMISI'):   # Jika tipe == 'BIDIKMISI':
    print(golongan_1)       #   Print gologan_1
else :                      # Jika Tidak :
    nilai = int(input())        # Masukkan input nilai (casting int)
    if (nilai > 10000000):      # Jika nilai > 10.000.000
        print(golongan_5)       #   print golongan_5
    elif (nilai > 7000000):     # Jika (7.000.000 < nilai <= 10.000.000)
        print(golongan_4)       #   print golongan_4
    elif (nilai > 4000000):     # Jika (4.000.000 < nilai <= 7.000.000)
        print(golongan_3)       #   print golongan_3
    else :                      # Jika (nilai <= 4.000.000)
        print(golongan_2)       #   print golongan_2