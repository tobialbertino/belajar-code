"""
No 1
"""
# fungsi untuk mahasiswa reguler 
def nilaiMahasiswaReguler(uts, uas, praktikum, *keaktifan):
    n_uts = uts * 0.30
    n_uas = uas * 0.35
    n_praktikum = praktikum * 0.30
    n_keaktifan = 0
    # Loop untuk niali keaktifan > 1
    i = 0
    for nilai in keaktifan:
        n_keaktifan += nilai
        i += 1
    n_keaktifan = (n_keaktifan / i) * 0.05
    n_final = n_uts + n_uas + n_praktikum + n_keaktifan
    return n_final

# fungsi untuk mahasiswa Alih Jenis
def nilaiMahasiswaAlihJenis(uts, uas, praktikum, *keaktifan, **matrikulasi):
    n_uts = uts * 0.25
    n_uas = uas * 0.25
    n_praktikum = praktikum * 0.20
    n_keaktifan = 0
    # Loop untuk niali keaktifan > 1
    i = 0
    for nilai in keaktifan:
        n_keaktifan += nilai
        i += 1
    n_keaktifan = n_keaktifan / i * 0.05
    # Keyword-Length Argument, ambil nilai matrikulasi[mat]
    for mat in matrikulasi:
        n_matrikulasi = matrikulasi[mat]
    n_matrikulasi *= 0.25
    n_final = n_uts + n_uas + n_praktikum + n_keaktifan + n_matrikulasi
    return n_final

# list = input().split(', ')
# print(list)

print(nilaiMahasiswaReguler(86, 78, 82, 80, 81, 81))
print(nilaiMahasiswaAlihJenis(85, 80, 86, 75, matrikulasi = 79))
print(nilaiMahasiswaAlihJenis(77, 65, 88, 75, 81, 80, matrikulasi = 82))