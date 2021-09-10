"""
No 3
"""
# fungsi menghitung indeks BMI
def BMI(berat, tinggi):
    bmi = berat / (tinggi**2)
    return bmi

berat, tinggi = input().split()                 # Input berat, tinggi dalam 1 line
berat, tinggi = float(berat), float(tinggi)/100 # Casting nilai menjadi float, ubah tinggi menjadi (meter)

bmi = BMI(berat, tinggi)
print(bmi)
if (bmi >= 40):                 # jika (BMI >= 40) 
    print('Class III Obesity')
elif (bmi >= 35):               # jika (35 <= BMI < 40)
    print('Class II Obesity')
elif (bmi >= 30):               # jika (30 <= BMI < 35)
    print('Class I Obesity')
elif (bmi >= 25):               # jika (25 <= BMI < 30)
    print('Overweight')     
elif (bmi >= 18.5):             # jika (18.5 <= BMI < 25)
    print('Normal weight')
else :                          # jika (BMI < 18.5)
    print('Below normal weight')
"""
melengkapi tabel :
A | 68, 187| Normal weight
B | 80, 175| Overweight
c | 90, 168| Class I Obesity
D | 54, 183| Below normal weight
"""