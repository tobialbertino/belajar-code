class Mangga:

    # magic method
    def __init__(self, nama, jumlah):
        self.nama = nama
        self.jumlah = jumlah
    
    def __repr__(self):
        return "Debug::Mangga: {}, jumlah: {}".format(self.nama, self.jumlah)

    def __str__(self):
        return "Mangga: {}, jumlah: {}".format(self.nama, self.jumlah)

    def __add__(self, object):
        return self.jumlah + object.jumlah
    
    @property
    def __dict__(self):
        return 'object mempunyai nama dan jumlah'

belanja1 = Mangga('arumanis', 10)
belanja2 = Mangga('manalagi', 30)
print(repr(belanja1))
print(belanja2)
print(belanja1 + belanja2)
print(belanja1.__dict__)