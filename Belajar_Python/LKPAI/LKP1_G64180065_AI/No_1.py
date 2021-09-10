"""
NO 1
"""
nilai = int(input())        # Ambil nilai input ->cast Integer
potong = 0                  # Tetapkan nilai Potongan Diskon awal

if (nilai > 50000) :                        # Jika nilai > 50.000 : 
    potong = nilai * 27/100                 #   Maka mendapat Diskon 27% dari nilai
elif (nilai > 30000):                       # Jika (30.000 < nilai <= 50.000) : 
    potong = nilai * 22/100                 #   Maka mendapat Diskon 22% dari nilai

print('Total harga yang harus dibayarkan :', nilai - potong)    # Print nilai - dikson yang didapat(dtype=float)